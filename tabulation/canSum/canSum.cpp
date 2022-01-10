#include<iostream>
#include<vector>

using namespace std;

bool canSum(int n, vector<int> const& numbers){
	vector<bool> tab(n+1, false);
	tab[0]=true;
	for(int i=0; i<n+1; ++i){
		if(tab[i] == true){
			for(int j=0; j<numbers.size(); ++j){
				int x = i+numbers[j];
				if(x<n+1)
					tab[x] = true;
			}
		}
	}
	return tab[n];
}

int main(int argv, char* argc[]){
	vector<int> numb{5,3,4};
	cout<<canSum(7, numb)<<endl;
	return 0;
}
