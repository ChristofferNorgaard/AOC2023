#include <bits/stdc++.h>
#include "../aoc.h"

using namespace std;

int main(int argc, char* argv[]){
	vector<string> line = getlines(argv[1]);
	vector<long long> time = getSepLong(line[0]);
	vector<long long> distance = getSepLong(line[1]);
	long long r = 1;
	for(long long y = 0; y < time.size(); y++){
		long long n = 0;
		for(long long i = 0; i <= time[y]; i++){
			n += distance[y] < i*(time[y] - i);
		}
		r *= n;
	}
	cout<<r<<endl;
	return 0;
}
