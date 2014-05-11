all:
	rm -rf src/obj/*.o
	g++ src/simplex.cpp -c -o src/obj/simplex.o
	g++ src/main.cpp -c -o src/obj/main.o  
	g++ -g -Wall src/obj/*.o -lm -o src/bin/simplex

clear:
	rm -rf src/obj/*.o src/bin/simplex


