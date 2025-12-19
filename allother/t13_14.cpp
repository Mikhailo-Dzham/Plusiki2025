#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int count_substrings(const string& text, const string& sub) {
    if (sub.empty()) return 0;
    int count = 0;
    size_t pos = text.find(sub);
    while (pos != string::npos) {
        count++;
        pos = text.find(sub, pos + 1);
    }
    return count;
}

int count_words(const string& text, const string& target_word) {
    stringstream ss(text);
    string word;
    int count = 0;
    // Extract by whitespace to find exact word matches
    while (ss >> word) {
        if (word == target_word) {
            count++;
        }
    }
    return count;
}

int t13_14() {
    // Hardcoded data
    string text = "apple pineapple applepie apple red apple";
    string target_word = "apple"; // Exact word
    string target_sub = "apple";  // Substring (inside pineapple, etc)

    cout << "Text: " << text << endl;
    
    // 1. Count exact words
    int w_count = count_words(text, target_word);
    cout << "Word '" << target_word << "' count: " << w_count << endl;

    // 2. Count substrings
    int s_count = count_substrings(text, target_sub);
    cout << "Substring '" << target_sub << "' count: " << s_count << endl;

    return 0;
}