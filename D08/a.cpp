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

map<string, Dirs> m;
	
int main(int argc, char* argv[]){
	vector<string> file = getlines(argv[1]);
	string dirs = file[0];
	for(int i = 2; i < file.size(); i++){
		string line = file[i];
		string name = line.substr(0,3);
		string left = line.substr(7,3);
		string right = line.substr(12, 3);
		m[name] = makeDir(left, right);
		cout<<name<<" "<<left<<" "<<right<<endl;
	}

	string cur = "AAA";
	int steps = 0;
	while(cur != "ZZZ"){
		if(dirs[steps % (int)dirs.size()] == 'L') cur = m[cur].left;	
		else cur = m[cur].right;
		steps++;
	}
	cout<<steps<<endl;
	return 0;
}
