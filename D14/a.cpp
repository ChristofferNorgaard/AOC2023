#include <bits/stdc++.h>
#include "../aoc.h"

using namespace std;

int main(int argc, char* argv[]){
	vector<string> lines = getlines(argv[1]);
	bool move = false;
	do {
		move = false;
		for(int i = 1; i < lines.size(); i++){
			for(int j = 0; j < lines[i].size(); j++){
				if(lines[i][j] == 'O' && lines[i-1][j] == '.'){
					move = true;
					lines[i-1][j] = 'O';
					lines[i][j] = '.';
				}
			}
		}
	} while(move);
	int sum = 0; 
	for(int i = 0; i < lines.size(); i++){
		for(int j = 0; j < lines[i].size(); j++){
			sum += (lines[i][j] == 'O')? lines.size() - i: 0;	
		}
	}
	cout<<sum<<endl;
	return 0;
}
