#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int var=10;
	int num=0;
	double real=10.5;
	duoble *ptreal;
	int * puntero=NULL;
	int * ptrint=NULL;
	puntero =&var;
	puntero=&num;
	ptrint=puntero;
	//*puntero=100;
	cout<<"var:"<<var<<endl;// imprimir 100
	cout<<"Valor puntero:"<<* puntero<<endl;
	cout<<"Direccion puntero:"<<puntero<<endl;
	return 0;
}

