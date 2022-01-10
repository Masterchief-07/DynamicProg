#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

long int fib(int n){
	vector<long int> fibtab(n+3, 0);
	fibtab[1] = 1;
	for(vector<long int>::iterator it=fibtab.begin(); it<fibtab.begin()+n; it++){
		*(it+1) += *it;
		*(it+2) += *it;
	}
	return fibtab[n];
}


int main(int argv, char* argc[]){

	cout<<fib(100)<<endl;

	return 0;
}




