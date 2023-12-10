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
	for(int i = 0; i < mp[0].size(); i++){
		vector<int> p;
		for(int j = 0; j < mp.size(); j++){
			p.push_back(INT_MAX);
			if(mp[j][i] == 'S'){
				s.x = i;
				s.y = j;
			}
		}
		dist.push_back(p);
	}
	vector<vector<int>> flood;
	for(int i = 0; i < 2*mp.size(); i++){
		vector<int> f;
		for(int j = 0; j < 2*mp[0].size(); j++){
			f.push_back(0);	
		}
		flood.push_back(f);
	}
	dist[s.y][s.x] = 0;
	queue<Point> q;
	for(int x = 0; x < mp[0].size(); x++){
		for(int y = 0; y < mp.size(); y++){
			for(const auto& p: nxt(makePoint(x, y))){
				if(p == s){
					q.push(makePoint(x, y));
					dist[y][x] = 1;
				}
			}
		}
	}
	Point prev = s;
	Point cur = q.front();
	flood[2*s.y][2*s.x] = 1;
	flood[s.y + cur.y][s.x + cur.x] = 1;
	vector<Point> order;
	order.push_back(s);
	while(!(cur == s)){
		order.push_back(cur);
		flood[2*cur.y][2*cur.x] = 1;
		for(const auto& p: nxt(cur)){
			if(!(p == prev)){
				prev = cur;
				cur = p;
				flood[cur.y + prev.y][cur.x + prev.x] = 1;
				break;
			}
		}
	}
	for(int i = 0; i < flood.size(); i++){
		for(int j = 0; j < flood[0].size(); j++){
				if(flood[i][j] == 0) cout << '.';
				if(flood[i][j] == 1) cout << "█";
				if(flood[i][j] == -1) cout << "░";
		}
		cout<<endl;
	}	
	queue<Point> f;
	for(int i = 0; i < flood[0].size(); i++){
		if(flood[0][i] == 0) f.push(makePoint(i, 0));
		if(flood[flood.size() -1][i] == 0) f.push(makePoint(i, flood.size()-1));
	}
	for(int i = 0; i < flood.size(); i++){
		if(flood[i][0] == 0) f.push(makePoint(0, i));
		if(flood[i][flood[0].size()-1] == 0) f.push(makePoint(flood[0].size()-1, i));
	}
	while(!f.empty()){
		Point p = f.front();
		f.pop();
		if(flood[p.y][p.x] == 0) flood[p.y][p.x] = -1;
		else continue;
		for(int x = max(p.x-1, 0); x < min((int)flood[0].size(), p.x+2); x++){
			for(int y = max(p.y-1, 0); y < min((int)flood.size(), p.y+2); y++){
				if(flood[y][x] == 0){
					f.push(makePoint(x, y));
				}
			}
		}
	}
	for(int i = 0; i < flood.size(); i++){
		for(int j = 0; j < flood[0].size(); j++){
				if(flood[i][j] == 0) cout << '.';
				if(flood[i][j] == 1) cout << "█";
				if(flood[i][j] == -1) cout << "░";
		}
		cout<<endl;
	}
	
	cout<<endl;
	int res = 0;
	for(int i = 0; i < flood.size(); i+=2){
		for(int j = 0; j < flood[0].size(); j+=2){
			if(flood[i][j] == 0) res++;
		}
	}
	cout<<res<<endl;
	return 0;
}
