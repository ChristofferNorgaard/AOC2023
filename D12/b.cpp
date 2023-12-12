#include <bits/stdc++.h>
#include "../aoc.h"

using namespace std;
struct Mem {
	int cur;
	int i;
	int q;
};

Mem makeMem(int cur, int i, int q){
	Mem mi;
	mi.cur = cur;
	mi.i = i;
	mi.q = q;
	return mi;
}
bool operator<(const Mem& l, const Mem& r) {
     return (l.cur<r.cur || (l.cur==r.cur && l.i<r.i) || (l.cur == r.cur && l.i == l.i && l.q < r.q));
}
vector<int> d;
string c;
map<Mem, int> m;
int prc(int cur, int i, int q, char rep='x'){
	char ci;
	if(rep == 'x') ci = c[cur];
	else ci = rep;
	Mem me = makeMem(cur, i, q);
	if(m.find(me) != m.end()){
		return m[me];
	}
	if(cur == c.size() && q == d.size()){ 
		return m[me] = 1;
	}
	if(cur == c.size()){
		return m[me] = 0;
	}
	if(ci == '#'){
		return m[me] = prc(cur+1, i+1, q);
	}
	if(ci == '.'){
		if(i == 0){
			return m[me] = prc(cur+1, i, q);
		}
		if(q >= d.size()) return 0;
		if(i == d[q]){
			return m[me] = prc(cur+1, 0, q+1);
		}
		else{
			return m[me] = 0;
		}
	}
	if(ci == '?'){
		return m[me] = (prc(cur, i, q, '#') + prc(cur, i, q, '.'));
	}
	return m[me] = 0;
	
}
int main(int argc, char* argv[]){
	int sum = 0;
	for(const auto& line: getlines(argv[1])){
		string con;
		for(int i = 0; i < 5; i++){
			con += split(line, " ")[0];
			con += "?";
		}
		con[con.size()-1] = '.';
		c = con;
		vector<int> lens = getSepInt(split(line, " ")[1], ","); 
		vector<int> di; 
		for(int i = 0; i < 5; i++){
		for(const auto& l: lens){
			//cout<<l<<" ";
			di.push_back(l);
		}};
		d = di;
		cout<<c<<endl;
		sum += prc(0, 0, 0);
		cout<< prc(0, 0, 0) << endl;
		m.clear();
		
	}
	cout<<sum<<endl;
	return 0;
}
