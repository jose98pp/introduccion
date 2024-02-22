#include <iostream>
using namespace std;

int fib(int n) {
	if (n <= 1) 
		return n;//condicion base 
	else {
		//cout << "Fibonacci de " << n << " = " << fib(n - 1) << " + " << fib(n - 2) << endl;
		return fib(n - 1) + fib(n - 2);// condicion de recursiva
	}
}

int main(int argc, char *argv[]) {
	const int num = 5;
	cout << "Fibonacci de " << num << " = " << fib(num) << endl;
	
	return 0;
}
