#include <iostream>

void increment( int &a ) {
	++a;
}

void ptr_increment ( int *a ) {
	++*a;
}

int main() {
	int a = 5;
	std::cout << a << '\n';

	increment(a);
	std::cout << a << '\n';

	ptr_increment(&a);
	std::cout << a << '\n';

	return 0;
}

