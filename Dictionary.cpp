#include "Dictionary.h"



Dictionary::SimpleDictionary() {

}

string Dictionary::getWord(int i) {
	return words[i];
}

void Dictionary::addWord(string word) {
	words.push_back(word);
}

string Dictionary::delWord(int i) {
	words.erase(i);
}

~Dictionary() {
}