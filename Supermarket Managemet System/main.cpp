#include <iostream>
#include <iomanip>
#include <windows.h>
#include <stdio.h>
#include <string>

using namespace std;

// Global Variables
int NumberOfProducts = 3;

// Resizes the console window
void ResizeWindow(){
    HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1600, 800, TRUE);
}

// Global Date Structure
struct Date{
    int Day,Month,Year;
};

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
} Products[9999];

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
            cin >> Item->ProductionDate.Day;
            cout << "\t New Month: ";
            cin >> Item->ProductionDate.Month;
            cout << "\t New Year: ";
            cin >> Item->ProductionDate.Year;
            break;
        case 5:
            cout << " Enter New Expire Date: ";
            cout << "\t New Day: ";
            cin >> Item->ExpireDate.Day;
            cout << "\t New Month: ";
            cin >> Item->ExpireDate.Month;
            cout << "\t New Year: ";
            cin >> Item->ExpireDate.Year;
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

/// M A I N
int main() {
    // Global Theme
    system("color 0E");

    // My Samples
    Products[0] = {0,"Spoon","Kitchen Utensils","Spoon",{10,11,2017},{14,10,2020},40,"Items",30.45,2.5};
    Products[1] = {1,"Napkins","Sanitary","Baby Wipes",{20,12,2018},{15,11,2021},12,"Packages",40.00,4.5};
    Products[2] = {2,"Lotion","Health And Bodycare","Nivea",{30,10,2019},{16,12,2022},10,"Bottle",99.39,5.0};

    while(true){
        // EDIT
        DeleteItem();
        EditItem();
    }


    return 0;
}

