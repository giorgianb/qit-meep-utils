all:  libqitmeeputils.a
libqitmeeputils.a: libqitmeeputils.o
	ar rvs libqitmeeputils.a libqitmeeputils.o
libqitmeeputils.o:
	g++ -Iinclude/ -c -std=c++14 -pedantic-errors -Wall -Wextra -O3 src/Block.cpp -o libqitmeeputils.o

clean:
	rm libqitmeeputils*
