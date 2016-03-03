/* board.h - board configuration macros for the ti_lm3s6965 platform */

/*
 * Copyright (c) 2013-2015 Wind River Systems, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
DESCRIPTION
This header file is used to specify and describe board-level aspects for
the 'ti_lm3s6965' platform.
 */

#ifndef _BOARD__H_
#define _BOARD__H_

#include <misc/util.h>

/* default system clock */

#define SYSCLK_DEFAULT_IOSC_HZ MHZ(12)

/* address bases */

#define PERIPH_ADDR_BASE_UART0 0x4000C000
#define PERIPH_ADDR_BASE_UART1 0x4000D000
#define PERIPH_ADDR_BASE_UART2 0x4000E000

/* IRQs */

#define IRQ_GPIO_PORTA 0
#define IRQ_GPIO_PORTB 1
#define IRQ_GPIO_PORTC 2
#define IRQ_GPIO_PORTD 3
#define IRQ_GPIO_PORTE 4
#define IRQ_UART0 5
#define IRQ_UART1 6
#define IRQ_SSI0 7
#define IRQ_I2C0 8
#define IRQ_PWM_FAULT 9
#define IRQ_PWM_GEN0 10
#define IRQ_PWM_GEN1 11
#define IRQ_PWM_GEN2 12
#define IRQ_QEI0 13
#define IRQ_ADC0_SEQ0 14
#define IRQ_ADC0_SEQ1 15
#define IRQ_ADC0_SEQ2 16
#define IRQ_ADC0_SEQ3 17
#define IRQ_WDOG0 18
#define IRQ_TIMER0A 19
#define IRQ_TIMER0B 20
#define IRQ_TIMER1A 21
#define IRQ_TIMER1B 22
#define IRQ_TIMER2A 23
#define IRQ_TIMER2B 24
#define IRQ_ANALOG_COMP0 25
#define IRQ_ANALOG_COMP1 26
#define IRQ_RESERVED0 27
#define IRQ_SYS_CONTROL 28
#define IRQ_FLASH_MEM_CTRL 29
#define IRQ_GPIO_PORTF 30
#define IRQ_GPIO_PORTG 31
#define IRQ_RESERVED1 32
#define IRQ_UART2 33
#define IRQ_RESERVED2 34
#define IRQ_TIMER3A 35
#define IRQ_TIMER3B 36
#define IRQ_I2C1 37
#define IRQ_QEI1 38
#define IRQ_RESERVED3 39
#define IRQ_RESERVED4 40
#define IRQ_RESERVED5 41
#define IRQ_ETH 42
#define IRQ_HIBERNATION 43

#ifndef _ASMLANGUAGE

#include <device.h>
#include <misc/util.h>
#include <drivers/rand32.h>

/* uart configuration settings */

#define CONFIG_UART_PORT_0_REGS PERIPH_ADDR_BASE_UART0
#define CONFIG_UART_PORT_0_IRQ IRQ_UART0
#define CONFIG_UART_PORT_1_REGS PERIPH_ADDR_BASE_UART1
#define CONFIG_UART_PORT_1_IRQ IRQ_UART1
#define CONFIG_UART_PORT_2_REGS PERIPH_ADDR_BASE_UART2
#define CONFIG_UART_PORT_2_IRQ IRQ_UART2

extern struct device * const uart_devs[];

/* Uart console configuration */
#if defined(CONFIG_UART_CONSOLE)

#define CONFIG_UART_CONSOLE_IRQ IRQ_UART0
#define CONFIG_UART_CONSOLE_INT_PRI 3

#define UART_CONSOLE_DEV (uart_devs[CONFIG_UART_CONSOLE_INDEX])

#endif /* CONFIG_UART_CONSOLE */

/* Bluetooth UART definitions */
#if defined(CONFIG_BLUETOOTH_UART)

#define CONFIG_BLUETOOTH_UART_INDEX 1
#define CONFIG_BLUETOOTH_UART_BAUDRATE 115200
#define CONFIG_BLUETOOTH_UART_IRQ IRQ_UART1
#define CONFIG_BLUETOOTH_UART_INT_PRI 3
#define CONFIG_BLUETOOTH_UART_FREQ SYSCLK_DEFAULT_IOSC_HZ

#define BT_UART_DEV (uart_devs[CONFIG_BLUETOOTH_UART_INDEX])

#endif /* CONFIG_BLUETOOTH_UART */

/* Simple UART definitions */
#define CONFIG_UART_SIMPLE_INDEX 2
#define CONFIG_UART_SIMPLE_BAUDRATE 115200
#define CONFIG_UART_SIMPLE_IRQ IRQ_UART2
#define CONFIG_UART_SIMPLE_INT_PRI 3
#define CONFIG_UART_SIMPLE_FREQ SYSCLK_DEFAULT_IOSC_HZ

#define EXC_FROM_IRQ(irq) ((irq) + 16)
#define VECTOR_FROM_IRQ(irq) EXC_FROM_IRQ(irq)
#define VECTOR_ADDR(vector) ((uint32_t *)((int)vector << 2))

#endif /* !_ASMLANGUAGE */

#endif /* _BOARD__H_ */