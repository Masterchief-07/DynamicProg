#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <functional>

/*
 * trouver un ensemble de mot permattant de former le text
 *
 */

using namespace std;

bool canConstruct(string text, const vector<string> &word)
{
	//static vector<string> text;
	static bool sorted = false;
	static vector<string> words{word};
	if(!sorted){
		sort(words.begin(), words.end(), greater<string>());
		sorted=true;
	}
	static map<string, bool> memo;
	if(memo.find(text) != memo.end())
		return memo[text];
	if(text.empty())
		return true;
	for(const auto &w:words){
		if(text.find(w) == 0){
			string text2 = text.substr(w.size());
			//cout<<text2.size()<<"\n";
			if(canConstruct(text2, words)){
				memo[text] = true;
				return true;
			}
		}
	}
	memo[text]=false;
	return false;
}

int main(int argv, char* argc[])
{
	stringstream st{argc[1]};
	vector<string> words{"bo", "rd", "ate", "t", "ska", "sk", "boar"};
	cout<<canConstruct(st.str(), words)<<endl;
	return 0;
}
