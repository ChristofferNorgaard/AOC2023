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
int main(int argc, char* argv[]){
	vector<string> hsh = split(getlines(argv[1])[0], ",");
	int sum = 0;
	for(const auto& s: hsh){
		sum += sh(s);
	}
	cout<<sum<<endl;
	return 0;
}
