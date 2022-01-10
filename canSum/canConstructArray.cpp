#include<iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<vector<string>>* canConstruct(string text, const vector<string> &word){
	static vector<string> words;
	static vector<vector<string>> result;
	if(text.empty()){
		result.push_back(words);
		words.clear();
		return &result;
	}
	for(const auto &w: word){
		if(text.find(w)==0){
			string text2 = text.substr(w.size());
			words.push_back(w);
			//cout<<w<<endl;
			canConstruct(text2, word);
		}
	}
	if(words.size()>=1)
		words.pop_back();
	return &result;
}

int main(int argv, char* argc[]){
	stringstream st{argc[1]};
	vector<string> words{"bo", "rd", "ate", "te", "ska", "sk", "boar"};
	vector<vector<string>> *result = canConstruct(st.str(), words);
	for(auto const& x:*result){
		for(auto const& w:x)
			cout<<w<<" ";
		cout<<endl;
	}
	return 0;
}


