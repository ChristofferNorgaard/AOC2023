#include <bits/stdc++.h>
#include "../aoc.h"

using namespace std;
struct Dirs{
	string left;
	string right;
};
Dirs makeDir(string left, string right){
	Dirs d;
	d.left = left;
	d.right = right;
	return d;
}

int gcd(int n1, int n2){
	if(n2 == 0) return n1;
	return gcd(n2, n1%n2);
}
map<string, Dirs> m;
	
int main(int argc, char* argv[]){
	vector<string> file = getlines(argv[1]);
	string dirs = file[0];
	vector<string> names;
	map<string, int> cycle;
	map<string, int> remainder;
	for(int i = 2; i < file.size(); i++){
		string line = file[i];
		string name = line.substr(0,3);
		string left = line.substr(7,3);
		string right = line.substr(12, 3);
		m[name] = makeDir(left, right);
		names.push_back(name);
		cout<<name<<" "<<left<<" "<<right<<endl;
	}

	for(auto const& name: names){	
		if(name[2] == 'Z'){ 
		string cur = name;
		int steps = 0;
		while(cur != name || steps == 0){
			if(dirs[steps % (int)dirs.size()] == 'L') cur = m[cur].left;	
			else cur = m[cur].right;
			steps++;
		}
		cycle[name] = steps;
		}
		else if(name[2] == 'A'){
		string cur = name;
		int steps = 0;
		while(cur[2] != 'Z'){
			if(dirs[steps % (int)dirs.size()] == 'L') cur = m[cur].left;	
			else cur = m[cur].right;
			steps++;
		}
		remainder[cur] = steps;
		}
	}
	long long lcm = -1;
	for(auto const& name: names){
		if(name[2] != 'Z') continue;
		if(lcm == -1) lcm = cycle[name];
		long long gcd_valc = gcd(lcm, cycle[name]);
		lcm = (lcm * cycle[name]) / gcd_valc;
	}
	cout<<lcm<<endl;
	return 0;
}
