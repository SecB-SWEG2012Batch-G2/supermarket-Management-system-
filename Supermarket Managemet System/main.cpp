
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <stdio.h>
#include <string>

using namespace std;

// Global Variables
int NumberOfProducts = 63, FlagDelete = 0, FlagEdit = 0;


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
    //ResizeWindow();
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
       FlagDelete = 1; FlagEdit = 1;
       cout<<"\n**********Product Not found**********\n"<<endl;
    }
}

}

void EditItem(){
    // Print Full Table For reference to edit
    //PrintInTableFormat();
    // Enter Serial Number of a product to edit
    int SerialNumber;
    cout << endl << " Enter Serial Number Of Item you want to edit: ";

    while(!(cin>>SerialNumber)){
        cout<< "\n**********Invalid input.**********\n";
        cout << endl << " Serial Number : ";
        cin.clear();
        cin.ignore(20, '\n');
    }
    Search(SerialNumber);

    if(!(FlagEdit)){
    Product *Item = &Products[SerialNumber];
    // List of options to edit
    int EditChoice;
edit:cout << endl << " What would you like to edit?" << endl;
    cout << "  1. Product Name" << "\t\t  6. Quantity" << endl;
    cout << "  2. Product Category" << "\t\t  7. Measurement Unit" << endl;
    cout << "  3. Product Type" << "\t\t  8. Unit Price" << endl;
    cout << "  4. Production Date" << "\t\t  9. Rating" << endl;
    cout << "  5. Expire Date" << "\t\t 10. Sales" << endl;
    cout << endl << " Edit Choice: ";

     while(!(cin>>EditChoice)){
        cout<< "\n**********Invalid input.**********\n";
        cout << endl << " Enter Choice( 1 - 10): ";
        cin.clear();
        cin.ignore(20, '\n');
    }
    if(EditChoice> 10 || EditChoice<1){
        cout<<" Enter Choice( 1 - 10): ";
        goto edit;
    }
    cout << endl;
    // Accept new values based on choice
    switch(EditChoice){
        case 1:
            cout << " Enter New Product Name: ";
            cin >> Item->ProductName;
            break;
        case 2:
            cout << " Enter New Product Category: ";
            cin >> Item->ProductName;
            break;
        case 3:
            cout << "Enter New Product Type: ";
            cin >> Item->ProductName;
            break;
        case 4:
        date:cout << " Enter New Production Date" << endl;
            cout << "\t New Day: ";
            while(!( cin >> Item->ProductionDate.Day)){  // INPUT VALIDATION FOR DATE EDITING
            cout<< "\n**********Invalid input.**********\n";
            cin.clear();
            cin.ignore(20, '\n');
            goto date;
            }
            if( Item->ProductionDate.Day>30 || Item->ProductionDate.Day<1){
                cout<<" **********Invalid Day.********** \n"; goto date;
            }

            cout << "\t New Month: ";
            cin >> Item->ProductionDate.Month;
            while(!( cin >> Item->ProductionDate.Month)){  // INPUT VALIDATION FOR DATE EDITING
            cout<< "\nInvalid input.\n";
            cin.clear();
            cin.ignore(20, '\n');
            goto date;
            }
            if( Item->ProductionDate.Month<1 || Item->ProductionDate.Month>12){
                cout<<" Invalid Day. \n"; goto date;
            }
            cout << "\t New Year: ";
            while(!( cin >> Item->ProductionDate.Year)){  // INPUT VALIDATION FOR DATE EDITING
            cout<< "\n**********Invalid input.**********\n";
            cin.clear();
            cin.ignore(20, '\n');
            goto date;
            }
            if( Item->ProductionDate.Year<2015 || Item->ProductionDate.Year>2021){
                cout<<"**********Invalid Day.**********\n"; goto date;
            }
            break;
        case 5:
            cout << " Enter New Expire Date: ";
            cout << "\t New Day: ";
            cin >> Item->ExpireDate.Day;
            while(!( cin >> Item->ExpireDate.Day)){  // INPUT VALIDATION FOR DATE EDITING
            cout<< "\n**********Invalid input.**********\n";
            cin.clear();
            cin.ignore(20, '\n');
            goto date;
            }
            if( Item->ExpireDate.Day<2015 || Item->ExpireDate.Day>2021){
                cout<<"**********Invalid Day.**********\n"; goto date;
            }

            cout << "\t New Month: ";
            while(!( cin >> Item->ExpireDate.Month)){  // INPUT VALIDATION FOR DATE EDITING
            cout<< "\n**********Invalid input.**********\n";
            cin.clear();
            cin.ignore(20, '\n');
            goto date;
            }
            if( Item->ExpireDate.Month<2015 || Item->ExpireDate.Month>2021){
                cout<<"**********Invalid Day.**********\n"; goto date;
            }

            cout << "\t New Year: ";
            while(!( cin >> Item->ExpireDate.Year)){  // INPUT VALIDATION FOR DATE EDITING
            cout<< "\n**********Invalid input.**********\n";
            cin.clear();
            cin.ignore(20, '\n');
            goto date;
            }
            if( Item->ExpireDate.Year<2015 || Item->ExpireDate.Year>2021){
                cout<<"**********Invalid Day.**********\n"; goto date;
            }

            break;
        case 6:
            cout << " Enter New Quantity: ";
            cin >> Item->Quantity;
            break;
        case 7:
            cout << " Enter New Measurement Unit: ";
            getline(cin,Item->MeasurementUnit);
            break;
        case 8:
            cout << " Enter New Unit Price: ";
            while(!(cin>>Item->UnitPrice)){
            cout<< "**********Invalid Day.**********\n";
            cout << " Enter New Unit Price: ";
            cin.clear();
            cin.ignore(20, '\n');

            }

            break;
        case 9:
            cout << " Enter New Rating: ";
            while(!(cin>>Item->Rating)){
            cout<< "**********Invalid Day.**********\n";
            cout << " Enter New Rating: ";
            cin.clear();
            cin.ignore(20, '\n');

            }
            break;
        case 10:
            cout << " Enter New Sale ";
            while(!(cin>>Item->Sales)){
            cout<< "**********Invalid Day.**********\n";
            cout << " Enter New Rating: ";
            cin.clear();
            cin.ignore(20, '\n');

            }

            break;
    }
    system("color 0A");
    cout << endl << " \t ---- \t Item Edited Successfully! \t ----" << endl << endl;
    }
    FlagEdit = 0;
    system("pause");
    system("color 0F");
    system("cls");

}

// This function asks for a serial number of an item and then it allows you to delete it from the stock
void DeleteItem(){
    system("cls");
    // Print Full Table For reference to edit
    //PrintInTableFormat();
    // Enter Serial Number of a product to edit
    AskDeletion:
    int SerialNumber;
    cout << endl << " Enter Serial Number Of Item you want to delete: ";

    while(!(cin>>SerialNumber)){   // INPUT VALIDATION FOR
        cout<< "\nInvalid input.\n\n";
        cin.clear();
        cin.ignore(20, '\n');
    }
    Search(SerialNumber);

    if( !(FlagDelete)){
    Product *Item = &Products[SerialNumber];
    cout << endl << " Are you sure you want to delete this item? (Y/N): ";
    system("color 0C");
    char ConfirmDeletion;
    cin >> ConfirmDeletion;
    if(ConfirmDeletion == 'Y'){
        for(int i = SerialNumber; i < NumberOfProducts - 1; i++){
            Products[i] = Products[i+1];
        }
        NumberOfProducts--;
        for(int i = 0; i < NumberOfProducts; i++){
            Item = &Products[i];
            Item->ProductNumber = i;
        }
        system("color 0A");
        cout << endl << " \t ---- \t Item Deleted Successfully! \t ----" << endl << endl;
        system("pause");
        system("cls");
    } else if (ConfirmDeletion == 'N'){
        system("color 0E");
        goto AskDeletion;
    }
    }
system("color 0F");
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

 //Initializing Beverage and soft Drinks sample data
Products[34] = {34,"Beer ", "Beverage and Soft Drinks ", "Beverage ",{6,9,21}, {0,0,0},103,"Milliliter ", 200,2.5 };
Products[35] = {35,"Cider ", "Beverage and Soft Drinks ", "Beverage ",{6,9,21}, {10,9,21},103,"Milliliter ",260, 4.4};
Products[36] = {36,"Hard Soda ", "Beverage and Soft Drinks ", "Beverage ",{3,12,21}, {10,9,21},100,"Milliliter ",300,4.9 };
Products[37] = {37,"Wine", "Beverage and Soft Drinks ", "Beverage ",{10,12,21}, {10,9,21},102,"Milliliter ",280,3.9 };
Products[38] = {38,"Barley ", "Beverage and Soft Drinks ", "Beverage ",{6,9,21}, {10,9,26},101,"Milliliters ",450,5 };
Products[39] = {39,"Turkish ", "Beverage and Soft Drinks ", "Beverage ",{6,9,21}, {10,9,27}, 106,"Liters ",40,4.9 };
Products[40] = {40,"Moka ", "Beverage and Soft Drinks ", "Beverage ",{6,9,21}, {10,9,25},100,"Milliliter ",320,4.5 };
Products[41] = {41,"Kamora ", "Beverage and Soft Drinks ", "Soft Drinks ",{6,9,21}, {10,9,21},107,"Milliliter ",300,4.9 };
Products[42] = {42,"Amarula ", "Beverage and Soft Drinks ", "Soft Drinks ",{6,9,20}, {10,9,21},108,"Milliliter ",360,4.4 };
Products[43] = {43,"Carolans ", "Beverage and Soft Drinks ", "Soft Drinks ",{6,9,21}, {10,9,21},109,"Milliliter ",380,5 };
Products[44] = {44,"Rosolio ", "Beverage and Soft Drinks ", "Soft Drinks ",{3,9,21}, {10,9,21},234,"Litres ",60,4.9 };
Products[45] = {45,"Aurum ", "Beverage and Soft Drinks ", "Soft Drinks ",{6,9,21}, {10,9,21},257,"Milliliter ",1200,4.6 };
Products[46] = {46,"Cointreau", "Beverage and Soft Drinks ", "Soft Drinks ",{6,9,21}, {10,9,21},234,"Milliliter ",300,5};
//Initializing Snacks sample data
Products[47] = {47,"Milky Way ", "Snack ", "Snack ",{6,9,21}, {10,9,17},100,"Milliliter ", 270,2.5 };
Products[48] = {48,"Sun Chips ", "Snack ", "Snack ",{1,9,21}, {10,9,21},100,"Milliliter ",290, 4.4};
Products[49] = {49,"Suncake ", "Snack ", "Snack ",{6,9,20}, {10,9,15},100,"Milliliter ",700,4.9 };
Products[50] = {50,"Vadai", "Snack ", "Snack ",{6,9,19}, {10,9,21},100,"Milliliter ",340,3.9 };
Products[51] = {51,"Popcorn ", "Snack ", "Snack ",{10,9,17}, {10,9,13},100,"Milliliters ",240,5 };
Products[52] = {52,"Candy ", "Snack ", "Snack ",{6,9,19}, {10,9,24}, 100,"Liters ",40,4.9 };
Products[53] = {53,"Fruit ", "Snack ", "Snack ",{6,9,18}, {10,9,21},100,"Milliliter ",30,4.5 };
Products[54] = {54,"Pretzels ", "Snack ", "Snack ",{7,9,21}, {10,9,21},100,"Milliliter ",10,4.9 };
Products[55] = {55,"Doughnuts ", "Snack ", "Snack ",{6,9,21}, {10,9,15},100,"Milliliter ",30,4.4 };
Products[56] = {56,"Peanuts ", "Snack ", "Snack ",{6,9,21}, {10,9,16},100,"Milliliter ",40,5 };
Products[57] = {57,"Poha ", "Snack ", "Snack ",{2,9,21}, {10,9,20},100,"Litres ",60,4.9 };
Products[58] = {58,"Momos ", "Snack ", "Snack ",{9,9,21}, {10,9,21},100,"Milliliter ",120,4.6 };
Products[59] = {59,"Khaman", "Snack ", "Snack ",{8,9,21}, {10,9,21},100,"Milliliter ",15,5 };

//Utensils
Products[60] = {60,"Spoon","Kitchen Utensils","Spoon",{10,11,2017},{14,10,2020},40,"Items",30.45,2.5};
Products[61] = {61,"Napkins","Sanitary","Baby Wipes",{20,12,2018},{15,11,2021},12,"Packages",40.00,4.5};
Products[62] = {62,"Lotion","Health And Bodycare","Nivea",{30,10,2019},{16,12,2022},10,"Bottle",99.39,5.0};


int Choice, InvalidChoiceCounter= 0;
Menu:cout<<"1. Print all Products. "<<endl;
       cout<<"2. Search for product. "<<endl;
       cout<<"3. Delete Item from Stock. "<<endl;
       cout<<"4. Edit a Product "<<endl;
        cout<<"5. Exit "<<endl;
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
       cout<<"Enter the Product number of the item you would like to search."<<endl;
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
    DeleteItem();
    goto Menu;

    case 4:
    system("cls");
    EditItem();
    goto Menu;
    case 5:
        return 0;//We can make it go to the main menu when we merge it all
    break;
    default:
    cout<<"\nInvalid Choice."<<endl;
    system("pause");
    system("cls");
    goto Menu;
}


}


