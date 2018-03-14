CFLAGS = /nologo /W4 /EHsc /Za /DWIN 

all: build

build: tema1.exe

tema1.exe: main.obj io.obj log.obj table.obj struct.obj hash.lib
	cl main.obj hash.lib /Fetema1.exe

main.obj: main.c
	cl $(CFLAGS) /c main.c

io.obj: io_handler.c
	cl $(CFLAGS) /c io_handler.c

table.obj: hash_table.c
	cl $(CFLAGS) /c hash_table.c

struct.obj: struct.c
	cl $(CFLAGS) /c struct.c

log.obj: log_handler.c
	cl $(CFLAGS) /c log_handler.c

clean:
	del main.obj io.obj log.obj table.obj struct.obj tema1.exe