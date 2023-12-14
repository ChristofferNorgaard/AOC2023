#include <bits/stdc++.h>
#include "../aoc.h"

using namespace std;

int main(int argc, char* argv[]){
	vector<string> lines = getlines(argv[1]);
	bool move = False;
	do {
		move = False;
		for(int i = 1; i < lines.size(); i++){
			for(int j = 0; j < lines[i].size(); j++){
				if(lines[i-1][j] == '.'){
					move = True;
					lines[i-1][j] = 'O';
					lines[i][j] = '.';
				}
			}
		}
	} while(move);
	for(const auto& l: lines){
		cout<<l<<endl;
	}
	return 0;
}
