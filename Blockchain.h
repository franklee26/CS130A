#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "Transaction.h"
#include <iostream>
#include <string>

// makes the actual blockchain from the transaction nodes
class Blockchain {
public:
	// constructor 
	Blockchain(Transaction* head);							// takes the head of the transaction chain

	// methods
	void insertTransaction(Transaction* node);				// inserts transaction
	void printChain();										// prints the blockchain, despite any errors

	// getters
	bool verifyChain();										// returns true if verified
	bool findTransactionSender(std::string sender);
	bool findTransactionReceiver(std::string receiver);
private:
	Transaction* head;
};

#endif