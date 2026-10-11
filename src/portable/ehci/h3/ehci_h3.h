/*
 * SPDX-FileCopyrightText: Copyright (c) 2026 Darrel Griët
 * SPDX-License-Identifier: MIT
 *
 * This file is part of the TinyUSB stack.
 */

#ifndef TUSB_EHCI_H3_H_
#define TUSB_EHCI_H3_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Set when the port went to the companion controller (PortOwner) instead of
// a disconnect. The application takes the port back and clears it.
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
