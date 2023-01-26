#include <iostream>

using namespace std;

void MC() {
	cout << "MC\n";
}

void BHC() {
	MC();
	cout << "BHC\n";
}

void MOMS() {
	BHC();
	cout << "MOMS\n";
}

void BBQ() {
	MOMS();
	cout << "BBQ\n";
}

void KFC() {
	BHC();
	BBQ();
	cout << "KFC\n";
}

int main()
{
	KFC();
	BBQ();

	return 0;
}