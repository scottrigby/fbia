<?php

/**
 * @file
 * Provide rules integration to manage facebook instant article using API.
 */

/**
 * Implements hook_rules_action_info() on behalf of the Facebook Instant Articles API module.
 */
function fb_instant_articles_api_rules_action_info() {
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
    'label' => t('Update facebook instant article'),
    'base' => 'rules_action_fb_instant_articles_read',
  );
  $actions['fb_instant_articles_delete'] = $defaults + array(
    'label' => t('Update facebook instant article'),
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
 */
function rules_action_fb_instant_articles_create($entity) {
  fbia_import_article($entity);
}

/**
 * Action: Update facebook instant article.
 */
function rules_action_fb_instant_articles_update($entity) {
  //update call().
}

/**
 * Action: Read facebook instant article.
 */
function rules_action_fb_instant_articles_read($entity) {
  //read call().
}

/**
 * Action: Delete facebook instant article.
 */
function rules_action_fb_instant_articles_delete($entity) {
  fbia_remove_article($entity);
}
