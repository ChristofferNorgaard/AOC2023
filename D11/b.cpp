#include <bits/stdc++.h>
#include "../aoc.h"

using namespace std;
struct Galaxy {
	long long x;
	long long y;
	long long ux;
	long long uy;
};

Galaxy makeGalaxy(long long x, long long y, long long ux = 0, long long uy = 0){
	Galaxy g;
	g.x = x;
	g.y = y;
	g.ux = ux;
	g.uy = uy;
	return g;
};
vector<Galaxy> update(vector<Galaxy> gal, long long x = LLONG_MAX, long long y = LLONG_MAX){
	vector<Galaxy> newgal; 
	for(const auto& g: gal){
		long long nx = g.ux;
		long long ny = g.uy;
		if(g.x > x) nx += 1000000-1;
		if(g.y > y) ny += 1000000-1;
		newgal.push_back(makeGalaxy(g.x, g.y, nx, ny));	
	} 	
	return newgal;
}
int main(int argc, char* argv[]){
	vector<Galaxy> gals; 
	vector<string> lines = getlines(argv[1]);
	for(long long i = 0; i < lines.size(); i++){
		for(long long j = 0; j < lines[i].size(); j++){
			if(lines[i][j] == '#'){
				gals.push_back(makeGalaxy(i, j));	
			}
		}
	}
	for(long long i = 0; i < lines.size(); i++){
		bool empty = true;
		for(const auto& g: gals){
			if(g.x == i) empty = false;
		}
		if(empty){
			gals = update(gals, i);
		}
	}
	for(long long i = 0; i < lines[0].size(); i++){
		bool empty = true;
		for(const auto& g: gals){
			if(g.y == i) empty = false;
		}
		if(empty){
			gals = update(gals, LLONG_MAX, i);
		}
	}
	for(long long i = 0; i < gals.size(); i++){
		gals[i].x += gals[i].ux;
		gals[i].y += gals[i].uy;
	}
	long long sum = 0;
	for(long long i = 0; i < gals.size(); i++){
		for(long long j = i+1; j < gals.size(); j++){
			cout<<i<< ": " << gals[i].x<<" "<<gals[i].y<<endl;
			cout<<i+1<<" "<<j+1<<" "<<abs(gals[i].x - gals[j].x) + abs(gals[i].y - gals[j].y)<<endl;
			sum += abs(gals[i].x - gals[j].x) + abs(gals[i].y - gals[j].y);	
		}
	}
	cout<<sum<<endl;
	return 0;
}
