#include <iostream>
#include <string>
#include <map>
#include <sstream>
using namespace std;

map<int, long int> memo;
long int fibcomput(int n){
	if(memo.find(n)!=memo.end())
		return memo[n];
	if(n<=2)
		return 1;
	memo[n] = fibcomput(n-1) + fibcomput(n-2);
	return memo[n]; 
}
	

int main(int argc, char *argv[]){
	
	stringstream st(argv[1]);
	int n; st>>n;
	cout<<fibcomput(n)<<endl;

	for(const auto &i:memo)
		cout<<i.second<<endl;
	return 0;
}
