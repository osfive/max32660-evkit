APP =		max32660-evkit
ARCH =		arm

CC =		${CROSS_COMPILE}gcc
LD =		${CROSS_COMPILE}ld
OBJCOPY =	${CROSS_COMPILE}objcopy

LDSCRIPT =	${.CURDIR}/ldscript

OBJECTS =	main.o						\
		osfive/sys/arm/maxim/max32660_uart.o		\
		osfive/sys/arm/maxim/max32660_gpio.o		\
		osfive/sys/arm/arm/nvic.o			\
		osfive/sys/arm/arm/trap.o			\
		osfive/sys/arm/arm/exception.o			\
		osfive/sys/kern/subr_prf.o			\
		osfive/sys/kern/subr_console.o			\
		osfive/sys/kern/kern_panic.o			\
		start.o

LIBRARIES =	LIBC LIBAEABI

CFLAGS =	-mthumb -mcpu=cortex-m4		\
		-nostdlib -fno-builtin-printf	\
		-g -Wall -Werror

all:	__compile __link __binary

clean:	__clean

.include "osfive/lib/libaeabi/Makefile.inc"
.include "osfive/lib/libc/Makefile.inc"
.include "osfive/mk/bsd.mk"
