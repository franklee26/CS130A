#include "Transaction.h"
#include "sha256.h"
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

	T->setHash();
	string theHash = T->getHash();
	cout<<theHash<<endl;
	cout<<T->getNonce()<<endl;

	return 0;
}
