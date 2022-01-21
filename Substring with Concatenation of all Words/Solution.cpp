#include "Solution.h"

vector<int> Solution::findSubstring(string s, vector<string>& words) {
	
	vector<string>::iterator wordsIterator = words.begin();

	string::size_type currentFind;

	string_view strView = s;

	string::size_type indexFind, cutedLength = 0, firstIndex;
	
	vector<int> output;

	vector<pair<int, int>> pairInidices;

	while(wordsIterator != words.end()) {
		string::size_type wordLength = (*wordsIterator).size();
		
		 do {
			indexFind = strView.find(*wordsIterator, cutedLength);

			if (indexFind != string::npos) {
				//strView = string_view(strView.begin() + indexFind + wordLength, strView.end());
				
			}
			else break;
			 
			firstIndex = cutedLength + indexFind;
			pairInidices.emplace_back(firstIndex, firstIndex + wordLength - 1);
			cout << firstIndex << " " << firstIndex + wordLength - 1 << endl;

			output.push_back(cutedLength + indexFind);
			cutedLength += indexFind + wordLength;

			//currentFind = indexFind;
			//cout << *wordsIterator << "  " << currentFind << endl;
			
		 } while (true);

					
		 wordsIterator++;
		 strView = s;
		 cutedLength = 0;
	}

	
	return output;
	//return *(new vector<int> { 777 });
}
