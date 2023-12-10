#include <bits/stdc++.h>
#include "../aoc.h"

using namespace std;

struct Point{
	int x;
	int y;
};

bool operator==(const Point& p1, const Point& p2){
	return (p1.x == p2.x && p1.y == p2.y);
}

vector<string> mp;
vector<Point> makePoints(int x1, int y1, int x2, int y2){
	Point p1;
	Point p2;
	p1.x = x1;
	p1.y = y1;
	p2.x = x2;
	p2.y = y2;
	vector<Point> ret;
	ret.push_back(p1);
	ret.push_back(p2);
	return ret;
}

Point makePoint(int x, int y){
	Point p;
	p.x = x;
	p.y = y;
	return p;
}
vector<Point> nxt(Point p){
	char m = mp[p.y][p.x];
	switch(m) {
		case '|':
			return makePoints(p.x, p.y+1, p.x, p.y-1);
		case '-':
			return makePoints(p.x+1, p.y, p.x-1, p.y);
		case 'L':
			return makePoints(p.x, p.y-1, p.x+1, p.y);
		case 'J':
			return makePoints(p.x, p.y-1, p.x-1, p.y);
		case '7':
			return makePoints(p.x-1, p.y, p.x, p.y+1);
		case 'F':
			return makePoints(p.x+1, p.y, p.x, p.y+1);
	}
	vector<Point> vp;
	return vp;
}

int main(int argc, char* argv[]){
	mp = getlines(argv[1]);
	vector<vector<int>> dist;
	Point s;
	for(int i = 0; i < mp.size(); i++){
		vector<int> p;
		for(int j = 0; j < mp[0].size(); j++){
			p.push_back(INT_MAX);
			if(mp[j][i] == 'S'){
				s.x = i;
				s.y = j;
			}
		}
		dist.push_back(p);
	}
	dist[s.y][s.x] = 0;
	queue<Point> q;
	for(int x = 0; x < mp[0].size(); x++){
		for(int y = 0; y < mp.size(); y++){
			for(const auto& p: nxt(makePoint(x, y))){
				//dist[p.y][p.x] = 1;
				//cout<<mp[y][x] << " " << mp[p.y][p.x]<<endl;
				if(p == s){
					q.push(makePoint(x, y));
					dist[y][x] = 1;
				}
			}
		}
	}
	
	while(!q.empty()){
		Point p = q.front();
		q.pop();
		for(const auto& pi: nxt(p)){
			if((dist[p.y][p.x] + 1) < dist[pi.y][pi.x]){
				dist[pi.y][pi.x] = dist[p.y][p.x] + 1;
				q.push(pi);
			}
		}
	}

	int mx = INT_MIN;
	for(int i = 0; i < dist.size(); i++){
		for(int j = 0; j < dist[0].size(); j++){
			if(dist[i][j] == INT_MAX) cout << '.';
			else {
				cout<<dist[i][j];
				mx = max(mx, dist[i][j]);
			}
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i = 0; i < dist.size(); i++){
		for(int j = 0; j < dist[0].size(); j++){
			cout<<mp[i][j];
		}
		cout<<endl;
	}
	cout<<mx<<endl;
	return 0;
}
