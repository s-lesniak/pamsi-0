CPPFLAGS=-pedantic -Wall -Iinc -c
LDFLAGS=-Wall 

__start__: pamsi-0
	./pamsi-0

obj:
	mkdir obj

pamsi-0: obj/main.o obj/tabasoc.o
	g++ ${LDFLAGS} -o pamsi-0 obj/main.o obj/tabasoc.o

obj/main.o: src/main.cpp
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/tabasoc.o: inc/tabasoc.hh inc/para.hh src/tabasoc.cpp
	g++ ${CPPFLAGS} -o obj/tabasoc.o src/tabasoc.cpp

clean:
	rm obj/*.o
