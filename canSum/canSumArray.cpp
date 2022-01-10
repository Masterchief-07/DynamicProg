#include<iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<int>* canSumArray(int targetSum, const vector<int>& number){
	static map<int, vector<int>*> memo;
	static vector<int> arr;
	if(memo.find(targetSum)!=memo.end())
		return memo[targetSum];
	if(targetSum == 0)
		return &arr;
	if(targetSum <= 0)
		return NULL;
	for(auto i:number){
		int remainder = targetSum-i;
		vector<int>* remainResult = canSumArray(remainder, number);
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
	if(vec==NULL){
		cout<<"NULL"<<"\n";
		return;
	}
	for (auto i:*vec)
		cout<<i<<" ";
	cout<<endl;
}


int main(int argv, char *argc[]){
	stringstream st{argc[1]}; int n; st>>n;
	vector<int> numbers{14,7};
	vector<int> *result = canSumArray(n, numbers);
	printVector(result);
	//delete(result);
	return 0;
}
