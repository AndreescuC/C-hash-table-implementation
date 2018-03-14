all: build

build: tema1 

tema1: main.o io.o log.o table.o struct.o
	gcc -o tema1 main.o io.o log.o table.o struct.o hash.lib
	
main.o: main.c
	gcc -c main.c

struct.o: struct.c
	gcc -c struct.c

io.o: io_handler.c
	gcc -o io.o -c io_handler.c

log.o: log_handler.c
	gcc -o log.o -c log_handler.c

table.o: hash_table.c
	gcc -o table.o -c hash_table.c

clean:
	rm -f tema1 main.o io.o log.o table.o struct.o
	
