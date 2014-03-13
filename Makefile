CPPFLAGS=-pedantic -Wall -Iinc -c
LDFLAGS=-Wall 

__start__: pamsi-0
	./pamsi-0

obj:
	mkdir obj

pamsi-0: obj/main.o obj/eksperyment.o obj/czas.o obj/tabliczb.o \
obj/stostab1.o
	g++ ${LDFLAGS} -o pamsi-0 obj/main.o obj/eksperyment.o \
obj/czas.o obj/tabliczb.o obj/stostab1.o

obj/main.o: src/main.cpp
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/eksperyment.o: inc/eksperyment.hh inc/tabliczb.hh \
inc/wynikbadania.hh inc/zrodlo.hh src/eksperyment.cpp
	g++ ${CPPFLAGS} -o obj/eksperyment.o src/eksperyment.cpp

obj/czas.o: inc/czas.hh src/czas.cpp
	g++ ${CPPFLAGS} -o obj/czas.o src/czas.cpp

obj/tabliczb.o: inc/tabliczb.hh src/tabliczb.cpp
	g++ ${CPPFLAGS} -o obj/tabliczb.o src/tabliczb.cpp

obj/stostab1.o: inc/stostab1.hh src/stostab1.cpp
	g++ ${CPPFLAGS} -o obj/stostab1.o src/stostab1.cpp
