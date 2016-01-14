#pragma once
#include <vector>
#include <string>
#include <cassert>

using namespace std;

class Router
{
public:
	Router();

	~Router();

	void solve();

private:
	bool change;
	bool swap;
	bool length;
	bool word;
	string start;
	string end;
	Dictionary* dict;
	deque<string> deque;
	vector<string> morph;



	bool canChange(string a, string b);

	bool canSwap(string a, string b);

	bool canLength(string a, string b);
};

