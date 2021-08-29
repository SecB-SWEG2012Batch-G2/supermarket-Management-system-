#include <iostream>
using namespace std;
struct Date{
    int DD, MM, YY;
};
struct Price {

};
//Bread_and_Bakery
struct Bread_and_Bakery {
string type;
string name;
Date Production_Date;
Date Expiration_date;
float cost;
float price;
float Quantity;
};
//Pasta_and_Rice
struct Pasta_and_Rice{
string name;
string type;
Date Expiration_date;
Date Production_Date;
float cost;
float price;
float Quantity;
};
//Dairy_and_Meat
struct Dairy_and_Meat{
string name;
string type;
Date Expiration_date;
Date Production_Date;
float cost;
float Price;
float Quantity;
};

int main(){

//Sample Data for Bread and Bakery section
Bread_and_Bakery Bread[8],Cookies[2];
Bread[0] = {"Bread"," Banana Bread",{3, 7, 2021},{6, 7, 2021}, 20,24,};
Bread[1] = {"Bread","Whole Wheat",{3, 7, 2021},{6, 7, 2021},10,12,};
Bread[2] = {"Bread","Sourdough",{3, 7, 2021},{6, 7, 2021},1,2,};
Bread[3] = {"Bread","Baguette",{3, 7, 2021},{6, 7, 2021},1,2,};
Bread[4] = {"Bread","Difo Dabo ",{3, 7, 2021},{6, 7, 2021},30,40,};
Bread[5] = {"Bread","White Bread",{3, 7, 2021},{6, 7, 2021},2,3,};
Bread[6] = {"Bread","Carrot cake",{3, 7, 2021},{6, 7, 2021}, , ,};
Bread[7] = {"Bread","Bagels",{3, 7, 2021},{6, 7, 2021}, , ,};
Cookies[0] = {"Cookie","Chocolate Chip",{3, 7, 2021},{6, 7, 2021}, , ,};
Cookies[1] = {"Cookie","Shortbread Cookie",{3, 7, 2021},{6, 7, 2021}, , ,};
Cookies[2] = {"Cookie","Peanut Butter Cookie",{3, 7, 2021},{3, 7, 2021}, , ,};


//Sample Data for Pasta and Rice
Pasta_and_Rice Pasta[6], Rice[2];
Pasta[0] = {"Pasta","Short Pasta",{3, 7, 2021},{6, 7, 2021}, , ,};
Pasta[1] = {"Pasta","Long Pasta",{3, 7, 2021},{6, 7, 2021}, , ,};
Pasta[2] = {"Pasta","Macaroni",{3, 7, 2021},{6, 7, 2021}, , ,};
Pasta[3] = {"Pasta","Fettuccine",{3, 7, 2021},{6, 7, 2021}, , ,};
Pasta[4] = {"Pasta","Lasagna",{3, 7, 2021},{6, 7, 2021}, , ,};
Pasta[5] = {"Pasta","Spaghetti",{3, 7, 2021},{3, 7, 2021}, , ,};
Rice[0] = {"Rice","Brown rice",{3, 7, 2021},{6, 7, 2021}, , ,};
Rice[1] = {"Rice","White Rice",{3, 7, 2021},{6, 7, 2021}, , , }
//Sample Data for Meat and Dairy Products
Dairy_and_Meat Meat[5], Dairy[5];
Meat[0] = {"Meat","Beef",{3, 7, 2021},{6, 7, 2021}, , ,};
Meat[1] = {"Meat","Pork",{3, 7, 2021},{6, 7, 2021}, , ,};
Meat[2] = {"Meat","Mutton",{3, 7, 2021},{6, 7, 2021}, , ,};
Meat[3] = {"Meat","Chicken",{3, 7, 2021},{6, 7, 2021}, , ,};
Meat[4] = {"Meat","Turkey",{3, 7, 2021},{6, 7, 2021}, , ,};

Dairy[0] = {"Dairy","Butter",{},{}, , ,};
Dairy[0] = {"Dairy","Milk",{},{}, , ,};
Dairy[0] = {"Dairy","Cheese",{},{}, , ,};
Dairy[0] = {"Dairy","Yoghurt",{},{}, , ,};
Dairy[0] = {"Dairy","Milk Powder",{},{}, , ,};
Dairy[0] = {"Dairy","Ice Cream",{},{}, , ,};


return 0;

}


