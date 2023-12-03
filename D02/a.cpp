#include <bits/stdc++.h>
#include "aoc.h"
using namespace std;
int main(int argc, char* argv[]){
	vector<string> lines = getlines(argv[1]);
	map<string, int> colors; 
	colors["red"] = 12;
	colors["green"] = 13;
	colors["blue"] = 14;
	int res = 0;
	for(const auto& lne: lines){
		string line = lne;
		replace(line.begin(), line.end(), ';', ',');
		int id = stoi(line.substr(line.find(" ") + 1, line.find(":") - line.find(" ")));
		cout<<id;
		vector<string> tokens = split(line.substr(line.find(": ")+2), ", ");
		bool possible = true;
		for(const auto& token: tokens){
			int amount = stoi(split(token, " ")[0]);
			string colr = split(token, " ")[1];
			possible = possible && (amount <= colors[colr]);
		}
		if(possible) res = res + id;
		cout<<" "<<res<<endl;

	}
	cout<<res<<endl;
}
