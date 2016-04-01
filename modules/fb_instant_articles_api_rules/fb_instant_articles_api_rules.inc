<?php

/**
 * @file
 * Provide rules integration to manage facebook instant article using API.
 */

/**
 * Implements hook_rules_action_info() on behalf of the Facebook Instant Articles API module.
 */
function fb_instant_articles_api_rules_rules_action_info() {
  $defaults = array(
    'parameter' => array(
      'entity' => array(
        'type' => 'entity',
        'label' => t('Entity'),
      ),
    ),
    'group' => t('Entity'),
    'access callback' => 'fb_instant_articles_api_rules_integration_access',
  );
  $actions['fb_instant_articles_create'] = $defaults + array(
    'label' => t('Add facebook instant article'),
    'base' => 'rules_action_fb_instant_articles_add',
  );
  $actions['fb_instant_articles_update'] = $defaults + array(
    'label' => t('Update facebook instant article'),
    'base' => 'rules_action_fb_instant_articles_update',
  );
  $actions['fb_instant_articles_read'] = $defaults + array(
    'label' => t('Read facebook instant article'),
    'base' => 'rules_action_fb_instant_articles_read',
  );
  $actions['fb_instant_articles_delete'] = $defaults + array(
    'label' => t('Delete facebook instant article'),
    'base' => 'rules_action_fb_instant_articles_update',
  );
  return $actions;
}

/**
 * Facebook Instant Articles API integration access callback.
 */
function fb_instant_articles_api_rules_integration_access($type, $name) {
  return user_access('administer site configuration');
}

/**
 * Action: Add facebook instant article.
 *
 * @param object $entity
 */
function rules_action_fb_instant_articles_create($entity) {
  if (isset($entity->entity_id)) {
    fbia_import_article($entity);
  }
}

/**
 * Action: Update facebook instant article.
 *
 * @param object $entity
 */
function rules_action_fb_instant_articles_update($entity) {
  if (isset($entity->entity_id)) {
    fbia_import_article($entity);
  }
}

/**
 * Action: Read facebook instant article.
 *
 * @param object $entity
 */
function rules_action_fb_instant_articles_read($entity) {
  //read call().
}

/**
 * Action: Delete facebook instant article.
 *
 * @param object $entity
 */
function rules_action_fb_instant_articles_delete($entity) {
  if (isset($entity->id)) {
    $url = url(drupal_get_path_alias($entity->entity_type . "/" . $entity->entity_id), array('absolute' => TRUE));
    fbia_remove_article($url);
  }
}
