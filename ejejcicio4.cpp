#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int v[] = {6, 7, 8};
	int *pi = NULL;
	int num;
	
	
	pi = v;
	
	
	for (int i = 0; i < 3; ++i) { 
		num = v[i]; 
		cout << "num: " << num << endl;
		cout << "pi: " << *pi << endl; 
		cout << "\n" << endl;
		pi = pi + 1; 
	}
	
	return 0;
}
