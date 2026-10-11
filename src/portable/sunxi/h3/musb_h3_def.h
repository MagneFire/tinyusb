/* Forked from tinyusb 0.21.0 src/portable/sunxi/musb_def.h (F1C100s) for the
 * Allwinner H3: same sunxi musb register layout, different base. Only the
 * registers and bits dcd_h3_musb.c uses. */
/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2021 Koji KITAYAMA
 * Copyright (c) 2021 Tian Yunhao (t123yh)
 * Copyright (c) 2021 Ha Thach (tinyusb.org)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * This file is part of the TinyUSB stack.
 */

#ifndef TUSB_MUSB_DEF
#define TUSB_MUSB_DEF

#define  USBC_Readb(reg)	                    (*(volatile unsigned char *)(reg))
#define  USBC_Readw(reg)	                    (*(volatile unsigned short *)(reg))
#define  USBC_Readl(reg)	                    (*(volatile unsigned long *)(reg))

#define  USBC_Writeb(value, reg)                (*(volatile unsigned char *)(reg) = (value))
#define  USBC_Writew(value, reg)	            (*(volatile unsigned short *)(reg) = (value))
#define  USBC_Writel(value, reg)	            (*(volatile unsigned long *)(reg) = (value))

#define  USBC_REG_test_bit_b(bp, reg)         	(USBC_Readb(reg) & (1 << (bp)))
#define  USBC_REG_test_bit_w(bp, reg)   	    (USBC_Readw(reg) & (1 << (bp)))

#define  USBC_REG_set_bit_b(bp, reg) 			(USBC_Writeb((USBC_Readb(reg) | (1 << (bp))) , (reg)))
#define  USBC_REG_set_bit_w(bp, reg) 	 		(USBC_Writew((USBC_Readw(reg) | (1 << (bp))) , (reg)))

#define  USBC_REG_clear_bit_b(bp, reg)	 	 	(USBC_Writeb((USBC_Readb(reg) & (~ (1 << (bp)))) , (reg)))
#define  USBC_REG_clear_bit_w(bp, reg)	 	 	(USBC_Writew((USBC_Readw(reg) & (~ (1 << (bp)))) , (reg)))

//---------------------------------------------------------------
//   reg base
//---------------------------------------------------------------
#define  USBC0_BASE                 0x01c19000   /* H3 musb OTG */

//-----------------------------------------------------------------------
//   musb reg offset
//-----------------------------------------------------------------------

#define  USBC_REG_o_FADDR		    0x0098
#define  USBC_REG_o_PCTL		    0x0040
#define  USBC_REG_o_INTTx		    0x0044
#define  USBC_REG_o_INTRx		    0x0046
#define  USBC_REG_o_INTTxE		    0x0048
#define  USBC_REG_o_INTRxE		    0x004A
#define  USBC_REG_o_INTUSB		    0x004C
#define  USBC_REG_o_INTUSBE         0x0050
#define  USBC_REG_o_EPIND		    0x0042

#define  USBC_REG_o_TXMAXP		    0x0080
#define  USBC_REG_o_CSR0		    0x0082
#define  USBC_REG_o_TXCSR		    0x0082
#define  USBC_REG_o_RXMAXP		    0x0084
#define  USBC_REG_o_RXCSR		    0x0086
#define  USBC_REG_o_COUNT0		    0x0088
#define  USBC_REG_o_RXCOUNT		    0x0088

#define  USBC_REG_o_EPFIFO0		    0x0000
#define  USBC_REG_o_EPFIFO1		    0x0004

#define  USBC_REG_o_TXFIFOSZ	    0x0090
#define  USBC_REG_o_RXFIFOSZ	    0x0094
#define  USBC_REG_o_TXFIFOAD	    0x0092
#define  USBC_REG_o_RXFIFOAD	    0x0096

#define  USBC_REG_o_VEND0		    0x0043

#define  USBC_REG_o_ISCR            0x0400

//-----------------------------------------------------------------------
//   registers
//-----------------------------------------------------------------------

#define  USBC_REG_FADDR(usbc_base_addr)		        ((usbc_base_addr) + USBC_REG_o_FADDR		)
#define  USBC_REG_PCTL(usbc_base_addr)		        ((usbc_base_addr) + USBC_REG_o_PCTL			)
#define  USBC_REG_INTTx(usbc_base_addr)		        ((usbc_base_addr) + USBC_REG_o_INTTx		)
#define  USBC_REG_INTRx(usbc_base_addr)		        ((usbc_base_addr) + USBC_REG_o_INTRx		)
#define  USBC_REG_INTTxE(usbc_base_addr)		    ((usbc_base_addr) + USBC_REG_o_INTTxE     	)
#define  USBC_REG_INTRxE(usbc_base_addr)		    ((usbc_base_addr) + USBC_REG_o_INTRxE     	)
#define  USBC_REG_INTUSB(usbc_base_addr)		    ((usbc_base_addr) + USBC_REG_o_INTUSB     	)
#define  USBC_REG_INTUSBE(usbc_base_addr)           ((usbc_base_addr) + USBC_REG_o_INTUSBE    	)
#define  USBC_REG_EPIND(usbc_base_addr)		        ((usbc_base_addr) + USBC_REG_o_EPIND      	)
#define  USBC_REG_TXMAXP(usbc_base_addr)		    ((usbc_base_addr) + USBC_REG_o_TXMAXP     	)

#define  USBC_REG_CSR0(usbc_base_addr)		        ((usbc_base_addr) + USBC_REG_o_CSR0       	)
#define  USBC_REG_TXCSR(usbc_base_addr)		        ((usbc_base_addr) + USBC_REG_o_TXCSR      	)

#define  USBC_REG_RXMAXP(usbc_base_addr)		    ((usbc_base_addr) + USBC_REG_o_RXMAXP     	)
#define  USBC_REG_RXCSR(usbc_base_addr)		        ((usbc_base_addr) + USBC_REG_o_RXCSR      	)

#define  USBC_REG_COUNT0(usbc_base_addr)		    ((usbc_base_addr) + USBC_REG_o_COUNT0     	)
#define  USBC_REG_RXCOUNT(usbc_base_addr)		    ((usbc_base_addr) + USBC_REG_o_RXCOUNT    	)

#define  USBC_REG_EPFIFO0(usbc_base_addr)		    ((usbc_base_addr) + USBC_REG_o_EPFIFO0		)
#define  USBC_REG_EPFIFO1(usbc_base_addr)		    ((usbc_base_addr) + USBC_REG_o_EPFIFO1		)
#define  USBC_REG_TXFIFOSZ(usbc_base_addr)	        ((usbc_base_addr) + USBC_REG_o_TXFIFOSZ		)
#define  USBC_REG_RXFIFOSZ(usbc_base_addr)	        ((usbc_base_addr) + USBC_REG_o_RXFIFOSZ		)
#define  USBC_REG_TXFIFOAD(usbc_base_addr)	        ((usbc_base_addr) + USBC_REG_o_TXFIFOAD		)
#define  USBC_REG_RXFIFOAD(usbc_base_addr)	        ((usbc_base_addr) + USBC_REG_o_RXFIFOAD		)
#define  USBC_REG_VEND0(usbc_base_addr)		        ((usbc_base_addr) + USBC_REG_o_VEND0		)

#define  USBC_REG_ISCR(usbc_base_addr)	    	    ((usbc_base_addr) + USBC_REG_o_ISCR			)

/* USB Power Control for device only  */
#define  USBC_BP_POWER_D_SOFT_CONNECT			6
#define  USBC_BP_POWER_D_HIGH_SPEED_EN			5
#define  USBC_BP_POWER_D_HIGH_SPEED_FLAG		4
#define  USBC_BP_POWER_D_RESUME					2

/* interrupt flags for ep0 and the Tx ep1~4 */
#define  USBC_BP_INTTx_FLAG_EP0					0

/* USB interrupt */
#define  USBC_BP_INTUSB_DISCONNECT				5
#define  USBC_BP_INTUSB_SOF						3
#define  USBC_BP_INTUSB_RESET					2
#define  USBC_BP_INTUSB_RESUME					1
#define  USBC_BP_INTUSB_SUSPEND					0

/* USB interrupt enable */
#define  USBC_BP_INTUSBE_EN_DISCONNECT			5
#define  USBC_BP_INTUSBE_EN_SOF					3
#define  USBC_BP_INTUSBE_EN_RESET				2
#define  USBC_BP_INTUSBE_EN_RESUME				1
#define  USBC_BP_INTUSBE_EN_SUSPEND				0

/* Control and Status Register for ep0 for device only */
#define  USBC_BP_CSR0_D_SERVICED_SETUP_END		7
#define  USBC_BP_CSR0_D_SERVICED_RX_PKT_READY   6
#define  USBC_BP_CSR0_D_SEND_STALL				5
#define  USBC_BP_CSR0_D_DATA_END				3
#define  USBC_BP_CSR0_D_SENT_STALL				2
#define  USBC_BP_CSR0_D_TX_PKT_READY			1

/* Tx ep Control and Status Register for Device only */
#define  USBC_BP_TXCSR_D_AUTOSET				15
#define  USBC_BP_TXCSR_D_MODE					13
#define  USBC_BP_TXCSR_D_DMA_REQ_EN				12
#define  USBC_BP_TXCSR_D_DMA_REQ_MODE			10
#define  USBC_BP_TXCSR_D_CLEAR_DATA_TOGGLE		6
#define  USBC_BP_TXCSR_D_SENT_STALL				5
#define  USBC_BP_TXCSR_D_SEND_STALL				4
#define  USBC_BP_TXCSR_D_FLUSH_FIFO				3
#define  USBC_BP_TXCSR_D_UNDER_RUN				2
#define  USBC_BP_TXCSR_D_FIFO_NOT_EMPTY 		1
#define  USBC_BP_TXCSR_D_TX_READY				0

/* Rx ep Control and Status Register for Device only */
#define  USBC_BP_RXCSR_D_AUTO_CLEAR			    15
#define  USBC_BP_RXCSR_D_DMA_REQ_EN			    13
#define  USBC_BP_RXCSR_D_DMA_REQ_MODE		    11

#define  USBC_BP_RXCSR_D_CLEAR_DATA_TOGGLE	    7
#define  USBC_BP_RXCSR_D_SENT_STALL			    6
#define  USBC_BP_RXCSR_D_SEND_STALL			    5
#define  USBC_BP_RXCSR_D_FLUSH_FIFO			    4
#define  USBC_BP_RXCSR_D_OVERRUN			    2
#define  USBC_BP_RXCSR_D_FIFO_FULL			    1
#define  USBC_BP_RXCSR_D_RX_PKT_READY		    0

/* Interface Status and Control */

#define  USBC_BP_ISCR_DPDM_PULLUP_EN			16
#define  USBC_BP_ISCR_FORCE_ID					14
#define  USBC_BP_ISCR_FORCE_VBUS_VALID			12
#define  USBC_BP_ISCR_VBUS_VALID_SRC			10

#define  USBC_BP_ISCR_VBUS_CHANGE_DETECT      	6
#define  USBC_BP_ISCR_ID_CHANGE_DETECT        	5
#define  USBC_BP_ISCR_DPDM_CHANGE_DETECT      	4

/* interrupt flags for ep0 and the Tx ep1~4 */
#define  USBC_INTTx_FLAG_EP0					(1 << USBC_BP_INTTx_FLAG_EP0)

/* USB interrupt */
#define  USBC_INTUSB_DISCONNECT				    (1 << USBC_BP_INTUSB_DISCONNECT)
#define  USBC_INTUSB_SOF						(1 << USBC_BP_INTUSB_SOF)
#define  USBC_INTUSB_RESET					    (1 << USBC_BP_INTUSB_RESET)
#define  USBC_INTUSB_RESUME					    (1 << USBC_BP_INTUSB_RESUME)
#define  USBC_INTUSB_SUSPEND					(1 << USBC_BP_INTUSB_SUSPEND)

#define USB_CSRL0_SETEND        0x00000010  // Setup End
#define USB_CSRL0_STALLED       0x00000004  // Endpoint Stalled
#define USB_CSRL0_RXRDY         0x00000001  // Receive Packet Ready

#define USB_TXFIFOSZ_DPB        0x00000010  // Double Packet Buffer Support

#endif
