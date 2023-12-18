#include <bits/stdc++.h>
#include "../aoc.h"

using namespace std;
int sh(string s){
	int cur = 0;
	for(const auto& c: s){
		cur += c;
		cur = cur*17;
		cur = cur % 256;
	}
	return cur;
}
struct lense{
	string label;
	int focal;
};
lense makelense(string l, int f){
	lense le;
	le.label = l;
	le.focal = f;
	return le;
}
int main(int argc, char* argv[]){
	vector<string> hsh = split(getlines(argv[1])[0], ",");
	vector<vector<lense>> l;
	for(int i = 0; i < 256; i++){
		vector<lense> a;
		l.push_back(a);
	}
	int sum = 0;
	for(const auto& s: hsh){
		int h = 0;
		if(s.find('=') != std::string::npos){
			string label = split(s, "=")[0];
			int focal = stoi(split(s, "=")[1]);
			h = sh(label);
			bool skip = false;
			for(int i = 0; i < l[h].size(); i++){
				if(l[h][i].label == label){
					l[h][i].focal = focal;
					skip = true;
					break;
				}
			}
			if(!skip){
				l[h].push_back(makelense(label, focal));
			}
		}
		else{
			string label = split(s, "-")[0];
			h = sh(label);
			int r = -1;
			for(int i = 0; i < l[h].size(); i++){
				if(l[h][i].label == label) r = i;
			}
			if(r != -1) l[h].erase(l[h].begin() + r);
		}
		cout<<s<<" "<<h<<endl;
		for(int b = 0; b < l.size(); b++){
		for(int i = 0; i < l[b].size(); i++){
			cout<<l[b][i].label<<" "<<b<<" "<<i<<" "<<l[b][i].focal<<endl;
			//sum += (b+1)*(i+1)*l[b][i].focal;
		}
	}
	}
	for(int b = 0; b < l.size(); b++){
		for(int i = 0; i < l[b].size(); i++){
			cout<<l[b][i].label<<" "<<b<<" "<<i<<" "<<l[b][i].focal<<endl;
			sum += (b+1)*(i+1)*l[b][i].focal;
		}
	}
	cout<<sum<<endl;
	return 0;
}
