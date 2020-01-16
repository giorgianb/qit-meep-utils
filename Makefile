all:  libqitmeeputils.a
libqitmeeputils.a: libqitmeeputils.o
	ar rvs libqitmeeputils.a Block.o GaussianBeam.o
libqitmeeputils.o: src/Block.cpp src/GaussianBeam.cpp
	g++ -Iinclude/ -c -std=c++14 -pedantic-errors -Wall -Wextra -O3 src/Block.cpp 
	g++ -Iinclude/ -c -std=c++14 -pedantic-errors -Wall -Wextra -O3 src/GaussianBeam.cpp 

clean:
	rm -f *.o libqitmeeputils*
