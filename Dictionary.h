#pragma once

using namespace std;

class Dictionary{
public:

	Dictionary();

	string getWord(int i);
	
	void addWord(string word);

	void delWord(int i);

	virtual int size();

	~Dictionary();

};

