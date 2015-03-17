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
    'description' => 'Retrieve a list of all indexes and entries.',
    'aliases' => array('dmindexes'),
    'arguments' => array(
      'search-data' => 'A comma separated list of indexkeys that you would like to search on.',
    ),
  );
  $items['get-entry-keys'] = array(
    'description' => 'Retrieve a list of entry keys available from specified indexes.',
    'aliases' => array('dmentrykeys'),
    'arguments' => array(
      'search-data' => 'A comma separated list of indexkeys whos entry keys you would like to recieve.',
    ),
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

  if (module_exists('devel_debug_log')) {
    ddl($response);
  }
}

/**
 * Drush get all indexes callback.
 */
function drush_digitalmeasures_get_indexes($arguments) {
  $response = digitalmeasures_digitalmeasures_get_indexes($arguments);

  drush_print_r($response);
  if (module_exists('devel_debug_log')) {
    ddl($response);
  }
}

/**
 * Drush get all entry keys callback.
 */
function drush_digitalmeasures_get_entry_keys($arguments) {
  $response = digitalmeasures_digitalmeasures_entry_keys_from_index($arguments);

  drush_print_r($response);
  if (module_exists('devel_debug_log')) {
    ddl($response);
  }
}
