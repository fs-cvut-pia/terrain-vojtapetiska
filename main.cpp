#include "TerrainMap.h"
#include "Path.h"
#include "AirplanePath.h"
#include "ShipPath.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

Point read_coordinates(const std::string& filename, int i_option) {
    Point p;

    std::ifstream input_file(filename);

    if (!input_file) throw std::runtime_error("Cannot open file " + filename);

    // Načítání dat ze souboru
    if (!(input_file >> p.x >> p.y)) {
        throw std::runtime_error("Error reading coordinates from file " + filename);
    }

    return p;
}

int main(int argc, char *argv[]) {
    const int nx = 256;
    const int ny = 256;

    std::string terrain_filename;

    // Načítání souboru s terénní mapou ze vstupních parametrů
    if (argc > 1) terrain_filename = argv[1];
    else { std::cout << "No terrain file specified!" << std::endl; return 0; }

    TerrainMap m(nx, ny, terrain_filename);

    // Načítání počátečního a koncového bodu ze souboru
    Point start = read_coordinates(terrain_filename, 2);
    Point finish = read_coordinates(terrain_filename, 4);

    // Vytvoření instancí cest a provedení hledání
    std::vector<Path*> paths = {
        new AirplanePath(m, "AirplanePath", start, finish),
        new ShipPath(m, "ShipPath", start, finish),
        // Případně další třídy můžete přidat podle potřeby
    };

    // Zpracování cest
    for (auto& p : paths) {
        std::cout << "Path search: " << p->getName() << std::endl;
        std::cout << "=============" << std::endl;
        p->find();
        p->printStats();
        std::cout << "=============" << std::endl;
        p->saveToFile();
        delete p;
    }

    return 0;
}



