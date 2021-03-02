TARGET=sall.out
OBJS=test.o src/mystring.o  src/bitmask.o src/myutils.o

TOPDIR=${PWD}
CFLAGS=-I${TOPDIR}/inc
LDFLAGS=-lMy_string -lMy_utils -lBit_mask
LIBPATH=${PWD}

all:sall.out

sall.out:test.o libMy_string.a libMy_utils.a libBit_mask.a
	gcc -L${LIBPATH} $< -o $@ ${LDFLAGS} -static
libmystring.a:src/My_string.o 
	ar rc $@ $^
libmyutils.a:src/My_utils.o 
	ar rc $@ $^
libbitmask.a:src/Bit_mask.o 
	ar rc $@ $^
%.o:src/%.c inc/%.h

test.o: test.c inc/*.h

test:
	./sall.out
