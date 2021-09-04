#include <iostream>
using namespace std;

struct Date{
    int DD, MM, YY;
};


struct Product{
    int ProductNumber;
    string ProductName;
    string Category;
    string ProductType;
    Date ProductionDate;
    Date ExpireDate;
    float Quantity;
    string MeasurementUnit;
    float UnitPrice;
    float Rating;
    int Sales=0;
}Products[50];

int main(){
Product Products[50];
Products[i] = {ProductNumber ,"ProductName ", " Category", "ProductType ",{date}, {edate},Quantity ,"MeasurementUnit ", ,Rating };

Products[i] = { ," ", " ", " ",{date}, {edate}, ," ", , };

//Initializing Bread and Bakery sample data
Products[1] = {1 ,"Banana Bread ", "Bread and Bakery ", "Bread ",{date}, {edate}, 200,"Loafes ", ,4.9 };
Products[2] = {2 ,"Whole Wheat ", "Bread and Bakery ", "Bread ",{date}, {edate},200 ,"Loafes ", ,2.5 };
Products[3] = {3 ,"Sourdough ", "Bread and Bakery ", "Bread ",{date}, {edate}, 200,"Loafes ", ,4.7 };
Products[4] = {4 ,"Baguette ", "Bread and Bakery ", "Bread ",{date}, {edate},200 ,"Loafes ", ,3 };
Products[5] = {5 ,"Difo Dabo ", "Bread and Bakery ", "Bread ",{date}, {edate}, 200," Loafes", ,4.9 };
Products[6] = {6 ,"White Bread ", "Bread and Bakery ", "Bread ",{date}, {edate}, 200,"Loafes ", ,2.8 };
Products[7] = {7 ,"Carrot Cake ", "Bread and Bakery ", "Bread ",{date}, {edate},200 ,"Loafes ", ,4.1 };
Products[8] = {8 ,"Bagels ", "Bread and Bakery ", "Bread ",{date}, {edate}, 200," Loafes", ,3.9 };
Products[9] = {9 ,"Chocolate Chip ", "Bread and Bakery ", "Cookies ",{date}, {edate},200 ,"Killograms ", ,4.8 };
Products[10] = {10 ,"Shortbead Cookie ", "Bread and Bakery ", "Cookies ",{date}, {edate}, 200,"Killograms ", ,4 };
Products[11] = {11 ,"Peanut Butter200 ", "Bread and Bakery ", "Cookies ",{date}, {edate},200 ,"Killograms ", ,2.5 };

//Initialising Pasta and rice sample data
Products[12] = {12,"Short Pasta ", "Pasta and Rice ", "Pasta ",{date}, {edate}, 100,"Killograms ", ,4.3 };
Products[13] = {13,"Long Pasta ", "Pasta and Rice ", "Pasta ",{date}, {edate}, 100,"Killograms ", ,4.3 };
Products[14] = {14,"Macaroni ", "Pasta and Rice ", "Pasta ",{date}, {edate}, 100,"Killograms ", ,4 };
Products[15] = {15,"Fettuccine", "Pasta and Rice ", "Pasta ",{date}, {edate}, ,"Killograms ", ,2.5 };
Products[16] = {16,"Lasagna", "Pasta and Rice ", "Pasta ",{date}, {edate}, 100,"Killograms ", ,5 };
Products[17] = {17,"Spaghetti", "Pasta and Rice ", "Pasta ",{date}, {edate}, 100," Killograms", ,4.9 };
Products[18] = {18,"Brown Rice ", "Pasta and Rice ", "Rice ",{date}, {edate}, 100,"Killograms ", ,4.7 };
Products[19] = {19,"White Rice ", "Pasta and Rice ", "Rice ",{date}, {edate},100 ," Killograms", ,2.5 };

//Initialising Dairy and meat sample data
Products[20] = {20 ,"Beef ", "Dairy and Meat ", "Meat ",{date}, {edate},100 ,"Killogram ", ,4.9 };
Products[21] = {21 ,"Pork ", "Dairy and Meat ", "Meat ",{date}, {edate},100 ,"Killogram ", ,2.5 };
Products[22] = {22 ,"Mutton ", "Dairy and Meat ", "Meat ",{date}, {edate},100 ,"Killogram ", , 4.4};
Products[23] = {23 ,"Chicken ", "Dairy and Meat ", "Meat ",{date}, {edate},100 ,"Killogram ", ,4.9 };
Products[24] = {24 ,"Turkey", "Dairy and Meat ", "Meat ",{date}, {edate},100 ,"Killogram ", ,3.9 };
Products[25] = {25 ,"Butter ", "Dairy and Meat ", "Dairy ",{date}, {edate}, ,"Killograms ", ,5 };
Products[26] = {26 ,"Milk ", "Dairy and Meat ", "Dairy ",{date}, {edate}, 100,"Liters ", ,4.9 };
Products[27] = {27 ,"Mozzarella ", "Dairy and Meat ", "Cheese ",{date}, {edate},100 ,"Killogram ", ,4.5 };
Products[27] = {27 ,"Cheddar ", "Dairy and Meat ", "Cheese ",{date}, {edate},100 ,"Killogram ", ,4.9 };
Products[27] = {27 ,"Parmesan ", "Dairy and Meat ", "Cheese ",{date}, {edate},100 ,"Killogram ", ,4.4 };
Products[27] = {27 ,"Gouda ", "Dairy and Meat ", "Cheese ",{date}, {edate},100 ,"Killogram ", ,5 };
Products[28] = {28 ,"Yoghurt ", "Dairy and Meat ", "Dairy ",{date}, {edate},100 ,"Litres ", ,4.9 };
Products[29] = {29 ,"Powdered Milk ", "Dairy and Meat ", "Dairy ",{date}, {edate},100 ,"Killogram ", ,4.6 };
Products[30] = {30 ,"Ice Cream", "Dairy and Meat ", "Dairy ",{date}, {edate},100 ,"Killogram ", ,5 };


}