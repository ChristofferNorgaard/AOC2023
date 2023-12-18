#include <bits/stdc++.h>
#include "../aoc.h"

using namespace std;
struct Point
{
	int x;
	int y;
};
Point makePoint(int x, int y){
	Point p;
	p.x = x;
	p.y = y;
	return p;
}
vector<Point> p;
double polygonArea(vector<Point> p)
{
    // Initialize area
    double area = 0.0;
 
    // Calculate value of shoelace formula
    int j = p.size() - 1;
    for (int i = 0; i < p.size(); i++)
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
	int sum = 0;
	for(const auto& l: lines){
		char amount = stoi(split(l, " ")[1]);
		sum += amount;
		switch(l[0]){
			case 'D':
				cur.y += amount;
				break;
			case 'U':
				cur.y -= amount;
				break;
			case 'L':
				cur.x += amount;
				break;
			case 'R':
				cur.x -= amount;
				break;
		}
		p.push_back(cur);
	}
	cout<<polygonArea(p)+sum/2 + 1<<endl;
	return 0;
}
