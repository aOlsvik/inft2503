//
// Created by Aleksander Olsvik on 19.09.2023.
//

#include "string"
#include "iostream"

using namespace std;

int main() {
    string word1, word2, word3;

    cout << "Type three words to build a sentence!" << endl;

    cin >> word1;
    cin >> word2;
    cin >> word3;


    string sentence = word1 + " " + word2 + " " + word3 + ".";

    cout << "Here's your sentence: " << sentence << endl;

    cout << "Length of word 1: " << word1.length() << endl;
    cout << "Length of word 2: " << word2.length() << endl;
    cout << "Length of word 3: " << word3.length() << endl;
    cout << "Lenght of the new sentence: " << sentence.length() << endl;

    string sentence2 = sentence;
    int end = std::min(12, static_cast<int>(sentence.length()));

    for(int i = 9; i<end; i++){
        sentence2[i] = 'x';
    }

    cout << "Altered position 10-12 of the sentence:" << endl;
    cout << "Original sentence: " << sentence << endl;
    cout << "Altered sentence: " << sentence2 << endl;

    int sentence_start_length = min(5, static_cast<int>(sentence.length()));
    string sentence_start = sentence.substr(0,sentence_start_length);

    cout << "The first 5 (max) signs of the sentence: " << sentence_start << endl;
    bool contains_hello = sentence.find('hello') != string::npos;
    cout << "Sentence contains 'hello': " << boolalpha << contains_hello << endl;

    string find_str("er");

    size_t occurrence = sentence.find(find_str);
    int count = 0;

    while(occurrence != string::npos){
        count++;
        occurrence = sentence.find(find_str, occurrence + 1);
    }

    if (count > 0) {
        std::cout << "The substring '" << find_str << "' was found " << count << " times." << endl;
    } else {
        std::cout << "The substring '" << find_str << "' was not found." << endl;
    }

}
