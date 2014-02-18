
//	Christian Davis
//	2/15/2014
//	CSUF ACM icpc practice

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string inputline,word;
	char c;

	while (cin){

		getline(cin, inputline);
		
		//copy only characters into the string word
		word.clear();
		for (int i = 0; i < inputline.length(); i++){
			c = inputline[i];
			if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
				word.push_back(c);
		}
		
		//convert to lower case
		transform(word.begin(), word.end(), word.begin(), ::tolower);

		//check if we hit the last line, end the program 
		if (word == "done"){
			return 0;
		}

		//establish the middle
		int M = word.length() / 2;
		if (word.length() % 2 > 0)
			M+=1;

		//compare the word from both ends
		bool is_a_palindrome = true;
		for (int i = 0, z = word.length()-1; i < z; i++, z--){
			if (word[i] == word[z])
				continue;
			else {
				is_a_palindrome = false;
				break;
			}
		}
		if (is_a_palindrome){
			cout << "You won't be eaten!"<<endl;
		}else{
			cout << "Uh oh.." << endl;
		}

	}
	
	return 0;
}