/// L I B R A R I E S
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <winuser.h>
#include <sstream>
#include <vector>
#include <fstream>

/// N A M E S P A C E
using namespace std;

/// Global Variables
float Quantity[100], TotalPrice = 0, Cash;
int NumberofBoughtItems, ProductNo[100], amount, Location[100];
bool ProductFound;
int NumberOfProducts=79, FlagDelete = 0, FlagEdit = 0;
string ThemeColor = "0E";

/// Prototype functions
int MainMenu(void);
string Capitalize(string);
void NumberOfProductsCounter(void);
/// Structures
// A date structure to contain all dates used in the program
struct Date
{
    int Day,Month,Year;
};

/*
    A product structure to contain the attributes of all item objects in stock
    It also contains a function to create an object.
*/
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
    int Sales = 0;

};
//Declaration of Products Using Vector
vector<Product> Products;

// Function to remove all spaces from a given string
string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}
//Function to count Product Size
void NumberOfProductsCounter()
{
    NumberOfProducts = Products.size();
}
//Creation of New Product
void CreateProduct()
{
    Product temporary;
    NumberOfProductsCounter();
    cout<<"\n Please Enter The Product Number : "<<NumberOfProducts + 1;
    NumberOfProducts++;
    temporary.ProductNumber = NumberOfProducts;
    //cin>>ProductNumber;

    cout<<"\n Please Enter The Product Name : ";
    cin>>temporary.ProductName;

    cout<<"\n Please Enter The Category Of The Product : ";
    cin>>temporary.Category;

    cout<<"\n Please Enter The Product Type : ";
    cin>>temporary.ProductType;

    cout<<"\n Please Enter The Production Date(Use space like this DD MM YY) : ";
    cin>>temporary.ProductionDate.Day;

    if(temporary.ProductionDate.Day == 0)  //In case of  a null value on Production Date
    {
        temporary.ProductionDate.Month=0;
        temporary.ProductionDate.Year=0;
    }

    else
    {
        cin>>temporary.ProductionDate.Month;
        cin>>temporary.ProductionDate.Year;
    }

    cout<<"\n Please Enter The Expired Date(Use space like this DD MM YY) : ";
    cin>>temporary.ExpireDate.Day;

    if(temporary.ExpireDate.Day == 0)  //In case of  a null value on Expire Date
    {
        temporary.ExpireDate.Month=0;
        temporary.ExpireDate.Year=0;
    }


    else
    {
        cin>>temporary.ExpireDate.Month;
        cin>>temporary.ExpireDate.Year;
    }

    cout<<"\n Please Enter The Quantity: ";
    cin>>temporary.Quantity;

    cout<<"\n Please Enter The Measurement Unit: ";
    cin>>temporary.MeasurementUnit;

    cout<<"\n Please Enter The Unit Price: ";
    cin>>temporary.UnitPrice;

    cout<<"\n Please Enter The Rating: ";
    cin>>temporary.Rating;

    cout<<"\n Please Enter The Number of Sales: ";
    cin>>temporary.Sales;
    Products.push_back(temporary);
    //Save new product detail into file
    fstream fout("Products.txt", ios::app);
    fout << endl << temporary.ProductNumber << ',' <<
         temporary.ProductName << ',' <<
         temporary.Category << ',' <<
         temporary.ProductType << ',' <<
         temporary.ProductionDate.Day << ',' <<
         temporary.ProductionDate.Month << ',' <<
         temporary.ProductionDate.Year << ',' <<
         temporary.ExpireDate.Day << ',' <<
         temporary.ExpireDate.Month << ',' <<
         temporary.ExpireDate.Year << ',' <<
         temporary.Quantity << ',' <<
         temporary.MeasurementUnit << ',' <<
         temporary.UnitPrice << ',' <<
         temporary.Rating << ',' <<
         temporary.Sales;
    fout.close();
}
//A function to load Products from file
void LoadProduct(string FileName)
{
    // define variables
    string tempString;
    Product temp;
    //number of lines
    int i = 0;

    fstream SuperMarket;
    SuperMarket.open(FileName, ios::app | ios::out | ios::in ); //opening the file.
    if (SuperMarket.is_open()) //if the file is open
    {
        //ignore first line

        while (!SuperMarket.eof()) //while the end of file is NOT reached
        {
            getline(SuperMarket, tempString, ',');
            tempString= removeSpaces(tempString);
            temp.ProductNumber= stoi(tempString);
            getline(SuperMarket, temp.ProductName, ',');
            getline(SuperMarket, temp.Category, ',');
            getline(SuperMarket, temp.ProductType, ',');
            getline(SuperMarket, tempString, ',');
            tempString= removeSpaces(tempString);
            temp.ProductionDate.Day = stoi(tempString);
            getline(SuperMarket, tempString, ',');
            tempString= removeSpaces(tempString);
            temp.ProductionDate.Month=stoi(tempString);
            getline(SuperMarket, tempString, ',');
            tempString= removeSpaces(tempString);
            temp.ProductionDate.Year=stoi(tempString);
            getline(SuperMarket, tempString, ',');
            tempString= removeSpaces(tempString);
            temp.ExpireDate.Day= stoi(tempString);
            getline(SuperMarket, tempString, ',');
            tempString= removeSpaces(tempString);
            temp.ExpireDate.Month= stoi(tempString);
            getline(SuperMarket, tempString, ',');
            tempString= removeSpaces(tempString);
            temp.ExpireDate.Year= stoi(tempString);
            getline(SuperMarket, tempString, ',');
            tempString= removeSpaces(tempString);
            temp.Quantity = stof(tempString);
            getline(SuperMarket, temp.MeasurementUnit, ',');
            getline(SuperMarket, tempString, ',');
            tempString= removeSpaces(tempString);
            temp.UnitPrice= stof(tempString);
            getline(SuperMarket, tempString, ',');
            tempString= removeSpaces(tempString);
            temp.Rating= stof(tempString);
            getline(SuperMarket, tempString, '\n');
            tempString= removeSpaces(tempString);
            temp.Sales = stoi(tempString);
            Products.push_back(temp);
            i++; //increment number of lines
        }
        SuperMarket.close(); //closing the file
    }
    else cout << "Unable to open file"; //if the file is not open output
}

// A function to create a new product
void InputProduct(int Count)
{
    NumberOfProductsCounter();
    for(int i = 0; i < Count; i++)
    {
        CreateProduct();
    }
    NumberOfProductsCounter();
}


/// UI Components
// Resizes the console window
void ThemeColorChanger(string color)
{
    string ThemeColor = "color " + color;
    system(ThemeColor.c_str());
}
void ChangeLineColor(int Color)
{
    /*
        Color 10 - Light Green
        Color 12 - Light Red
    */
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, Color);
}
void ResizeWindow()
{
    system("mode 650");
    /*HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1600, 800, TRUE);
    */
}
// Welcome Screen
/*
    This function contains a simple ASCII art generated from
    PatorJK.com specifically used the Text 2 ASCII generator app (https://patorjk.com/software/taag/#p=display&f=Univers&t=CartShop)
    website along with a simple welcome header.
*/
void welcomeScreen()
{
    cout << "\n\n" << endl;
    ChangeLineColor(10);
    cout << R"(
                        ,ad8888ba,                                     ad88888ba   88
                       d8"'    `"8b                            ,d     d8"     "8b  88)";
    ChangeLineColor(11);
    cout << R"(
                      d8'                                      88     Y8,          88
                      88             ,adPPYYba,  8b,dPPYba,  MM88MMM  `Y8aaaaa,    88,dPPYba,    ,adPPYba,   8b,dPPYba,)";
    ChangeLineColor(12);
    cout << R"(
                      88             ""     `Y8  88P'   "Y8    88       `"""""8b,  88P'    "8a  a8"     "8a  88P'    "8a
                      Y8,            ,adPPPPP88  88            88             `8b  88       88  8b       d8  88       d8)";
    ChangeLineColor(13);
    cout << R"(
                       Y8a.    .a8P  88,    ,88  88            88,    Y8a     a8P  88       88  "8a,   ,a8"  88b,   ,a8"
                        `"Y8888Y"'   `"8bbdP"Y8  88            "Y888   "Y88888P"   88       88   `"YbbdP"'   88`YbbdP"' )";
    ChangeLineColor(14);
    cout << R"(
                                                                                                             88
                                                                                                             88
    )" << endl;
    ChangeLineColor(14);
    cout << endl;
    cout << "\t\t\t\t\t\t*" << setfill('*') << setw(50) << "*" << endl;
    cout << "\t\t\t\t\t\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t\t\t\t\t\t*" << setfill(' ') << setw(32) << "W E L C O M E !" << setfill(' ') << setw(18) << "*" << endl;
    cout << "\t\t\t\t\t\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t\t\t\t\t\t*" << setfill('-') << setw(50) << "*" << endl;
    cout << endl;
}

// Progress Indicating Functions
void FeedBackMessage(string Message, int LineColor)
{
    /*
        LineColor options:
        10 - Light Green
        11 - Light Aqua
        12 - Light Red
        13 - Light Pink
        14 - Light Yellow
        15 - Light White
    */
    ChangeLineColor(LineColor);
    cout << "\n\t\t\t\t\t\t\t " << Capitalize(Message) << "!" << endl << endl;
    ChangeLineColor(14);
}

// Capitalize a given text
string Capitalize(string Text)
{
    for_each(Text.begin(), Text.end(), [](char & c)
    {
        c = ::toupper(c);
    });
    return Text;
}

// App header
void AppHeader(string Title)
{
    ChangeLineColor(14);
    cout << "\n" << setw(200) << setfill('_')  << "\n" << endl;
    ChangeLineColor(15);
    cout << "\t\t\t\t\t\t\t\t" << Capitalize(Title) << endl;
    ChangeLineColor(7);
    cout << setw(200) << setfill('_')  << "\n" << endl;
    ChangeLineColor(14);
}
// App footer
void AppFooter()
{
    cout << "\n" << setfill(' ');
    ChangeLineColor(14);
    cout << "\n" << setw(200) << setfill('=')  << "\n" << endl;
    system("pause");
    system("cls");
}

/// Displaying Functions
/*
    The Following three functions are made to show the data in a table format
    they can be called whenever with a product object passed on and they will
    show the product detail with a table format complete with headers and
    dividers.
*/
// Print a table divider
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

// Prints the table headers describing what each column corresponds to
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

// Takes in a product object and it lists out the objects attributes in a table format
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

/*
    This functions assembles all the above print functions and runs in a loop
    to show a table of all products available in stock
*/
void PrintInTableFormat()
{
    cout << endl << "\t\t\t\t\t\t\t Here's a list of all products... " << endl << endl;
    // Print In Table Format Function
    PrintTableDividers();
    PrintTableHeader();
    NumberOfProductsCounter();
    // Loop Through the samples to print the details in table format
    for(int i = 0; i < NumberOfProducts; i++)
    {
        PrintTableDividers();
        PrintInItemValue(Products[i]);
    }
    PrintTableDividers();
}

// This functions prints a receipt for the cashier to show/print/give to the customer once a purchase has been made
void PrintReceipt()
{
    system("cls");
    cout<<setfill(' ')<<setw(30)<<"Receipt\n";
    cout<<setfill(' ')<<"Item No"<<setw(15)<<"Name \t"<<setw(8)<<"Quantity"<<setw(8)<<"Price"<<setw(10)<<"Amount\n";
    for(int i=0; i<NumberofBoughtItems; i++)
    {
        int N;
        N=Location[i];
        cout<<setfill(' ')<<"Item "<<i+1<<": "<<setw(15)<<Products[N].ProductName<<setw(8)<<Quantity[i]<<setw(8)<<Products[N].UnitPrice<<setw(10)<<Quantity[i]*Products[N].UnitPrice<<endl;
        cout << "\t-" << setfill('-') << setw(50) << "-" << endl;
        TotalPrice=TotalPrice+(Quantity[i]*Products[N].UnitPrice);
    }

    cout<<setfill(' ')<<setw(47)<<"Txbl   "<<TotalPrice<<endl;
    cout<<setfill(' ')<<setw(47)<<"Tax(15%)   "<<0.15*TotalPrice<<endl;
    TotalPrice=1.15*TotalPrice;
    cout<<setfill(' ')<<setw(47)<<"TotalPrice  "<<TotalPrice<<endl;
    cout<<setfill(' ')<<setw(47)<<"Cash: ";
    cin>>Cash;
    cout<<setfill(' ')<<setw(47)<<"Change: "<<Cash-TotalPrice<<endl;
    cout<<setfill(' ')<<setw(30)<<"Thank You For Your Purchase" << endl;
    for(int i=0; i<NumberofBoughtItems; i++)
    {
        int N;
        N=Location[i];
        Products[N].Quantity=Products[N].Quantity-Quantity[i];
        Products[N].Sales = Products[N].Sales + Quantity[i];
    }
    system("pause");
    system("cls");
    MainMenu();
}

void CashierAccount()
{
    //ProductSampleData();
    cout<<setfill(' ') << setw(50) <<"Welcome to CartShop\n\n";
    amount=1000;
    cout<<"\tEnter The Details of The Items Below \n \tIf You Finish Your Purchase  at Any Time Enter 0 \n";
    for(int i=0; i<amount; i++)
    {
        ProductFound=false;
MainMenu:
        cout<<"Item "<<i+1<<":\n";
ProductNum:
        cout<<"\tProduct Number: ";
        cin>>ProductNo[i];
        for(int j=0; j<500; j++)
        {
            switch(ProductNo[i])
            {
            case 0:
                char opt;
Finish:
                NumberofBoughtItems = i;
                PrintReceipt();
                cout << "\tHave You Finished Your Purchase(Y/N)\n";
                cin >> opt;
                opt = (char)toupper(opt);
                switch(opt)
                {
                case 'N':
                    system("pause");
                    goto MainMenu;
                    break;
                case 'Y':
                    system("pause");
                    PrintReceipt();
                    break;
                default:
                    cout<<"\t Error: Invalid Input Try again\n";
                    goto Finish;
                    break;
                }
            case 1 ... 9999:
                if(ProductNo[i] == Products[j].ProductNumber)
                {
                    Location[i] = j;
                    ProductFound = true;
                    NumberofBoughtItems = i + 1;
                }
                break;
            default :
                cout << "\tInvalid Number. Try Again!\n";
                goto ProductNum;
                break;
            }
        }
        if(ProductFound == false)
        {
            cout<<"\tCouldn't Find The Product. Try Again!\n";
            goto ProductNum;
        }
        cout << "\t\t Quantity: ";
        cin >> Quantity[i];
        cout << "\t-" << setfill('-') << setw(50) << "-" << endl;
    }
}

void Search(int SearchedProduct)
{
    int i;
    for( i = 0; i < Products.size(); i++)
    {
        if( SearchedProduct == Products[i].ProductNumber && Products[i].ProductNumber != 0)
        {
            FeedBackMessage("Product Found",10);
            cout << "\t\t\t\t\t\t\t    Result";
            cout << endl << endl;
            PrintTableDividers();
            PrintTableHeader();
            PrintTableDividers();
            PrintInItemValue(Products[i]);
            PrintTableDividers();
            cout << endl << endl;
            i = 9999;
        }
        else if(Products[i].ProductNumber == 0)
        {
            cout << "\n\t\t\t\t\t\t\t\tResult \n";
            i = 9999;
            FlagDelete = 1;
            FlagEdit = 1;
            FeedBackMessage("Product Not Found",12);
        }
    }
}


void Save(){
    fstream ProductsFile;
    ProductsFile.open("Products.txt", ios::out);
    if(ProductsFile.is_open()){
        for(int i = 0; i < NumberOfProducts; i++){
            ProductsFile << Products[i].ProductNumber << ",";
            ProductsFile << Products[i].ProductName << ",";
            ProductsFile << Products[i].Category << ",";
            ProductsFile << Products[i].ProductType << ",";
            ProductsFile << Products[i].ProductionDate.Day << ",";
            ProductsFile << Products[i].ProductionDate.Month << ",";
            ProductsFile << Products[i].ProductionDate.Year << ",";
            ProductsFile << Products[i].ExpireDate.Day << ",";
            ProductsFile << Products[i].ExpireDate.Month << ",";
            ProductsFile << Products[i].ExpireDate.Year << ",";
            ProductsFile << Products[i].Quantity << ",";
            ProductsFile << Products[i].MeasurementUnit << ",";
            ProductsFile << Products[i].UnitPrice << ",";
            ProductsFile << Products[i].Rating << ",";
            ProductsFile << Products[i].Sales << ",";
            ProductsFile << "\n";
        }
        ProductsFile.close();
        FeedBackMessage("File Edited Successfully",10);
    } else {
        FeedBackMessage("Error While Editing File",12);
    }
    ProductsFile.close();
    LoadProduct("Products.txt");
}

void EditItem()
{
    // Enter Serial Number of a product to edit
    int SerialNumber;
    cout << endl << " Enter Serial Number Of Item you want to edit: ";
    while(!(cin>>SerialNumber))
    {
        cout<< "\n**********Invalid input.**********\n";
        cout << endl << " Serial Number : ";
        cin.clear();
        cin.ignore(20, '\n');
    }
    Search(SerialNumber);
    if(!(FlagEdit))
    {
        Product *Item = &Products[SerialNumber];
        // List of options to edit
        int EditChoice;
        edit:
        cout << endl << " What would you like to edit?" << endl;
        cout << "  1. Product Name" << "\t\t  6. Quantity" << endl;
        cout << "  2. Product Category" << "\t\t  7. Measurement Unit" << endl;
        cout << "  3. Product Type" << "\t\t  8. Unit Price" << endl;
        cout << "  4. Production Date" << "\t\t  9. Rating" << endl;
        cout << "  5. Expire Date" << "\t\t 10. Sales" << endl;
        cout << endl << " Edit Choice: ";

        while(!(cin>>EditChoice))
        {
            cout<< "\n**********Invalid input.**********\n";
            cout << endl << " Enter Choice( 1 - 10): ";
            cin.clear();
            cin.ignore(20, '\n');
        }
        if(EditChoice > 10 || EditChoice < 1)
        {
            cout << " Enter Choice( 1 - 10): ";
            goto edit;
        }
        cout << endl;
        // Accept new values based on choice
        switch(EditChoice)
        {
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
    date:
            cout << " Enter New Production Date" << endl;
            cout << "\t New Day: ";
            while(!( cin >> Item->ProductionDate.Day))   // INPUT VALIDATION FOR DATE EDITING
            {
                cout<< "\n**********Invalid input.**********\n";
                cin.clear();
                cin.ignore(20, '\n');
                goto date;
            }
            if( Item->ProductionDate.Day<1 || Item->ProductionDate.Day>30)
            {
                cout<<" **********Invalid Day.********** \n";
                goto date;
            }

            cout << "\t New Month: ";

            while(!( cin >> Item->ProductionDate.Month))   // INPUT VALIDATION FOR DATE EDITING
            {
                cout<< "\nInvalid input.\n";
                cin.clear();
                cin.ignore(20, '\n');
                goto date;
            }
            if( Item->ProductionDate.Month<1 || Item->ProductionDate.Month>12)
            {
                cout<<" Invalid Day. \n";
                goto date;
            }
            cout << "\t New Year: ";
            while(!( cin >> Item->ProductionDate.Year))   // INPUT VALIDATION FOR DATE EDITING
            {
                cout<< "\n**********Invalid input.**********\n";
                cin.clear();
                cin.ignore(20, '\n');
                goto date;
            }
            if( Item->ProductionDate.Year<2015 || Item->ProductionDate.Year>2021)
            {
                cout<<"**********Invalid Year.**********\n";
                goto date;
            }
            break;
        case 5:
            cout << " Enter New Expire Date: ";
            cout << "\t New Day: ";

            while(!( cin >> Item->ExpireDate.Day))   // INPUT VALIDATION FOR DATE EDITING
            {
                cout<< "\n**********Invalid input.**********\n";
                cin.clear();
                cin.ignore(20, '\n');
                goto date;
            }
            if( Item->ExpireDate.Day<1 || Item->ExpireDate.Day>30)
            {
                cout<<"**********Invalid Day.**********\n";
                goto date;
            }

            cout << "\t New Month: ";
            while(!( cin >> Item->ExpireDate.Month))   // INPUT VALIDATION FOR DATE EDITING
            {
                cout<< "\n**********Invalid input.**********\n";
                cin.clear();
                cin.ignore(20, '\n');
                goto date;
            }
            if( Item->ExpireDate.Month<1 || Item->ExpireDate.Month>12)
            {
                cout<<"**********Invalid Day.**********\n";
                goto date;
            }

            cout << "\t New Year: ";
            while(!( cin >> Item->ExpireDate.Year))   // INPUT VALIDATION FOR DATE EDITING
            {
                cout<< "\n**********Invalid input.**********\n";
                cin.clear();
                cin.ignore(20, '\n');
                goto date;
            }
            if( Item->ExpireDate.Year<2015 || Item->ExpireDate.Year>2021)
            {
                cout<<"**********Invalid Day.**********\n";
                goto date;
            }

            break;
        case 6:
            cout << " Enter New Quantity: ";

            while(!( cin >> Item->Quantity))   // INPUT VALIDATION FOR DATE EDITING
            {
                cout<< "\n**********Invalid input.**********\n";
                cin.clear();
                cin.ignore(20, '\n');
                goto date;
            }
            break;
        case 7:
            cout << " Enter New Measurement Unit: ";
            getline(cin,Item->MeasurementUnit);
            break;
        case 8:
            cout << " Enter New Unit Price: ";
            while(!(cin>>Item->UnitPrice))
            {
                cout<< "**********Invalid Day.**********\n";
                cout << " Enter New Unit Price: ";
                cin.clear();
                cin.ignore(20, '\n');

            }

            break;
        case 9:
            cout << " Enter New Rating: ";
            while(!(cin>>Item->Rating))
            {
                cout<< "**********Invalid Day.**********\n";
                cout << " Enter New Rating: ";
                cin.clear();
                cin.ignore(20, '\n');

            }
            break;
        case 10:
            cout << " Enter New Sale ";
            while(!(cin>>Item->Sales))
            {
                cout<< "**********Invalid Day.**********\n";
                cout << " Enter New Rating: ";
                cin.clear();
                cin.ignore(20, '\n');

            }

            break;
        }
        system("color 0A");
        Save();
        FeedBackMessage("Item Edited Successfully", 10);
        //cout << endl << " \t ---- \t Item Edited Successfully! \t ----" << endl << endl;
    }
    FlagEdit = 0;
    system("pause");
    system("color 0F");
    system("cls");

}

// This function asks for a serial number of an item and then it allows you to delete it from the stock
void DeleteItem()
{
AskDeletion:
    // Enter Serial Number of a product to edit
    int SerialNumber;
    cout << endl << "\t\t\t\t\t\tEnter Serial Number Of Item you want to delete: ";

    while(!(cin>>SerialNumber))    // Error handling for serial number input
    {
        FeedBackMessage("Invalid Input", 15);
        cin.clear();
        cin.ignore(20, '\n');
    }
    Search(SerialNumber);

    if( !(FlagDelete))
    {
        Product *Item = &Products[SerialNumber];
        ChangeLineColor(12);
        cout << endl << "\t\t\t\t\t\tAre you sure you want to delete this item? (Y/N)";
        ChangeLineColor(12);
        cout<< endl << "\n\t\t\t\t\t\t\t\t1. Yes";
        ChangeLineColor(12);
        cout<< endl << "\t\t\t\t\t\t\t\t2. No"<<endl;

        ChangeLineColor(12);
        cout << "\n\n\t\t\t\t\t\t\t   Confirm Delete : ";
        int ConfirmDeletion;
        while(!(cin>>ConfirmDeletion))    // Error handling for confirm deletion choice
        {
            FeedBackMessage("Invalid Input", 15);
            cin.clear();
            cin.ignore(20, '\n');
        }
        if(ConfirmDeletion == 1)
        {
            NumberOfProductsCounter();
            for(int i = SerialNumber; i < NumberOfProducts - 1; i++)
            {
                Products[i] = Products[i+1];
            }
            NumberOfProducts--;
            for(int i = 0; i < NumberOfProducts; i++)
            {
                Item = &Products[i];
                Item->ProductNumber = i;
            }
            FeedBackMessage("Item Deleted Successfully", 10);
        }
        else if (ConfirmDeletion == 2)
        {
            FeedBackMessage("Item Not Deleted", 15);
            goto AskDeletion;
        }
    }
    FlagDelete = 0;
}

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
    if((FirstProduct.ProductionDate.Year < SecondProduct.ProductionDate.Year)||((FirstProduct.ProductionDate.Year == SecondProduct.ProductionDate.Year)&&(FirstProduct.ProductionDate.Month < SecondProduct.ProductionDate.Month))||(((FirstProduct.ProductionDate.Year == SecondProduct.ProductionDate.Year)&&(FirstProduct.ProductionDate.Month == SecondProduct.ProductionDate.Month))&&(FirstProduct.ProductionDate.Day < SecondProduct.ProductionDate.Day)))
        return 1;
    else
        return 0;
}

//Used to Compare products using there production date in descending order
bool CompareUsingProductionDateDescending( Product FirstProduct, Product SecondProduct)
{
    if((FirstProduct.ProductionDate.Year > SecondProduct.ProductionDate.Year)||((FirstProduct.ProductionDate.Year == SecondProduct.ProductionDate.Year)&&(FirstProduct.ProductionDate.Month > SecondProduct.ProductionDate.Month))||(((FirstProduct.ProductionDate.Year == SecondProduct.ProductionDate.Year)&&(FirstProduct.ProductionDate.Month == SecondProduct.ProductionDate.Month))&&(FirstProduct.ProductionDate.Day > SecondProduct.ProductionDate.Day)))
        return 1;
    else
        return 0;
}

//Used to Compare products using there expiration date in ascending order
bool CompareUsingExpirationDateAscending( Product FirstProduct, Product SecondProduct)
{
    if((FirstProduct.ExpireDate.Year < SecondProduct.ExpireDate.Year)||
            ((FirstProduct.ExpireDate.Year == SecondProduct.ExpireDate.Year)&&
             (FirstProduct.ExpireDate.Month < SecondProduct.ExpireDate.Month))||
            (((FirstProduct.ExpireDate.Year == SecondProduct.ExpireDate.Year)&&
              (FirstProduct.ExpireDate.Month == SecondProduct.ExpireDate.Month))&&
             (FirstProduct.ExpireDate.Day < SecondProduct.ExpireDate.Day)))
        return 1;
    else
        return 0;
}

//Used to Compare products using there expiration date in descending order
bool CompareUsingExpirationDateDescending( Product FirstProduct, Product SecondProduct)
{
    if((FirstProduct.ExpireDate.Year > SecondProduct.ExpireDate.Year)||((FirstProduct.ExpireDate.Year == SecondProduct.ExpireDate.Year)&&(FirstProduct.ExpireDate.Month > SecondProduct.ExpireDate.Month))||(((FirstProduct.ExpireDate.Year == SecondProduct.ExpireDate.Year)&&(FirstProduct.ExpireDate.Month == SecondProduct.ExpireDate.Month))&&(FirstProduct.ExpireDate.Day > SecondProduct.ExpireDate.Day)))
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

/// Settings
void Settings()
{
    int SettingChoice, ResetChoice;
    cout << "\t\t\t\t What would you like to do? " << endl;
    cout << "\t\t\t\t\t\t\t 1. Reset Product Sample" << endl;
    cin >> SettingChoice;
    switch(SettingChoice){
    case 1:
        ChangeLineColor(12);
        cout << "\t\t\t\tAre you sure you want to reset product samples? " << endl;
        ChangeLineColor(12);
        cout << "\t\t\t\t\t\t\t1. Yes" << endl;
        ChangeLineColor(12);
        cout << "\t\t\t\t\t\t\t2. No" << endl;
        cin >> ResetChoice;
        if(ResetChoice == 1){
            LoadProduct("ProductsSample.txt");
            FeedBackMessage("Database Reset Successfully", 10);
        } else {
            FeedBackMessage("Database Remains Unchanged", 15);
        }
        break;
    }

}

/// Developers
void Developers()
{
    string ListOfDevNames[5] = {"Brook Feleke  ","Dagmawi Esayas", "Dawit Getachew","Ebenezer Yonas","Melat Gizachew"};
    string ListOfDevIDs[5] = {"ETS 1234/12","ETS 1234/12", "ETS 1234/12","ETS 1234/12","ETS 1234/12"};
    for(int i = 0; i < 5; i++)
    {
        cout << "\t\t\t\t\t\t\t" << i + 1 << ". " << ListOfDevNames[i] << "\t" << ListOfDevIDs[i] << endl;
    }
}

/// Main Menu
// Main Menu to allow navigation
int MainMenu()
{
    int Choice, InvalidChoiceCounter= 0;
Menu:
    welcomeScreen();
    //system("cls");
    cout<<"\t\t\t\t\t\t\t 1. Print all Products. "<<endl;
    cout<<"\t\t\t\t\t\t\t 2. Search for product. "<<endl;
    cout<<"\t\t\t\t\t\t\t 3. Delete Item from Stock. "<<endl;
    cout<<"\t\t\t\t\t\t\t 4. Edit a Product "<<endl;
    cout<<"\t\t\t\t\t\t\t 5. Sorting Functions "<<endl;
    cout<<"\t\t\t\t\t\t\t 6. Sell "<<endl;
    cout<<"\t\t\t\t\t\t\t 7. Enter a new Product. "<<endl;
    cout<<"\t\t\t\t\t\t\t 8. Settings. "<<endl;
    cout<<"\t\t\t\t\t\t\t 9. Introduction/Usage. "<<endl;
    cout<<"\t\t\t\t\t\t\t10. Developers. "<<endl;
    cout<<"\t\t\t\t\t\t\t11. Exit "<<endl;
    cout<<"\n\n\t\t\t\t\t\t\t\tChoice: ";

    // Error handling for main menu choice
    while(!(cin>>Choice))
    {
        FeedBackMessage("Invalid Input", 15);
        cin.clear();
        cin.ignore(20, '\n');
        system("pause");
        system("cls");
        goto Menu;
    }

    switch(Choice)
    {
    // Print all data in table format
    case 1:
        AppHeader("Print All");
        PrintInTableFormat();
        AppFooter();
        goto Menu;
    // Search for an item in stock
    case 2:
        AppHeader("Search Items");
        int ProductNumberSearch; // Search Key
        cout << "\n\t\t\t\t\tEnter the Product number of the item you would like to search." << endl;
        cout << "\n\t\t\t\t\t\t\tProduct Number: ";

        // Error handling for product numbers
        while(!(cin >> ProductNumberSearch))
        {
            FeedBackMessage("Invalid Input", 7);
            cin.clear();
            cin.ignore(20, '\n');
            cout << "\t\t\t\t\t\t\t\Re-enter Product Number: ";

            InvalidChoiceCounter++;
            if(InvalidChoiceCounter >= 3)
            {
                InvalidChoiceCounter = 0;
                goto Menu; //We can make it go to the main menu when we merge it all
            }
        }
        Search(ProductNumberSearch); //Calling Search function
        //FeedBackMessage("Item Found!", 10);
        AppFooter();
        goto Menu;
        break;
    // Delete an item from stock
    case 3:
        AppHeader("Delete Items");
        DeleteItem();
        AppFooter();
        goto Menu;
    // Edit an item from stock
    case 4:
        EditItem();
        goto Menu;
    // Sort items in stock
    case 5:
        //system("cls");
ReturnToChoice:
        cout<<"Choose how you want to sort: "<<endl;
        cout<<"1. Unit Price"<<endl;
        cout<<"2. Rating"<<endl;
        cout<<"3. Production date"<<endl;
        cout<<"4. Expire date"<<endl;
        cout<<"5. Quantity"<<endl;
        cout<<"6. Sales"<<endl;
        int Choice,OrderChoice;
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
        case 1:
            if(OrderChoice == 1)
            {
                sort(Products.begin(), Products.end(), CompareUsingUnitPriceAscending);
                PrintInTableFormat();
            }
            else if(OrderChoice == 2)
            {
                sort(Products.begin(), Products.end(), CompareUsingUnitPriceDescending);
                PrintInTableFormat();
            }
            else
            {
                cout<<"Invalid Choice! Try Again";
                goto ReturnToOrderChoice;
            }
            break;
        case 2:
            if(OrderChoice == 1)
            {
                sort(Products.begin(), Products.end(), CompareUsingRatingAscending);
                PrintInTableFormat();
            }
            else if(OrderChoice == 2)
            {
                sort(Products.begin(), Products.end(), CompareUsingRatingDescending);
                PrintInTableFormat();
            }
            else
            {
                cout<<"Invalid Choice! Try Again";
                goto ReturnToOrderChoice;
            }
            break;
        case 3:
            if(OrderChoice == 1)
            {
                sort(Products.begin(), Products.end(), CompareUsingProductionDateAscending);
                PrintInTableFormat();
            }
            else if(OrderChoice == 2)
            {
                sort(Products.begin(), Products.end(), CompareUsingProductionDateDescending);
                PrintInTableFormat();
            }
            else
            {
                cout<<"Invalid Choice! Try Again";
                goto ReturnToOrderChoice;
            }
            break;
        case 4:
            if(OrderChoice == 1)
            {
                sort(Products.begin(), Products.end(), CompareUsingExpirationDateAscending);
                PrintInTableFormat();
            }
            else if(OrderChoice == 2)
            {
                sort(Products.begin(), Products.end(), CompareUsingExpirationDateDescending);
                PrintInTableFormat();
            }
            else
            {
                cout<<"Invalid Choice! Try Again";
                goto ReturnToOrderChoice;
            }
            break;
        case 5:
            if(OrderChoice == 1)
            {
                sort(Products.begin(), Products.end(), CompareUsingQuantityAscending);
                PrintInTableFormat();
            }
            else if(OrderChoice == 2)
            {
                sort(Products.begin(), Products.end(), CompareUsingQuantityDescending);
                PrintInTableFormat();
            }
            else
            {
                cout<<"Invalid Choice! Try Again";
                goto ReturnToOrderChoice;
            }
            break;
        case 6:
            if(OrderChoice == 1)
            {
                sort(Products.begin(), Products.end(), CompareUsingSalesAscending);
                PrintInTableFormat();
            }
            else if(OrderChoice == 2)
            {
                sort(Products.begin(), Products.end(), CompareUsingSalesDescending);
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
        goto Menu;
    // Sales
    case 6:
        CashierAccount();
    // Enter a new product into stock
    case 7:
        system("cls");
        int Amount;
        cout<<"Enter the amount you want to input:";
        cin>>Amount;
        InputProduct(Amount);
        goto Menu;
    // Settings
    case 8:
        AppHeader("Settings");
        Settings();
        AppFooter();
        goto Menu;
    // Developers
    case 10:
        AppHeader("Developers Info");
        Developers();
        AppFooter();
        goto Menu;
    // Exit
    case 11:
        return 0; //We can make it go to the main menu when we merge it all
        break;
    // Error handling for all other options
    default:
        FeedBackMessage("Invalid Input", 15);
        system("pause");
        system("cls");
        goto Menu;
    }
}

/// Initialization
// A simple function to call and initiate system variables to help in demo and general settings
void InitializeSystemVariables()
{
    ResizeWindow();
    ThemeColorChanger(ThemeColor);
}



/// M A I N
int main()
{
    //Calls function to load products from file
    LoadProduct("Products.txt");
    InitializeSystemVariables();

    /*for(int i = 0; i < NumberOfProducts; i++){
        cout << Products[i].ProductName << endl;
    }
    int loc;
    Product *prdctPTR;
    cout << "Enter location: ";
    cin >> loc;
    for(int i = 0; i < NumberOfProducts; i++){
        if(loc == i + 1){
            prdctPTR = &Products[i];
            cout << "Enter new product name: ";
            cin >> prdctPTR -> ProductName;
        }
    }
    cout << endl << endl << endl << endl;
    cout << "Changed!";
    cout << endl << endl << endl << endl;
    for(int i = 0; i < NumberOfProducts; i++){
        cout << Products[i].ProductName << endl;
    }
    system("pause");*/

    MainMenu();
}
