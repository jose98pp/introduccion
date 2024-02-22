#include <iostream>
using namespace std;
int factorialNormal(int n){
	int fact=1;
	for(int i=1;i<=n;i++)
		fact=i*fact;
	return fact;
}
int factorial(int n){
	if (n==0)
		return 1;
	else
		return factorial(n-1)*n;
	
}
	

int main(int argc, char *argv[]) {
	const int num=5;
	cout<<"factorial:"<<factorial(num)<<endl;
	
	return 0;
}

