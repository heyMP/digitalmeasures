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
  $items['get-schemadata'] = array(
    'description' => 'Retrieve schema data from digital measures.',
    'aliases' => array('dmdata'),
    'arguments' => array(
      'search-data' => 'A comma separated list of indexkeys and entry keys,
        separated by a colon, that you would like to search on.',
    ),
    'examples' => array(
      'drush dmdata USERNAME:mgp140,USERNAME:kpf107' => 'Retrieve all profile infromation for mgp140 and kpf107.',
    ),
  );
  $items['get-indexes'] = array(
    'description' => 'Retrieve retrieve a list of all indexes and entries.',
    'aliases' => array('dmindexes'),
  );

  return $items;
}

/**
 * Drush retrieve user profile callback.
 */
function drush_digitalmeasures_get_schemadata($arguments) {
  // Convert the arguments string into a nested array
  $arguments_array = _digitalmeasures_arguments_string_to_array($arguments);
  // Make request to Digital Measures
  $response = digitalmeasures_digitalmeasures_get_schemadata($arguments_array);

  drush_print_r($response);
  if (module_exists('devel_debug_log')) {
    ddl($response);
  }
}

/**
 * Drush get all indexes callback.
 */
function drush_digitalmeasures_get_indexes() {
  $response = digitalmeasures_digitalmeasures_get_all_indexes();

  drush_print_r($response);
  if (module_exists('devel_debug_log')) {
    ddl($response);
  }
}
