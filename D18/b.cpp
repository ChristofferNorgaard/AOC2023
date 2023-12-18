#include <bits/stdc++.h>
#include "../aoc.h"

using namespace std;
struct Point
{
	long long x;
	long long y;
};
Point makePoint(long long x, long long y){
	Point p;
	p.x = x;
	p.y = y;
	return p;
}
vector<Point> p;
long long polygonArea(vector<Point> p)
{
    // Initialize area
    long long area = 0.0;
 
    // Calculate value of shoelace formula
    long long j = p.size() - 1;
    for (long long i = 0; i < p.size(); i++)
    {
        area += (p[j].x + p[i].x) * (p[j].y - p[i].y);
        j = i;  // j is previous vertex to i
    }
 
    // Return absolute value
    return abs(area / 2);
}
int main(int argc, char* argv[]){
	vector<string> lines = getlines(argv[1]);
	Point cur = makePoint(0, 0);
	p.push_back(cur);
	long long sum = 0;
	for(const auto& l: lines){
		long long amount = stoi("0x" + split(l, " ")[2].substr(2, 5), 0, 16);
		cout<<split(l, " ")[2].substr(2, 5)<<endl;
		sum += amount;
		switch(split(l, " ")[2][7]){
			case '1':
				cur.y += amount;
				break;
			case '3':
				cur.y -= amount;
				break;
			case '2':
				cur.x += amount;
				break;
			case '0':
				cur.x -= amount;
				break;
		}
		p.push_back(cur);
	}
	cout<<polygonArea(p)+sum/2 + 1<<endl;
	return 0;
}
