#include <iostream>
using namespace std;


	
	
	void funcion (int &var){ 
		
		var =100; 
		
	} 
		//borrando el "&" deberia imprimir el 10
		
		
		int main(){ 
			
			int var = 10; 
			funcion(var); 
			
			cout<<"var:"<<var<<endl;//imprimir100 
			return 0;
		} 
	


