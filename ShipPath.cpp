class ShipPath : public Path {
public:
    ShipPath(TerrainMap& m, Point start, Point finish) : Path(m, "ship_path", start, finish) {}

    bool find() override {
        // Implementace algoritmu pro nejkratší cestu pro lodě
        // ...

        return true; // True, pokud byla cesta nalezena, jinak false
    }
};

