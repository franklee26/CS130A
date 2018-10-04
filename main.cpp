#include "Transaction.h"
#include "sha256.h"
using namespace std; 

int main() {

	string input = "oka";
	string output = sha256(input);

	cout<<output<<endl;

	return 0;
}
