#include "Transaction.h"
#include "Blockchain.h"
#include <string>
#include <sstream>
using namespace std;

int main() {
	Transaction* T = new Transaction(0);
	Blockchain* B = new Blockchain(T);
	bool usedOption1 = false;
	cout<<endl;
	cout<<endl;
	while (1) {
		double input;

		cout<<"\t========================================================="<<endl;
		cout<<"\t| Welcome to the blockchain transaction application...\t|"<<endl;
		cout<<"\t| Would you like to: \t\t\t\t\t|"<<endl;
		cout<<"\t| (1) Add a transaction to the chain\t\t\t|"<<endl;
		cout<<"\t| (2) Find a transaction with the name of the sender\t|"<<endl;
		cout<<"\t| (3) Verify and print the current chain\t\t|"<<endl;
		cout<<"\t| (4) Find a transaction with the name of the receiver\t|"<<endl;
		cout<<"\t| (5) Exit the programme\t\t\t\t|"<<endl;
		cout<<"\t========================================================="<<endl;
		cout<<"Please enter an input: ";
		cin>>input;

		bool isInt = true;
		if (input - (int)input > 0) {
			isInt = false;
		}

		if (input < 1 || input > 5 || !cin.good() || !isInt) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			//cin.ignore();
			cerr<<"Invalid input: Please enter an integer 1-4..."<<endl;
			continue;
		}
		// we have good inputs now.
		if (input == 5) {
			cout<<"Exiting..."<<endl;
			break;
		}
		// notice that we can not use (2) or (3) until we use (1)
		else if ((input == 2 || input == 3) && usedOption1 == false) {
			cerr<<"Empty chain! Please add a transaction first"<<endl;
		}

		// if this is the first time adding a transaction
		else if (input == 1 && usedOption1 == false) {
			cout<<endl;
			double amount;
			string sender;
			string receiver;
			cout<<"Please enter the sender: ";
			cin>>sender;
			cout<<"Please enter the receiver: ";
			cin>>receiver;
			cout<<"Please enter the amount: ";
			cin>>amount;
			bool isItInt = true;
			if (amount - (int)amount > 0) {
				isItInt = false;
			}
			if (!cin.good() || !isItInt) {
				cerr<<"Error: amount value must be of type int."<<endl;
				cin.clear();
				cin.ignore();
				continue;
			}
			T->setSender(sender);
			T->setReceiver(receiver);
			T->setAmount(amount);
			usedOption1 = true;
			cout<<"Added new transaction!"<<endl;
		}

		else if (input == 1 && usedOption1 == true) {
			cout<<endl;
			double amount;
			string sender;
			string receiver;
			cout<<"Please enter the sender: ";
			cin>>sender;
			cout<<"Please enter the receiver: ";
			cin>>receiver;
			cout<<"Please enter the amount: ";
			cin>>amount;
			bool isItInt = true;
			if (amount - (int)amount > 0) {
				isItInt = false;
			}
			if (!cin.good() || !isItInt) {
				cerr<<"Error: amount value must be of type int."<<endl;
				cin.clear();
				cin.ignore();
				continue;
			}
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
			B->findTransactionSender(senderName);
		}

		else if (input == 4 && usedOption1 == true) {
			string receiverName;
			cout<<"Please enter the receiver name: ";
			cin>>receiverName;
			cout<<endl;
			B->findTransactionReceiver(receiverName);
		}

		cout<<endl;
	}

	return 0;
}
