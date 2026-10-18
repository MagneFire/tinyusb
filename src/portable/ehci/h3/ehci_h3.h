/*
 * SPDX-FileCopyrightText: Copyright (c) 2026 Darrel Griët
 * SPDX-License-Identifier: MIT
 *
 * This file is part of the TinyUSB stack.
 */

#ifndef TUSB_EHCI_H3_H_
#define TUSB_EHCI_H3_H_

#include <stdbool.h>
#include <stdint.h>
#include "common/tusb_common.h"

#ifdef __cplusplus
extern "C" {
#endif

// The hcd entry points (host/hcd.h), named for the controller: the board
// implements hcd_* itself and routes each call to this EHCI or to the OHCI
// companion that shares its port. ehci_init/ehci_deinit are in ehci_api.h.
void ehci_h3_int_handler(uint8_t rhport, bool in_isr);
uint32_t ehci_h3_frame_number(uint8_t rhport);
bool ehci_h3_port_connect_status(uint8_t rhport);
void ehci_h3_port_reset(uint8_t rhport);
void ehci_h3_port_reset_end(uint8_t rhport);
tusb_speed_t ehci_h3_port_speed_get(uint8_t rhport);
void ehci_h3_device_close(uint8_t rhport, uint8_t dev_addr);
bool ehci_h3_edpt_open(uint8_t rhport, uint8_t daddr, tusb_desc_endpoint_t const * ep_desc);
bool ehci_h3_edpt_close(uint8_t rhport, uint8_t daddr, uint8_t ep_addr);
bool ehci_h3_edpt_xfer(uint8_t rhport, uint8_t daddr, uint8_t ep_addr, uint8_t * buffer, uint16_t buflen);
bool ehci_h3_edpt_abort_xfer(uint8_t rhport, uint8_t dev_addr, uint8_t ep_addr);
bool ehci_h3_setup_send(uint8_t rhport, uint8_t daddr, uint8_t const setup_packet[8]);
bool ehci_h3_edpt_clear_stall(uint8_t rhport, uint8_t dev_addr, uint8_t ep_addr);

// Implemented by the board: the port's connect status changed (from the
// interrupt handler). The board posts hcd_event_device_attach/remove for
// the controller that owns the port.
void ehci_h3_port_changed(bool connected, bool in_isr);

// Set when the port went to the companion controller (PortOwner) instead of
// a disconnect. The board clears it once it has moved the port over.
extern volatile int ehci_h3_port_handed_over;

// NAK reload for every queue head, 0 to 15.
void ehci_h3_set_nak_rl(uint8_t rl);
uint8_t ehci_h3_nak_rl(void);

// Bytes landed so far for the transfer attached to (dev_addr, ep_addr).
uint32_t ehci_h3_xfer_progress(uint8_t dev_addr, uint8_t ep_addr);

// Completion polling from the main loop, with the EHCI interrupt masked.
void ehci_h3_poll_async(uint8_t rhport);

#ifdef __cplusplus
}
#endif

#endif
