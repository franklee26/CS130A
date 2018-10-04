#include "Transaction.h"
#include <cstdlib>
#include <openssl/sha.h>

// non-member functions

std::string makeNonce() {			// make a random length 3 Nonce string
	std::string answer = "";
	for (int i=0; i<3; i++) {
		answer += char(rand()%26 + 97);
	}
	return answer;
}

// member functions

Transaction::Transaction(int amount) {
	this->amount = amount;
	this->sender = "";
	this->receiver = "";
	this->nonce = "";
	this->hash = "";
	this->next = NULL;
}

Transaction::Transaction(int amount, std::string sender, std::string receiver, 
		std::string nonce, std::string hash, Transaction* next) {
	this->amount = amount;
	this->sender = sender;
	this->receiver = receiver;
	this->nonce = nonce;
	this->hash = hash;
	this->next = next;
}

void Transaction::setAmount(int amount) {
	this->amount = amount;
}

void Transaction::setSender(std::string sender) {
	this->sender = sender;
}

void Transaction::setReceiver(std::string receiver) {
	this->receiver = receiver;
}

void Transaction::setNonce(std::string nonce) {
	this->nonce = nonce;
}

void Transaction::setHash(std::string hash) {
	this->hash = hash;
}

void Transaction::setHash() {
	;
}

void Transaction::setNext(Transaction* next) {
	this->next = next;
}

int Transaction::getAmount() {
	return amount;
}

std::string Transaction::getSender() {
	return sender;
}

std::string Transaction::getNonce() {
	return nonce;
}

std::string Transaction::getHash() {
	return hash;
}

Transaction* Transaction::getNext() {
	return next;
}