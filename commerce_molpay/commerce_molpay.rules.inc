<?php

/**
 * Rules integration for MOLPay.
 */

/**
 * Implements hook_rules_action_info().
 */
function commerce_molpay_rules_action_info() {
  $actions = array();

  // Must enable 2checkout payment before this will work!!
  $actions['commerce_molpay_redirect'] = array(
    'label' => t('Redirect to 2checkout'),
    'parameter' => array(
      'commerce_order' => array(
        'type' => 'commerce_order',
        'label' => t('Order in checkout'),
      ),
    ),
    'group' => t('Commerce Checkout'),
    'base' => 'commerce_molpay_redirect_checkout',
  );
  $actions['commerce_molpay_add_shipping'] = array(
    'label' => t('Add shipping rates from $_REQUEST'),
    'parameter' => array(
      'commerce_order' => array(
        'type' => 'commerce_order',
        'label' => t('Order in checkout'),
      ),
    ),
    'group' => t('Commerce Shipping'),
    'base' => 'commerce_molpay_add_shipping',
  );
  return $actions;
}
