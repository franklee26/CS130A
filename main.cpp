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

	// Transaction* T = new Transaction(26);
	// T->setSender("Frank");
	// T->setReceiver("Emilia");

	// Transaction* T1 = new Transaction(15);
	// T1->setSender("Elisabeth");
	// T1->setReceiver("Jacob");

	// Transaction* T2 = new Transaction(3);
	// T2->setSender("Bowie");
	// T2->setReceiver("Sailors");

	// Transaction* T3 = new Transaction(18);
	// T3->setSender("Jason");
	// T3->setReceiver("Maroon");

	// Transaction* T4 = new Transaction(19);
	// T4->setSender("Elisabeth");
	// T4->setReceiver("Michael");

	// Blockchain* B = new Blockchain(T);
	// B->insertTransaction(T1);
	// B->insertTransaction(T2);
	// B->insertTransaction(T3);
	// B->insertTransaction(T4);

	// if (B->findTransaction("Elisabeth")) {
	// 	cout<<"Found!"<<endl;
	// } else {
	// 	cout<<"Not found!"<<endl;
	// }

	// if (B->verifyChain()) {
	// 	cout<<"Verified!!! Printing entire chain..."<<endl;
	// 	B->printChain();
	// } else {
	// 	cout<<"Error!"<<endl;
	// }

int main() {
	Transaction* T = new Transaction(0);
	Blockchain* B = new Blockchain(T);
	bool usedOption1 = false;
	cout<<endl;
	cout<<endl;
	while (1) {
		int input;

		cout<<"\t========================================================="<<endl;
		cout<<"\t| Welcome to the blockchain transaction application...\t|"<<endl;
		cout<<"\t| Would you like to: \t\t\t\t\t|"<<endl;
		cout<<"\t| (1) Add a transaction to the chain\t\t\t|"<<endl;
		cout<<"\t| (2) Find a transaction with the name of the sender\t|"<<endl;
		cout<<"\t| (3) Verify and print the current chain\t\t|"<<endl;
		cout<<"\t| (4) Exit the programme\t\t\t\t|"<<endl;
		cout<<"\t========================================================="<<endl;
		cout<<"Input: ";
		cin>>input;
		if (input < 1 || input > 4 || !cin.good()) {
			cin.clear();
			cin.ignore();
			cerr<<"Error: Please enter an integer 1-3..."<<endl;
			continue;
		}
		// we have good inputs now.
		if (input == 4) {
			cout<<"Exiting..."<<endl;
			break;
		}
		// notice that we can not use (2) or (3) until we use (1)
		else if ((input == 2 || input == 3) && usedOption1 == false) {
			cout<<"Empty chain! Please add a transaction first"<<endl;
		}

		// if this is the first time adding a transaction
		else if (input == 1 && usedOption1 == false) {
			cout<<endl;
			int amount;
			string sender;
			string receiver;
			cout<<"Please enter the sender: ";
			cin>>sender;
			cout<<"Please enter the receiver: ";
			cin>>receiver;
			cout<<"Please enter the amount: ";
			cin>>amount;
			T->setSender(sender);
			T->setReceiver(receiver);
			T->setAmount(amount);
			usedOption1 = true;
			cout<<"Added new transaction!"<<endl;
		}

		else if (input == 1 && usedOption1 == true) {
			cout<<endl;
			int amount;
			string sender;
			string receiver;
			cout<<"Please enter the sender: ";
			cin>>sender;
			cout<<"Please enter the receiver: ";
			cin>>receiver;
			cout<<"Please enter the amount: ";
			cin>>amount;
			Transaction* temp = new Transaction(amount);
			temp->setSender(sender);
			temp->setReceiver(receiver);
			B->insertTransaction(temp);
		}

		else if (input == 3 && usedOption1 == true) {
			cout<<endl;
			if (B->verifyChain()) {
				cout<<"Chain verified! Printing entire chain..."<<endl;
				B->printChain();
			}
		}

		else if (input == 2 && usedOption1 == true) {
			string senderName;
			cout<<"Please enter the sender name: ";
			cin>>senderName;
			cout<<endl;
			B->findTransaction(senderName);
		}

		cout<<endl;
	}

	return 0;
}
