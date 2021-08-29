#include <iostream>

using namespace std;

struct Date{
    int DD, MM, YY;
};
    //Cereals
struct Category1{
    string Name;
    Date StockAllocation;
    float QuantityInKg;
    float PricePerKg;
};
    //Cooking Oils
struct Category2{
    string Name;
    string Type;
    Date ProductionDate;
    Date ExpireDate;
    float QuantityInLiters;
    float PriceByLiter;
};
    //Canned Foods
struct Category3{
    string Name;
    string Type;
    Date ProductionDate;
    Date ExpireDate;
    float Quantity;
    float UnitPrice;
};

struct Item{
    Category1 Cereals;
    Category2 CookingOils;
    Category3 CannedFoods;
};

int main()
{
    // Setting Sample data

    //Items for the Cereal section Using Initialization
    
   Item Barely = {{"Barely" ,{12, 12, 2013}, 45, 12}},
   Sorghum = {{"Sorghum" ,{12, 12, 2013}, 45, 13}}, Wheat = {{"Wheat" ,{12, 12, 2013}, 50, 10}},
   Oats = {{"Oats", {12, 12, 2013}, 50, 38}}, Millets = {{"Millets", {12, 12, 2013}, 60, 24}};

    //Items for the Cooking Oils section
    
   Item JazzleBerry, Oracle, Tena, NewStar, Flawless;
   JazzleBerry.CookingOils.Name = "Jazzle Berry";
   JazzleBerry.CookingOils.Type = "Cottonseed Oil";
   JazzleBerry.CookingOils.ProductionDate = {12, 7, 2013};
   JazzleBerry.CookingOils.ExpireDate = {12, 7, 2014};
   JazzleBerry.CookingOils.QuantityInLiters = 89;
   JazzleBerry.CookingOils.PriceByLiter =  95;

   Oracle.CookingOils.Name = "Oracle";
   Oracle.CookingOils.Type = "Peanut oil";
   Oracle.CookingOils.ProductionDate = {12, 7, 2013};
   Oracle.CookingOils.ExpireDate = {12, 7, 2014};
   Oracle.CookingOils.QuantityInLiters = 126;
   Oracle.CookingOils.PriceByLiter = 117;

   Tena.CookingOils.Name = "Tena";
   Tena.CookingOils.Type = "Sunflower oil";
   Tena.CookingOils.ProductionDate = {12, 7, 2013};
   Tena.CookingOils.ExpireDate = {12, 7, 2014};
   Tena.CookingOils.QuantityInLiters = 120;
   Tena.CookingOils.PriceByLiter = 136;

   NewStar.CookingOils.Name = "New Star";
   NewStar.CookingOils.Type = "Vegetable oil";
   NewStar.CookingOils.ProductionDate = {12, 7, 2013};
   NewStar.CookingOils.ExpireDate = {12, 7, 2014};
   NewStar.CookingOils.QuantityInLiters = 240;
   NewStar.CookingOils.PriceByLiter = 130;

   Flawless.CookingOils.Name = "Flawless";
   Flawless.CookingOils.Type = "Avocado oil";
   Flawless.CookingOils.ProductionDate = {12, 7, 2013};;
   Flawless.CookingOils.ExpireDate = {12, 7, 2014};
   Flawless.CookingOils.QuantityInLiters = 45;
   Flawless.CookingOils.PriceByLiter = 150;

   //Items for the Canned food section

   Item Campbell[2], Heinz, HealthyChoice, EdenFoods, GreenGiant, AmericanGarden;

   Campbell[0] = {{},{},{"Campell","Soup", {15,10, 2012},{15,10, 2014}, 214, 55}};
   Campbell[1] = {{},{},{"Campell","Fruit", {9, 10, 2013},{15,10, 2014}, 230, 65}};
   Heinz = {{},{},{"Heinz","Baked beans", {26,5, 2012},{26, 5, 2014}, 200, 45}};
   HealthyChoice = {{},{},{"Healthy Choice","Pasta Sauce", {23, 7, 2013},{3, 7, 2014}, 200, 50}};
   EdenFoods = {{},{},{"Eden Foods","Mushrooms", {31, 1, 2013},{31, 07, 2014}, 213, 53}};
   GreenGiant = {{},{},{"Green Giant","Green beans", {31, 01, 2013},{31, 01, 2014}, 314, 63 }};
   AmericanGarden = {{},{},{"American Garden","Sweet Corn", {28, 8, 2013},{ 27, 02, 2015}, 256, 71}};

    return 0;
}
