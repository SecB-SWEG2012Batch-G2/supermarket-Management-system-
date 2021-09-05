#include <iostream>
#include <cstring>
#include <iomanip>
#include <windows.h>
#include <stdio.h>
#include <string>

using namespace std;

// Global Variables
int NumberOfProducts = 3;
char MenuChoice[11];
char ChosenFunction[31];

//Global structure Date
struct Date{
    int DD, MM, YY;
};



// Resizes the console window
void ResizeWindow(){
    HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1600, 800, TRUE);
}


// Super Structure
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

    //Unit Profit Calculator
    float Profit(){
        float UnitProfit;
        UnitProfit= UnitPrice*0.03;
        return UnitProfit;
    }

    //User Input Function
    void CreateProduct(){
        cout<<"\n Please Enter The Product Name : ";
        cin>>ProductNumber;

        cout<<"\n Please Enter The Category Of The Product : ";
        cin>>Category;

        cout<<"\n Please Enter The Product Type : ";
        cin>>ProductType;

        cout<<"\n Please Enter The Production Date : ";
        cin>>ProductionDate.DD;

        if(ProductionDate.DD == 0){ //In case of  a null value on Production Date
            ProductionDate.MM=0;
            ProductionDate.YY=0;
        }

        else{
            cin>>ProductionDate.MM;
            cin>>ProductionDate.YY;
        }

        cout<<"\n Please Enter The Expired Date : ";
        cin>>ExpireDate.DD;

        if(ExpireDate.DD == 0){ //In case of  a null value on Expire Date
            ExpireDate.MM=0;
            ExpireDate.YY=0;
        }


        else{
            cin>>ExpireDate.MM;
            cin>>ExpireDate.YY;
        }

        cout<<"\n Please Enter The Quantity: ";
        cin>>Quantity;

        cout<<"\n Please Enter The Unit Price: ";
        cin>>UnitPrice;

        cout<<"\n Please Enter The Price: ";
        cin>>Rating;

        cout<<"\n Please Enter The Number of Sales: ";
        cin>>Sales;

    }


}Products[9999];

  void welcomeScreen();
  void MainMenu();
  void GoodbyeScreen();
  void Manager();
  void Employee();

int main(){
    // Global Theme
    system("color 0E");

    MainMenu();
    return 0;
}

//Product *Products = new Product[NumberOfProducts];

// Function to Print Table Dividers " +--+ "
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
// Function to Print Table Headers (Product Name, Price)
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
// This Functions Prints the details of the passed product structure
void PrintInItemValue(Product Item) {
    // Table Values
    string ProductionDate = to_string(Item.ProductionDate.DD) + "/" + to_string(Item.ProductionDate.MM) + "/" + to_string(Item.ProductionDate.YY);
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

// This Function asks a serial number of an item and then it allows you to edit properties of it
void EditItem(){
    // Print Full Table For reference to edit
    PrintInTableFormat();
    // Enter Serial Number of a product to edit
    int SerialNumber;
    cout << endl << " Enter Serial Number Of Item you want to edit: ";
    cin >> SerialNumber;
    Product *Item = &Products[SerialNumber];
    // List of options to edit
    int EditChoice;
    cout << endl << " What would you like to edit?" << endl;
    cout << "  1. Product Name" << "\t\t  6. Quantity" << endl;
    cout << "  2. Product Category" << "\t\t  7. Measurement Unit" << endl;
    cout << "  3. Product Type" << "\t\t  8. Unit Price" << endl;
    cout << "  4. Production Date" << "\t\t  9. Rating" << endl;
    cout << "  5. Expire Date" << "\t\t 10. Sales" << endl;
    cout << endl << " Edit Choice: ";
    cin >> EditChoice;
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
            cout << " Enter New Production Date" << endl;
            cout << "\t New Day: ";
            cin >> Item->ProductionDate.DD;
            cout << "\t New Month: ";
            cin >> Item->ProductionDate.MM;
            cout << "\t New Year: ";
            cin >> Item->ProductionDate.YY;
            break;
        case 5:
            cout << " Enter New Expire Date: ";
            cout << "\t New Day: ";
            cin >> Item->ExpireDate.DD;
            cout << "\t New Month: ";
            cin >> Item->ExpireDate.MM;
            cout << "\t New Year: ";
            cin >> Item->ExpireDate.YY;
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
            cin >> Item->UnitPrice;
            break;
        case 9:
            cout << " Enter New Rating: ";
            cin >> Item->Rating;
            break;
        case 10:
            cout << " Enter New Sale ";
            cin >> Item->Sales;
            break;
    }
    system("color 0A");
    cout << endl << " \t ---- \t Item Editted Successfully! \t ----" << endl << endl;
    system("pause");
    system("cls");

}

// This function asks for a serial number of an item and then it allows you to delete it from the stock
void DeleteItem(){
    system("cls");
    // Print Full Table For reference to edit
    PrintInTableFormat();
    // Enter Serial Number of a product to edit
    AskDeletion:
    int SerialNumber;
    cout << endl << " Enter Serial Number Of Item you want to delete: ";
    cin >> SerialNumber;
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


//Welcome Screen
void welcomeScreen(){
    cout << R"(


  ,ad8888ba,                                     ad88888ba   88
 d8"'    `"8b                            ,d     d8"     "8b  88
d8'                                      88     Y8,          88
88             ,adPPYYba,  8b,dPPYba,  MM88MMM  `Y8aaaaa,    88,dPPYba,    ,adPPYba,   8b,dPPYba,
88             ""     `Y8  88P'   "Y8    88       `"""""8b,  88P'    "8a  a8"     "8a  88P'    "8a
Y8,            ,adPPPPP88  88            88             `8b  88       88  8b       d8  88       d8
 Y8a.    .a8P  88,    ,88  88            88,    Y8a     a8P  88       88  "8a,   ,a8"  88b,   ,a8"
  `"Y8888Y"'   `"8bbdP"Y8  88            "Y888   "Y88888P"   88       88   `"YbbdP"'   88`YbbdP"'
                                                                                       88
                                                                                       88


    )" << endl;
    cout << endl;
    cout << "\t*" << setfill('*') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(32) << "W E L C O M E !" << setfill(' ') << setw(18) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill('-') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(40) << "Choose an Account to work with" << setfill(' ') << setw(10) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(30) << "1. Manager" << setfill(' ') << setw(20) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(31) << "2. Employee" << setfill(' ') << setw(19) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(30) << "3. Cashier" << setfill(' ') << setw(20) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill('*') << setw(50) << "*" << endl;
    cout << endl;
}
// Goodbye Screen
void GoodbyeScreen(){
    cout << endl << endl;
    cout << "\t*" << setfill('*') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(32) << "G O O D  B Y E !" << setfill(' ') << setw(18) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill('*') << setw(50) << "*" << endl;
    cout << endl << endl << endl << endl << endl;
}

//Manger or Administrator's Account
void Manager(){
    char username[6], password[10];
    char AdminPassword[] ="Adm12345";
    char AdminUsername[] = "Admin";

    PasswordEntry:

    cout << endl << endl;
    cout << "\t*" << setfill('*') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(32) << "Welcome to Admin!" << setfill(' ') << setw(18) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(45) << "Please Enter your User Name and Password" << setfill(' ') << setw(5) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill('*') << setw(50) << "*" << endl;
    cout<<"User Name: ";
    cin.getline(username,6);
    cout<<"Password: ";
    cin.getline(password,9);
    system("cls");

    if(strcmp(username, AdminUsername)==0 && strcmp(password, AdminPassword)==0){

            cout << "\t*" << setfill('*') << setw(50) << "*" << endl;
            cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
            cout << "\t*" << setfill(' ') << setw(32) << "W E L C O M E !" << setfill(' ') << setw(18) << "*" << endl;
            cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
            cout << "\t*" << setfill('-') << setw(50) << "*" << endl;
            cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
            cout << "\t*" << setfill(' ') << setw(40) << "Choose the actions you want to take" << setfill(' ') << setw(10) << "*" << endl;
            cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
            cout << "\t*" << setfill(' ') << setw(30) << "1. Print Product list" << setfill(' ') << setw(20) << "*" << endl;
            cout << "\t*" << setfill(' ') << setw(34) << "2. Input new Product Item" << setfill(' ') << setw(16) << "*" << endl;
            cout << "\t*" << setfill(' ') << setw(31) << "3. Delete Product Item" << setfill(' ') << setw(19) << "*" << endl;
            cout << "\t*" << setfill(' ') << setw(29) << "4. Edit Product Item" << setfill(' ') << setw(21) << "*" << endl;
            cout << "\t*" << setfill(' ') << setw(18) << "5. Search" << setfill(' ') << setw(32) << "*" << endl;
            cout << "\t*" << setfill(' ') << setw(16) << "6. Sort" << setfill(' ') << setw(34) << "*" << endl;
            cout << "\t*" << setfill(' ') << setw(43) << "7. Calculate total number of Sales" << setfill(' ') << setw(7) << "*" << endl;
            cout << "\t*" << setfill(' ') << setw(40) << "8. Calculate Individual Profit " << setfill(' ') << setw(10) << "*" << endl;
            cout << "\t*" << setfill(' ') << setw(35) << "9. View Statistical Report" << setfill(' ') << setw(15) << "*" << endl;
            cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
            cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
            cout << "\t*" << setfill('*') << setw(50) << "*" << endl;
            cout << endl;

            cin.getline(ChosenFunction, 30);
            // My Samples
            Products[0] = {0,"Spoon","Kitchen Utensils","Spoon",{10,11,2017},{14,10,2020},40,"Items",30.45,2.5};
            Products[1] = {1,"Napkins","Sanitary","Baby Wipes",{20,12,2018},{15,11,2021},12,"Packages",40.00,4.5};
            Products[2] = {2,"Lotion","Health And Bodycare","Nivea",{30,10,2019},{16,12,2022},10,"Bottle",99.39,5.0};

    while(true){
        // EDIT
        DeleteItem();
        EditItem();
    }
    }


    else{
        int Flag;
        cout<<"Incorrect password!"<<endl;
        FlagEntry:
        cout<<"Enter 0 to change accounts and 1 for re-entry: ";
        cin>>Flag;
        system("cls");
        if(Flag==0){
            return;
        }
        else if(Flag==1){
            goto PasswordEntry;
            }
        else{
            cout<<"Re-enter flag"<<endl;
            goto FlagEntry;
        }

    }
}

//Employee's Account
void Employee(){

    cout << "\t*" << setfill('*') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(32) << "W E L C O M E !" << setfill(' ') << setw(18) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill('-') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(40) << "Choose the action you want to take" << setfill(' ') << setw(10) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(30) << "1. Print Product list" << setfill(' ') << setw(20) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(18) << "2. Search" << setfill(' ') << setw(32) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(16) << "3. Sort" << setfill(' ') << setw(34) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill('*') << setw(50) << "*" << endl;
    cout << endl;

    cin.getline(ChosenFunction, 30);

}

//
void MainMenu(){


    home:welcomeScreen();
    cin.getline(MenuChoice,10);
    system("cls");
     while(strcmp(MenuChoice, "Manager")==0 || strcmp(MenuChoice, "manager")==0){
        Manager();

     }

     while(strcmp(MenuChoice, "Employee")==0 || strcmp(MenuChoice, "employee")==0){
        Employee();

     }
     while(strcmp(MenuChoice, "Cashier")==0 || strcmp(MenuChoice, "cashier")==0){

     }
        cout << endl;

    cout << endl << endl;
}

