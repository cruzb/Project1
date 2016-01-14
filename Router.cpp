#include "Router.h"
#include <cstdlib>

Router::Router(bool changeIn, bool swapIn, bool lengthIn, bool wordIn,
			const string startIn, const string endIn, Dictionary* dictIn) :
			change(change), swap(swapIn), length(lengthIn), word(wordIn), start(startIn), end(endIn), dict(dictIn)
{
	stack.push(start);
}

Router::~Router(){
}




void Router::solve() {
	string word = start;
	bool loop = true;

	morph.push_back(word);

	while(!deque.empty() && loop){
		for(int i = 0; i < dict->size(); i++){
			if(change){
				if(canChange(word, dict->getWord(i))){
					if(dict->getWord(i) == end)
						loop = false;

					deque.push(dict->getWord(i));
					dict->delWord(i);
				}
			}

			else if(swap){
				if(canSwap(word, dict->getWord(i))){
					if(dict->getWord(i) == end)
						loop = false;

					deque.push(dict->getWord(i));
					dict->delWord(i);
				}
			}

			else if(length){
				if(canLength(word, dict->getWord(i))){
					if(dict->getWord(i) == end)
						loop = false;

					deque.push(dict->getWord(i));
					dict->delWord(i);
				}
			}
				
		}

		if(stack){
			word = deque.back(); //set word as word from top of stack
			deque.pop_back(); //delete top word of stack
		}
		else{
			word = deque.front(); //set word as word from front of queue
			deque.pop_front(); //delete word at front of queue
		}	
		morph.push_back(word); //add to list of words in morph
		
	}

	//either the end word is found or does not exist


	//print the path
	if(word){
		cout << "Words in morph: " << morph.size() << endl;
		for(vector<int>::iterator it = morph.begin(); it != morph.end(); it++){
			cout << it* << endl;
		}
	}
	else{
		cout << "Words in morph: " << morph.size() << endl;
		for(vector<int>::iterator it = morph.begin(); it != morph.end(); it+=3){
			cout << it* << "," << (it+1)* << "," << (it+2)* << endl;
		}
	}

	

}



bool Router::canChange(string a, string b) {
	if (a.length() != b.length())
		return false;

	int different = 0;
	int index = -1;
	for (unsigned int i = 0; i < a.length(); i++) {
		if (a[i] != b[i]){
			different++;
			index = i;
		}
	}

	if(different == 1){

		if(!word){//if we are not printing in word form, and thus printing modification form
			words.push_back("c");
			words.push_back(to_string(index));
			words.push_back(b[i]);
		}
		return true;
	}
	else return false;
}



bool Router::canSwap(string a, string b) {
	if(a.length() != b.length())
		return false;

	int different = 0;
	vector<int> indexes;
	vector<char> characters;
	for (unsigned int i = 0; i < a.length(); i++) {
		if(a[i] != b[i]){
			different++;
			indexes.push_back(i);
			characters.push_back(a[i]);
			characters.push_back(b[i]);
		}
	}
	if(different != 2)
		return false;

	assert(indexes.size() == 2);//ensure that 2 char indexes were stored
	//if the two indexes are not next to each other return false
	if(!(indexes[0] - indexes[1] == 1 || indexes[0] - indexes[1] == -1))
		return false;

	//if the two different characters are the same 
	if ((characters[0] == characters[3]) && (characters[1] == characters[2])){

		if(!word){//if we are not printing in word form, and thus printing modification form
			words.push_back("s");
			words.push_back(to_string(indexes[0]));
		}
		return true;
	}
	else return false;
}



bool Router::canLength(string a, string b) {
	if (!(abs((int)(a.length() - b.length())) == 1))
		return false;
		
	int index = -1;

	assert(abs((int)(a.length() - b.length())) == 1);
	unsigned int count = 0;
	if (a.length() < b.length()) {//if a is smaller than b
		for (unsigned int i = 0; i < a.length(); i++) {
			index = b.find(a[i]);
			if (index != string::npos) //if all characters from a are in b
				count++;
		}
		if (count == a.length()){
			if(!word){//if we are not printing in word form, and thus printing modification form
				words.push_back("i");
				words.push_back(index);
				words.push_back(b[index]);
			}
			return true;
		}
		else return false;
	}
	else {//if b is smaller than a
		for (unsigned int i = 0; i < b.length(); i++) {
			index = a.find(b[i]);
			if (index != string::npos) // if all characters from b are in a
				count++;
		}
		if (count == b.length()){
			if(!word){//if we are not printing in word form, and thus printing modification form
				words.push_back("d");
				words.push_back(index);
			}
			return true;
		}
		else return false;
	
	}
}