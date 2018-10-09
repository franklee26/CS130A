#include "Blockchain.h"
using namespace std;

Blockchain::Blockchain(Transaction* head) {
	this->head = head;
}

void Blockchain::insertTransaction(Transaction* node) {
	;
}

bool Blockchain::verifyChain() {
	return false;
}

bool Blockchain::findTransaction(string sender) {
	return false;
}