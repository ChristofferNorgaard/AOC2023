#include <bits/stdc++.h>
#include "../aoc.h"

using namespace std;

void printlines(vector<string> l){
	for(const auto& c: l){
		cout<<c<<endl;
	}
	return;
}
vector<string> cycle(vector<string> lines){
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
	//printlines(lines);
	move = false;
	do {
		move = false;
		for(int i = 0; i < lines.size(); i++){
			for(int j = 1; j < lines[i].size(); j++){
				if(lines[i][j] == 'O' && lines[i][j-1] == '.'){
					move = true;
					lines[i][j-1] = 'O';
					lines[i][j] = '.';
				}
			}
		}
	} while(move);
	//cout<<" "<<endl;
	//printlines(lines);
	move = false;
	do {
		move = false;
		for(int i = 0; i < lines.size()-1; i++){
			for(int j = 0; j < lines[i].size(); j++){
				if(lines[i][j] == 'O' && lines[i+1][j] == '.'){
					move = true;
					lines[i+1][j] = 'O';
					lines[i][j] = '.';
				}
			}
		}
	} while(move);
	//cout<<endl;
	//printlines(lines);
	//cout<<endl;
	move = false;
	do {
		move = false;
		for(int i = 0; i < lines.size(); i++){
			for(int j = 0; j < lines[i].size()-1; j++){
				if(lines[i][j] == 'O' && lines[i][j+1] == '.'){
					move = true;
					lines[i][j+1] = 'O';
					lines[i][j] = '.';
				}
			}
		}
	} while(move);
	//printlines(lines);
	return lines;
}
int score(vector<string> lines){
	int sum = 0; 
	for(int i = 0; i < lines.size(); i++){
		for(int j = 0; j < lines[i].size(); j++){
			sum += (lines[i][j] == 'O')? lines.size() - i: 0;	
		}
	}
	return sum;
}
string join(vector<string> s){
	string i;
	for(const auto& line: s){
		i += line;
	}
	return i;
}
map<string, int> done;
int main(int argc, char* argv[]){
	vector<string> lines = getlines(argv[1]);
	for(long long x = 0; x < 1000000000; x++){
		lines = cycle(lines);
		//cout<<endl;
		//printlines(lines);
		if(done.find(join(lines)) != done.end()) {
			int index = done[join(lines)]; 
			printlines(lines);
			x = 1000000000 - (1000000000 - index) % (x - index);
			//return 0;
		}
		done[join(lines)] = x;
	}	
	cout<<score(lines)<<endl;
	return 0;
}
