/******************************************************************************
 *
 *  Copyright 2014 Google, Inc.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at:
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 ******************************************************************************/

#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "btcore/include/device_features.h"
#include "hci/include/hci_layer.h"
#include "hci/include/hci_packet_factory.h"
#include "hci/include/hci_packet_parser.h"

static const char CONTROLLER_MODULE[] = "controller_module";

typedef struct controller_t {
  bool (*get_is_ready)(void);

  const RawAddress* (*get_address)(void);
  const bt_version_t* (*get_bt_version)(void);

  const uint8_t* (*get_ble_supported_states)(void);

  bool (*supports_simple_pairing)(void);
  bool (*supports_secure_connections)(void);
  bool (*supports_simultaneous_le_bredr)(void);
  bool (*supports_reading_remote_extended_features)(void);
  bool (*supports_interlaced_inquiry_scan)(void);
  bool (*supports_rssi_with_inquiry_results)(void);
  bool (*supports_extended_inquiry_response)(void);
  bool (*supports_central_peripheral_role_switch)(void);
  bool (*supports_enhanced_setup_synchronous_connection)(void);
  bool (*supports_enhanced_accept_synchronous_connection)(void);
  bool (*supports_3_slot_packets)(void);
  bool (*supports_5_slot_packets)(void);
  bool (*supports_classic_2m_phy)(void);
  bool (*supports_classic_3m_phy)(void);
  bool (*supports_3_slot_edr_packets)(void);
  bool (*supports_5_slot_edr_packets)(void);
  bool (*supports_sco)(void);
  bool (*supports_hv2_packets)(void);
  bool (*supports_hv3_packets)(void);
  bool (*supports_ev3_packets)(void);
  bool (*supports_ev4_packets)(void);
  bool (*supports_ev5_packets)(void);
  bool (*supports_esco_2m_phy)(void);
  bool (*supports_esco_3m_phy)(void);
  bool (*supports_3_slot_esco_edr_packets)(void);
  bool (*supports_role_switch)(void);
  bool (*supports_hold_mode)(void);
  bool (*supports_sniff_mode)(void);
  bool (*supports_park_mode)(void);
  bool (*supports_non_flushable_pb)(void);
  bool (*supports_sniff_subrating)(void);
  bool (*supports_encryption_pause)(void);

  bool (*supports_ble)(void);
  bool (*supports_ble_packet_extension)(void);
  bool (*supports_ble_connection_parameters_request)(void);
  bool (*supports_ble_privacy)(void);
  bool (*supports_ble_set_privacy_mode)(void);
  bool (*supports_ble_2m_phy)(void);
  bool (*supports_ble_coded_phy)(void);
  bool (*supports_ble_extended_advertising)(void);
  bool (*supports_ble_periodic_advertising)(void);
  bool (*supports_ble_peripheral_initiated_feature_exchange)(void);
  bool (*supports_ble_connection_parameter_request)(void);
  bool (*supports_ble_periodic_advertising_sync_transfer_sender)(void);
  bool (*supports_ble_periodic_advertising_sync_transfer_recipient)(void);
  bool (*supports_ble_connected_isochronous_stream_central)(void);
  bool (*supports_ble_connected_isochronous_stream_peripheral)(void);
  bool (*supports_ble_isochronous_broadcaster)(void);
  bool (*supports_ble_synchronized_receiver)(void);

  // Get the cached acl data sizes for the controller.
  uint16_t (*get_acl_data_size_classic)(void);
  uint16_t (*get_acl_data_size_ble)(void);
  uint16_t (*get_iso_data_size)(void);

  // Get the cached acl packet sizes for the controller.
  // This is a convenience function for the respective
  // acl data size + size of the acl header.
  uint16_t (*get_acl_packet_size_classic)(void);
  uint16_t (*get_acl_packet_size_ble)(void);
  uint16_t (*get_iso_packet_size)(void);

  uint16_t (*get_ble_default_data_packet_length)(void);
  uint16_t (*get_ble_maximum_tx_data_length)(void);
  uint16_t (*get_ble_maximum_tx_time)(void);
  uint16_t (*get_ble_maxium_advertising_data_length)(void);
  uint8_t (*get_ble_number_of_supported_advertising_sets)(void);
  uint8_t (*get_ble_periodic_advertiser_list_size)(void);

  // Get the number of acl packets the controller can buffer.
  uint16_t (*get_acl_buffer_count_classic)(void);
  uint8_t (*get_acl_buffer_count_ble)(void);
  uint8_t (*get_iso_buffer_count)(void);

  uint8_t (*get_ble_acceptlist_size)(void);

  uint8_t (*get_ble_resolving_list_max_size)(void);
  void (*set_ble_resolving_list_max_size)(int resolving_list_max_size);
  uint8_t* (*get_local_supported_codecs)(uint8_t* number_of_codecs);
  uint8_t (*get_le_all_initiating_phys)(void);

} controller_t;

const controller_t* controller_get_interface();

const controller_t* controller_get_test_interface(
    const hci_t* hci_interface,
    const hci_packet_factory_t* packet_factory_interface,
    const hci_packet_parser_t* packet_parser_interface);
