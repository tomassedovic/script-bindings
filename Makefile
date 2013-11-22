CC=gcc
GUILE_LIBS=`guile-config link`
GUILE_CFLAGS=`guile-config compile`
LUA_LIBS=`pkg-config --libs lua5.2`
LUA_CFLAGS=`pkg-config --cflags lua5.2`

all: guile lua

guile: guile.o
	${CC} guile.o ${GUILE_LIBS} -o guile

guile.o: guile.c
	${CC} -c ${GUILE_CFLAGS} guile.c

lua: lua.o
	${CC} lua.o ${LUA_LIBS} -o lua

lua.o: lua.c
	${CC} -c ${LUA_CFLAGS} lua.c

clean:
	rm *.o guile lua
