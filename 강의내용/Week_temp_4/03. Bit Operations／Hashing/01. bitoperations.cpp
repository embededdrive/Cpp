#include <iostream>

using namespace std;

int main()
{
	int A = 3;			// 0011
	int B = 5;			// 0101

	int C = A & B;
	cout << C << '\n';	// 0001
	
	int D = A | B;
	cout << D << '\n';	// 0111

	int E = A ^ B;
	cout << E << '\n';	// 0110

	int F = ~A;
	cout << F << '\n';	// 1100

	int G = A >> 1;
	cout << G << '\n';	// 0001

	int H = A << 1;
	cout << H << '\n';	// 0110

	return 0;
}