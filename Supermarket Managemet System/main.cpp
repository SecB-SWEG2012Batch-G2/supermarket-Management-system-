#include <iostream>

using namespace std;

/*
    Kitchen Utensils
    Sanitary Products
    Health and Body Care
*/

struct Date{
    int dd,mm,yy;
};

struct KitchenUtensils{
    int serialNumber;
    string name;
    string type;
};

struct SanitaryProducts{
    int serialNumber;
    string name;
    string manufacturer;
    Date productionDate;
    Date expireDate;
    string type;
};

struct HealthAndBodyCare{
    int serialNumber;
    string name;
    string manufacturer;
    Date productionDate;
    Date expireDate;
    string type;
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
