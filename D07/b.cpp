#include <bits/stdc++.h>
#include "../aoc.h"

using namespace std;
string order = "J23456789TQKA";
struct Hand {
	int bid;
	string h;
	vector<int> cards;
};

int isFive(Hand h){
	if(h.cards[0] == 5) return 6;	
	if(h.cards[0] == 4) return 5;
	if(h.cards[0] == 3 && h.cards[1] == 2) return 4;
	if(h.cards[0] == 3) return 3;
	if(h.cards[0] == 2 && h.cards[1] == 2) return 2;
	if(h.cards[0] == 2) return 1;
	return 0;
}

Hand makehand(string s, int b){
	cout<< s;
	Hand h;
	h.bid = b;
	h.h = "";
	for(int i = 1; i < 13; i++){
		h.cards.push_back(count(s.begin(), s.end(), order[i]));
	}
	sort(h.cards.begin(), h.cards.end(), greater<int>());
	h.cards[0] += count(s.begin(), s.end(), 'J');
	h.h = to_string(isFive(h));
	cout << " " << h.h;
	for(const char& c: s){
		h.h += 'A' + (char)order.find(c);	
	}
	cout<<endl;
	return h;
}

bool handsorter(Hand const& h1, Hand const& h2){
	return h1.h < h2.h;
}
int main(int argc, char* argv[]){
	ifstream infile(argv[1]);
	vector<Hand> hands;
	string a; 
	int b;
	while (infile >> a >> b){
		hands.push_back(makehand(a, b));
	}
	sort(hands.begin(), hands.end(), &handsorter);
	int r = 0;
	for(int i = 0; i < hands.size(); i++){
		cout<<hands[i].h<<" "<<hands[i].bid<<endl;
		r += hands[i].bid*(i+1);
	}
	cout<<r<<endl;
	return 0;
}
