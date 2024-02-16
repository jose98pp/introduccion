#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int v[]={6,7,8};
	int *pi=NULL;
	int num;
	num =v[0];
	pi=v;
	cout<<"num:"<<num<<endl;
	cout<<"pi:"<<num<<endl;
	cout<<"\n"<<endl;
	
	num =v[1];
	pi=pi+1;
	cout<<"num:"<<num<<endl;
	cout<<"pi:"<<num<<endl;
	cout<<"\n"<<endl;
	
	
	num =v[2];
	pi=pi+1;
	cout<<"num:"<<num<<endl;
	cout<<"pi:"<<num<<endl;
	
	num =v[4];
	pi=pi+1;
	cout<<"num:"<<num<<endl;
	cout<<"pi:"<<num<<endl;
	return 0;
}

