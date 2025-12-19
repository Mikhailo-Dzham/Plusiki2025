#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Helper to generate input file
void create_input_file(const string& filename) {
    ofstream f(filename);
    if (f.is_open()) {
        f << "10 5 3 4 8 2 6"; // Example data
        f.close();
    }
}

int t12_9() {
    string filename = "numbers.txt";
    create_input_file(filename);

    // 1. Read numbers into memory
    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    vector<int> nums;
    int n;
    while (infile >> n) {
        nums.push_back(n);
    }
    infile.close();

    // 2. Process logic: compare current with next
    // Iterate up to the second to last element
    for (size_t i = 0; i < nums.size() - 1; ++i) {
        if (nums[i] > nums[i+1]) {
            nums[i] = nums[i] * nums[i];
        }
    }

    // 3. Rewrite the file
    ofstream outfile(filename);
    for (const auto& num : nums) {
        outfile << num << " ";
    }
    outfile.close();

    cout << "Task 9 completed. File '" << filename << "' updated." << endl;
    return 0;
}