#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Template class "MyString" where 'T' is the type of "symbol"
template <typename T>
class MyString {
private:
    vector<T> data;
    T separator;

public:
    // Constructor
    MyString(T sep) : separator(sep) {}

    // Add symbol to the string
    void add(T symbol) {
        data.push_back(symbol);
    }

    // 2. Set/Change Separator
    void setSeparator(T sep) {
        separator = sep;
    }

    // 4. Length of string
    size_t length() const {
        return data.size();
    }

    // 6. Access by index []
    T& operator[](int index) {
        if (index < 0 || index >= data.size()) {
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }

    // 7. Delete specific symbol (by value)
    void removeSymbol(T val) {
        // Erase-remove idiom
        auto it = data.begin();
        while (it != data.end()) {
            if (*it == val) {
                it = data.erase(it);
            } else {
                ++it;
            }
        }
    }

    // 3. Concatenation: returns new object {this->data + separator + other->data}
    MyString<T> operator+(const MyString<T>& other) const {
        MyString<T> result = *this;
        
        // Logic: Add separator between the two strings if both are non-empty
        if (!result.data.empty() && !other.data.empty()) {
            result.add(separator);
        }

        for (const T& item : other.data) {
            result.add(item);
        }
        return result;
    }

    // 5. Merge symbols -> Convert array to single std::string
    string merge() const {
        stringstream ss;
        for (size_t i = 0; i < data.size(); ++i) {
            ss << data[i];
            // Add separator strictly between elements (optional interpretation, 
            // but standard for "join" operations)
            if (i < data.size() - 1) {
                ss << separator; 
            }
        }
        return ss.str();
    }

    // 1. I/O Overloading
    // Output: prints elements separated by separator
    friend ostream& operator<<(ostream& os, const MyString<T>& obj) {
        os << obj.merge();
        return os;
    }

    // Input: For simplicity, reads N items. 
    // (Real generic input is complex without specific delimiters)
    void input(int count) {
        T temp;
        for(int i=0; i<count; ++i) {
            cin >> temp;
            add(temp);
        }
    }
};

int t18_7() {
    // === Test 1: Integer String ===
    cout << "--- Integer String ---" << endl;
    MyString<int> numStr(0); // Separator is 0
    
    numStr.add(10);
    numStr.add(20);
    
    cout << "Str1: " << numStr << endl; // Output: 10020 (10, separator 0, 20)
    
    // Change separator to 999
    numStr.setSeparator(999);
    cout << "Str1 (new sep): " << numStr << endl;

    // Test Concatenation
    MyString<int> numStr2(999);
    numStr2.add(30);
    numStr2.add(40);
    
    MyString<int> sumStr = numStr + numStr2;
    cout << "Concatenated: " << sumStr << endl;

    // Test Merge (to std::string)
    string s = sumStr.merge();
    cout << "Merged string: " << s << endl;

    // Test Removal
    cout << "Removing 999 (separator values treated as data during concat)..." << endl;
    sumStr.removeSymbol(999);
    cout << "Cleaned: " << sumStr << endl;

    // === Test 2: String String (Meta-string) ===
    cout << "\n--- String of Strings ---" << endl;
    MyString<string> textStr(" | "); // Separator is " | "
    
    textStr.add("Tha");
    textStr.add("Warudo");
    textStr.add("!!!");

    cout << "TextStr: " << textStr << endl;
    
    cout << "Element [1]: " << textStr[1] << endl;

    return 0;
}