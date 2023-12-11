#include <bits/stdc++.h>
#include "../aoc.h"

using namespace std;
struct Galaxy {
	int x;
	int y;
	int ux;
	int uy;
};

Galaxy makeGalaxy(int x, int y, int ux = 0, int uy = 0){
	Galaxy g;
	g.x = x;
	g.y = y;
	g.ux = ux;
	g.uy = uy;
	return g;
};
vector<Galaxy> update(vector<Galaxy> gal, int x = INT_MAX, int y = INT_MAX){
	vector<Galaxy> newgal; 
	for(const auto& g: gal){
		int nx = g.ux;
		int ny = g.uy;
		if(g.x > x) nx++;
		if(g.y > y) ny++;
		newgal.push_back(makeGalaxy(g.x, g.y, nx, ny));	
	} 	
	return newgal;
}
int main(int argc, char* argv[]){
	vector<Galaxy> gals; 
	vector<string> lines = getlines(argv[1]);
	for(int i = 0; i < lines.size(); i++){
		for(int j = 0; j < lines[i].size(); j++){
			if(lines[i][j] == '#'){
				gals.push_back(makeGalaxy(i, j));	
			}
		}
	}
	for(int i = 0; i < lines.size(); i++){
		bool empty = true;
		for(const auto& g: gals){
			if(g.x == i) empty = false;
		}
		if(empty){
			gals = update(gals, i);
		}
	}
	for(int i = 0; i < lines[0].size(); i++){
		bool empty = true;
		for(const auto& g: gals){
			if(g.y == i) empty = false;
		}
		if(empty){
			gals = update(gals, INT_MAX, i);
		}
	}
	for(int i = 0; i < gals.size(); i++){
		gals[i].x += gals[i].ux;
		gals[i].y += gals[i].uy;
	}
	int sum = 0;
	for(int i = 0; i < gals.size(); i++){
		for(int j = i+1; j < gals.size(); j++){
			cout<<i<< ": " << gals[i].x<<" "<<gals[i].y<<endl;
			cout<<i+1<<" "<<j+1<<" "<<abs(gals[i].x - gals[j].x) + abs(gals[i].y - gals[j].y)<<endl;
			sum += abs(gals[i].x - gals[j].x) + abs(gals[i].y - gals[j].y);	
		}
	}
	cout<<sum<<endl;
	return 0;
}
