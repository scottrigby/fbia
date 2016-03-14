<?php

/**
 * @file
 * Contains \Drupal\FacebookInstantArticlesFormatterInterface.
 */

namespace Drupal\FacebookInstantArticlesFormatterInterface;

/**
 * Interface for defining a Drupal Instant Article formatter class.
 *
 * Interface FacebookInstantArticlesFormatterTrait
 * @package Drupal\FacebookInstantArticlesFormatterTrait
 */
interface FacebookInstantArticlesFormatterInterface {

  /**
   * Formats pieces of HTML source for Instant Articles markup compatibility.
   *
   * @param string $source
   *   Source HTML for an Instant Articles post, passed by reference.
   *
   * See @link https://developers.facebook.com/docs/instant-articles/guides/articlecreate Overview. @endlink
   * See @link https://developers.facebook.com/docs/instant-articles/reference Format reference. @endlink
   */
  public function format(&$source);
  
}
