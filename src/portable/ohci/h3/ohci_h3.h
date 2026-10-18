/*
 * SPDX-FileCopyrightText: Copyright (c) 2026 Darrel Griët
 * SPDX-License-Identifier: MIT
 *
 * This file is part of the TinyUSB stack.
 */

#ifndef TUSB_OHCI_H3_H_
#define TUSB_OHCI_H3_H_

#include <stdbool.h>
#include <stdint.h>
#include "common/tusb_common.h"

#ifdef __cplusplus
extern "C" {
#endif

// The hcd entry points (host/hcd.h), named for the controller: the board
// implements hcd_* itself and routes each call to this OHCI or to the EHCI
// that shares its port. The controller has one port; rhport is whatever
// number usbh uses for it.
bool ohci_h3_init(uint8_t rhport, uint32_t base);
void ohci_h3_int_handler(uint8_t rhport, bool in_isr);
uint32_t ohci_h3_frame_number(uint8_t rhport);
bool ohci_h3_port_connect_status(uint8_t rhport);
void ohci_h3_port_reset(uint8_t rhport);
void ohci_h3_port_reset_end(uint8_t rhport);
tusb_speed_t ohci_h3_port_speed_get(uint8_t rhport);
void ohci_h3_device_close(uint8_t rhport, uint8_t dev_addr);
bool ohci_h3_edpt_open(uint8_t rhport, uint8_t daddr, tusb_desc_endpoint_t const * ep_desc);
bool ohci_h3_edpt_close(uint8_t rhport, uint8_t daddr, uint8_t ep_addr);
bool ohci_h3_edpt_xfer(uint8_t rhport, uint8_t daddr, uint8_t ep_addr, uint8_t * buffer, uint16_t buflen);
bool ohci_h3_edpt_abort_xfer(uint8_t rhport, uint8_t dev_addr, uint8_t ep_addr);
bool ohci_h3_setup_send(uint8_t rhport, uint8_t daddr, uint8_t const setup_packet[8]);
bool ohci_h3_edpt_clear_stall(uint8_t rhport, uint8_t dev_addr, uint8_t ep_addr);

// Implemented by the board: the port's connect status changed. The board
// posts hcd_event_device_attach/remove for the controller that owns the port.
void ohci_h3_port_changed(bool connected, bool in_isr);

// The root hub port register (HcRhPortStatus1), a register read by offset
// for diagnostics, and a stop of the controller.
uint32_t ohci_h3_rhport_status(void);
void ohci_h3_rhport_write(uint32_t v);
uint32_t ohci_h3_read(uint32_t offset);
void ohci_h3_halt(void);

#ifdef __cplusplus
}
#endif

#endif
