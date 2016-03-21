<?php

/**
 * @file
 * Settings for Facebook Instant Articles UI module.
 */

/**
 * Form constructor for settings form.
 */
function fbia_ui_settings() {
  $args = array(
    '@claim_url' => 'https://developers.facebook.com/docs/instant-articles/claim-url',
    '@development_feed' => 'https://developers.facebook.com/docs/instant-articles/publishing#testing-development-feed',
  );

  // The Facebook app connection info could alternatively be stored via the fb
  // module, but it's not yet ported to D8, and a bit cumbersome just for this.
  $form['fbia_app_id'] = array(
    '#title' => t('Facebook App ID'),
    '#type' => 'textfield',
    '#default_value' => variable_get('fbia_app_id'),
  );

  $form['fbia_app_secret'] = array(
    '#title' => t('Facebook App Secret'),
    '#type' => 'textfield',
    '#default_value' => variable_get('fbia_app_secret'),
  );

  $form['fbia_page_id'] = array(
    '#title' => t('Facebook Page ID'),
    '#type' => 'textfield',
    '#default_value' => variable_get('fbia_page_id'),
    '#description' => t('In order to designate the domain that will host your 
      articles you must add your Facebook page ID to a metatag in the HEAD tag 
      of your HTML page. See <a href="@claim_url">Claiming your URL</a>.', $args),
  );

  $form['fbia_environment'] = array(
    '#title' => t('Facebook Instant Articles environment'),
    '#type' => 'select',
    '#options' => array(
      'development' => t('Development'),
      'production' => t('Production'),
    ),
    '#default_value' => variable_get('fbia_environment', 'development'),
    '#description' => t('Articles in the development environment can never be 
      taken live. See <a href="@development_feed">See Development Feed</a>.', $args),
  );
  
  return system_settings_form($form);
}
