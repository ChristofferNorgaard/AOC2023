#include <bits/stdc++.h>
#include "aoc.h"
using namespace std;

int main(int argc, char* argv[]){
	vector<string> lines = getlines(argv[1]);
	int total = 0;
	vector<int> amount;
	for(int i = 0; i < lines.size(); i++) amount.push_back(1); 
	for(int id = 0; id < lines.size(); id++){
		string line = lines[id].substr(lines[id].find(": ")+2);
		string win = split(line, " | ")[0];
		string my = split(line, " | ")[1];
		vector<int> winnums;
		vector<int> mynums;
		for(const auto& num: split(win, " ")){
			if (num == "") continue;
			stringstream s(num);
			int a;
			s >> a;
			winnums.push_back(a);
		}
		for(const auto& num: split(my, " ")){
			if (num == "") continue;
			stringstream s(num);
			int a;
			s >> a;
			mynums.push_back(a);
		}
		int count = 0;
		for(const auto& mynum: mynums){
			for(const auto& winnum: winnums){
				if(mynum == winnum){
					count += 1;
					break;
				}
			}
		}
		cout << count << endl;
		for(int j = id+1; j <= id + count; j++){
			amount[j] += amount[id];
		}
	}
	for(const auto& c: amount) total += c;
	cout << total << endl;
	return 0;
}
