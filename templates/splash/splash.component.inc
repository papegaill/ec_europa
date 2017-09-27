<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_definition_hook().
 */
function ec_europa_atomium_definition_splash() {
  return array(
    'label' => 'Splash',
    'description' => 'Splash.',
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function ec_europa_preprocess_splash(&$variables, $hook) {
  if (empty($variables['path'])) {
    $variables['path'] = '/node';
  }

  $variables['languages_list'] = array();
  foreach ($variables['languages_list_array'] as $language) {
    $variables['languages_list'][] = array(
      '#theme' => array('link__' . $variables['theme_hook_original']),
      '#text' => $language->name,
      '#path' => $variables['path'],
      '#options' => array(
        'attributes' => array(
          'class' => array(
            'ecl-button',
            'ecl-button--block',
            'ecl-button--splash-page',
            'ecl-u-mb-xxxs',
          ),
          'lang' => $language->language,
          'hreflang' => $language->language,
          'rel' => 'alternate',
        ),
        'html' => FALSE,
      ),
    );
  }

  $variables['languages_list'] = array_chunk(
    $variables['languages_list'],
    round(count($variables['languages_list']) / 2)
  );

  foreach ($variables['languages_list'] as $index => &$language) {
    $language['#theme'] = array('html_tag__' . $variables['theme_hook_original']);
    $language['#tag'] = 'div';
    $language['#attributes'] = array(
      'class' => array(
        'column-' . $index,
        'ecl-col-md-6',
      ),
    );
  }

  $variables['attributes_array']['class'][] = 'ecl-row';
}