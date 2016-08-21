
# Makefile
# dark_neo
# Original Makefile template date creation:
#	2014-06-06

CC	= gcc
CFLAGS 	= -Wall -O3 -g `pkg-config --cflags gtk+-2.0`
SRC 	= main-window.c
OBJS 	= ${SRC:.c=.o}
VERSION = 0.0.0
EXEC 	= mw-${VERSION}

all: ${EXEC}

${EXEC}: ${OBJS}
	${CC} ${CFLAGS} -o ${EXEC} ${OBJS} `pkg-config --libs gtk+-2.0`

%.o: %.c %.h
	${CC} ${CFLAGS} -S `pkg-config --libs gtk+-2.0` -c ${SRC}

clean:
	rm -fv ${EXEC} ${OBJS}

