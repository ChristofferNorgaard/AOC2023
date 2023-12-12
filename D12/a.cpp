#include <bits/stdc++.h>
#include "../aoc.h"

using namespace std;
int prc(string c, int i, queue<int> d){
	//cout<<c<<" "<< i <<" " << d.front()<<endl;
	if(c.size() == 0 && d.empty()){
		return 1;
	}
	if(c.size() == 0){
		return 0;
	}
	if(c[0] == '#'){
		return prc(c.substr(1), i+1, d);
	}
	if(c[0] == '.'){
		if(i == 0){
			return prc(c.substr(1), i, d);
		}
		if(d.empty()) return 0;
		if(i == d.front()){
			d.pop();	
			return prc(c.substr(1), 0, d);
		}
		else{
			return 0;
		}
	}
	if(c[0] == '?'){
		string a = c;
		string b = c;
		a[0] = '.';
		b[0] = '#';
		return prc(a, i, d) + prc(b, i, d);
	}
	return 0;
	
}
int main(int argc, char* argv[]){
	int sum = 0;
	for(const auto& line: getlines(argv[1])){
		string con = split(line, " ")[0];
		con += '.';
		vector<int> lens = getSepInt(split(line, " ")[1], ","); 
		queue<int> d; 
		for(const auto& l: lens){
			//cout<<l<<" ";
			d.push(l);
		};
		//cout<<endl;
		sum += prc(con, 0, d);
		
	}
	cout<<sum<<endl;
	return 0;
}
