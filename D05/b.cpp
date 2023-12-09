#include <bits/stdc++.h>
#include "../aoc.h"

using namespace std;

struct Range{
	long long in;
	long long out;
	long long len;
};
struct Dim {
	long long start;
	long long len;
}
bool inRange(Range r, long long i){
	return (r.in <= i && i <= r.in + r.len); 
}
long long rangeMapTo(Range r, long long i){
	return (r.out + i - r.in);
}

Range makeRange(long long in, long long out, long long len){
	Range r;
	r.in = in;
	r.out = out;
	r.len = len;
	return r;
}
Dim makeDim(long long start, long long len){
	Dim d;
	d.start = start;
	d.len = len;
	return d;
}
vector<long long> splitPoints(vector<Range> map){
	vector<long long> points;
	for(const auto& range: map){
		points.push_back(range.in);
		points.push_bakc(range.in + range.len)
	}
}
int main(int argc, char* argv[]){
	vector<string> lines = getlines(argv[1]);
	vector<long long> seedsranges = getSepLong(lines[0]);
	vector<Dim> seeds;
	for(int i = 0; i < seedsranges.size(); i+=2){
		seeds.push_back(makeDim(seedsranges[i], seedsranges[i+1]);
	}
	cout<<seeds.size()<<endl;
	vector<vector<Range>> maps;
	long long res= LONG_MAX;
	for(const auto& line: lines){
		if(line.size() == 0){
			vector<Range> map;
			maps.push_back(map);
		}
		if(!('0' <= line[0] && line.at(0) <= '9')){
			continue;
		};	
		vector<long long> par = getSepLong(line);
		maps[maps.size()-1].push_back(makeRange(par[1], par[0], par[2]));
	}
	for(long long i = 0; i < maps.size(); i++){
		//cout<<i<<endl;
		for(const auto& rng: maps[i]){
			//cout<<rng.out << " " << rng.in << " " << rng.len<< endl;
		}
	}
	
	vector<Dim> newSeeds;
	for(auto const& map: maps){
		for(auto const& seed: seeds){
			
		}
	}
	return 0;
}
