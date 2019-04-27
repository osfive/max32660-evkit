APP =		max32660-evkit
MACHINE =	arm

CC =		${CROSS_COMPILE}gcc
LD =		${CROSS_COMPILE}ld
OBJCOPY =	${CROSS_COMPILE}objcopy

OBJDIR =	obj
LDSCRIPT =	${CURDIR}/ldscript

OBJECTS =	main.o						\
		osfive/sys/arm/maxim/max32660_uart.o		\
		osfive/sys/arm/maxim/max32660_gpio.o		\
		start.o

KERNEL =
LIBRARIES =	libc libaeabi

CFLAGS =	-mthumb -mcpu=cortex-m4		\
		-nostdlib -fno-builtin-printf	\
		-g -Wall -Werror

all:	${OBJDIR}/${APP}.elf

clean:
	@rm -f ${OBJECTS} ${OBJDIR}/${APP}.elf

include osfive/lib/libaeabi/Makefile.inc
include osfive/lib/libc/Makefile.inc
include osfive/mk/default.mk
