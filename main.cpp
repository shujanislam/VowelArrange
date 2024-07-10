#include<iostream>
#include<vector>
#include<string>

using namespace std;

void result(int word_len, int vowel_len){
	int fact = 1;
	int vowel_fact = 1;

	for(int i = 1; i <= word_len; i++){
		fact *= i;
	}

	for(int j = 1; j <= vowel_len; j++){
		vowel_fact *= j; 
	}

	int solution = fact * vowel_fact;

	cout<<"Number of ways to arrange the letters of the word(keeping the vowels together): "<<solution<<endl;
}

int main(){
	bool isVowel;
	char name[6];
	char vowel[] = {'a', 'e', 'i', 'o', 'u'};
	string new_word[10];
	int new_word_index = 0;

	string vowel_bind;

	int len = sizeof(name)/sizeof(name[0]);
	int vowel_len = sizeof(vowel)/sizeof(vowel[0]);

	cout<<"Enter a 6 letter word: "<<endl;

	for(int x = 0; x < 6; x++){
		cout<<"Letter ("<<(x+1)<<"): ";
		cin>>name[x];
	}

	for(int i = 0; i < len; i++){
		isVowel = false;
		for(int j = 0; j < vowel_len; j++){
			if(vowel[j] == name[i]){
				vowel_bind += name[i];
				isVowel = true;
			}		
		}

		if(!isVowel){
			new_word[new_word_index] = name[i];
			new_word_index++;
		}
	}

	new_word[new_word_index] += vowel_bind;
	new_word_index++;

	int vowel_bind_len = vowel_bind.length();

	result(new_word_index, vowel_bind_len);
	return 0;
}
