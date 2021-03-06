TOPDIR=${PWD}
CFLAGS=-I${TOPDIR}/include
LDFLAGS=-lMy_string -lMy_utils -lBit_mask
LIBPATH=${PWD}

all:sall.out

sall.out:test.o libMy_string.a libMy_utils.a libBit_mask.a
	gcc -L${LIBPATH} $< -o $@ ${LDFLAGS} 
libmystring.a:src/My_string.o 
	ar rc $@ $^
libmyutils.a:src/My_utils.o 
	ar rc $@ $^
libbitmask.a:src/Bit_mask.o 
	ar rc $@ $^
%.o:src/%.c include/%.h

test.o: test.c include/*.h

test:
	./sall.out

clean:
	rm -rf *.a *.o src/*.o ${TARGET}
