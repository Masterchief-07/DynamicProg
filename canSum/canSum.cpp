#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

/*
 * indique si c'est possible d'avoir targetSum grace a la som des nombre de number
 * on peut utiliser nimporte lequel des nombre dans number comme nous voulons
 * tous les nombres sont positif
*/

bool canSum(int targetSum, const vector<int>& number){
	static map<int, bool> memo;
	if(memo.find(targetSum) != memo.end())
		return memo[targetSum];
	if(targetSum==0)
		return true;
	if(targetSum < 0)
		return false;
	for(auto i:number){
		const int remainder = targetSum - i;
		if(canSum(remainder, number)==true)
		{
			memo[targetSum] = true; 
			return true;
		}
	}
	memo[targetSum] = false;
	return false;
}


int main(int argv, char *argc[])
{
	vector<int> number{2,4};
	stringstream st{argc[1]}; int n; st>>n;
	cout<<canSum(n, number)<<endl;
	return 0;
}
