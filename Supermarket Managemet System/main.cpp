#include <iostream>
#include <iomanip>
#include <windows.h>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

// Global Variables
int NumberOfProducts = 59;

// Resizes the console window
void ResizeWindow()
{
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1600, 800, TRUE);
}
struct Date
{
    int Day,Month,Year;
};

struct Product
{
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
} Products[9999];

//Product *Products = new Product[NumberOfProducts];

// Function to Print Table Dividers " +--+ "
void PrintTableDividers()
{
    cout << setw(2) << " +---------------+";
    cout << setw(24) << "--------------------------+";
    cout << setw(24) << "--------------------------+";
    cout << setw(24) << "--------------------------+";
    cout << setw(15) << "-----------------+";
    cout << setw(15) << "-----------------+";
    cout << setw(8) << "----------+";
    cout << setw(16) << "------------------+";
    cout << setw(10) << "------------+";
    cout << setw(6) << "--------+";
    cout << setw(5) << "-------+";
    cout << endl;
}
// Function to Print Table Headers (Product Name, Price)
void PrintTableHeader()
{
    // Table Headers
    cout << setw(2) << " | Serial Number" << " | ";
    cout << setw(24) << "Product Name" << " | ";
    cout << setw(24) << "Category" << " | ";
    cout << setw(24) << "Product Type" << " | ";
    cout << setw(15) << "Production Date" << " | ";
    cout << setw(15) << "Expire Date" << " | ";
    cout << setw(8) << "Quantity" << " | ";
    cout << setw(16) << "Measurement Unit" << " | ";
    cout << setw(10) << "Unit Price" << " | ";
    cout << setw(6) << "Rating" << " | ";
    cout << setw(5) << "Sales" << " | ";
    cout << endl;
}
// This Functions Prints the details of the passed product structure
void PrintInItemValue(Product Item)
{
    // Table Values
    string ProductionDate = to_string(Item.ProductionDate.Day) + "/" + to_string(Item.ProductionDate.Month) + "/" + to_string(Item.ProductionDate.Year);
    cout << " | " << setw(13) << Item.ProductNumber << " | ";
    cout << setw(24) << Item.ProductName << " | ";
    cout << setw(24) << Item.Category << " | ";
    cout << setw(24) << Item.ProductType << " | ";
    cout << setw(15) << ProductionDate << " | ";
    cout << setw(15) << ProductionDate << " | ";
    cout << setw(8) << Item.Quantity << " | ";
    cout << setw(16) << Item.MeasurementUnit << " | ";
    cout << setw(10) << Item.UnitPrice << " | ";
    cout << setw(6) << Item.Rating << " | ";
    cout << setw(5) << Item.Sales << " | ";
    cout << endl;
}
// Print In Table Format Function
void PrintInTableFormat()
{
    // Initialization
    ResizeWindow();
    // Print Full Table For reference to edit
    cout << endl << " Here's a list of all products... " << endl << endl;
    // Print In Table Format Function
    PrintTableDividers();
    PrintTableHeader();
    // Loop Through the samples to print the details in table format
    for(int i = 0; i < NumberOfProducts; i++)
    {
        PrintTableDividers();
        PrintInItemValue(Products[i]);
    }
    PrintTableDividers();
}

//Used to Compare products using there unit price in ascending order
bool CompareUsingUnitPriceAscending( Product FirstProduct, Product SecondProduct)
{
    if(FirstProduct.UnitPrice < SecondProduct.UnitPrice)
        return 1;
    else
        return 0;
}

//Used to Compare products using there unit price in descending order
bool CompareUsingUnitPriceDescending( Product FirstProduct, Product SecondProduct)
{
    if(FirstProduct.UnitPrice > SecondProduct.UnitPrice)
        return 1;
    else
        return 0;
}

//Used to Compare products using there rating in ascending order
bool CompareUsingRatingAscending( Product FirstProduct, Product SecondProduct)
{
    if(FirstProduct.Rating < SecondProduct.Rating)
        return 1;
    else
        return 0;
}

//Used to Compare products using there rating in descending order
bool CompareUsingRatingDescending( Product FirstProduct, Product SecondProduct)
{
    if(FirstProduct.Rating > SecondProduct.Rating)
        return 1;
    else
        return 0;
}

//Used to Compare products using there production date in ascending order
bool CompareUsingProductionDateAscending( Product FirstProduct, Product SecondProduct)
{
    if(FirstProduct.ProductionDate.Year < SecondProduct.ProductionDate.Year)
        return 1;
    else if((FirstProduct.ProductionDate.Year == SecondProduct.ProductionDate.Year)&& (FirstProduct.ProductionDate.Month < SecondProduct.ProductionDate.Month))
        return 1;
    else if(((FirstProduct.ProductionDate.Year == SecondProduct.ProductionDate.Year)&&(FirstProduct.ProductionDate.Month == SecondProduct.ProductionDate.Month))&& (FirstProduct.ProductionDate.Day < SecondProduct.ProductionDate.Day))
        return 1;
    else
        return 0;
}

//Used to Compare products using there production date in descending order
bool CompareUsingProductionDateDescending( Product FirstProduct, Product SecondProduct)
{
    if(FirstProduct.ProductionDate.Year > SecondProduct.ProductionDate.Year)
        return 1;
    else if((FirstProduct.ProductionDate.Year == SecondProduct.ProductionDate.Year)&& (FirstProduct.ProductionDate.Month > SecondProduct.ProductionDate.Month))
        return 1;
    else if(((FirstProduct.ProductionDate.Year == SecondProduct.ProductionDate.Year)&&(FirstProduct.ProductionDate.Month == SecondProduct.ProductionDate.Month))&& (FirstProduct.ProductionDate.Day > SecondProduct.ProductionDate.Day))
        return 1;
    else
        return 0;
}

//Used to Compare products using there expiration date in ascending order
bool CompareUsingExpirationDateAscending( Product FirstProduct, Product SecondProduct)
{
    if(FirstProduct.ExpireDate.Year < SecondProduct.ExpireDate.Year)
        return 1;
    else if((FirstProduct.ExpireDate.Year == SecondProduct.ExpireDate.Year)&& (FirstProduct.ExpireDate.Month < SecondProduct.ExpireDate.Month))
        return 1;
    else if(((FirstProduct.ExpireDate.Year == SecondProduct.ExpireDate.Year)&&(FirstProduct.ExpireDate.Month == SecondProduct.ExpireDate.Month))&& (FirstProduct.ExpireDate.Day < SecondProduct.ExpireDate.Day))
        return 1;
    else
        return 0;
}

//Used to Compare products using there expiration date in descending order
bool CompareUsingExpirationDateDescending( Product FirstProduct, Product SecondProduct)
{
    if(FirstProduct.ExpireDate.Year > SecondProduct.ExpireDate.Year)
        return 1;
    else if((FirstProduct.ExpireDate.Year == SecondProduct.ExpireDate.Year)&& (FirstProduct.ExpireDate.Month > SecondProduct.ExpireDate.Month))
        return 1;
    else if(((FirstProduct.ExpireDate.Year == SecondProduct.ExpireDate.Year)&&(FirstProduct.ExpireDate.Month == SecondProduct.ExpireDate.Month))&& (FirstProduct.ExpireDate.Day > SecondProduct.ExpireDate.Day))
        return 1;
    else
        return 0;
}

//Used to Compare products using there quantity in ascending order
bool CompareUsingQuantityAscending( Product FirstProduct, Product SecondProduct)
{
    if(FirstProduct.Quantity < SecondProduct.Quantity)
        return 1;
    else
        return 0;
}

//Used to Compare products using there quantity in descending order
bool CompareUsingQuantityDescending( Product FirstProduct, Product SecondProduct)
{
    if(FirstProduct.Quantity > SecondProduct.Quantity)
        return 1;
    else
        return 0;
}

//Used to Compare products using there sales in ascending order
bool CompareUsingSalesAscending( Product FirstProduct, Product SecondProduct)
{
    if(FirstProduct.Sales < SecondProduct.Sales)
        return 1;
    else
        return 0;
}

//Used to Compare products using there sales in descending order
bool CompareUsingSalesDescending( Product FirstProduct, Product SecondProduct)
{
    if(FirstProduct.Sales > SecondProduct.Sales)
        return 1;
    else
        return 0;
}



int main()
{

//Products[i] = {ProductNumber ,"ProductName ", " Category", "ProductType ",{date}, {10,9,21},Quantity ,"MeasurementUnit ", ,Rating };

//Products[i] = { ," ", " ", " ",{date}, {10,9,21}, ," ", , };

//Initializing Bread and Bakery sample data
    Products[1] = {1,"Banana Bread ", "Bread and Bakery ", "Bread ",{6,9,21}, {10,9,21}, 200,"Loafes ",22,4.9 };
    Products[2] = {2,"Whole Wheat ", "Bread and Bakery ", "Bread ",{6,9,21}, {10,9,21},400,"Loafes ",3,2.5 };
    Products[3] = {3,"Sourdough ", "Bread and Bakery ", "Bread ",{6,9,21}, {10,9,21}, 250,"Loafes ",4,4.7 };
    Products[4] = {4,"Baguette ", "Bread and Bakery ", "Bread ",{6,9,21}, {10,9,21},260,"Loafes ",10,3 };
    Products[5] = {5,"Difo Dabo ", "Bread and Bakery ", "Bread ",{6,9,21}, {10,9,21}, 600," Loafes",20,4.9 };
    Products[6] = {6,"White Bread ", "Bread and Bakery ", "Bread ",{6,9,21}, {10,9,21}, 600,"Loafes ",3,2.8 };
    Products[7] = {7,"Carrot Cake ", "Bread and Bakery ", "Bread ",{6,9,21}, {10,9,21},450,"Loafes ",20,4.1 };
    Products[8] = {8,"Bagels ", "Bread and Bakery ", "Bread ",{6,9,21}, {10,9,21}, 245," Loafes",12,3.9 };
    Products[9] = {9,"Chocolate Chip ", "Bread and Bakery ", "Cookies ",{6,9,21}, {10,9,21},233,"Killograms ",30,4.8 };
    Products[10] = {10,"Shortbead Cookie ", "Bread and Bakery ", "Cookies ",{6,9,21}, {10,9,21}, 120,"Killograms ",28,4 };
    Products[11] = {11,"Peanut Butter200 ", "Bread and Bakery ", "Cookies ",{6,9,21}, {10,9,21},290,"Killograms ",28,2.5 };

//Initialising Pasta and rice sample data
    Products[12] = {12,"Short Pasta ", "Pasta and Rice ", "Pasta ",{6,9,21}, {10,9,21}, 123,"Killograms ",25,4.3 };
    Products[13] = {13,"Long Pasta ", "Pasta and Rice ", "Pasta ",{6,9,21}, {10,9,21}, 150,"Killograms ",25,4.3 };
    Products[14] = {14,"Macaroni ", "Pasta and Rice ", "Pasta ",{6,9,21}, {10,9,21}, 400,"Killograms ",24,4 };
    Products[15] = {15,"Fettuccine", "Pasta and Rice ", "Pasta ",{6,9,21}, {10,9,21},300,"Killograms ",28,2.5 };
    Products[16] = {16,"Lasagna", "Pasta and Rice ", "Pasta ",{6,9,21}, {10,9,21}, 100,"Killograms ",32,5 };
    Products[17] = {17,"Spaghetti", "Pasta and Rice ", "Pasta ",{6,9,21}, {10,9,21}, 110," Killograms",30,4.9 };
    Products[18] = {18,"Brown Rice ", "Pasta and Rice ", "Rice ",{6,9,21}, {10,9,21}, 180,"Killograms ",30,4.7 };
    Products[19] = {19,"White Rice ", "Pasta and Rice ", "Rice ",{6,9,21}, {10,9,21},160," Killograms",27,2.5 };

//Initialising Dairy and meat sample data
    Products[20] = {20,"Beef ", "Dairy and Meat ", "Meat ",{6,9,21}, {10,9,21},150,"Killogram ",250,4.9 };
    Products[21] = {21,"Pork ", "Dairy and Meat ", "Meat ",{6,9,21}, {10,9,21},154,"Killogram ", 200,2.5 };
    Products[22] = {22,"Mutton ", "Dairy and Meat ", "Meat ",{6,9,21}, {10,9,21},144,"Killogram ",260, 4.4};
    Products[23] = {23,"Chicken ", "Dairy and Meat ", "Meat ",{6,9,21}, {10,9,21},145,"Killogram ",300,4.9 };
    Products[24] = {24,"Turkey", "Dairy and Meat ", "Meat ",{6,9,21}, {10,9,21},133,"Killogram ",280,3.9 };
    Products[25] = {25,"Butter ", "Dairy and Meat ", "Dairy ",{6,9,21}, {10,9,21},130,"Killograms ",450,5 };
    Products[26] = {26,"Milk ", "Dairy and Meat ", "Dairy ",{6,9,21}, {10,9,21}, 110,"Liters ",40,4.9 };
    Products[27] = {27,"Mozzarella ", "Dairy and Meat ", "Cheese ",{6,9,21}, {10,9,21},110,"Killogram ",320,4.5 };
    Products[28] = {28,"Cheddar ", "Dairy and Meat ", "Cheese ",{6,9,21}, {10,9,21},120,"Killogram ",300,4.9 };
    Products[29] = {29,"Parmesan ", "Dairy and Meat ", "Cheese ",{6,9,21}, {10,9,21},110,"Killogram ",360,4.4 };
    Products[30] = {30,"Gouda ", "Dairy and Meat ", "Cheese ",{6,9,21}, {10,9,21},330,"Killogram ",380,5 };
    Products[31] = {31,"Yoghurt ", "Dairy and Meat ", "Dairy ",{6,9,21}, {10,9,21},430,"Litres ",60,4.9 };
    Products[32] = {32,"Powdered Milk ", "Dairy and Meat ", "Dairy ",{6,9,21}, {10,9,21},230,"Killogram ",1200,4.6 };
    Products[33] = {33,"Ice Cream", "Dairy and Meat ", "Dairy ",{6,9,21}, {10,9,21},100,"Killogram ",310,5 };

    //Initializing Beverage and soft Drinks sample data
    Products[34] = {34,"Beer ", "Beverage and Soft Drinks ", "Beverage ",{6,9,21}, {10,9,21},103,"Milliliter ", 200,2.5 };
    Products[35] = {35,"Cider ", "Beverage and Soft Drinks ", "Beverage ",{6,9,21}, {10,9,21},103,"Milliliter ",260, 4.4};
    Products[36] = {36,"Hard Soda ", "Beverage and Soft Drinks ", "Beverage ",{6,9,21}, {10,9,21},100,"Milliliter ",300,4.9 };
    Products[37] = {37,"Wine", "Beverage and Soft Drinks ", "Beverage ",{6,9,21}, {10,9,21},102,"Milliliter ",280,3.9 };
    Products[38] = {38,"Barley ", "Beverage and Soft Drinks ", "Beverage ",{6,9,21}, {10,9,26},101,"Milliliters ",450,5 };
    Products[39] = {39,"Turkish ", "Beverage and Soft Drinks ", "Beverage ",{6,9,21}, {10,9,27}, 106,"Liters ",40,4.9 };
    Products[40] = {40,"Moka ", "Beverage and Soft Drinks ", "Beverage ",{6,9,21}, {10,9,25},100,"Milliliter ",320,4.5 };
    Products[41] = {41,"Kamora ", "Beverage and Soft Drinks ", "Soft Drinks ",{6,9,21}, {10,9,21},107,"Milliliter ",300,4.9 };
    Products[42] = {42,"Amarula ", "Beverage and Soft Drinks ", "Soft Drinks ",{6,9,20}, {10,9,21},108,"Milliliter ",360,4.4 };
    Products[43] = {43,"Carolans ", "Beverage and Soft Drinks ", "Soft Drinks ",{6,9,21}, {10,9,21},109,"Milliliter ",380,5 };
    Products[44] = {44,"Rosolio ", "Beverage and Soft Drinks ", "Soft Drinks ",{6,9,21}, {10,9,21},234,"Litres ",60,4.9 };
    Products[45] = {45,"Aurum ", "Beverage and Soft Drinks ", "Soft Drinks ",{6,9,21}, {10,9,21},257,"Milliliter ",1200,4.6 };
    Products[46] = {46,"Cointreau", "Beverage and Soft Drinks ", "Soft Drinks ",{6,9,21}, {10,9,21},234,"Milliliter ",300,5 };

    //Initializing Snacks sample data
    Products[47] = {47,"Milky Way ", "Snack ", "Snack ",{6,9,21}, {10,9,17},100,"Milliliter ", 270,2.5 };
    Products[48] = {48,"Sun Chips ", "Snack ", "Snack ",{6,9,21}, {10,9,21},100,"Milliliter ",290, 4.4};
    Products[49] = {49,"Suncake ", "Snack ", "Snack ",{6,9,20}, {10,9,15},100,"Milliliter ",700,4.9 };
    Products[50] = {50,"Vadai", "Snack ", "Snack ",{6,9,19}, {10,9,21},100,"Milliliter ",340,3.9 };
    Products[51] = {51,"Popcorn ", "Snack ", "Snack ",{6,9,17}, {10,9,13},100,"Milliliters ",240,5 };
    Products[52] = {52,"Candy ", "Snack ", "Snack ",{6,9,19}, {10,9,24}, 100,"Liters ",40,4.9 };
    Products[53] = {53,"Fruit ", "Snack ", "Snack ",{6,9,18}, {10,9,21},100,"Milliliter ",30,4.5 };
    Products[54] = {54,"Pretzels ", "Snack ", "Snack ",{6,9,21}, {10,9,21},100,"Milliliter ",10,4.9 };
    Products[55] = {55,"Doughnuts ", "Snack ", "Snack ",{6,9,21}, {10,9,15},100,"Milliliter ",30,4.4 };
    Products[56] = {56,"Peanuts ", "Snack ", "Snack ",{6,9,21}, {10,9,16},100,"Milliliter ",40,5 };
    Products[57] = {57,"Poha ", "Snack ", "Snack ",{6,9,21}, {10,9,20},100,"Litres ",60,4.9 };
    Products[58] = {58,"Momos ", "Snack ", "Snack ",{6,9,21}, {10,9,21},100,"Milliliter ",120,4.6 };
    Products[59] = {59,"Khaman", "Snack ", "Snack ",{6,9,21}, {10,9,21},100,"Milliliter ",15,5 };


ReturnToChoice:
    cout<<"Choose how you want to sort: "<<endl;
    cout<<"1. Unit Price"<<endl;
    cout<<"2. Rating"<<endl;
    cout<<"3. Production date"<<endl;
    cout<<"4. Expire date"<<endl;
    cout<<"5. Quantity"<<endl;
    cout<<"6. Sales"<<endl;
    char Choice,OrderChoice;
    cout<<"Your choice: ";
    cin>>Choice;
ReturnToOrderChoice:
    cout<<"Choose Order"<<endl;
    cout<<"1. Ascending Order"<<endl;
    cout<<"2. Descending Order"<<endl;
    cout<<"Your choice: ";
    cin>>OrderChoice;

    switch(Choice)
    {
    case '1':
        if(OrderChoice == '1')
        {
            sort(Products, Products+NumberOfProducts, CompareUsingUnitPriceAscending);
            PrintInTableFormat();
        }
        else if(OrderChoice == '2')
        {
            sort(Products, Products+NumberOfProducts, CompareUsingUnitPriceDescending);
            PrintInTableFormat();
        }
        else
        {
            cout<<"Invalid Choice! Try Again";
            goto ReturnToOrderChoice;
        }
        break;
    case '2':
        if(OrderChoice == '1')
        {
            sort(Products, Products+NumberOfProducts, CompareUsingRatingAscending);
            PrintInTableFormat();
        }
        else if(OrderChoice == '2')
        {
            sort(Products, Products+NumberOfProducts, CompareUsingRatingDescending);
            PrintInTableFormat();
        }
        else
        {
            cout<<"Invalid Choice! Try Again";
            goto ReturnToOrderChoice;
        }
        break;
    case '3':
        if(OrderChoice == '1')
        {
            sort(Products, Products+NumberOfProducts, CompareUsingProductionDateAscending);
            PrintInTableFormat();
        }
        else if(OrderChoice == '2')
        {
            sort(Products, Products+NumberOfProducts, CompareUsingProductionDateDescending);
            PrintInTableFormat();
        }
        else
        {
            cout<<"Invalid Choice! Try Again";
            goto ReturnToOrderChoice;
        }
        break;
    case '4':
        if(OrderChoice == '1')
        {
            sort(Products, Products+NumberOfProducts, CompareUsingExpirationDateAscending);
            PrintInTableFormat();
        }
        else if(OrderChoice == '2')
        {
            sort(Products, Products+NumberOfProducts, CompareUsingExpirationDateDescending);
            PrintInTableFormat();
        }
        else
        {
            cout<<"Invalid Choice! Try Again";
            goto ReturnToOrderChoice;
        }
        break;
    case '5':
        if(OrderChoice == '1')
        {
            sort(Products, Products+NumberOfProducts, CompareUsingQuantityAscending);
            PrintInTableFormat();
        }
        else if(OrderChoice == '2')
        {
            sort(Products, Products+NumberOfProducts, CompareUsingQuantityDescending);
            PrintInTableFormat();
        }
        else
        {
            cout<<"Invalid Choice! Try Again";
            goto ReturnToOrderChoice;
        }
        break;
    case '6':
        if(OrderChoice == '1')
        {
            sort(Products, Products+NumberOfProducts, CompareUsingSalesAscending);
            PrintInTableFormat();
        }
        else if(OrderChoice == '2')
        {
            sort(Products, Products+NumberOfProducts, CompareUsingSalesDescending);
            PrintInTableFormat();
        }
        else
        {
            cout<<"Invalid Choice! Try Again";
            goto ReturnToOrderChoice;
        }
        break;
    default:
        cout<<"Invalid Choice! Try Again";
        system("cls");
        goto ReturnToChoice;
    }

    return 0;
}
