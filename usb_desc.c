/* Copyright (c) 2008 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT. 
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRENTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *
 * $LastChangedRevision: 133 $
 */
 
#include "usb_desc.h"
#include "nordic_common.h"               
 
//-----------------------------------------------------------------------------
// Report descriptors
//-----------------------------------------------------------------------------
 
code const uint8_t g_usb_hid_report_keyboard[] =
{
  #include "nrfr_keyboard_report_desc.h"  
};
 
code const uint8_t g_usb_hid_report_mouse[] =
{
  #include "nrfr_mouse_report_desc.h"   
};
 
code const uint8_t g_usb_hid_report_rc[] = 
{
  #include "nrfr_remote_report_desc.h"   
};
 
code uint8_t g_usb_hid_report_data[] = 
{
  #include "nrfr_data_report_desc.h"    
};
 
code hal_usb_hid_t g_usb_hid_hids[] = 
{
//    { &g_usb_conf_desc.hid1, g_usb_hid_report_keyboard, sizeof(g_usb_hid_report_keyboard) }, 
//    { &g_usb_conf_desc.hid2, g_usb_hid_report_mouse, sizeof(g_usb_hid_report_mouse) },               
//    { &g_usb_conf_desc.hid3, g_usb_hid_report_rc, sizeof(g_usb_hid_report_rc) },
    { &g_usb_conf_desc.hid4, g_usb_hid_report_data, sizeof(g_usb_hid_report_data) },
};
 
//-----------------------------------------------------------------------------
// Endpoint packet size definitions
//-----------------------------------------------------------------------------
 
#define MAX_PACKET_SIZE_EP0 0x020
#define EP1_PACKET_SIZE 0x00a
#define EP2_PACKET_SIZE 0x00a
#define EP3_PACKET_SIZE 0x00a
#define EP4_PACKET_SIZE 0x020
 
//-----------------------------------------------------------------------------
// Device descriptor
//-----------------------------------------------------------------------------
 
code const hal_usb_dev_desc_t g_usb_dev_desc =
{
  sizeof(hal_usb_dev_desc_t),         // bLength
  USB_DESC_DEVICE,                    // bDescriptorType
  SWAP(0x0200),                       // bcdUSB
  0x00,                               // bDeviceClass
  0x00,                               // bDeviceSubClass
  0x00,                               // bDeviceProtocol
  MAX_PACKET_SIZE_EP0,                // bMaxPacketSize0
  SWAP(VID),                          // idVendor (Nordic )
  SWAP(PID),                          // idProduct (dongle)
  SWAP(0x0100),                       // bcdDevice
  0x01,                               // iManufacturer
  0x02,                               // iProduct
  0x03,                               // iSerialNumber
  0x01                                // bNumConfigurations
};
 
//-----------------------------------------------------------------------------
// Configuration, interface and endpoint descriptors
// From "USB Device Class Definition for Human Interface Devices (HID)".
// Section 7.1:
// "When a Get_Descriptor(Configuration) request is issued,
// it returns the Configuration descriptor, all Interface descriptors,
// all Endpoint descriptors, and the HID descriptor for each interface."
//-----------------------------------------------------------------------------
 
code const usb_conf_desc_templ_t g_usb_conf_desc =
{
  { // configuration_descriptor hid_configuration_descriptor
    sizeof(hal_usb_conf_desc_t),         // Length
    USB_DESC_CONFIGURATION,                               // Type                             
    SWAP(sizeof(usb_conf_desc_templ_t)),        // Totallength
    0x01,                               // NumInterfaces
    0x01,                               // bConfigurationValue
    0x00,                               // iConfiguration
    0xA0,                               // bmAttributes (0x80 + Remote Wakeup)
    0x32                                // MaxPower (in 2mA units) = 100 * 2mA
  },
//-----------------------------------------------------------------------------
// Keyboard interface decriptor
//-----------------------------------------------------------------------------
//  { // interface_descriptor hid_interface_descriptor    (KEYBOARD)
//    sizeof(hal_usb_if_desc_t),        // Length
//    0x04,                               // bDescriptorType
//    0x00,                               // bInterfaceNumber
//    0x00,                               // bAlternateSetting
//    0x01,                               // bNumEndpoints
//    0x03,                               // bInterfaceClass (3 = HID)
//    0x01,                               // bInterfaceSubClass (Boot)
//    0x01,                               // bInterfaceProcotol(0=None, 1=Keyb, 2=Mouse)
//    0x00                                // iInterface
//  },
//  { // class_descriptor hid_descriptor
//    sizeof(hal_usb_hid_desc_t),          // Length
//    0x21,                              // bDescriptorType
//    SWAP(0x0111),	                            // bcdHID
//    0x00,	                            // bCountryCode
//    0x01,	                            // bNumDescriptors
//    0x22,                               // bDescriptorType
//    SWAP(sizeof(g_usb_hid_report_keyboard)),   // wItemLength (tot. len. of report
//                                        // descriptor)
//  },
//  { // endpoint_descriptor hid_endpoint_in_descriptor
//    sizeof(hal_usb_ep_desc_t),              // Length
//    0x05,                               // bDescriptorType
//    0x81,                               // bEndpointAddress
//    0x03,                               // bmAttributes
//    SWAP(EP1_PACKET_SIZE),              // MaxPacketSize (LITTLE ENDIAN)
//    10                                  // bInterval
//  },
////-----------------------------------------------------------------------------
//// Mouse interface decriptor
////-----------------------------------------------------------------------------
//   { // interface_descriptor hid_interface_descriptor    (MOUSE)
//    sizeof(hal_usb_if_desc_t),             // Length
//    0x04,                               // bDescriptorType
//    0x01,                               // bInterfaceNumber
//    0x00,                               // bAlternateSetting
//    0x01,                               // bNumEndpoints
//    0x03,                               // bInterfaceClass (3 = HID)
//    0x01,                               // bInterfaceSubClass
//    0x02,                               // bInterfaceProcotol(0=None, 1=Keyb, 2=Mouse)
//    0x00                                // iInterface
//  },
//  { // class_descriptor hid_descriptor
//    sizeof(hal_usb_hid_desc_t),             // Length
//    0x21,	                                // bDescriptorType
//    SWAP(0x0111),	                                // bcdHID
//    0x00,	                                // bCountryCode
//    0x01,	                                // bNumDescriptors
//    0x22,                                   // bDescriptorType
//    SWAP(sizeof(g_usb_hid_report_mouse)), // wItemLength (tot. len. of report
//                                            // descriptor)
//  },
//  { // endpoint_descriptor hid_endpoint_in_descriptor
//    sizeof(hal_usb_ep_desc_t),          // Length
//    0x05,                               // bDescriptorType
//    0x82,                               // bEndpointAddress
//    0x03,                               // bmAttributes
//    SWAP(EP2_PACKET_SIZE),              // MaxPacketSize (LITTLE ENDIAN)
//    2                                   // bInterval
//  },
////-----------------------------------------------------------------------------
//// Remote interface descriptor
////-----------------------------------------------------------------------------
//  { // interface_descriptor hid_interface_descriptor    (REMOTE CONTROL)
//    sizeof(hal_usb_if_desc_t),          // Length
//    0x04,                               // bDescriptorType
//    0x02,                               // bInterfaceNumber
//    0x00,                               // bAlternateSetting
//    0x01,                               // bNumEndpoints
//    0x03,                               // bInterfaceClass (3 = HID)
//    0x00,                               // bInterfaceSubClass
//    0x00,                               // bInterfaceProcotol(0=None, 1=Keyb, 2=Mouse)
//    0x00                                // iInterface
//  },
//  { // class_descriptor hid_descriptor
//    sizeof(hal_usb_hid_desc_t),          // Length
//    0x21,	                            // bDescriptorType
//    SWAP(0x0111),	                    // bcdHID
//    0x00,	                            // bCountryCode
//    0x01,	                            // bNumDescriptors
//    0x22,                               // bDescriptorType
//    SWAP(sizeof(g_usb_hid_report_rc)),// wItemLength (tot. len. of report
//                                        // descriptor)
//  },
//  { // endpoint_descriptor hid_endpoint_in_descriptor
//    sizeof(hal_usb_ep_desc_t),          // Length
//    0x05,                               // bDescriptorType
//    0x83,                               // bEndpointAddress
//    0x03,                               // bmAttributes
//    SWAP(EP3_PACKET_SIZE),              // MaxPacketSize (LITTLE ENDIAN)
//    10                                  // bInterval
//  },
//-----------------------------------------------------------------------------
// Data interface descriptor
//-----------------------------------------------------------------------------
  { // interface_descriptor hid_interface_descriptor
    sizeof(hal_usb_if_desc_t),
    USB_DESC_INTERFACE,
    3,         // bInterfaceNumber
    0,         // bAlternateSetting
    2,         // bNumEndpoints
    0x03,      // bInterfaceClass (3 = HID)
    0x00,      // bInterfaceSubClass 
    0x11,      // bInterfaceProtocol 
    0x00,      // iInterface
  },
  /* HID Descriptor */
  {
      sizeof(hal_usb_hid_desc_t),
      USB_CLASS_DESCRIPTOR_HID, // bDescriptorType
      SWAP(0x0110), // bcdHID -  HID Spec 1.11
      0x00,         // bCountryCode 
      1,            // bNumDescriptors - Number of HID class descriptors to follow
      0x22,         // bDescriptorType - Report Descriptor Type 
      SWAP(sizeof(g_usb_hid_report_data)), // wDescriptorLength Hid report length
   },
  /* Endpoint Descriptor EP4IN */
  {
    sizeof(hal_usb_ep_desc_t),
    USB_DESC_ENDPOINT,
    0x84,                        // bEndpointAddress
    USB_ENDPOINT_TYPE_INTERRUPT, // bmAttributes
    SWAP(EP4_PACKET_SIZE),                // wMaxPacketSize
    0x06                         // bInterval
  },
  /* Endpoint Descriptor EP4OUT */
  {
    sizeof(hal_usb_ep_desc_t),
    USB_DESC_ENDPOINT,
    0x04,                        // bEndpointAddress
    USB_ENDPOINT_TYPE_INTERRUPT, // bmAttributes
    SWAP(EP4_PACKET_SIZE),                // wMaxPacketSize
    0x06                         // bInterval
  },
};
 
//-----------------------------------------------------------------------------
// String descriptors
//-----------------------------------------------------------------------------
 
#define USB_STRING_IDX_1_DESC "Nordic Semiconductor"
#define USB_STRING_IDX_2_DESC "Nordic Semiconductor nRFready Desktop Solution "
#define USB_STRING_IDX_3_DESC "0123456789"
#define USB_STRING_IDX_4_DESC "abcdefghij"
 
code uint8_t g_usb_string_desc_1[] = {
    sizeof(USB_STRING_IDX_1_DESC) * 2, 
    0x03, 
    'N',00,
    'o',00,
    'r',00,
    'd',00,
    'i',00,
    'c',00,
    ' ',00,
    'S',00,
    'e',00,
    'm',00,
    'i',00,
    'c',00,
    'o',00,
    'n',00,
    'd',00,
    'u',00,
    'c',00,
    't',00,
    'o',00,
    'r', 00 
};
 
code uint8_t g_usb_string_desc_2[] = {
    sizeof(USB_STRING_IDX_2_DESC) * 2,
    0x03, 
    'N',00,
    'o',00,
    'r',00,
    'd',00,
    'i',00,
    'c',00,
    ' ',00,
    'S',00,
    'e',00,
    'm',00,
    'i',00,
    'c',00,
    'o',00,
    'n',00,
    'd',00,
    'u',00,
    'c',00,
    't',00,
    'o',00,
    'r',00, 
    ' ',00, 
    'n',00,
    'R',00,
    'F',00,
    'r',00,
    'e',00,
    'a',00,
    'd',00,
    'y',00,
    ' ',00, 
    'D',00,
    'e',00,
    's',00,
    'k',00,
    't',00,
    'o',00,
    'p',00,
    ' ',00,
    'S',00,
    'o',00,
    'l',00,
    'u',00,
    't',00,
    'i',00,
    'o',00,
    'n',00,
    ' ',00,
};
 
//This is a dummy serial number. The real serial number should be
//written by the application
code uint8_t g_usb_string_desc_3[] = {
    sizeof(USB_STRING_IDX_3_DESC) * 2, 
    0x03, 
    0xFF,0xFF,
    0xFF,0xFF,
    0xFF,0xFF,
    0xFF,0xFF,
    0xFF,0xFF,
    0xFF,0xFF,
    0xFF,0xFF,
    0xFF,0xFF,
    0xFF,0xFF,
    0xFF,0xFF
};
 
code uint8_t g_usb_string_desc_4[] = {
    sizeof(USB_STRING_IDX_4_DESC) * 2, 
    0x03, 
    0xFF,0xFF,
    0xFF,0xFF,
    0xFF,0xFF,
    0xFF,0xFF,
    0xFF,0xFF,
    0xFF,0xFF,
    0xFF,0xFF,
    0xFF,0xFF,
    0xFF,0xFF,
    0xFF,0xFF
};
 
code usb_string_desc_templ_t g_usb_string_desc = {
    g_usb_string_desc_1,
    g_usb_string_desc_2,
    g_usb_string_desc_3,
    g_usb_string_desc_4,
};
