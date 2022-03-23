target:	hw1

hw1_lib:	hw1_lib.h hw1_lib.cpp
			g++ -c hw1_lib.cpp -std=c++11

hw1_main:	hw1_lib.h hw1_main.cpp
			g++ -c hw1_main.cpp -std=c++11


hw1:	hw1_main hw1_lib
		g++ hw1_lib.o hw1_main.cpp -o hw1 -std=c++11

clean:
		rm hw1