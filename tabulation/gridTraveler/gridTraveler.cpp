#include <iostream>
#include <vector>
#include <array>
#include <sstream>
using namespace std;

long int gridTraveler(const int& x, const int& y){
	vector<vector<long int>> tab(x+2, vector<long int>(y+2,0));
	tab[1][1] = 1;
	for(int i=0; i<x+1; ++i){
		for(int j=0; j<y+1; j++){
			tab[i+1][j]+=tab[i][j];
			tab[i][j+1]+=tab[i][j];
		}
	}
	return tab[x][y];
}

int main(int argv, char* argc[]){
	stringstream st{argc[1]}; int n; st>>n;
	stringstream st2{argc[2]}; int m; st2>>m;
	cout<<gridTraveler(n,m)<<endl;
	return 0;
}



