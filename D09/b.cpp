#include <bits/stdc++.h>
#include "../aoc.h"

using namespace std;
int next(vector<int> vec){
	if(count(vec.begin(), vec.end(), 0) == vec.size()) return 0;
	vector<int> nvec;
	for(int i = 1; i < vec.size(); i++){
		nvec.push_back(vec[i] - vec[i-1]);
	}
	return vec[0] - next(nvec);
}
int main(int argc, char* argv[]){
	int sum = 0;
	for(auto const& line: getlines(argv[1])){
		sum += next(getSepInt(line));
	}
	cout<<sum<<endl;
	return 0;

}
