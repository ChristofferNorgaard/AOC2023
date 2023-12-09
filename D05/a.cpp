#include <bits/stdc++.h>
#include "../aoc.h"

using namespace std;

struct Range{
	long long in;
	long long out;
	long long len;
};
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
int main(int argc, char* argv[]){
	vector<string> lines = getlines(argv[1]);
	vector<long long> seeds = getSepLong(lines[0]);
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
		cout<<i<<endl;
		for(const auto& rng: maps[i]){
			cout<<rng.out << " " << rng.in << " " << rng.len<< endl;
		}
	}
	cout<<"Maps: "<<endl;
	for(long long seed: seeds){
		long long cur = seed;
		for(const auto& map: maps){
			cout<<cur<<" ";
			for(const auto& r: map){
				//cout<<r.in<<" "<<r.out << " " << r.len << endl;
				if(inRange(r, cur)){
					cur = rangeMapTo(r, cur);
					//cout<<"Map to:" << cur<<" "<<endl;
					break;
				}
			}
		}
		cout<<cur<<endl;
		res = min(cur, res);
	}
	cout<< "Min number: " << res << endl;
	return 0;
}
