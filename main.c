/*-
 * Copyright (c) 2018 Ruslan Bukin <br@bsdpad.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/cdefs.h>
#include <sys/console.h>
#include <sys/systm.h>
#include <sys/malloc.h>

#include <machine/frame.h>

#include <arm/arm/nvic.h>
#include <arm/maxim/max32660.h>

struct max32660_uart_softc uart_sc;
struct max32660_gpio_softc gpio_sc;

void app_main(void);

#define	PIN_UART1_TX	10
#define	PIN_UART1_RX	11
#define	PIN_LED		13
#define	UART_BAUDRATE	115200

static void
uart_putchar(int c, void *arg)
{
	struct max32660_uart_softc *sc;
 
	sc = arg;
 
	if (c == '\n')
		max32660_uart_putc(sc, '\r');

	max32660_uart_putc(sc, c);
}

void
app_main(void)
{

	max32660_gpio_init(&gpio_sc, GPIO_BASE);
	max32660_gpio_mode(&gpio_sc, 0, PIN_LED, MODE_OUT);
	max32660_gpio_mode(&gpio_sc, 0, PIN_UART1_TX, MODE_AF2);
	max32660_gpio_mode(&gpio_sc, 0, PIN_UART1_RX, MODE_AF2);
	max32660_gpio_out(&gpio_sc, 0, PIN_LED, 1);

	max32660_uart_init(&uart_sc, UART1_BASE, 48000000, UART_BAUDRATE);
	console_register(uart_putchar, (void *)&uart_sc);

	while (1)
		printf("Hello world!\n");
}
