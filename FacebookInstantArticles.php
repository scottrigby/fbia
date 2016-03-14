<?php

/**
 * @file
 * Contains \Drupal\FacebookInstantArticles.
 */

namespace Drupal\FacebookInstantArticles;

use Facebook\Facebook;
use Drupal\FacebookInstantArticlesFormatterInterface;

/**
 * A wrapper around Facebook's SDK, integrating Instant Articles with Drupal.
 *
 * Class FacebookInstantArticles
 * @package Drupal\FacebookInstantArticles
 */
class FacebookInstantArticles extends Facebook {

  /**
   * Facebook page ID to host Instant Articles.
   *
   * @var int|null
   */
  protected $pageID;

  /**
   * The Facebook Instant Articles Environment for this site.
   *
   * @var string|null $environment
   *   Can be one of:
   *   - development
   *   - production
   */
  protected $environment;

  public function __construct(array $config) {
    parent::__construct($config);

    $this->pageID = variable_get('fbia_page_id');
    $this->environment = variable_get('fbia_environment', 'development');
  }

  /**
   * {@inheritdoc}
   *
   * Posts an Instant Article to the Facebook page.
   *
   * @param string $source
   *   Source HTML for an Instant Articles post.
   * @param bool $takeLive
   *   Not necessary if development mode is TRUE, as articles in the development
   *   environment can never be taken live. Otherwise, if in the Production
   *   environment, this specifies if the Instant Articles are published.
   */
  public function post($source, $takeLive = FALSE) {
    // Format the source HTML.
    foreach ($this->formatters() as $class_name) {
      if (in_array('Drupal\FacebookInstantArticlesFormatterInterface', class_implements($class_name))) {
        $class_name::format($source);
      }
    }

    $params['html_source'] = $source;

    // Take live does not matter if the article is posted in development mode.
    if ($this->environment == 'development') {
      $params['development_mode'] = TRUE;
    }
    else {
      $params['development_mode'] = FALSE;
      $params['take_live'] = $takeLive;
    }

    parent::post($this->pageID .'/instant_articles', $params);
  }

  /**
   * Defines HTML formatter classes responsible for ensuring proper markup.
   *
   * @return array
   *   An array of supported formatter class names.
   */
  protected function formatters() {
    return module_invoke_all('fbia_formatters');
  }

}
