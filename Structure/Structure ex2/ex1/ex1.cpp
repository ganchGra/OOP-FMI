#include<iostream>

void printSpace(size_t num) {
	if (num)
	{
		std::cout << " ";
		printSpace(num - 1);
	}
}

void printFTC(int c, int t) {
	if (t)
	{
		std::cout << c << " ";
		printFTC(c - 1, t - 1);
	}
	else {
		std::cout << c << " ";
	}
}

void printBack(int c,int t) {
	if (t)
	{
		std::cout << c << " ";
		printBack(c + 1, t - 1);
	}
	else {
		std::cout << c << " ";
	}
}

void printRow(int row,int current,int n) {
	printFTC(n, row);
	if (row != n-1)
	{
		printSpace(4 * n - (2+ (row + 1) * 4));
		printBack(n - row, row);
	}
	else {
		printBack(2, row - 1);
	}
}

void printRows(int current, int n) {
	if (current < n)
	{
		printRow(current, n,n);

		std::cout << std::endl;
		printRows(current + 1, n);
	}
}

void printN(int num) {
	printRows(0,num);
}

int main() {
	int n;
	std::cin >> n;
	printN(n);

	return 0;
}