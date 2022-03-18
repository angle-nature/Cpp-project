#include<stdio.h>

int byteXor(int x, int y, int n) {
	int x_shift = x >> (n << 3);
	int y_shift = y >> (n << 3);
	int x_byte = x_shift & 0xff;
	int y_byte = y_shift & 0xff;
	return !!(x_byte ^ y_byte);
}

int isLessOrEqual(int x, int y) {
	return !(((y + ((~x) + 1)) >> 31) & 1);
}

int main()
{
	printf("%d\n", isLessOrEqual(6,-1));
	return 0;
}