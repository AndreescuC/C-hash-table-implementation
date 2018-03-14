CFLAGS = /nologo /W4 /EHsc /Za /DWIN 

all: build

build: tema1.exe

tema1.exe: main.obj hash.lib
	cl main.obj hash.lib /Fetema1.exe

main.obj: main.c
	cl $(CFLAGS) /c main.c

clean:
	del main.obj tema1.exe