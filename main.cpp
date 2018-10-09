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

	Blockchain* B = new Blockchain(T);
	B->insertTransaction(T1);
	// mess up the hash
	T1->setHash("sjdlk28qeuowad3");
	B->insertTransaction(T2);

	B->printChain();
	if (B->verifyChain()) {
		cout<<"Verified!!!"<<endl;
	} else {
		cout<<"Error!"<<endl;
	}

	return 0;
}
