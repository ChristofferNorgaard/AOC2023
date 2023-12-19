#include <bits/stdc++.h>
#include "../aoc.h"

using namespace std;
int mem[200][200][4];
vector<vector<int>> n;
void v(int x, int y, int lx, int ly, int c, int d){
	if(c >= 4) return;	
	if(x < 0 || x >= n.size() || y < 0 || y >= n[0].size()) return;
	//cout<<d<<endl;
	d += n[x][y];
	if(mem[x][y][0] < d){
		return;	
	}
	mem[x][y][0] = d;
	for(int i = 0; i < 3; i++){
		if(lx != 1){
			v(
		}
	}
}
int main(int argc, char* argv[]){
	for(int i = 0; i < 200; i++){
		for(int j = 0; j < 200; j++){
			for(int r = 0; r < 4; r++){
				mem[i][j][r] = INT_MAX;
			}
		}
	}
	vector<string> l = getlines(argv[1]);
	for(const auto& line: l){
		vector<int> v;
		for(const auto& c: line){
			v.push_back((int)(c - '0'));
		}
		n.push_back(v);
	}
	v(0, 0, 0, 0, 0, 0);
	cout<<n[n.size()-1][n[0].size()-1]<<endl;
	//cout<<mem[n.size()-1][n[0].size()-1][0]<<mem[n.size()-1][n[0].size()-1][1]<<mem[n.size()-1][n[0].size()-1][2]<<endl;
	//cout<<min(mem[n.size()-1][n[0].size()-1][0], min(mem[n.size()-1][n[0].size()-1][1], min(mem[n.size()-1][n[0].size()-1][2], mem[n.size()-1][n[0].size()-1][3])))<<endl;
	cout<<mem[n.size()-1][n[0].size()-1][0]<<endl;
	return 0;
}
