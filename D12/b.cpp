#include <bits/stdc++.h>
#include "../aoc.h"

using namespace std;

long long mem[200][200][200][3];
vector<int> d;
string c;
long long prc(long long cur, long long i, long long q, long long rep=0){
	//cout<<cur<<" "<<i<<" "<<q<<endl;
	char ci = (rep == 0)? c[cur] : (rep == 1)? '#' : '.';
	if(mem[cur][i][q][rep] != -1) return mem[cur][i][q][rep];
	if(cur == c.size() && q == d.size()){ 
		return mem[cur][i][q][rep] = 1;
	}
	if(cur == c.size()){
		return mem[cur][i][q][rep] = 0;
	}
	if(ci == '#'){
		return mem[cur][i][q][rep] = prc(cur+1, i+1, q);
	}
	if(ci == '.'){
		if(i == 0){
			return mem[cur][i][q][rep] = prc(cur+1, i, q);
		}
		if(q >= d.size()) return 0;
		if(i == d[q]){
			return mem[cur][i][q][rep] = prc(cur+1, 0, q+1);
		}
		else{
			return mem[cur][i][q][rep] = 0;
		}
	}
	if(ci == '?'){
		return mem[cur][i][q][rep] = (prc(cur, i, q, 1)+ prc(cur, i, q, 2)); 
	}
	return mem[cur][i][q][rep] = 0;
	
}
int main(int argc, char* argv[]){
	long long sum = 0;
	for(const auto& line: getlines(argv[1])){
		memset(mem, -1, sizeof(long long)*200*200*200*3);
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
		
	}
	cout<<sum<<endl;
	return 0;
}
