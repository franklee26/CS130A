CXX = g++ -std=c++11

main: Transaction.o main.o
	${CXX} $^ -o $@ -lcrypto

clean:
	rm -f *.o main