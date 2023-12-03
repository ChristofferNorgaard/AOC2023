#include <bits/stdc++.h>
#include "aoc.h"
using namespace std;
int main(int argc, char* argv[]){
	vector<string> lines = getlines(argv[1]);
	map<string, int> colors; 
	int res = 0;
	for(const auto& lne: lines){
		colors["red"] = 0;
		colors["green"] = 0;
		colors["blue"] = 0;
		string line = lne;
		replace(line.begin(), line.end(), ';', ',');
		int id = stoi(line.substr(line.find(" ") + 1, line.find(":") - line.find(" ")));
		cout<<id;
		vector<string> tokens = split(line.substr(line.find(": ")+2), ", ");
		for(const auto& token: tokens){
			int amount = stoi(split(token, " ")[0]);
			string colr = split(token, " ")[1];
			colors[colr] = max(colors[colr], amount);
		}
		res = res + colors["red"]*colors["green"]*colors["blue"];
		cout<<" "<<res<<endl;

	}
	cout<<res<<endl;
}
