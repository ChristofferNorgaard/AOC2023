#include <bits/stdc++.h>
#include "aoc.h"
using namespace std;
struct Point {
	int value;
	int x;
	int y;
	int len;

	bool operator==(const Point& other) const {
		return value == other.value && x == other.x && y == other.y && len == other.len;
	}
};

Point makepoint(int value, int x, int y, int len){
	Point p;
	p.value = value;
	p.x = x;
	p.y = y;
	p.len = len;
	return p;
}
int main(int argc, char* argv[]){
	vector<Point> points;
	auto lines = getlines(argv[1]);
	for(int i = 0; i < lines.size(); i++){
		string line = lines[i];
		for(int j = 0; j < line.size(); j++){
			if(line[j] == '.') continue;
			if('0' <= line[j] && line[j] <= '9'){
				int end = 0;
				for(int x = j; x < line.size(); x++){
					if('0' <= line[x] && line[x] <= '9'){
						end += 1;
					}
					else break;
				}
				points.push_back(makepoint(stoi(line.substr(j, end)), i, j, end));
				j += end-1;	
				continue;
			}
			points.push_back(makepoint(-(int)line[j], i, j, 1));
		}
	}
	for(const auto& p : points){
		if(p.value > 0) cout<<p.value << " " << p.x << " " << p.y << " " << p.len << endl;
		if(p.value < 0) cout<<(char)(-p.value) << " " << p.x << " " << p.y << " " << p.len << endl;
	}
	
	int sum = 0;
	for(const auto& p: points){
		if(p.value < 0) continue;
		for(const auto& q: points){
			if(p == q) continue;
			if(q.value >= 0) continue;
			if(p.x-1 <= q.x && q.x <= p.x+1 && p.y-1 <= q.y && q.y <= p.y+p.len){	
				sum += p.value;
				cout << p.value << " " << (char)(-q.value) << endl;
				break;
			} 
		}
	}
	cout << sum << endl;
	return 0;
}
