
# Makefile
# Sergio Cruz
# Original Makefile template date creation:
#	2014-06-06

CC	= gcc
CFLAGS 	= -Wall -O2 -g `pkg-config --cflags gtk+-2.0` `mysql_config --cflags`
SRC 	= main.c \
		mwin.c \
		events.c \
		mwin-conn.c
OBJS 	= ${SRC:.c=.o}
VERSION = 0.0.1
EXEC 	= mysql-mngr-${VERSION}

all: ${EXEC}

${EXEC}: ${OBJS}
	${CC} ${CFLAGS} -o ${EXEC} ${OBJS} \
		`pkg-config --libs gtk+-2.0` \
		`mysql_config --libs`

%.o: %.c %.h
	${CC} ${CFLAGS} -c ${SRC}

clean:
	rm -fv ${EXEC} ${OBJS}
