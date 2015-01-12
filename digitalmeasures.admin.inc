<?php

/**
 * @file
 * Administrative page callbacks for the Digital Measures module.
 */

/**
 * Digital Measures admin configuration form.
 */
function digitalmeasures_admin_config_form($form, &$form_state) {
  $form['digitalmeasures_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#default_value' => variable_get('digitalmeasures_username', ''),
  );
  $form['digitalmeasures_password'] = array(
    '#type' => 'textfield',
    '#title' => t('Password'),
    '#default_value' => variable_get('digitalmeasures_password', ''),
  );
  $form['digitalmeasures_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Base Url'),
    '#default_value' => variable_get('digitalmeasures_url', DIGITALMEASURES_BASE_URL),
  );


  return system_settings_form($form);
}
