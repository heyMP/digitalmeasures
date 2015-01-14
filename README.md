# Digital Measures API

This is a Drupal module will act as an API to request data from the [Digital Measures](http://www.digitalmeasures.com/) platform.

## Instructions
  1. Install the digitalmeasures module on your Drupal site. You will also need [drupal_debug_log](https://www.drupal.org/project/devel_debug_log) for development purposes.
  2. Visit the modules configuration page, admin/config/services/digitalmeasures.  Enter your Digital Measures account username, password, and base url(defaults to https://beta.digitalmeasures.com. It is recomended to use the beta url for development).
  3. Run 'drush cc drush' to let drush have access to the new drush commands defined by this module.
  4. Run 'drush dmindexes' to retrieve a list of active searchable indexes in Digital Measures.
  5. Run 'drush dmdata --help' to see an example of how to search on those indexes.

## Drupal Debug Log

For development purposes, [drupal_debug_log](https://www.drupal.org/project/devel_debug_log)
is used to log all api results.

You can view the results on the devel debug log page: admin/reports/debug
