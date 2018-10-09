#include "Transaction.h"
#include "Blockchain.h"
#include <string>
using namespace std;

// std::string makeJonce() {					// make a random length 3 Nonce string
// 	std::string answer = "";
// 	srand(time(NULL));
// 	for (int i=0; i<3; i++) {
// 		answer += char(rand()%26 + 97);
// 	}
// 	return answer;
// } 

int main() {

	Transaction* T = new Transaction(26);
	T->setSender("Frank");
	T->setReceiver("Emilia");

	Transaction* T1 = new Transaction(15);
	T1->setSender("Elisabeth");
	T1->setReceiver("Jacob");

	Transaction* T2 = new Transaction(3);
	T2->setSender("Bowie");
	T2->setReceiver("Sailors");

	Transaction* T3 = new Transaction(18);
	T3->setSender("Jason");
	T3->setReceiver("Maroon");

	Transaction* T4 = new Transaction(19);
	T4->setSender("Elisabeth");
	T4->setReceiver("Michael");

	Blockchain* B = new Blockchain(T);
	B->insertTransaction(T1);
	B->insertTransaction(T2);
	B->insertTransaction(T3);
	B->insertTransaction(T4);

	if (B->findTransaction("Elisabeth")) {
		cout<<"Found!"<<endl;
	} else {
		cout<<"Not found!"<<endl;
	}

	if (B->verifyChain()) {
		cout<<"Verified!!! Printing entire chain..."<<endl;
		B->printChain();
	} else {
		cout<<"Error!"<<endl;
	}

	return 0;
}
