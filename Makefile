CPPFLAGS=-pedantic -Wall -Iinc -c
LDFLAGS=-Wall 

__start__: pamsi-0
	./pamsi-0

obj:
	mkdir obj

pamsi-0: obj/main.o obj/tabasoc.o obj/tadrzewo.o obj/drzewo.o
	g++ ${LDFLAGS} -o pamsi-0 obj/main.o obj/tabasoc.o \
obj/tadrzewo.o obj/drzewo.o obj/elemdrzewa.o

obj/main.o: src/main.cpp
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/tabasoc.o: inc/tabasoc.hh inc/para.hh src/tabasoc.cpp
	g++ ${CPPFLAGS} -o obj/tabasoc.o src/tabasoc.cpp

obj/tadrzewo.o: inc/tadrzewo.hh inc/drzewo.hh src/tadrzewo.cpp
	g++ ${CPPFLAGS} -o obj/tadrzewo.o src/tadrzewo.cpp

obj/elemdrzewa.o: inc/elemdrzewa.hh src/elemdrzewa.cpp
	g++ ${CPPFLAGS} -o obj/elemdrzewa.o src/elemdrzewa.cpp

obj/drzewo.o: inc/drzewo.hh inc/elemdrzewa.hh src/drzewo.cpp
	g++ ${CPPFLAGS} -o obj/drzewo.o src/drzewo.cpp

clean:
	rm obj/*.o
