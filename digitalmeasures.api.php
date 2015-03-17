<?php

/**
 * @file
 * Digital Measures API documentation.
 */

/**
 * Retrieve schema data from Digital Measures.
 *
 * @param $arguments
 *   An array of index keys to search on where the key of array is the
 *   'indexKey' and the value is the 'entryKey' that you want to search on.
 *   Example:
 *     array(
 *       'USERNAME' => array('mgp140', 'btopro'),
 *       'CAMPUS_NAME' => array('University Park'),
 *     );
 * @param $output
 *   Choose how your reponse data is rendered.
 *   - php
 *   - xml
 *
 * @return response data from Digital Measures
 */
function hook_digitalmeasures_get_schemadata($arguments = array(), $output = 'php') {
  // Define Resource ID
  $resource_id = 'login/service/v4/SchemaData/INDIVIDUAL-ACTIVITIES-University';
  // Connect to Digital Measures
  $response = _digitalmeasures_connect($resource_id, $arguments);
  // Output the data as php array
  return _digital_measures_render_response_data($response, $output);
}

/**
 * Retrieve a list of all indexes and entries.
 *
 * @param $output
 *   Choose how your reponse data is rendered.
 *   - php
 *   - xml
 */
function hook_digitalmeasures_get_indexes($arguments = array(), $output = 'php') {
  $resource_id = 'login/service/v4/SchemaIndex/INDIVIDUAL-ACTIVITIES-University';
  $response = _digitalmeasures_connect($resource_id, $arguments);

  return _digital_measures_render_response_data($response, $output);
}
