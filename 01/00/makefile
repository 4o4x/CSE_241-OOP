target:	hw1

hw1_lib:	hw1_lib.h hw1_lib.cpp
			g++ -c hw1_lib.cpp -lm

hw1_main:	hw1_lib.h hw1_main.cpp
			g++ -c hw1_main.cpp -lm


hw1:	hw1_main hw1_lib
		g++ hw1_lib.o hw1_main.cpp -o hw1 -lm

clean:
		rm hw1