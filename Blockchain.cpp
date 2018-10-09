#include "Blockchain.h"
using namespace std;

Blockchain::Blockchain(Transaction* head) {
	if (head == NULL) {
		cerr<<"head transaction can not be NULL. Please try again...";
		exit(1);
	}
	this->head = head;
}

void Blockchain::insertTransaction(Transaction* node) {
	// make sure node points to head
	node->setNext(this->head);
	(this->head)->setHead(false);		// no longer the head
	string previousHash = (this->head)->getHashForThis();
	this->head = node;
	// alright, now I need to set this node's hash as the previous hash
	// make sure my new head 
	(this->head)->setHash(previousHash);
}

void Blockchain::printChain() {
	cout<<"======================================================================="<<endl;
	Transaction* copy = this->head;
	while (copy != NULL) {
		if (copy->isHead()) {
			cout<<"This is the head node."<<endl;
		}
		cout<<"SENDER: "<<copy->getSender()<<endl;
		cout<<"RECEIVER: "<<copy->getReceiver()<<endl;
		cout<<"AMOUNT: "<<copy->getAmount()<<endl;
		cout<<"HASH: "<<copy->getSetHash()<<endl;
		copy = copy->getNext();
		cout<<"======================================================================="<<endl;
		if (copy != NULL) {
			cout<<"\t\t\t\t|"<<endl;
			cout<<"\t\t\t\t|"<<endl;
			cout<<"\t\t\t\tV"<<endl;
			cout<<"======================================================================="<<endl;
		}
	}
}

bool Blockchain::verifyChain() {
	Transaction* copy = this->head;
	while (copy != NULL) {
		if (copy->getNext() == NULL) {
			// so I'm at the last transaction
			if (copy->getSetHash() != "NULL") {
				// now print this wrong transaction
				cout<<"Error in the following head transaction: "<<endl;
				cout<<"======================================================================="<<endl;
				cout<<"SENDER: "<<copy->getSender()<<endl;
				cout<<"RECEIVER: "<<copy->getReceiver()<<endl;
				cout<<"AMOUNT: "<<copy->getAmount()<<endl;
				cout<<"HASH: "<<copy->getSetHash()<<endl;
				cout<<"======================================================================="<<endl;
				return false;
			}
			return true;
		} else {
			// so the next transaction is not null
			string currentHash = copy->getSetHash();
			// compare this to the generated hash from the previous transaction
			string generatedPrevHash = (copy->getNext())->getHashForThis();
			if (currentHash != generatedPrevHash) {
				cout<<"Error between the following transaction: "<<endl;
				cout<<"======================================================================="<<endl;
				cout<<"SENDER: "<<copy->getSender()<<endl;
				cout<<"RECEIVER: "<<copy->getReceiver()<<endl;
				cout<<"AMOUNT: "<<copy->getAmount()<<endl;
				cout<<"HASH: "<<copy->getSetHash()<<endl;
				cout<<"======================================================================="<<endl;
				cout<<"SENDER: "<<(copy->getNext())->getSender()<<endl;
				cout<<"RECEIVER: "<<(copy->getNext())->getReceiver()<<endl;
				cout<<"AMOUNT: "<<(copy->getNext())->getAmount()<<endl;
				cout<<"HASH: "<<(copy->getNext())->getSetHash()<<endl;
				cout<<"======================================================================="<<endl;
				return false;
			}
		}
		copy = copy->getNext();
	}
	// by the time I get here, the chain has been verified!
	return true;
}	

bool Blockchain::findTransaction(string sender) {
	bool found = false;
	Transaction* copy = this->head;
	while (copy != NULL) {
		if (copy->getSender() == sender) {
			found = true;
			cout<<endl;
			cout<<"Found transaction match: "<<endl;
			cout<<"======================================================================="<<endl;
			cout<<"SENDER: "<<copy->getSender()<<endl;
			cout<<"RECEIVER: "<<copy->getReceiver()<<endl;
			cout<<"AMOUNT: "<<copy->getAmount()<<endl;
			cout<<"HASH: "<<copy->getSetHash()<<endl;
			cout<<"======================================================================="<<endl;
			cout<<endl;
		}
		copy = copy->getNext();
	}
	// so it's not found by now
	if (found == false) {
		cout<<"Sender name not found in blockchain."<<endl;
	}
	return found;
}