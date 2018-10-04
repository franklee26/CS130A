#include "Transaction.h"
using namespace std; 

int main() {

	std::string answer = "";
	for (int i=0; i<3; i++) {
		answer += char(rand()%26 + 97);
	}

	cout<<answer<<endl;

	return 0;
}
