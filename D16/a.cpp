#include <bits/stdc++.h>
#include "../aoc.h"

bool mm[200][200][3][3];

struct Beam {
	int x; 
	int y;
	int h;
	int v;
};

Beam makebeam(int x, int y, int h, int v){
	Beam b;
	b.x = x;
	b.y = y;
	b.h = h;
	b.v = v;
	return b;
}
using namespace std;

int main(int argc, char* argv[]){
	vector<string> m = getlines(argv[1]);
	vector<vector<int>> act;
	for(int i = 0; i < m[0].size(); i++){
		vector<int> a;
		for(int j = 0; j < m.size(); j++){
			a.push_back(0);	
		}
		act.push_back(a);
	}
	queue<Beam> q;
	q.push(makebeam(0, 0, 1, 0));
	while(!q.empty()){
		Beam b = q.front();
		q.pop();
		while(true){
			if(b.x < 0 || b.x >= m[0].size() || b.y < 0 || b.y >= m.size()){
				break;
			}
			if(mm[b.x][b.y][b.h+1][b.v+1]) break;
			mm[b.x][b.y][b.h+1][b.v+1] = true;
			act[b.x][b.y] = 1;
			if(m[b.y][b.x] == '.'){
				b.x += b.h;
				b.y += b.v;
				continue;
			}
			if(m[b.y][b.x] == '\\'){
				swap(b.h, b.v);
				b.x += b.h;
				b.y += b.v;
				continue;
			}
			if(m[b.y][b.x] == '/'){
				b.h = -b.h;
				b.v = -b.v;
				swap(b.h, b.v);
				b.x += b.h;
				b.y += b.v;
				continue;

			}
			if(m[b.y][b.x] == '|'){
				if(b.v == -1 || b.v == 1){
					b.x += b.h;
					b.y += b.v;
					continue;
				}
				q.push(makebeam(b.x, b.y-1, 0, -1));
				b.y += 1;
				b.h = 0;
				b.v = 1;
				continue;
			}
			if(m[b.y][b.x] == '-'){
				if(b.h != 0){
					b.x += b.h;
					b.y += b.v;
					continue;
				}
				q.push(makebeam(b.x-1, b.y, -1, 0));
				b.x += 1;
				b.h = 1;
				b.v = 0;
				continue;
			}
		}
	}
	int sum = 0;
	for(int i = 0; i < m[0].size(); i++){
		for(int j = 0; j < m.size(); j++){
			sum += act[j][i];
			if(act[j][i]) cout<<'#';
			else cout<<'.';
		}
		cout<<endl;
	}
	cout<<sum<<endl;
	return 0;
}
