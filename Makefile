CC=gcc
GUILE_LIBS=`guile-config link`
GUILE_CFLAGS=`guile-config compile`
LUA_LIBS=`pkg-config --libs lua5.2 2>/dev/null || pkg-config --libs lua 2>/dev/null`
LUA_CFLAGS=`pkg-config --cflags lua5.2 2>/dev/null || pkg-config --cflags lua 2>/dev/null`
SQUIRREL_DIR=./lib/squirrel
SQUIRREL_LIBS=-s -fno-exceptions -fno-rtti ${SQUIRREL_DIR}/lib/libsqstdlib.a ${SQUIRREL_DIR}/lib/libsquirrel.a
SQUIRREL_CFLAGS=-I${SQUIRREL_DIR}/include

all: guile lua squirrel

guile: guile.o
	${CC} guile.o ${GUILE_LIBS} -o guile

guile.o: guile.c
	${CC} -c ${GUILE_CFLAGS} guile.c

lua: lua.o
	${CC} lua.o ${LUA_LIBS} -o lua

lua.o: lua.c
	${CC} -c ${LUA_CFLAGS} lua.c

squirrel: squirrel.o ${SQUIRREL_DIR}/lib/libsquirrel.a
	g++ squirrel.o ${SQUIRREL_LIBS} -o squirrel

squirrel.o: squirrel.c
	gcc -c ${SQUIRREL_CFLAGS} squirrel.c

${SQUIRREL_DIR}/lib/libsquirrel.a:
	cd ${SQUIRREL_DIR} && make

clean:
	rm -rf *.o guile lua squirrel
