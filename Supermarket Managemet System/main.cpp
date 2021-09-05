
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <stdio.h>
#include <string>

using namespace std;

// Global Variables
int NumberOfProducts = 33;

// Resizes the console window
void ResizeWindow(){
    HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1600, 800, TRUE);
}
struct Date{
    int Day,Month,Year;
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
    int Sales = 0;
} Products[9999];



void PrintTableDividers(){
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
void PrintTableHeader(){
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

void PrintInItemValue(Product Item) {
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

void PrintInTableFormat(){
    // Initialization
    ResizeWindow();
    // Print Full Table For reference to edit
    cout << endl << " Here's a list of all products... " << endl << endl;
    // Print In Table Format Function
    PrintTableDividers();
    PrintTableHeader();
    // Loop Through the samples to print the details in table format
    for(int i = 0; i < NumberOfProducts; i++){
        PrintTableDividers();
        PrintInItemValue(Products[i]);
    }
    PrintTableDividers();
}

void Search(int SearchedProduct){

int i;
for( i = 1; i<9999; i++){

    if( SearchedProduct == Products[i].ProductNumber && Products[i].ProductNumber != 0){
        cout<<endl<<endl;
        PrintTableHeader();
        PrintTableDividers();
        PrintInItemValue(Products[i]);
        cout<<endl<<endl;
        i = 9999;
    }
    else if(Products[i].ProductNumber == 0){
       i = 9999;
       cout<<"\n**********Product Not found**********\n"<<endl;
    }
}



}



int main(){
//Initializing Bread and Bakery sample data
Products[1] = {1 ,"Banana Bread ", "Bread and Bakery ", "Bread ",{6,9,21}, {10,9,21}, 200,"Loafs ",22 ,4.9 };
Products[2] = {2 ,"Whole Wheat ", "Bread and Bakery ", "Bread ",{6,9,21}, {10,9,21},200 ,"Loafs ",3 ,2.5 };
Products[3] = {3 ,"Sourdough ", "Bread and Bakery ", "Bread ",{6,9,21}, {10,9,21}, 200,"Loafs ",4 ,4.7 };
Products[4] = {4 ,"Baguette ", "Bread and Bakery ", "Bread ",{6,9,21}, {10,9,21},200 ,"Loafs ",10 ,3 };
Products[5] = {5 ,"Difo Dabo ", "Bread and Bakery ", "Bread ",{6,9,21}, {10,9,21}, 200," Loafs",20 ,4.9 };
Products[6] = {6 ,"White Bread ", "Bread and Bakery ", "Bread ",{6,9,21}, {10,9,21}, 200,"Loafs ",3 ,2.8 };
Products[7] = {7 ,"Carrot Cake ", "Bread and Bakery ", "Bread ",{6,9,21}, {10,9,21},200 ,"Loafs ",20 ,4.1 };
Products[8] = {8 ,"Bagels ", "Bread and Bakery ", "Bread ",{6,9,21}, {10,9,21}, 200," Loafs",12 ,3.9 };
Products[9] = {9 ,"Chocolate Chip ", "Bread and Bakery ", "Cookies ",{6,9,21}, {10,9,21},200 ,"Kilogram ",30 ,4.8 };
Products[10] = {10 ,"Shortbread Cookie ", "Bread and Bakery ", "Cookies ",{6,9,21}, {10,9,21}, 200,"Kilogram ",28 ,4 };
Products[11] = {11 ,"Peanut Butter ", "Bread and Bakery ", "Cookies ",{6,9,21}, {10,9,21},200 ,"Kilogram ",28 ,2.5 };

//Initializing Pasta and rice sample data
Products[12] = {12,"Short Pasta ", "Pasta and Rice ", "Pasta ",{6,9,21}, {10,9,21}, 100,"Kilogram ",25 ,4.3 };
Products[13] = {13,"Long Pasta ", "Pasta and Rice ", "Pasta ",{6,9,21}, {10,9,21}, 100,"Kilogram ",25 ,4.3 };
Products[14] = {14,"Macaroni ", "Pasta and Rice ", "Pasta ",{6,9,21}, {10,9,21}, 100,"Kilogram ",24 ,4 };
Products[15] = {15,"Fettuccine", "Pasta and Rice ", "Pasta ",{6,9,21}, {10,9,21},100 ,"Kilogram ",28 ,2.5 };
Products[16] = {16,"Lasagna", "Pasta and Rice ", "Pasta ",{6,9,21}, {10,9,21}, 100,"Kilogram ",32 ,5 };
Products[17] = {17,"Spaghetti", "Pasta and Rice ", "Pasta ",{6,9,21}, {10,9,21}, 100," Kilogram",30 ,4.9 };
Products[18] = {18,"Brown Rice ", "Pasta and Rice ", "Rice ",{6,9,21}, {10,9,21}, 100,"Kilogram ",30 ,4.7 };
Products[19] = {19,"White Rice ", "Pasta and Rice ", "Rice ",{6,9,21}, {10,9,21},100 ," Kilogram",27 ,2.5 };

//Initializing Dairy and meat sample data
Products[20] = {20 ,"Beef ", "Dairy and Meat ", "Meat ",{6,9,21}, {10,9,21},100 ,"Kilogram ",250 ,4.9 };
Products[21] = {21 ,"Pork ", "Dairy and Meat ", "Meat ",{6,9,21}, {10,9,21},100 ,"Kilogram ", 200,2.5 };
Products[22] = {22 ,"Mutton ", "Dairy and Meat ", "Meat ",{6,9,21}, {10,9,21},100 ,"Kilogram ",260 , 4.4};
Products[23] = {23 ,"Chicken ", "Dairy and Meat ", "Meat ",{6,9,21}, {10,9,21},100 ,"Kilogram ",300 ,4.9 };
Products[24] = {24 ,"Turkey", "Dairy and Meat ", "Meat ",{6,9,21}, {10,9,21},100 ,"Kilogram ",280 ,3.9 };
Products[25] = {25 ,"Butter ", "Dairy and Meat ", "Dairy ",{6,9,21}, {10,9,21},100 ,"Kilogram ",450 ,5 };
Products[26] = {26 ,"Milk ", "Dairy and Meat ", "Dairy ",{6,9,21}, {10,9,21}, 100,"Liters ",40 ,4.9 };
Products[27] = {27 ,"Mozzarella ", "Dairy and Meat ", "Cheese ",{6,9,21}, {10,9,21},100 ,"Kilogram ",320 ,4.5 };
Products[28] = {28 ,"Cheddar ", "Dairy and Meat ", "Cheese ",{6,9,21}, {10,9,21},100 ,"Kilogram ",300 ,4.9 };
Products[29] = {29 ,"Parmesan ", "Dairy and Meat ", "Cheese ",{6,9,21}, {10,9,21},100 ,"Kilogram ",360 ,4.4 };
Products[30] = {30 ,"Gouda ", "Dairy and Meat ", "Cheese ",{6,9,21}, {10,9,21},100 ,"Kilogram ",380 ,5 };
Products[31] = {31 ,"Yoghurt ", "Dairy and Meat ", "Dairy ",{6,9,21}, {10,9,21},100 ,"Liters ",60 ,4.9 };
Products[32] = {32 ,"Powdered Milk ", "Dairy and Meat ", "Dairy ",{6,9,21}, {10,9,21},100 ,"Kilogram ",1200 ,4.6 };
Products[33] = {33 ,"Ice Cream", "Dairy and Meat ", "Dairy ",{6,9,21}, {10,9,21},100 ,"Kilogram ",300 ,5 };


int Choice, InvalidChoiceCounter= 0;
Menu:cout<<"1. Print all Products. "<<endl;
       cout<<"2. Search for product. "<<endl;
       cout<<"3. Exit "<<endl;
       cout<<"Choice: ";

while(!(cin>>Choice)){
        cout<< "Invalid input.\n\n";
        cin.clear();
        cin.ignore(20, '\n');
        goto Menu;
}

switch(Choice){
    case 1:
        system("cls");
        PrintInTableFormat();
        cout<<endl<<endl<<endl;
        goto Menu;
    case 2:
        system("cls");
        int ProductNumberSearch;//Search Key
Search:cout<<"Enter the Product number of the item you would like to search."<<endl;
       cout<<"Product Number: ";

       while(!(cin>>ProductNumberSearch)){
        cout<< "\nInvalid input.\n\n";
        cin.clear();
        cin.ignore(20, '\n');
        cout<<"Re-enter Product Number: ";
        InvalidChoiceCounter++;
        if(InvalidChoiceCounter >= 3){
        InvalidChoiceCounter = 0;
        goto Menu;//We can make it go to the main menu when we merge it all
       }
       }

    Search(ProductNumberSearch);//Calling Search function
    goto Menu;
    break;
    case 3:
        return 0;//We can make it go to the main menu when we merge it all
    break;
    default:
    InvalidChoiceCounter++;
    cout<<"\nInvalid Choice."<<endl;

    if(InvalidChoiceCounter >= 3){
        InvalidChoiceCounter = 0;
        goto Menu;//We can make it go to the main menu when we merge it all
    }

}


/*ResizeWindow();
PrintTableDividers();
PrintTableHeader();*/
}
