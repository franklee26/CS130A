#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>

class Transaction {
private:
	Transaction* next;		// points to next transaction node
	int amount;				// amount of money transferred
	std::string sender;		// sender of the money
	std::string receiver;	// receiver of the money
	std::string nonce;		// random string used for crypto. hashing
	std::string hash;		// hash of the previous transaction, left empty if node head
	bool isHeadCheck;		// indicator if this transaction is head (defaults to true)
public:
	// constructors

	Transaction(int amount);
	Transaction(int amount, std::string sender, std::string receiver);
	Transaction(int amount, std::string sender, std::string receiver, 
		std::string nonce, std::string hash, Transaction* next, bool isHeadCheck);

	// methods

	void setAmount(int amount);
	void setSender(std::string sender);
	void setReceiver(std::string receiver);
	void setNonce(std::string nonce);
	void setNonce();							// set nonce using in-built alg
	void setHash(std::string hash);				// set hash provided the hash
	// void setHash();							// set hash using in-built alg.
	void setNext(Transaction* next);
	void setHead(bool isHeadCheck);				// sets current transaction as the head

	// getters

	int getAmount();
	std::string getSender();
	std::string getReceiver();
	std::string getNonce();
	std::string getHashForThis();				// this auto generates a viable nonce as well
	std::string getSetHash();					
	Transaction* getNext();
	bool isHead();
};

#endif
