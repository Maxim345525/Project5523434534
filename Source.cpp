#include <iostream>
using namespace std;
class Flat {
private:
    int area; 
    double price; 
public:
    Flat() : area(0), price(0.0) {}
    Flat(int area, double price) : area(area), price(price) {}
    bool operator==(const Flat& other) const {
        return (area == other.area);
    }
    Flat& operator=(const Flat& other) {
        if (this != &other) {
            area = other.area;
            price = other.price;
        }
        return *this;
    }
    bool operator>(const Flat& other) const {
        return (price > other.price);
    }
    friend std::ostream& operator<<(std::ostream& os, const Flat& flat) {
        os << "Area: " << flat.area << " sq.m., Price: " << flat.price << " USD";
        return os;
    }
};
int main() {
    Flat flat1(80, 100000.0);
    Flat flat2(90, 120000.0);
    Flat flat3(80, 110000.0);
    if (flat1 == flat3) {
        cout << "Flat 1 and Flat 3 have the same area." << endl;
    }
    else {
        cout << "Flat 1 and Flat 3 do not have the same area." << endl;
    }
    flat3 = flat2;
    cout << "Flat 3: " << flat3 << endl;
    if (flat2 > flat1) {
        cout << "Flat 2 is more expensive than Flat 1." << endl;
    }
    else {
        cout << "Flat 2 is not more expensive than Flat 1." << endl;
    }
    return 0;
}
