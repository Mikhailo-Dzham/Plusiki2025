#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

// Helper to read words from file into a set
set<string> loadWords(const string& filename) {
    set<string> words;
    ifstream file(filename);
    string word;
    if (file.is_open()) {
        while (file >> word) {
            words.insert(word);
        }
    }
    return words;
}

int t20_8() {
    // Create dummy files
    ofstream f1("file1.txt"); f1 << "apple banana orange grape"; f1.close();
    ofstream f2("file2.txt"); f2 << "banana kiwi apple lemon"; f2.close();

    // 1. Load data
    set<string> set1 = loadWords("file1.txt");
    set<string> set2 = loadWords("file2.txt");

    // Vectors to store results
    vector<string> commonWords;
    vector<string> diffWords;

    // 2. Find Intersection (Common words)
    set_intersection(set1.begin(), set1.end(),
                     set2.begin(), set2.end(),
                     back_inserter(commonWords));

    // 3. Find Symmetric Difference (Words not in common)
    set_symmetric_difference(set1.begin(), set1.end(),
                             set2.begin(), set2.end(),
                             back_inserter(diffWords));

    // 4. Output Results
    cout << "--- File 1 Content: ";
    for(const auto& w : set1) cout << w << " ";
    cout << endl;

    cout << "--- File 2 Content: ";
    for(const auto& w : set2) cout << w << " ";
    cout << endl << endl;

    cout << "1. Common Words (Intersection): ";
    for (const auto& w : commonWords) cout << w << " ";
    cout << endl;

    cout << "2. Unique Words (Symmetric Difference): ";
    for (const auto& w : diffWords) cout << w << " ";
    cout << endl;

    return 0;
}