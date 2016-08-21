
# Makefile
# dark_neo
# Original Makefile template date creation:
#	2014-06-06

CC	= gcc
CFLAGS 	= -Wall -O2 -g
SRC 	= mysql-test.c
OBJS 	= ${SRC:.c=.o}
VERSION = 0.0.0
EXEC 	= mysql-test-${VERSION}

all: ${EXEC}

${EXEC}: ${OBJS}
	${CC} ${CFLAGS} `mysql_config --cflags` -o ${EXEC} ${OBJS} \
				`mysql_config --libs`

%.o: %.c %.h
	${CC} ${CFLAGS} `mysql_config --cflags` -c ${SRC}

clean:
	rm -fv ${EXEC} ${OBJS}

