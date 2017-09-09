#include <iostream>
using namespace std;
int main()
{
	int A[2] = { 4, 12 };
	int size = 2;
	int temp = 0;
	for (int i = 0; i < size; i++) {
		temp ^= A[i];
	}
	int bit = 0;
	while ((temp & 1) != 1) {
		bit++;
		temp = temp >> 1;
	}
	int result[2];
	result[0] = 0;
	result[1] = 0;
	for (int i = 0; i < size; i++) {
		if (((A[i] >> bit) & 1) == 1) {
			result[0] ^= A[i];
		}
		else {
			result[1] ^= A[i];
		}
	}
	return 0;
}