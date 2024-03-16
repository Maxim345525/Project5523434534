#include <iostream>
using namespace std;
class Overcoat {
private:
    string type;
    double price;
public:
    Overcoat() : type(""), price(0.0) {}
    Overcoat(string type, double price) : type(type), price(price) {}
    bool operator==(const Overcoat& other) const {
        return (type == other.type);
    }
    Overcoat& operator=(const Overcoat& other) {
        if (this != &other) {
            type = other.type;
            price = other.price;
        }
        return *this;
    }
    bool operator>(const Overcoat& other) const {
        return (type == other.type && price > other.price);
    }
    friend ostream& operator<<(std::ostream& os, const Overcoat& overcoat) {
        os << "Type: " << overcoat.type << ", Price: " << overcoat.price;
        return os;
    }
};
int main() {
    Overcoat coat1("Winter", 100.0);
    Overcoat coat2("Winter", 150.0);
    Overcoat coat3("Spring", 120.0);
    if (coat1 == coat2) {
        cout << "Coat 1 and Coat 2 are of the same type." << endl;
    }
    else {
        cout << "Coat 1 and Coat 2 are not of the same type." << endl;
    }
    coat3 = coat1;
    cout << "Coat 3: " << coat3 << endl;
    if (coat1 > coat2) {
        cout << "Coat 1 is more expensive than Coat 2." << endl;
    }
    else {
        cout << "Coat 1 is not more expensive than Coat 2." << endl;
    }
    return 0;
}
