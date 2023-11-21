class AirplanePath : public Path {
public:
    AirplanePath(TerrainMap& m, Point start, Point finish) : Path(m, "airplane_path", start, finish) {}

    bool find() override {
        // Implementace algoritmu pro nejkratší cestu mezi dvěma body pro letadla
        // ...

        return true; // True, pokud byla cesta nalezena, jinak false
    }
};

