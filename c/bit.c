#include <stdio.h>
// Demonstration of a simple program that swaps bits.

int swapBitn(int bitPos, int *num) {
	int temp = 1;
	int numBak = *num;
	temp = temp << bitPos;	
	*num = *num & (~temp);	
	// This means, a bit 0 swap is required. So
	if(numBak == (*num)) {
		*num = (*num) | temp;
	}
	return *num;
}

int main() {

	int a = 0x0000;
	int b = 0xAF01;
	printf("%x", swapBitn(2, &b));
}
