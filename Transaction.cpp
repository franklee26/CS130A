#include "Transaction.h"
#include <cstdlib>
#include "sha256.h"

// non-member functions

std::string makeNonce() {					// make a random length 3 Nonce string
	std::string answer = "";
	srand(time(NULL));
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
	this->isHeadCheck = false;
}

Transaction::Transaction(int amount, std::string sender, std::string receiver) {
	this->sender = sender;
	this->receiver = receiver;
	this->isHeadCheck = false;
}

Transaction::Transaction(int amount, std::string sender, std::string receiver, 
		std::string nonce, std::string hash, Transaction* next, bool isHeadCheck) {
	this->amount = amount;
	this->sender = sender;
	this->receiver = receiver;
	this->nonce = nonce;
	this->hash = hash;
	this->next = next;
	this->isHeadCheck = isHeadCheck;
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

void Transaction::setNonce() {
	this->nonce = makeNonce();
}

void Transaction::setHash(std::string hash) {
	size_t lastIndex = hash.find_last_of(hash);
	if (hash[lastIndex] != '0' && hash[lastIndex] != '1' && hash[lastIndex] != '2'
		&& hash[lastIndex] != '3' && hash[lastIndex] != '4') {
		std::cout<<"Invalid hash: last digit must be 0-4."<<std::endl;
		return;
	}
	this->hash = hash;
}

void Transaction::setHash() {
	// I need to make a nonce first
	if (this->nonce == "") {
		std::cout<<"Detected empty nonce. Filling empty nonce with generated nonce..."<<std::endl;
		this->nonce = makeNonce();
	}
	if (this->sender == "" || this->receiver == "") {
		std::cout<<"Error: Need sender and receiver. Exiting."<<std::endl;
		return; 
	}
	// first I need to actually make a hash
	std::string key = std::to_string(this->amount) + this->sender + 
	this->receiver + this->nonce;
	// encrypt it
	std::string ENCRYPTED = sha256(key);
	// now I need to ensure that the last char in this key is a digit 0-4
	size_t lastIndex = ENCRYPTED.find_last_of(ENCRYPTED);
	while (ENCRYPTED[lastIndex] != '0' && ENCRYPTED[lastIndex] != '1' && ENCRYPTED[lastIndex] != '2'
		&& ENCRYPTED[lastIndex] != '3' && ENCRYPTED[lastIndex] != '4') {
		//std::cout<<"MAKING NEW NONCE. REPLACE: "<<ENCRYPTED[lastIndex]<<std::endl;
		this->nonce = makeNonce();		// make a new nonce
		key = std::to_string(this->amount) + this->sender + 
			this->receiver + this->nonce;
		ENCRYPTED = sha256(key);
	}
	std::cout<<"Done. Successfully generated viable SHA256 hash."<<std::endl;
	this->hash = ENCRYPTED;
}

void Transaction::setNext(Transaction* next) {
	this->next = next;
}

void Transaction::setHead(bool isHeadCheck) {
	this->isHeadCheck = isHeadCheck;
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

bool Transaction::isHead() {
	return this->isHeadCheck;
}