#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <set>

using namespace std;

class RestrictedString {
private:
    string allowedChars; // Set of allowed characters
    string content;      // The actual string content

    // Helper: Check if a character is in the allowed set
    bool isAllowed(char c) const {
        return allowedChars.find(c) != string::npos;
    }

    // Helper: Filter a string leaving only allowed characters
    string filterString(const string& raw, const string& allowed) const {
        string result = "";
        for (char c : raw) {
            if (allowed.find(c) != string::npos) {
                result += c;
            }
        }
        return result;
    }

public:
    // Constructor: Define allowed characters initially
    RestrictedString(string allowed) : allowedChars(allowed), content("") {}

    // Constructor: Allowed chars + Initial content
    RestrictedString(string allowed, string initContent) : allowedChars(allowed) {
        // Validate initial content
        for (char c : initContent) {
            if (!isAllowed(c)) {
                throw invalid_argument("Constructor Error: Character '" + string(1, c) + "' is not allowed.");
            }
        }
        content = initContent;
    }

    // Getters
    size_t length() const { return content.length(); }
    string getValue() const { return content; }
    string getAllowed() const { return allowedChars; }

    // --- Modifying Allowed Characters ---

    void addAllowedChar(char c) {
        if (allowedChars.find(c) == string::npos) {
            allowedChars += c;
        }
    }

    void removeAllowedChar(char c) {
        size_t pos = allowedChars.find(c);
        if (pos != string::npos) {
            allowedChars.erase(pos, 1);
            // Re-validate content: remove the character from current string too
            content = filterString(content, allowedChars);
        }
    }

    // --- I/O Overloading (Console & File) ---
    // Works for both cin/cout and fstream because they inherit from istream/ostream

    friend ostream& operator<<(ostream& os, const RestrictedString& rs) {
        os << rs.content;
        return os;
    }

    friend istream& operator>>(istream& is, RestrictedString& rs) {
        string input;
        is >> input;
        
        // Validate input immediately
        for (char c : input) {
            if (rs.allowedChars.find(c) == string::npos) {
                // Determine if we should throw or set failbit. 
                // Task says "initiate error", so throwing is explicit.
                throw runtime_error("Input Error: Character '" + string(1, c) + "' is not in the allowed set.");
            }
        }
        rs.content = input;
        return is;
    }

    // --- Concatenation ---
    // Rule: New Allowed = Intersection of allowed sets.
    // Result string = (String1 + String2) filtered by New Allowed.
    RestrictedString operator+(const RestrictedString& other) const {
        // 1. Find Intersection of allowed chars
        string newAllowed = "";
        for (char c : this->allowedChars) {
            if (other.allowedChars.find(c) != string::npos) {
                newAllowed += c;
            }
        }

        // 2. Create new object
        RestrictedString result(newAllowed);

        // 3. Concatenate raw strings and filter strictly by new intersection
        string combinedRaw = this->content + other.content;
        result.content = filterString(combinedRaw, newAllowed);

        return result;
    }

    // --- Hash Function ---
    // Simple polynomial rolling hash
    size_t getHash() const {
        size_t hash = 0;
        size_t p = 31;
        size_t m = 1e9 + 9;
        size_t p_pow = 1;
        
        for (char c : content) {
            hash = (hash + (c - 'a' + 1) * p_pow) % m;
            p_pow = (p_pow * p) % m;
        }
        return hash;
    }
};

int t17_9() {
    try {
        cout << "--- Test 1: Construction & Input ---" << endl;
        // Allowed: a, b, c. Input: "abc" -> OK
        RestrictedString s1("abc");
        cout << "Enter string (allowed: abc): "; 
        // Note: If you enter 'd' here, it will crash/catch exception.
        // For demonstration, let's manually set it or try-catch input.
        try {
            cin >> s1; 
            cout << "You entered: " << s1 << endl;
        } catch (const exception& e) {
            cerr << e.what() << endl;
            // Fallback for the rest of the demo
            s1 = RestrictedString("abc", "aba"); 
            cout << "Fallback set to: " << s1 << endl;
        }

        cout << "\n--- Test 2: Concatenation with Intersection ---" << endl;
        // S1 allowed: "abc", content: "aba"
        // S2 allowed: "bcd", content: "bcb"
        // Intersection allowed: "bc"
        // Raw concat: "ababcb"
        // Filtered by "bc": "bbcb" (removes 'a')
        
        RestrictedString s2("bcd", "bcb");
        cout << "S1 (" << s1.getAllowed() << "): " << s1 << endl;
        cout << "S2 (" << s2.getAllowed() << "): " << s2 << endl;

        RestrictedString s3 = s1 + s2;
        
        cout << "Result S3 (S1 + S2):" << endl;
        cout << "  Allowed: " << s3.getAllowed() << endl;
        cout << "  Content: " << s3 << endl;
        cout << "  Length:  " << s3.length() << endl;
        cout << "  Hash:    " << s3.getHash() << endl;

        cout << "\n--- Test 3: Modifying Allowed Chars ---" << endl;
        // Remove 'b' from S3. S3 was "bbcb" (if S1 was "aba"). 
        // Allowed was "bc". New allowed "c". Content becomes "c".
        cout << "Removing 'b' from S3..." << endl;
        s3.removeAllowedChar('b');
        cout << "S3 Content: " << s3 << endl;
        cout << "S3 Allowed: " << s3.getAllowed() << endl;

        cout << "\n--- Test 4: File I/O ---" << endl;
        ofstream outfile("task9_test.txt");
        outfile << s3; // Uses overloaded <<
        outfile.close();
        cout << "Written S3 to file 'task9_test.txt'." << endl;

        ifstream infile("task9_test.txt");
        RestrictedString s4("c"); // Must have compatible allowed chars to read successfully
        infile >> s4; // Uses overloaded >>
        cout << "Read from file: " << s4 << endl;
        infile.close();

    } catch (const exception& e) {
        cerr << "CRITICAL ERROR: " << e.what() << endl;
    }

    return 0;
}