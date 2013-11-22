CC=gcc
GUILE_CFLAGS=`guile-config compile`
GUILE_LIBS=`guile-config link`

guile: guile.o
	${CC} guile.o ${GUILE_LIBS} -o guile

guile.o: guile.c
	${CC} -c ${GUILE_CFLAGS} guile.c
