#include <iostream>

using namespace std;

struct Date{
    int dd,mm,yy; // Date/Month/Year
};
struct Address{
    string city,region,country; //Address
};

struct Beverages{
    string productName;    //Product Name
    string alcholCategory;    //Category type like alcoholic or non alcoholic
    Date Mfg;   //Product Manufacturing date
    Date Exp;   //Product Expiring date
    Address productAddress;    //Product production address
    string Company;    //Producer Company
    string Telephone;    //Company Phone Number
};

struct Water : Beverages {
    float Calcium,Magnesium,Sodium,Potassium,Bicarbonates,Chloride,Sulphate,TDS,pH;    //Water Chemical Composition in mg/L
};

struct Milk : Beverages{
    string milkType;   //Milk type like Almond, Soy, Oat milk
    string milkSource;    //Milk Source like Cow, Goat
    bool containLactose;   //Contains Lactose
    float Calcium,Magnesium,vitaminD,Phosphorus;    //Milk Chemical Composition in mg/L
};

struct Sodas : Beverages {    //Carbonated drinks
    bool containFlavor;
    string flavorType;    //Flavor type
    float sugar, calcium;   //Mineral content
};

struct Juices : Beverages {
    string fruit; //Fruit it contains
    float Calcium,Magnesium,vitaminD,Phosphorus;    //mineral containt
};

struct EnergyDrinks : Beverages {
    float Caffeine;
    float sugar;
    float energyBooster;
    float vitamins, minerals;
    string Additives;
};

struct Beer : Beverages {
    float alcholicContaint;
    float Potassium, Magnesium;
};

struct Wine : Beverages {
    float alcholicContaint;
    float Potassium, Magnesium;
};

struct Cider : Beverages {
    float alcholicContaint;
    float Potassium, Magnesium;
};

struct Snack{
    string productName;    //Product Name
    string alcholCategory;    //Category type like alcoholic or non alcoholic
    Date Mfg;   //Product Manufacturing date
    Date Exp;   //Product Expiring date
    Address productAddress;    //Product production address
    string Company;    //Producer Company
    string Telephone;    //Company Phone Number
};

struct Cookies : Snack{
    string snackType;
    string Ingredients;
    float Fat, Sugar;
};

struct Sandwiches : Snack{
    string snackType;
    string Ingredients;
    float Fat, Sugar;
};

struct Cakes : Snack{
    string snackType;
    string Ingredients;
    float Fat, Sugar;
};

struct Bars : Snack{
    string snackType;
    string Ingredients;
    float Fat, Sugar;
};

struct Pastries : Snack{
    string snackType;
    string Ingredients;
    float Fat, Sugar;
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
