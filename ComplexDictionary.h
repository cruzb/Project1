#pragma once
#include "Dictionary.h"

class ComplexDictionary : public Dictionary
{
public:
	ComplexDictionary();

	ComplexDictionary(string name);

	~ComplexDictionary();


private:
	vector<string> words;
	int size;
	
};