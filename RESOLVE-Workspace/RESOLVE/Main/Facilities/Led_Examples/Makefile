CC = gcc
FLAGS = 

MSPCC = msp430-gcc
MSPFLAGS = -mmcu=msp430f1611

FAC = ../../../Main/Facilities
CON = ../../../Main/Concepts

STD_FAC = $(FAC)/Standard
STD_CON = $(CON)/Standard

DEPS = $(STD_CON)/Integer_Template/Std_Integer_Realiz.c \
	   $(STD_CON)/Boolean_Template/Std_Boolean_Realiz.c \
	   $(STD_FAC)/Std_Boolean_Fac.c \
	   $(STD_FAC)/Std_Integer_Fac.c \
	   $(CON)/Clock_Template/Std_Clock_Realiz.c \
	   $(STD_FAC)/Std_Clock_Fac.c \
	   $(CON)/Leds_Template/Std_Leds_Realiz.c \
	   $(CON)/Leds_Template/Toggling_Realiz.c \
	   naive_malloc.c

main:
	$(CC) $(FLAGS) $(DEPS) -DDEBUG Leds_Test.c -o main

make telos:
	$(MSPCC) $(MSPFLAGS) $(DEPS) -DTELOS Leds_Test.c -o main

clean:
	rm -f main *.o core

install:
	make clean
	make telos
	msp430-objcopy -O ihex main main.ihex
	tos-bsl --telosb -c /dev/ttyUSB0 -r -e -I -p main.ihex
