CXX = g++ -std=c++11

main: Transaction.o main.o sha256.o
	${CXX} $^ -o $@ 

clean:
	rm -f *.o main