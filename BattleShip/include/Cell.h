class Cell {
public:
    // Con/Des
    Cell() = default;
    Cell(char cell_type, int x, int y, char ship_type, int ship_number);
    ~Cell();

    // accessor functions
    char getType();
    bool isBoat(); 
    char getBoatType();
    int getBoatNumber();

    // change cell type
    void changeCell();

    // put a ship down
    void setTypeShip(char ship_type, int ship_number);

    // change cell accordingly when a boat is hit
    void changeCellWhenHitWithBoat();

    // change cell when hit with no boat
    void changeCellWhenHitWithNoBoat();

private:
    // cell_type_ has 3 states:
    // . - has nothing or a ship
    // X - sunken ship
    // O - when shot but not a ship
    char cell_type_;
    int x_coor_;
    int y_coor_;

    //boat info
    // ship_type_ has 4 states(only shown when players are setting boats)
    // S - submarine(1)
    // D - destroyer(2)
    // B - battleship(3)
    // C - carrier(4)
    char ship_type_;
    int ship_number_;
};
