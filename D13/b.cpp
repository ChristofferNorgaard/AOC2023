#include <bits/stdc++.h>
#include "../aoc.h"

using namespace std;
vector<string> flip(vector<string> f){
	vector<string> r;
	for(int i = 0; i < f[0].size(); i++){
		r.push_back("");
		for(auto const& c : f){
			r[r.size()-1] += c[i];
		}
	}
	//cout<<"r"<<endl;
	return r;

}
bool trymirror(string c, int i){
	string c1 = c.substr(i);
	string c2 = c.substr(0,i);
	//cout<<c2 << " | "<<c1;
	reverse(c2.begin(), c2.end());
	//cout<<" "<< c1.find(c2) << " " << c2.find(c1) << endl;
	return c1.find(c2) == 0 || c2.find(c1) == 0;
}
int main(int argc, char* argv[]){
	vector<string> lines = getlines(argv[1]);
	vector<vector<string>> exm; 
	vector<string> e;
	exm.push_back(e);
	int row = 0;
	int col = 0;
	for(const auto& line: lines){
		if(line.size() == 0){
			vector<string> e;
			exm.push_back(e);
			continue;
		}			
		exm[exm.size()-1].push_back(line);
	}
	for(const auto& e: exm){
		for(int i = 1; i < e[0].size(); i++){
			int ok = 0;
			for(const auto& l: e){
				ok += !trymirror(l, i);	
			}
			if(ok == 1){
				row += i;
			}
		}
		vector<string> f = flip(e);
		for(int i = 1; i < f[0].size(); i++){
			int ok = 0;
			for(const auto& l: f){
				ok += !trymirror(l, i);	
			}
			if(ok == 1){
				col += i;
			}

		};
	}
	cout<<col*100 + row<<endl;
	return 0;
}
