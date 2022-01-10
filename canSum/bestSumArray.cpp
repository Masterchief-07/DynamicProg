#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

vector<int>* bestSumArray(int targetSum, vector<int>& number)
{
	static bool sorted = false;
	if(!sorted){
		sort(number.begin(), number.end(), greater<int>());
		sorted=true;
	}
	static map<int, vector<int>*>memo;
	static vector<int> arr;
	if (memo.find(targetSum) != memo.end())
		return memo[targetSum];
	if (targetSum == 0)
		return &arr;
	if (targetSum <= 0)
		return NULL;
	for (auto i:number){
		vector<int> *remainResult = bestSumArray(targetSum-i, number);
		if(remainResult != NULL){
			arr.push_back(i);
			memo[targetSum] = &arr;
			return memo[targetSum];
		}
	}
	memo[targetSum] = NULL;
	return memo[targetSum];
}

void printVector(const vector<int>* vec){
	if (vec == NULL){
		cout<<"NULL\n";
		return;
	}
	for(auto i:*vec)
		cout<<i<<" ";
	cout<<"\n";
}

int main(int argv, char *argc[])
{
	stringstream st{argc[1]}; int n; st>>n;
	vector<int> number{2,3,5};
	vector<int> *result = bestSumArray(n, number);
	printVector(result);
	return 0;
}


