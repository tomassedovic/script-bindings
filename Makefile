CC=gcc
CFLAGS=`guile-config compile`
LIBS=`guile-config link`

main: main.o
	${CC} main.o ${LIBS} -o main

main.o: main.c
	${CC} -c ${CFLAGS} main.c
