vec3.o : vec3.cpp vec3.hpp
	g++ vec3.cpp -c -o vec3.o
main.o : main.cpp vec3.hpp
	g++ main.cpp -c -o main.o
main : main.o vec3.o
	g++ vec3.o main.o -o main
all :  main
clean : 
	rm -rf main main.o vec3.o