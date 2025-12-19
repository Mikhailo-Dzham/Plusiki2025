#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// ==========================================
// Abstract Base Class: Shape3D
// ==========================================
class Shape3D {
public:
    virtual ~Shape3D() {}

    // Pure virtual methods to be implemented by derived classes
    virtual double getVolume() const = 0;
    virtual double getLateralSurfaceArea() const = 0;
    virtual double getTotalSurfaceArea() const = 0; // "Area of all faces"
    virtual int getVertexCount() const = 0;
    virtual string getName() const = 0;
};

// ==========================================
// Class: Parallelepiped (Rectangular Cuboid)
// ==========================================
class Parallelepiped : public Shape3D {
private:
    double length, width, height;

public:
    Parallelepiped(double l, double w, double h) : length(l), width(w), height(h) {}

    double getVolume() const override {
        return length * width * height;
    }

    double getLateralSurfaceArea() const override {
        // Perimeter of base * height
        return 2 * (length + width) * height;
    }

    double getTotalSurfaceArea() const override {
        // Lateral area + 2 * Base area
        return getLateralSurfaceArea() + 2 * (length * width);
    }

    int getVertexCount() const override {
        return 8;
    }

    string getName() const override {
        return "Parallelepiped";
    }
};

// ==========================================
// Class: Pyramid3 (Triangular Pyramid)
// Assumption: Regular triangular pyramid (Equilateral base)
// ==========================================
class Pyramid3 : public Shape3D {
private:
    double side;   // Side length of the equilateral base
    double height; // Vertical height of the pyramid

public:
    Pyramid3(double s, double h) : side(s), height(h) {}

    double getVolume() const override {
        // Area of equilateral base = (sqrt(3)/4) * side^2
        double baseArea = (sqrt(3.0) / 4.0) * side * side;
        return (1.0 / 3.0) * baseArea * height;
    }

    double getLateralSurfaceArea() const override {
        // We need the slant height.
        // Apothegm of base (distance from center to midpoint of side): r = side / (2*sqrt(3))
        double r = side / (2.0 * sqrt(3.0));
        // Slant height (Pythagoras): L = sqrt(height^2 + r^2)
        double slantHeight = sqrt(height * height + r * r);

        // Lateral surface = 3 * (1/2 * side * slantHeight)
        return 3.0 * (0.5 * side * slantHeight);
    }

    double getTotalSurfaceArea() const override {
        double baseArea = (sqrt(3.0) / 4.0) * side * side;
        return getLateralSurfaceArea() + baseArea;
    }

    int getVertexCount() const override {
        return 4; // 3 base + 1 apex
    }

    string getName() const override {
        return "Triangular Pyramid";
    }
};

// ==========================================
// Class: Pyramid4 (Rectangular Pyramid)
// ==========================================
class Pyramid4 : public Shape3D {
private:
    double length, width; // Base dimensions
    double height;        // Vertical height

public:
    Pyramid4(double l, double w, double h) : length(l), width(w), height(h) {}

    double getVolume() const override {
        double baseArea = length * width;
        return (1.0 / 3.0) * baseArea * height;
    }

    double getLateralSurfaceArea() const override {
        // Need two different slant heights because base is rectangular
        // Slant height for side 'length': L1 = sqrt(height^2 + (width/2)^2)
        double l1 = sqrt(height * height + (width / 2.0) * (width / 2.0));

        // Slant height for side 'width': L2 = sqrt(height^2 + (length/2)^2)
        double l2 = sqrt(height * height + (length / 2.0) * (length / 2.0));

        // Area = 2 triangles with base 'length' + 2 triangles with base 'width'
        return (length * l1) + (width * l2);
    }

    double getTotalSurfaceArea() const override {
        return getLateralSurfaceArea() + (length * width);
    }

    int getVertexCount() const override {
        return 5; // 4 base + 1 apex
    }

    string getName() const override {
        return "Rectangular Pyramid";
    }
};

// ==========================================
// Main Function
// ==========================================
int t16_9() {
    // Collection of shapes (using pointers to base class)
    vector<Shape3D*> shapes;

    // 1. Add shapes to the array
    shapes.push_back(new Parallelepiped(2.0, 3.0, 4.0));
    shapes.push_back(new Pyramid3(4.0, 5.0)); // Side 4, Height 5
    shapes.push_back(new Pyramid4(3.0, 4.0, 6.0)); // Base 3x4, Height 6

    // Variables for totals
    double totalVolume = 0;
    double totalSurfaceArea = 0;
    int totalVertices = 0;

    cout << fixed << setprecision(2);
    cout << "--- Individual Shape Details ---" << endl;

    // 2. Iterate and calculate
    for (const auto* shape : shapes) {
        double v = shape->getVolume();
        double sa = shape->getTotalSurfaceArea();
        int vert = shape->getVertexCount();

        cout << "Shape: " << shape->getName() << endl;
        cout << "  Volume: " << v << endl;
        cout << "  Total Area: " << sa << endl;
        cout << "  Vertices: " << vert << endl;
        cout << "--------------------------------" << endl;

        totalVolume += v;
        totalSurfaceArea += sa;
        totalVertices += vert;
    }

    // 3. Output Final Results
    cout << "=== SUMMARY ===" << endl;
    cout << "Total Volume of all shapes: " << totalVolume << endl;
    cout << "Total Surface Area (all faces): " << totalSurfaceArea << endl;
    cout << "Total Number of Vertices: " << totalVertices << endl;

    // Cleanup memory
    for (auto* shape : shapes) {
        delete shape;
    }
    shapes.clear();

    return 0;
}