/*
    Copyright (c) 2007 Stefan Engelke <mbox@stefanengelke.de>

    Permission is hereby granted, free of charge, to any person 
    obtaining a copy of this software and associated documentation 
    files (the "Software"), to deal in the Software without 
    restriction, including without limitation the rights to use, copy, 
    modify, merge, publish, distribute, sublicense, and/or sell copies 
    of the Software, and to permit persons to whom the Software is 
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be 
    included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 
    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
    DEALINGS IN THE SOFTWARE.

    $Id$
*/

/* Memory Map */
enum nrf24_regs {
    NRF24_REG_CONFIG      = 0x00,
    NRF24_REG_EN_AA       = 0x01,
    NRF24_REG_EN_RXADDR   = 0x02,
    NRF24_REG_SETUP_AW    = 0x03,
    NRF24_REG_SETUP_RETR  = 0x04,
    NRF24_REG_RF_CH       = 0x05,
    NRF24_REG_SETUP    = 0x06,
    NRF24_REG_STATUS  = 0x07,
    NRF24_REG_OBSERVE_TX  = 0x08,
    NRF24_REG_CD          = 0x09,
    NRF24_REG_RX_ADDR_P0  = 0x0A,
    NRF24_REG_RX_ADDR_P1  = 0x0B,
    NRF24_REG_RX_ADDR_P2  = 0x0C,
    NRF24_REG_RX_ADDR_P3  = 0x0D,
    NRF24_REG_RX_ADDR_P4  = 0x0E,
    NRF24_REG_RX_ADDR_P5  = 0x0F,
    NRF24_REG_TX_ADDR     = 0x10,
    NRF24_REG_RX_PW_P0    = 0x11,
    NRF24_REG_RX_PW_P1    = 0x12,
    NRF24_REG_RX_PW_P2    = 0x13,
    NRF24_REG_RX_PW_P3    = 0x14,
    NRF24_REG_RX_PW_P4    = 0x15,
    NRF24_REG_RX_PW_P5    = 0x16,
    NRF24_REG_FIFO_STATUS = 0x17,
    NRF24_REG_DYNPD       = 0x1C,
};
/* Bit Mnemonics */

/* configuratio nregister */
#define MASK_RX_DR  6
#define MASK_TX_DS  5
#define MASK_MAX_RT 4
#define EN_CRC      3
#define CRCO        2
#define PWR_UP      1
#define PRIM_RX     0

/* enable auto acknowledgment */
#define ENAA_P5     5
#define ENAA_P4     4
#define ENAA_P3     3
#define ENAA_P2     2
#define ENAA_P1     1
#define ENAA_P0     0

/* enable rx addresses */
#define ERX_P5      5
#define ERX_P4      4
#define ERX_P3      3
#define ERX_P2      2
#define ERX_P1      1
#define ERX_P0      0

/* setup of address width */
#define AW          0 /* 2 bits */

/* setup of auto re-transmission */
#define ARD         4 /* 4 bits */
#define ARC         0 /* 4 bits */

/* RF setup register */
#define PLL_LOCK    4
#define RF_DR       3
#define RF_PWR      1 /* 2 bits */   

/* general status register */
#define RX_DR       6
#define TX_DS       5
#define MAX_RT      4
#define RX_P_NO     1 /* 3 bits */
#define TX_FULL     0

/* transmit observe register */
#define PLOS_CNT    4 /* 4 bits */
#define ARC_CNT     0 /* 4 bits */

/* fifo status */
#define TX_REUSE    6
#define FIFO_FULL   5
#define TX_EMPTY    4
#define RX_FULL     1
#define RX_EMPTY    0

/* dynamic length */
#define DPL_P0      0
#define DPL_P1      1
#define DPL_P2      2
#define DPL_P3      3
#define DPL_P4      4
#define DPL_P5      5

/* Instruction Mnemonics */
#define NRF24_R_REGISTER    0x00 /* last 4 bits will indicate reg. address */
#define NRF24_W_REGISTER    0x20 /* last 4 bits will indicate reg. address */
#define NRF24_REGISTER_MASK 0x1F
#define NRF24_R_RX_PAYLOAD  0x61
#define NRF24_W_TX_PAYLOAD  0xA0
#define NRF24_FLUSH_TX      0xE1
#define NRF24_FLUSH_RX      0xE2
#define NRF24_REUSE_TX_PL   0xE3
#define NRF24_ACTIVATE      0x50 
#define NRF24_R_RX_PL_WID   0x60
#define NRF24_NOP           0xFF
