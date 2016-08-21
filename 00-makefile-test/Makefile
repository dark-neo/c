
# Makefile
# dark_neo
# Original Makefile template date creation:
#	2014-06-06

CC		= gcc
CFLAGS 	= -Wall -O2 -g
INCLUDE =
LIBS 	=
SRC 	= main.c person.c
OBJS 	= ${SRC:.c=.o}
VERSION = 0.0.0
EXEC 	= hello-world-${VERSION}

all: ${EXEC}

${EXEC}: ${OBJS}
		${CC} ${CFLAGS} ${INCLUDE} -o ${EXEC} ${OBJS} ${LIBS}

%.o: %.c %.h
		${CC} ${CFLAGS} ${INCLUDE } -c ${SRC}

clean:
		rm -fv ${EXEC} ${OBJS}

