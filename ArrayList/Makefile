
all: arraylist main 

arraylist: ArrayList.cpp
	g++ -ggdb -c ArrayList.cpp -o ArrayList.o

main: main.cpp
	g++ -ggdb -c main.cpp -o main.o
	g++ -ggdb -o ArrayList ArrayList.o main.o

clean:
	rm -f *.o *.out

