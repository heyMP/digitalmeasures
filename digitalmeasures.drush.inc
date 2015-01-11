<?php

/**
 * @file
 * Custom drush commands for the digitalmeasures module.
 */

/**
 * Implements hook_drush_command().
 */
function digitalmeasures_drush_command() {
  $items = array();
  $items['user_profile'] = array(
    'description' => 'Retrieve user profile data from Digital Measures.',
    'aliases' => array('dmup'),
    'arguments' => array(
      'username' => 'Username of the profile.',
    ),
    'examples' => array(
      'drush dmup mgp140' => 'Retrieve all profile infromation for mgp140.',
    ),
  );

  return $items;
}

/**
 * digitalmeasures retrieve user profile command.
 */
function drush_digitalmeasures_user_profile($username) {
  digitalmeasures_digitalmeasures_user_profile($username);
}
