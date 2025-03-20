// S4822-Matos-Restaurant-Dishes-App.cpp 


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
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
        if (calories > 700) {
            throw runtime_error("Too many calories " + name);
        }
        if (price > 24.00) {
            throw runtime_error("Too expensive " + name);
        }

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
void experiment01()
{
    vector<Dish*> dishDb;

    Dish* d1 = new Dish("Paella", "Rice + seafood + chorizo", 800, 25.99);
    d1->display();
    dishDb.push_back(d1);

    Dish* d2 = new Dish("Mac & Cheese", "Creamy noddles + Cheddar cheese", 200, 5.00);
    d2->display();
    dishDb.push_back(d2);



    Restaurant r1("Delicious at Torrance", "123 Crenshaw Ave, Torrance CA 90555", "555-1234");
    r1.addDish(d1);
    r1.addDish(d2);

    r1.display();
}

//---------------------------------------------------------------------------------------
template <typename T1, typename T2, typename T3, typename T4>
class Quad {
public:
    T1 first;
    T2 second;
    T3 third;
    T4 fourth;

    Quad(T1 v1 = {}, T2 v2 = {}, T3 v3 = {}, T4 v4 = {})
        : first(v1), second(v2), third(v3), fourth(v4) {}

    void display() {
        cout << "<" << first << ", " << second << ", " 
            << third << ", " << fourth << "\n";
    }
};




void experiment02()
{
    //TODO - Read dishes file, create a vector<Triplets<string, string, string>> container
    //       Create a restaurant
    //       Add individual dishes from db.

    vector<Quad<string, string, string, string>> quadDb;
    vector<Dish> dishDb;

    ifstream mydiskfile("c:/temp/dishes.txt");
    if (!mydiskfile) {
        cout << "ERROR - File not found \n";
        exit(101);
    }

    string strName, strDesc, strCal, strPri;
    while (getline(mydiskfile, strName)) {
        getline(mydiskfile, strDesc);
        getline(mydiskfile, strCal);
        getline(mydiskfile, strPri);

        auto qRecord = Quad<string, string, string,string>
                       (strName, strDesc, strCal, strPri);

        quadDb.push_back(qRecord);
    }
    mydiskfile.close();

    //Filter dishes - reject according to business rules
    for (size_t i = 0; i < quadDb.size(); i++)
    {
        try {
            auto q = quadDb[i];
            dishDb.push_back(Dish(q.first, q.second,
                                  stoi(q.third), stod(q.fourth)));

        }
        catch (exception& e) {
            cout << "Problem with a dish - call a manager " << e.what() << endl;
        }
    }

    //DONE!
    cout << "dishDb size is " << dishDb.size() << endl;

}



int main()
{
    //experiment01();   //NAIVE code - will fail when exceptions are thrown
    experiment02();

    cout << "\nAll done!\n";
}

