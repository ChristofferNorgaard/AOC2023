#include <bits/stdc++.h>
#include "../aoc.h"

using namespace std;

struct Part{
	int x, m, a, s;
	/*Part(int x_, int m_, int a_, int s_){
		x = x_;
		m = m_;
		a = a_;
		s = s_;
	};*/ };

struct Range{
	int l = INT_MIN;
	int u = INT_MAX;
	bool inRange(int i){
		return (l < i && i < u);
	};
};

struct Workflow{
	Range x;
	Range m;
	Range a;
	Range s;
	string r;	
};

string proc(Workflow wk, Part p){
		if (wk.s.inRange(p.s) && wk.m.inRange(p.m) && wk.a.inRange(p.a) && wk.s.inRange(p.s)){
			return wk.r;
		}
		return "";
};

map<string, vector<Workflow>> w;
vector<Part> parts;
string getPile(Part p, string cur){
	cout<<cur<<endl;
	for(const auto& wrk : w[cur]){
		string out = proc(wrk, p);
		if(out == "A") return "A";
		if(out == "R") return "R";
		if(out == "") continue;
		return getPile(p, out);
	};	
}
int main(int argc, char* argv[]){
	vector<string> lines = getlines(argv[1]);
	for(const auto& l : lines){
		if(l.size() == 0) continue;
		if(l[0] != '{'){
			string name = split(l, "{")[0];
			string rest = split(l, "{")[1].substr(0, split(l, "{")[1].size()-1);
			vector<Workflow> wr;

			vector<string> z = split(rest,",");
			for(int i =0; i < z.size(); i++){
				cout<<z[i]<<endl;
			}
			
			for(int i = 0; i < z.size(); i++){
				string wz = z[i];
				Workflow wrk;
				if(wz.find(':') == std::string::npos){
					wrk.r = wz;
					wr.push_back(wrk);
					continue;
				}
				wrk.r = split(wz, ":")[1];	
				string prim = split(wz, ":")[0].substr(0, 2);
				int r = stoi(split(wz, ":")[0].substr(2));
					if(prim == "a>"){
						wrk.a.l = r;
						};
					if(prim == "a<"){
						wrk.a.u = r;
						};
					if(prim == "m>"){
						wrk.m.l = r;
						};
					if(prim == "m<"){
						wrk.m.u = r;
						};
					if(prim == "x>"){
						wrk.x.l = r;
						};
					if(prim == "x<"){
						wrk.x.u = r;
						};
					if(prim == "s<"){
						wrk.s.l = r;
						};
					if(prim == "s>"){
						wrk.s.u = r;
						};
				wr.push_back(wrk);
			};
			cout<<name<<endl;
			w[name] = wr;
		}
		else{
			string rl = l.substr(1, l.size()-2);
			vector<string> nstr = split(rl, ",");
			Part p;
			p.x = stoi(nstr[0].substr(2));
			p.m = stoi(nstr[1].substr(2));
			p.a = stoi(nstr[2].substr(2));
			p.s = stoi(nstr[3].substr(2));
			parts.push_back(p);
		};
		
	}
	cout<<"P"<<endl;
	int sum = 0;
		for(const auto& p: parts){
			cout<<p.x<<" "<<p.m<<" "<<p.a<<" "<<p.s<<" "<<getPile(p, "in")<<endl;
			if(getPile(p, "in") == "A"){
				sum += p.x + p.a + p.m + p.s;
			}	
		}
		cout<<sum<<endl;
	return 0;

}
