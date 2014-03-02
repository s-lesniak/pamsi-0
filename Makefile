CPPFLAGS=-pedantic -Wall -Iinc -c
LDFLAGS=-Wall 

__start__: pamsi-0
	./pamsi-0

obj:
	mkdir obj

pamsi-0: obj/main.o
	g++ ${LDFLAGS} -o pamsi-0 obj/main.o

obj/main.o: src/main.cpp
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp
