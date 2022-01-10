#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

vector<int>* bestSumArray(int targetSum, vector<int>& number)
{
	static map<int, vector<int>*>memo;
	static vector<int> arr;
	static vector<int> shortest;
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
			if(shortest.size()==0 || shortest.size() < arr.size())
				shortest = arr;
		}
	}
	memo[targetSum] = &shortest;
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
