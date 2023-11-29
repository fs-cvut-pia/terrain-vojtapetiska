#ifndef TERRAINMAP_H
#define TERRAINMAP_H

#include <cmath>
#include <vector>
#include <string>

// Struktura Point
struct Point {
    Point() {};
    Point(int i, int j) : x(i), y(j) {};
    int x;
    int y;
    constexpr static int nx_max = 10000;
    Point& operator= (double a) { x = a; y = a; return *this; };
    bool operator!= (Point const& v) const { return !(operator== (v)); };
    bool operator== (Point const& v) const { return x == v.x && y == v.y; };
    Point operator+ (Point const& v) const { return Point(x+v.x, y+v.y); };
    Point operator- (Point const& v) const { return Point(x-v.x, y-v.y); };
    bool operator<  (Point const& v) const { return x + y*nx_max; }; // This is to provide a simple ordering
    double length() const { return std::sqrt(x*x + y*y); }
};

// Tøída Matrix
template<typename T>
class Matrix {
public:
    Matrix(int n, int m) : nx(n), ny(m), data(n*m) {};
    void zero() { for (T& i : data) i = 0; };
    T operator() (int i, int j) const { return data[i+nx*j]; };
    T& operator() (int i, int j) { return data[i+nx*j]; };
    T operator() (Point const& ij) const { return data[ij.x+nx*ij.y]; };
    T& operator() (Point const& ij) { return data[ij.x+nx*ij.y]; };
    T flattened(int i) const { return data[i]; };
    T& flattened(int i) { return data[i]; };
public:
    int nx;
    int ny;
    std::vector<T> data;
};

// Tøída TerrainMap
class TerrainMap {
public:
    TerrainMap(int n, int m);
    TerrainMap(int n, int m, std::string filename);
    int alt(int x, int y);
    int alt(Point const& v);
    void outputStats();
    bool validCoords(Point p) const;
    const int nx;
    const int ny;

    // Veøejná metoda pro získání výškových dat
    const Matrix<int>& getAltitude() const {
        return altitude;
    }

public:
    Matrix<int> altitude;
    Matrix<int> access_count;
};

#endif

