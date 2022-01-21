#include "Solution.h"

vector<int> Solution0::findSubstring(string s, vector<string>& words) {

	unordered_set<string> unique_words {words.begin(), words.end() };
	//cout << unique_words.size() << " " << words.size() << endl;
	size_t combination_variants = words.size() * 2 + 1;

	unordered_set<int> outputSet{};
	size_t wordItr = 0, i = 0, shift = 0;
	string::size_type findIndex;

	while (wordItr < words.size()) {

		while(true) {
			if(unique_words.size() <= 2) findIndex = s.find(words[wordItr], i++);
			else findIndex = s.find(words[wordItr], shift);
			//findIndex = s.find(words[wordItr], i++);

			if (findIndex != string::npos) {
				shift = findIndex + words[wordItr].length();
				string lastString = s.substr(shift);
				vector<string> lastWords = words;
				
				if (lastWords.size() > 1) {
					lastWords.erase(lastWords.begin() + wordItr);
					if (checkAll(lastString, lastWords, combination_variants))
						outputSet.insert(findIndex);
				}
				else outputSet.insert(findIndex);
			}
			else break;
		} 
		shift = 0;
		i = 0;
		wordItr++;
	}
	vector<int> outputVector{ outputSet.begin(), outputSet.end() };
	return outputVector;
}

bool Solution0::checkAll(string s, vector<string> words, size_t deepth) {
	if (words.empty() || deepth == 0) return false;
	
	bool result = false;

	if (s.find(words[0]) == 0) {

		vector<string> lastWords = words;
		lastWords.erase(lastWords.begin());
		string lastString = s.substr(words[0].length());

		//cout << "Iter Function/Found: " << words[0] << " lastString: " << lastString << endl;
		//for_each(lastWords.begin(), lastWords.end(), [](string s) {cout << s << endl; });

		if (words.size() == 1) return true;

		deepth--;
		result = checkAll(lastString, lastWords, deepth);
	}
	else {
		vector<string> lastWords = words;
		rotate(lastWords.begin(), lastWords.begin() + 1, lastWords.end());
		deepth--;
		result = checkAll(s, lastWords, deepth);
	}
		
	return result;
	
}