#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Define the page width for centering (standard console width is usually 80)
const int PAGE_WIDTH = 80;

void create_test_file(const string& filename) {
    ofstream f(filename);
    if (f.is_open()) {
        f << "Hello World\n";           // Length 11 (odd) -> needs padding
        f.close();
    }
}

int t14_11() {
    string input_filename = "task11_input.txt";
    string output_filename = "task11_output.txt";

    // Create a dummy file for testing
    create_test_file(input_filename);

    ifstream infile(input_filename);
    ofstream outfile(output_filename);

    if (!infile.is_open() || !outfile.is_open()) {
        cerr << "Error: Could not open files." << endl;
        return 1;
    }

    string line;
    cout << "Processing lines..." << endl;

    while (getline(infile, line)) {
        // Skip empty lines if necessary, or just center them (they remain empty)
        if (line.empty()) {
            outfile << endl;
            continue;
        }

        // Rule: If line length is odd, add a space to the left
        if (line.length() % 2 != 0) {
            line = " " + line;
        }

        // Calculate left padding to center the text
        // Formula: (Total Width - Line Width) / 2
        int padding = 0;
        if (line.length() < PAGE_WIDTH) {
            padding = (PAGE_WIDTH - line.length()) / 2;
        }

        // Write padding spaces
        for (int i = 0; i < padding; ++i) {
            outfile << " ";
        }

        // Write the (possibly modified) line
        outfile << line << endl;
    }

    infile.close();
    outfile.close();

    cout << "Done. Centered text written to " << output_filename << endl;

    return 0;
}