#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Point {
    int x1, x2;
    double m;

    // Calculation for sorting criteria: m * (x1 + x2)
    double getMoment() const {
        return m * (x1 + x2);
    }
};

// Comparator for sorting
bool comparePoints(const Point& a, const Point& b) {
    return a.getMoment() < b.getMoment();
}

int t21_12() {
    const string inputName = "points_in.txt";
    const string outputName = "segments_out.txt";

    // 1. Create dummy input file for testing
    ofstream createIn(inputName);
    if (createIn.is_open()) {
        // Format: (x1, x2): m
        createIn << "(1, 2): 5.0\n";
        createIn << "(3, 4): 2.5\n";
        createIn << "(0, 1): 10.0\n"; 
        createIn << "(2, 2): 1.0\n";
        createIn.close();
    }

    // 2. Read points
    ifstream inFile(inputName);
    if (!inFile.is_open()) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    vector<Point> points;
    char ignore; // buffer to skip '(', ',', ')', ':'
    Point p;

    // Parsing loop: assumes strict format "(x1, x2): m"
    while (inFile >> ignore >> p.x1 >> ignore >> p.x2 >> ignore >> ignore >> p.m) {
        points.push_back(p);
    }
    inFile.close();

    // 3. Sort points based on formula
    sort(points.begin(), points.end(), comparePoints);

    // 4. Write segments to output file
    // A segment connects Point[i] and Point[i+1]
    ofstream outFile(outputName);
    if (!outFile.is_open()) return 1;

    outFile << "--- Sorted Points & Segments ---\n";
    for (size_t i = 0; i < points.size(); ++i) {
        outFile << "Point " << i << ": (" << points[i].x1 << ", " << points[i].x2 
                << ") mass=" << points[i].m 
                << " [Val: " << points[i].getMoment() << "]\n";
    }
    
    outFile << "\n--- Segments ---\n";
    if (points.size() < 2) {
        outFile << "Not enough points to form segments.\n";
    } else {
        for (size_t i = 0; i < points.size() - 1; ++i) {
            outFile << "Segment [" << i << "-" << (i+1) << "]: "
                    << "(" << points[i].x1 << "," << points[i].x2 << ") -> "
                    << "(" << points[i+1].x1 << "," << points[i+1].x2 << ")\n";
        }
    }
    outFile.close();

    cout << "Done. Check " << outputName << endl;
    return 0;
}