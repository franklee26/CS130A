#include "Blockchain.h"
using namespace std;

Blockchain::Blockchain(Transaction* head) {
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
	cout<<"====="<<endl;
	Transaction* copy = this->head;
	while (copy != NULL) {
		if (copy->isHead()) {
			cout<<"Head!"<<endl;
		}
		cout<<"SENDER: "<<copy->getSender()<<endl;
		cout<<"RECEIVER: "<<copy->getReceiver()<<endl;
		cout<<"AMOUNT: "<<copy->getAmount()<<endl;
		cout<<"HASH: "<<copy->getSetHash()<<endl;
		cout<<"====="<<endl;
		copy = copy->getNext();
	}
}

bool Blockchain::verifyChain() {
	Transaction* copy = this->head;
	while (copy != NULL) {
		if (copy->getNext() == NULL) {
			// so I'm at the last transaction
			if (copy->getSetHash() != "NULL") {
				return false;
			}
			return true;
		} else {
			// so the next transaction is not null
			string currentHash = copy->getSetHash();
			// compare this to the generated hash from the previous transaction
			string generatedPrevHash = (copy->getNext())->getHashForThis();
			if (currentHash != generatedPrevHash) {
				return false;
			}
		}
		copy = copy->getNext();
	}
	return true;
}	

bool Blockchain::findTransaction(string sender) {
	return false;
}