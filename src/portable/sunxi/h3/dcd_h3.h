/*
 * SPDX-FileCopyrightText: Copyright (c) 2026 Darrel Griët
 * SPDX-License-Identifier: MIT
 *
 * This file is part of the TinyUSB stack.
 */

#ifndef TUSB_DCD_H3_H_
#define TUSB_DCD_H3_H_

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

//--------------------------------------------------------------------+
// Board hooks, implemented by the application
//--------------------------------------------------------------------+

// Clocks, resets and PHY0 routed to the musb in peripheral mode. The board
// also routes the musb interrupt to dcd_int_handler(0).
void dcd_h3_board_init(void);

// Unmask or mask the musb interrupt at the interrupt controller.
void dcd_h3_board_int_enable(bool enable);

// Free-running microsecond counter, for the TX DMA drain timeout.
uint32_t dcd_h3_board_time_us(void);

// Buffers are cleaned and invalidated through dcd_dcache_clean() and
// dcd_dcache_invalidate() (device/dcd.h).

//--------------------------------------------------------------------+
// Driver extras
//--------------------------------------------------------------------+

// Bytes of the current OUT transfer on ep_addr that have reached memory.
// *dma is set when RX DMA is running and the count includes its residual.
uint32_t dcd_h3_out_landed(uint8_t ep_addr, bool *dma);

// Inner DMA per direction, bit 0 RX and bit 1 TX.
void dcd_h3_dma_enable(uint32_t mask);
uint32_t dcd_h3_dma_enabled(void);

// SOF interrupt on or off.
void dcd_h3_sof_irq(bool on);

// RX packets drained behind the first (DPB), TX interrupts with TXPKTRDY
// still set.
void dcd_h3_dpb_stats(uint32_t *rx_extra, uint32_t *tx_busy);

// DMA transfers per direction, RX transfers ended by a short packet, and
// residual counts larger than the transfer.
void dcd_h3_dma_stats(uint32_t *rx, uint32_t *tx, uint32_t *rx_short, uint32_t *bad);

#ifdef __cplusplus
}
#endif

#endif
