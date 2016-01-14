#include "Dictionary.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <string>



ComplexDictionary::ComplexDictionary() {
	size = 0;
}

ComplexDictionary::ComplexDictionary(string name) {
	string buffer;
	cin >> buffer;
	size = atoi(buffer.c_str());

	build(name);
}

int ComplexDictionary::size(){
	return words.size();
}

static void ComplexDictionary::build(string name) {
	string buffer;
	while (cin >> buffer) {
		size_t index = -1;
		if (buffer.find("//") != string::npos) {
			if (index = buffer.find("&")) {
				reversal(buffer);
			}
			else if (index = buffer.find("[")) {
				size_t endIndex = buffer.find("]");
				insertEach(buffer, index, endIndex);
			}
			else if (index = buffer.find("?")) {
				optional(buffer, index);
			}
			else if (index = buffer.find("!")) {
				swap(buffer, index);
			}
			else
				words.push_back(buffer);
		}
	}

	reverse(words.begin(), words.end());
}


void ComplexDictionary::reversal(string word) {
	string temp = word.substr(0, word.size - 1); //remove ampersand
	string revTemp = temp;
	reverse(revTemp.begin(), revTemp.end());

	words.push_back(temp);
	words.push_back(revTemp);
}

void ComplexDictionary::insertEach(string word, size_t begin, size_t end) {
	vector<string> insertChars;
	string temp = word;
	while (begin != end) { //add all characters between [] to vector insertChars
		insertChars.push_back(temp.substr(begin, 1));
		begin++;
	}

	//if order in dictionary matters
	reverse(insertChars.begin(), insertChars.end());
	
	//inclusive or exclusive end?
	string beginning = word.substr(0, begin);
	//inclusive or exclusive end?
	string ending = word.substr(end, word.length() - end);


	for(int i = 0; i < insertChars.size(); i++) {
		temp = beginning;
		temp.append(insertChars[i]);
		temp.append(ending);
		words.push_back(temp);
	}
}

void ComplexDictionary::optional(string word, size_t charIndex) {
	string temp = word;
	temp.erase(charIndex);
	words.push_back(temp);
	temp = word;
	temp.erase(charIndex - 1, charIndex);

	words.push_back(temp);
}

void ComplexDictionary::swap(string word, size_t charIndex) {
	string temp = word;
	temp.erase(charIndex);

	words.push_back(temp);

	temp = word;
	char a = temp[charIndex - 2];
	char b = temp[charIndex - 1];
	temp[charIndex - 1] = a;
	temp[charIndex - 2] = b;
	temp.erase(charIndex);

	words.push_back(temp);
}
