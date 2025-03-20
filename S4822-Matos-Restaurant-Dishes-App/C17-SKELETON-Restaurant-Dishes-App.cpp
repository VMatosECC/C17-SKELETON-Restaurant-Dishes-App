// S4822-Matos-Restaurant-Dishes-App.cpp 


#include <iostream>
#include <vector>
using namespace std;

class Dish
{
private:
    string name;
    string description;
    int    calories;
    double price;

public:
    Dish(string n = "NoName", string d = "NoDescription", int c = 0, double p = 1.00)
        : name(n), description(d), calories(c), price(p) {
    //TODO-validate data - if needed!
    }

    string getName() { return name; }

    void display() {
        cout << "Dish[Name: " << name << ", Description: " << description
            << ", Calories: " << calories << ", Price: " << price << "]\n";
    }

};//--------------------------------------------------------------------
class Restaurant
{
private:
    string name;
    string address;
    string phone;
    vector<Dish*> menu;

public:
    Restaurant(string n = "NoRestName", string a = "NoAddressYet",
        string p = "NoPhoneYet", vector<Dish*> m = {})
        : name(n), address(a), phone(p), menu(m) {
        //TODO-validation logic goes here
    }

    void display() {
        cout << "\nRestaurant[Name: " << name 
            << ", Address:" << address << ", Phone: " << phone << endl;

        for (Dish* pd : menu) { cout << "\n\t"; pd->display(); }
        cout << endl;
    }

    void addDish(Dish* pd) {
        menu.push_back(pd);
    }
};

//------------------------------------------------------------------
int main()
{
    vector<Dish*> dishDb;

    Dish* d1 = new Dish("Paella", "Rice + seafood + chorizo", 800, 25.99);
    d1->display();
    dishDb.push_back(d1);

    Dish* d2 = new Dish("Mac & Cheese", "Creamy noddles + Cheddar cheese", 200, 5.00);
    d2->display();
    dishDb.push_back(d2);


     
    Restaurant r1("Delicious at Torrance", "123 Crenshaw AVe, Torrance CA 90555", "555-1234");
    r1.addDish(d1);
    r1.addDish(d2);

    r1.display();

    cout << "\nAll done!\n";
}

