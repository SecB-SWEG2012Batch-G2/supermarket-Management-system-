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
float Quantity[100], TotalPrice = 0, Cash, ProfitMarigin = 0.3;
int NumberofBoughtItems, ProductNo[100], amount, Location[100];
bool ProductFound;
int NumberOfProducts=79, FlagDelete = 0, FlagEdit = 0;
string ThemeColor = "0E";
int IsFullScreenMode = 1;

/// Prototype functions
int MainMenu(void);
int MainScreen(void);
void CashierAccount(void);
void login(void);
void signUp(void);
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
void LoadProduct()
{
    // define variables
    string tempString,line;
    Product temp;
    //number of lines
    int i = 0;

    fstream SuperMarket;
    SuperMarket.open("Products.txt", ios::app | ios::out | ios::in ); //opening the file.
    if (SuperMarket.is_open()) //if the file is open
    {
        //ignore first line

        while (getline(SuperMarket,line)) //while the end of file is NOT reached
        {
            stringstream ss(line);
            getline(ss, tempString, ',');
            tempString= removeSpaces(tempString);
            temp.ProductNumber= stoi(tempString);
            getline(ss, temp.ProductName, ',');
            getline(ss, temp.Category, ',');
            getline(ss, temp.ProductType, ',');
            getline(ss, tempString, ',');
            tempString= removeSpaces(tempString);
            temp.ProductionDate.Day = stoi(tempString);
            getline(ss, tempString, ',');
            tempString= removeSpaces(tempString);
            temp.ProductionDate.Month=stoi(tempString);
            getline(ss, tempString, ',');
            tempString= removeSpaces(tempString);
            temp.ProductionDate.Year=stoi(tempString);
            getline(ss, tempString, ',');
            tempString= removeSpaces(tempString);
            temp.ExpireDate.Day= stoi(tempString);
            getline(ss, tempString, ',');
            tempString= removeSpaces(tempString);
            temp.ExpireDate.Month= stoi(tempString);
            getline(ss, tempString, ',');
            tempString= removeSpaces(tempString);
            temp.ExpireDate.Year= stoi(tempString);
            getline(ss, tempString, ',');
            tempString= removeSpaces(tempString);
            temp.Quantity = stof(tempString);
            getline(ss, temp.MeasurementUnit, ',');
            getline(ss, tempString, ',');
            tempString= removeSpaces(tempString);
            temp.UnitPrice= stof(tempString);
            getline(ss, tempString, ',');
            tempString= removeSpaces(tempString);
            temp.Rating= stof(tempString);
            getline(ss, tempString, '\n');
            tempString= removeSpaces(tempString);
            temp.Sales = stoi(tempString);
            Products.push_back(temp);
            i++; //increment number of lines
        }
        SuperMarket.close(); //closing the file
    }
    else cout << "Unable to open file"; //if the file is not open output
}
//Writes to File When Exiting
void WriteToFile(){
     fstream file("Products.txt", ios::trunc | ios::out);
for(int i = 0; i <Products.size(); i++){
      file << Products[i].ProductNumber << ',' <<
         Products[i].ProductName << ',' <<
         Products[i].Category << ',' <<
         Products[i].ProductType << ',' <<
         Products[i].ProductionDate.Day << ',' <<
         Products[i].ProductionDate.Month << ',' <<
         Products[i].ProductionDate.Year << ',' <<
         Products[i].ExpireDate.Day << ',' <<
         Products[i].ExpireDate.Month << ',' <<
         Products[i].ExpireDate.Year << ',' <<
         Products[i].Quantity << ',' <<
         Products[i].MeasurementUnit << ',' <<
         Products[i].UnitPrice << ',' <<
         Products[i].Rating << ',' <<
         Products[i].Sales << endl;
}
file.close();
}

//Structure for storing Account Details
struct Account{
    string Name,userName,password,position;
    void accountPosition(){
        up:
        cout<<"Your Position in the organization? "<<endl;
        cout<<"1. Manager"<<endl;
        cout<<"2. Cashier"<<endl;
        cout<<"Your Answer: ";
        int choice;
        cin>>choice;
        if(choice==1){
            position="Manager";
        }else if(choice==2){
        position="Cashier";
        }else{
            cout<<"Invalid Answer!!";
            goto up;
        }
    }
};
vector<Account> Accounts;

//Function for loading Account from file
void loadAccount()
{
    // define variables
    string line;
    Account temp;
    //number of lines
    fstream AccountDetail;
    AccountDetail.open("Accounts.txt", ios::app | ios::out | ios::in ); //opening the file.
    if (AccountDetail.is_open()) //if the file is open
    {
        //ignore first line
        while (getline(AccountDetail,line)) //while the end of file is NOT reached
        {
            stringstream ss(line);
            getline(ss,temp.Name,',');
            getline(ss,temp.position,',');
            getline(ss,temp.userName,',');
            getline(ss,temp.password);
            Accounts.push_back(temp);
        }
        AccountDetail.close(); //closing the file
    }
    else cout << "Unable to open file"; //if the file is not open output
}
//Function for creating Accounts
string accountCreation(){
    Account temp;
    cout<<"Enter Your Name: ";
    cin.clear();
    cin.ignore();
    getline(cin,temp.Name);
    temp.accountPosition();
    cout<<"Set user name: ";
    cin>>temp.userName;
    cout<<"Set Password: ";
    cin>>temp.password;
    Accounts.push_back(temp);
    fstream file("Accounts.txt", ios::out | ios::in | ios::app);
    if(!(file.is_open())){
    cout<<"Failed to open file!!";
    }
    file<<endl<<temp.Name<<','<<temp.position<<','<<temp.userName<<','<<temp.password;
    file.close();
    return temp.position;
}
//Function for modifying Account details
void modifyAccount(){
    cout<<"Enter User name to change: ";
    string userSearch;
    cin>>userSearch;
    for(int i=0;i<Accounts.size();i++){
        if(Accounts[i].userName==userSearch){
            cout<<"What do you want to change"<<endl;
            cout<<"1. Account holder name"<<endl;
            cout<<"2. Password"<<endl;
            cout<<"3. Position in Organization"<<endl;
            cout<<"Your choice: ";
            int choice;
            cin>>choice;
            if(choice==1){
            cout<<"Enter your name: ";
            cin.clear();
            cin.ignore();
            getline(cin,Accounts[i].Name);
            }else if(choice==2){
            cout<<"Enter new password to change: ";
            cin.clear();
            cin.ignore();
            getline(cin,Accounts[i].password);
            }else if(choice==3){
            cout<<"Enter New Position: ";
            Accounts[i].accountPosition();
            }
        if(Accounts[i].position=="Manager"){
        system("pause");
        system("cls");
        MainMenu();
        }else{
            CashierAccount();
        }
        }
    }
        fstream file("Accounts.txt", ios::out | ios::in | ios::trunc);
    if(!(file.is_open())){
    cout<<"Failed to open file!!";
    }
    for(int i=0;i<Accounts.size();i++){
    file<<Accounts[i].Name<<','<<Accounts[i].position<<','<<Accounts[i].userName<<','<<Accounts[i].password<<endl;
    }
    file.close();

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
    // Initialization
    //ResizeWindow();
    // Print Full Table For reference to edit
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
    int Choice;
    system("cls");
    welcomeScreen();
    ChangeLineColor(14);
    cout<<setfill(' ')<<setw(30)<<"Receipt\n";
    cout<<setfill(' ')<<"Item No"<<setw(15)<<"Name \t"<<setw(8)<<"Quantity"<<setw(8)<<"Price"<<setw(10)<<"Amount\n";
    ChangeLineColor(15);
        cout << "\t-" << setfill('-') << setw(50) << "-" << endl;
        ChangeLineColor(14);
    for(int i=0; i<NumberofBoughtItems; i++)
    {
        int N;
        N=Location[i];
        cout<<setfill(' ')<<"Item "<<i+1<<": "<<setw(15)<<Products[N].ProductName<<setw(8)<<Quantity[i]<<setw(8)<<Products[N].UnitPrice<<setw(10)<<Quantity[i]*Products[N].UnitPrice<<endl;
        ChangeLineColor(15);
        cout << "\t-" << setfill('-') << setw(50) << "-" << endl;
        ChangeLineColor(14);
        TotalPrice=TotalPrice+(Quantity[i]*Products[N].UnitPrice);
    }

    cout<<setfill(' ')<<setw(47)<<"Txbl   "<<TotalPrice<<endl;
    cout<<setfill(' ')<<setw(47)<<"Tax(15%)   "<<0.15*TotalPrice<<endl;
    TotalPrice=1.15*TotalPrice;
    cout<<setfill(' ')<<setw(47)<<"TotalPrice  "<<TotalPrice<<endl;
    cout<<setfill(' ')<<setw(47)<<"Cash: ";
    cin>>Cash;
    cout<<setfill(' ')<<setw(47)<<"Change: "<<Cash-TotalPrice<<endl;
    for(int i=0; i<NumberofBoughtItems; i++)
    {
        int N;
        N=Location[i];
        Products[N].Quantity=Products[N].Quantity-Quantity[i];
        Products[N].Sales = Products[N].Sales + Quantity[i];
    }
     cout<<setfill(' ')<<setw(30)<<"Thank You For Your Purchase" << endl;
     system("pause");
      cout<<setfill(' ')<<setw(30)<<"To Perform another Sales Press 1, To Return to MainMenu Press 2, To exit Press 3;" << endl;
      Menu:
      cout<<setfill(' ')<<setw(30)<<"Choice: ";
      while(!(cin>>Choice))
    {
        ChangeLineColor(12);
        cout<<"Error! Invalid Input\n";
        cin.clear();
        cin.ignore(20, '\n');
        ChangeLineColor(14);
        goto Menu;
    }
    switch(Choice)
    {
        case 1:
            system("cls");
            CashierAccount();
            break;
        case 2:
            system("cls");
            MainScreen();
            break;
        case 3:
          WriteToFile();
         exit(0);
         break;
         default:
            ChangeLineColor(12);
            cout<<"Error!Choose a Correct Number\n";
            system("pause");
            system("cls");
            ChangeLineColor(14);
            goto Menu;
            break;


    }

}

void CashierAccount()
{
    ChangeLineColor(14);
    cout<<setfill(' ') << setw(50) <<"Welcome to CartShop\n\n";
    cout<<"\tEnter The Details of The Items Below \n \tIf You Finish Your Purchase  at Any Time Enter 0 \n";
    for(int i=0; i<1000; i++)
    {
        ProductFound=false;
MainMenu:
        cout<<"Item "<<i+1<<":\n";
ProductNum:
        cout<<"\tProduct Number: ";
        while(!(cin>>ProductNo[i]))
                {
                    ChangeLineColor(12);
                    cout<<"Error! Invalid Input\n";
                    cin.clear();
                    cin.ignore(' ', '\n');
                    ChangeLineColor(14);
                    goto ProductNum;
                }
        for(int j=0; j<Products.size(); j++)
        {
            switch(ProductNo[i])
            {
            case 0:
                char opt;
Finish:
                NumberofBoughtItems = i;

                cout << "\tHave You Finished Your Purchase(Y/N)\n";
                cin >> opt;
                opt = (char)toupper(opt);

                if(opt=='N')
                    {
                        system("pause");
                        goto MainMenu;
                        break;
                    }
                    if(opt=='Y')
                    {
                        system("pause");
                        PrintReceipt();
                        break;
                    }
                    else
                        {
                    ChangeLineColor(12);
                    cout<<"\t Error: Invalid Input Try again\n";
                    ChangeLineColor(14);
                    goto Finish;
                    break;
                    }

            case 1 ... 999999:
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
        Quant:
        cout << "\t\t Quantity: ";
        while(!(cin>>Quantity[i]))
                {
                    ChangeLineColor(12);
                    cout<<"Error! Invalid Input\n";
                    cin.clear();
                    cin.ignore(' ', '\n');
                    ChangeLineColor(14);
                    goto Quant;
                }
        ChangeLineColor(15);
        cout << "\t-" << setfill('-') << setw(50) << "-" << endl;
        ChangeLineColor(14);
    }
}

bool Search(int SearchedProduct)
{
    int i;
    for( i = 1; i < Products.size(); i++)
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
            i = 1 + Products.size();
            return true;
        }
        else if(Products[i].ProductNumber == 0)
        {
            cout << "\n\t\t\t\t\t\t\t\tResult \n";
            i = 1 + Products.size();
            FlagDelete = 1;
            FlagEdit = 1;
            FeedBackMessage("Product Not Found",12);
            return false;
        }
    }
    if(FlagEdit==1&&FlagDelete==1){
        return false;
    }
}


//function to calculate profit
void ProfitCalc(){
ProfitMenu:cout<<endl<<"\t\t\t\t\t\t\t PROFIT PAGE "<<endl;
    float ProfitInBirr = 0;
    float GrossIncome = 0;
    float SingleProductIncome = 0;
    float SingleProductProfit = 0;
    int ProfitChoice;
for(int i = 0; i <Products.size(); i++){
       GrossIncome += float(Products[i].Sales*Products[i].UnitPrice);

}
cout<<"\t\t\t\t\t\t\t1. Single Product."<<endl;
cout<<"\t\t\t\t\t\t\t2. Total Products Profit."<<endl;
cout<<"\t\t\t\t\t\t\t3. Main Menu."<<endl;
cout<<"Choice: ";
cin>>ProfitChoice;
switch(ProfitChoice){
case 1:
cout<<" Enter Product Number: ";
int ProfitProductSearch;
cin>>ProfitProductSearch;
 for(int i = 1; i < Products.size(); i++)
    {
        if( ProfitProductSearch == Products[i].ProductNumber && Products[i].ProductNumber != 0){
            SingleProductIncome = float(Products[i].UnitPrice*Products[i].Sales);
            SingleProductProfit = float(ProfitMarigin*SingleProductIncome);
             FeedBackMessage("Product Found",10);
            cout << "\t\t\t\t\t\t\t    Result";
            cout << endl << endl;
            PrintTableDividers();
            PrintTableHeader();
            PrintTableDividers();
            PrintInItemValue(Products[i]);
            PrintTableDividers();
            cout << endl << endl;
            cout<< "\t\t\t\t\t\t\tIncome From Product: "<<SingleProductIncome<<" Birr"<<endl;
            cout<< "\t\t\t\t\t\t\tIncome From Product: "<<SingleProductProfit<<" Birr"<<endl;
            i = 1 + Products.size();

        }
         else if(ProfitProductSearch>Products.size()){
            cout << "\n\t\t\t\t\t\t\t\tResult \n";
            i = 1 + Products.size();
            FeedBackMessage(" Product Not Found ",12);
            system("pause");
            system("cls");
            goto ProfitMenu;
        }
    }
    break;
case 2:
ProfitInBirr = float(GrossIncome*ProfitMarigin);
cout<<"\t\t\t\t\t\t\t Total Income: "<<GrossIncome<<" Birr"<<endl;
cout<<"\t\t\t\t\t\t\t Profit :"<<ProfitInBirr<<" Birr"<<endl;
break;
case 3:
    system("cls");
    MainMenu();
break;
default:
    FeedBackMessage(" Invalid Choice ", 12);
    system("cls");
    goto ProfitMenu;

}
}


void EditItem()
{
    // Print Full Table For reference to edit
    //PrintInTableFormat();
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
    bool flag=Search(SerialNumber);
    if(flag)
    {
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
        if(EditChoice> 10 || EditChoice<1)
        {
            cout<<" Enter Choice( 1 - 10): ";
            goto edit;
        }
        cout << endl;
        // Accept new values based on choice
        switch(EditChoice)
        {
        case 1:
            cout << " Enter New Product Name: ";
            cin.clear();
            cin.ignore(20, '\n');
            getline(cin,Products[SerialNumber].ProductName);
            break;
        case 2:
            cin.clear();
            cin.ignore(20, '\n');
            cout << " Enter New Product Category: ";
            getline(cin,Products[SerialNumber].Category);
            break;
        case 3:
            cin.clear();
            cin.ignore(20, '\n');
            cout << "Enter New Product Type: ";
            getline(cin,Products[SerialNumber].ProductType);
            break;
        case 4:
date:
            cout << " Enter New Production Date" << endl;
            cout << "\t New Day: ";
            while(!( cin >> Products[SerialNumber].ProductionDate.Day))   // INPUT VALIDATION FOR DATE EDITING
            {
                cout<< "\n**********Invalid input.**********\n";
                cin.clear();
                cin.ignore(20, '\n');
                goto date;
            }
            if( Products[SerialNumber].ProductionDate.Day<1 || Products[SerialNumber].ProductionDate.Day>30)
            {
                cout<<" **********Invalid Day.********** \n";
                goto date;
            }

            cout << "\t New Month: ";

            while(!( cin >> Products[SerialNumber].ProductionDate.Month))   // INPUT VALIDATION FOR DATE EDITING
            {
                cout<< "\nInvalid input.\n";
                cin.clear();
                cin.ignore(20, '\n');
                goto date;
            }
            if( Products[SerialNumber].ProductionDate.Month<1 || Products[SerialNumber].ProductionDate.Month>12)
            {
                cout<<" Invalid Day. \n";
                goto date;
            }
            cout << "\t New Year: ";
            while(!( cin >> Products[SerialNumber].ProductionDate.Year))   // INPUT VALIDATION FOR DATE EDITING
            {
                cout<< "\n**********Invalid input.**********\n";
                cin.clear();
                cin.ignore(20, '\n');
                goto date;
            }
            if( Products[SerialNumber].ProductionDate.Year<2015 || Products[SerialNumber].ProductionDate.Year>2021)
            {
                cout<<"**********Invalid Year.**********\n";
                goto date;
            }
            break;
        case 5:
            cout << " Enter New Expire Date: ";
            cout << "\t New Day: ";

            while(!( cin >> Products[SerialNumber].ExpireDate.Day))   // INPUT VALIDATION FOR DATE EDITING
            {
                cout<< "\n**********Invalid input.**********\n";
                cin.clear();
                cin.ignore(20, '\n');
                goto date;
            }
            if( Products[SerialNumber].ExpireDate.Day<1 || Products[SerialNumber].ExpireDate.Day>30)
            {
                cout<<"**********Invalid Day.**********\n";
                goto date;
            }

            cout << "\t New Month: ";
            while(!( cin >> Products[SerialNumber].ExpireDate.Month))   // INPUT VALIDATION FOR DATE EDITING
            {
                cout<< "\n**********Invalid input.**********\n";
                cin.clear();
                cin.ignore(20, '\n');
                goto date;
            }
            if( Products[SerialNumber].ExpireDate.Month<1 || Products[SerialNumber].ExpireDate.Month>12)
            {
                cout<<"**********Invalid Day.**********\n";
                goto date;
            }

            cout << "\t New Year: ";
            while(!( cin >> Products[SerialNumber].ExpireDate.Year))   // INPUT VALIDATION FOR DATE EDITING
            {
                cout<< "\n**********Invalid input.**********\n";
                cin.clear();
                cin.ignore(20, '\n');
                goto date;
            }
            if( Products[SerialNumber].ExpireDate.Year<2015 || Products[SerialNumber].ExpireDate.Year>2021)
            {
                cout<<"**********Invalid Day.**********\n";
                goto date;
            }

            break;
        case 6:
            cout << " Enter New Quantity: ";

            while(!( cin >> Products[SerialNumber].Quantity))   // INPUT VALIDATION FOR DATE EDITING
            {
                cout<< "\n**********Invalid input.**********\n";
                cin.clear();
                cin.ignore(20, '\n');
                goto date;
            }
            break;
        case 7:
            cout << " Enter New Measurement Unit: ";
            cin.clear();
            cin.ignore(20, '\n');
            getline(cin,Products[SerialNumber].MeasurementUnit);
            break;
        case 8:
            cout << " Enter New Unit Price: ";
            while(!(cin>>Products[SerialNumber].UnitPrice))
            {
                cout<< "**********Invalid Day.**********\n";
                cout << " Enter New Unit Price: ";
            cin.clear();
            cin.ignore(20, '\n');

            }

            break;
        case 9:
            cout << " Enter New Rating: ";
            while(!(cin>>Products[SerialNumber].Rating))
            {
                cout<< "**********Invalid Day.**********\n";
                cout << " Enter New Rating: ";
                cin.clear();
                cin.ignore(20, '\n');

            }
            break;
        case 10:
            cout << " Enter New Sale ";
            while(!(cin>>Products[SerialNumber].Sales))
            {
                cout<< "**********Invalid Day.**********\n";
                cout << " Enter New Rating: ";
                cin.clear();
                cin.ignore(20, '\n');

            }

            break;
        }
        system("color 0A");
        cout << endl << " \t ---- \t Item Edited Successfully! \t ----" << endl << endl;
    }else{
        FeedBackMessage("Product Not Found",12);
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
    bool flag = Search(SerialNumber);

    if(flag)
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

//
void SaveSettings()
{
    fstream SettingsFile;
    SettingsFile.open("Settings.txt", ios::out);
    if(SettingsFile.is_open()){
        SettingsFile << IsFullScreenMode;
        SettingsFile.close();
    }
}

void LoadSettings()
{
    fstream SettingsFile;
    SettingsFile.open("Settings.txt", ios::in);
    if(SettingsFile.is_open()){
        string line;
        while(getline(SettingsFile, line)){
            IsFullScreenMode = stoi(line);
        }
        SettingsFile.close();
    }
}

/// Developers
void Developers()
{
    string ListOfDevNames[5] = {"Brook Feleke  ","Dagmawi Esayas", "Dawit Getachew","Ebenezer Yonas","Melat Gizachew"};
    string ListOfDevIDs[5] = {"ETS 0184/12","ETS 0204/12", "ETS 0214/12","ETS 0226/12","ETS 1020/12"};
    for(int i = 0; i < 5; i++)
    {
        cout << "\t\t\t\t\t\t\t" << i + 1 << ". " << ListOfDevNames[i] << "\t" << ListOfDevIDs[i] << endl;
    }
}
void About()
{
    cout<<"\t\t\t\t\t\t\tThe project is a Supermarket Management System. \n\t\t\t\t\t\t\tA system placed in hopes of making the daily purchase and transaction easier. \n\t\t\t\t\t\t\tThe main advantage of this system will be to convert the manual work such as billing calculations, organizing stock items data and employee management."<<endl;

}
void ChangeFullScreenMode()
{
    LoadSettings();
    if(IsFullScreenMode == 1){
        int DisableFullScreenModeChoice;
        cout << endl << "\t\t\t\t\t\tDo you want to disable full screen mode?" << endl << endl;
        cout << "\t\t\t\t\t\t\t\t 1. Yes" << endl;
        cout << "\t\t\t\t\t\t\t\t 2. No" << endl << endl;
        cout << "\t\t\t\t\t\t\t\tChoice: ";
        cin >> DisableFullScreenModeChoice;
        if(DisableFullScreenModeChoice == 1){
            IsFullScreenMode = 0;
            SaveSettings();
            FeedBackMessage("Full Screen Mode Disabled!", 10);
            ChangeLineColor(15);
            cout << endl << "\t\t\t\t\t\tChanges will take effect on the next start of the app!" << endl << endl;
        } else if(DisableFullScreenModeChoice == 2) {
            FeedBackMessage("No Changes Have Been Made", 15);
        }
    } else {
        int EnableFullScreenModeChoice;
        cout << endl << "\t\t\t\t\t\tDo you want to enable full screen mode?" << endl << endl;
        cout << "\t\t\t\t\t\t\t\t 1. Yes" << endl;
        cout << "\t\t\t\t\t\t\t\t 2. No" << endl << endl;
        cout << "\t\t\t\t\t\t\t\tChoice: ";
        cin >> EnableFullScreenModeChoice;
        if(EnableFullScreenModeChoice == 1){
            IsFullScreenMode = 1;
            SaveSettings();
            ChangeLineColor(10);
            cout << endl << endl;
            FeedBackMessage("Full Screen Mode Enabled!", 10);
            ResizeWindow();
        } else if(EnableFullScreenModeChoice == 2) {
            FeedBackMessage("No Changes Have Been Made", 15);
        }
    }
}

void Settings()
{
int SettingChoice, ResetChoice;
    cout << "\t\t\t\t\t\t\t What would you like to do? " << endl << endl;
    cout << "\t\t\t\t\t\t\t 1. Fullscreen Mode" << endl;
    cout << "\t\t\t\t\t\t\t 2. Reset Product Sample" << endl << endl;
    cout << "\t\t\t\t\t\t\t\tChoice: ";
    cin >> SettingChoice;
    switch(SettingChoice){
    // Full Screen Mode
    case 1:
        ChangeFullScreenMode();
        break;
    case 2:
        ChangeLineColor(12);
        cout << "\t\t\t\tAre you sure you want to reset product samples? " << endl;
        ChangeLineColor(12);
        cout << "\t\t\t\t\t\t\t1. Yes" << endl;
        ChangeLineColor(12);
        cout << "\t\t\t\t\t\t\t2. No" << endl;
        cin >> ResetChoice;
        if(ResetChoice == 1){
            //LoadProduct("ProductsSample.txt");
            LoadProduct();
            FeedBackMessage("Database Reset Successfully", 10);
        } else {
            FeedBackMessage("Database Remains Unchanged", 15);
        }
        break;
    }
}
void AccountManagment()
{
    Menu:
    cout<<endl;
    cout<<"\t "<<setfill('\t')<<setw(18) <<"1. Sign Up. "<<endl;
    cout<<"\t "<<setfill('\t')<<setw(25) <<"2. Modify Account. "<<endl;
    cout<<"\t "<<setfill('\t')<<setw(23) <<"3. Back to Menu. "<<endl;
    cout<<"\t "<<setfill('\t')<<setw(15) <<"4. Exit. "<<endl<<endl;
    cout<<"\t "<<setfill('\t')<<setw(14) <<"Choice: ";
    int choice;
    while(!(cin>>choice))
    {
        FeedBackMessage("Invalid Input", 15);
        cin.clear();
        cin.ignore(20, '\n');
        system("pause");
        //system("cls");
    }

    switch(choice)
    {
    // Print all data in table format
    case 1:
        signUp();
        break;
    case 2:
      modifyAccount();
        break;
    case 3:
        system("cls");
        MainMenu();
        break;
    case 4:
        WriteToFile();
        //return 0;
        exit(0);
        break;
    default:
        cout<<"Invalid Input\n";
        system("cls");
        goto Menu;
        break;
}

}

/// Main Menu
// Main Menu to allow navigation
int MainScreen(){
    Menu:
    welcomeScreen();
     cout<<"\t "<<setfill('\t')<<setw(17) <<"1. Login. "<<endl;
    cout<<"\t "<<setfill('\t')<<setw(17) <<"2. About. "<<endl;
    cout<<"\t "<<setfill('\t')<<setw(22) <<"3. Developers. "<<endl;
    cout<<"\t "<<setfill('\t')<<setw(19) <<"4. Setting. "<<endl;
    cout<<"\t "<<setfill('\t')<<setw(16) <<"5. Exit. "<<endl<<endl;
    cout<<"\t "<<setfill('\t')<<setw(15) <<"Choice: ";
    int choice;
    while(!(cin>>choice))
    {
        FeedBackMessage("Invalid Input", 15);
        cin.clear();
        cin.ignore(20, '\n');
        system("pause");
        //system("cls");
    }

    switch(choice)
    {
    // Print all data in table format
    case 1:
        login();
        break;
    case 2:
        AppHeader("About");
        About();
        AppFooter();
        goto Menu;
    case 3:
        AppHeader("Developers Info");
        Developers();
        AppFooter();
        goto Menu;
        break;
    case 4:
        AppHeader("Setting");
        Settings();
        AppFooter();
        goto Menu;
        break;
    case 5:
        WriteToFile();
        //return 0;
        exit(0);
        break;
}
}
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
    cout<<"\t\t\t\t\t\t\t 8. Profit Information. "<<endl;
    cout<<"\t\t\t\t\t\t\t 9. Settings. "<<endl;
    cout<<"\t\t\t\t\t\t\t 10. Introduction/Usage. "<<endl;
    cout<<"\t\t\t\t\t\t\t 11. Account Managment. "<<endl;
    cout<<"\t\t\t\t\t\t\t 12. Logout "<<endl;
    cout<<"\t\t\t\t\t\t\t 14. Exit "<<endl;
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
        cout<<"\t\t\t\t\t\t\tChoose how you want to sort: "<<endl;
        cout<<"\t\t\t\t\t\t\t1. Unit Price"<<endl;
        cout<<"\t\t\t\t\t\t\t2. Rating"<<endl;
        cout<<"\t\t\t\t\t\t\t3. Production date"<<endl;
        cout<<"\t\t\t\t\t\t\t4. Expire date"<<endl;
        cout<<"\t\t\t\t\t\t\t5. Quantity"<<endl;
        cout<<"\t\t\t\t\t\t\t6. Sales"<<endl;
        int Choice,OrderChoice;
        cout<<"\t\t\t\t\t\t\tYour choice: ";
        cin>>Choice;
ReturnToOrderChoice:
        cout<<"\t\t\t\t\t\t\tChoose Order"<<endl;
        cout<<"\t\t\t\t\t\t\t1. Ascending Order"<<endl;
        cout<<"\t\t\t\t\t\t\t2. Descending Order"<<endl;
        cout<<"\t\t\t\t\t\t\tYour choice: ";
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
      case 8:
        system("cls");
        AppHeader("Profit Information");
        ProfitCalc();
        AppFooter();
        system("pause");
        goto Menu;
    // Developers
    case 11:
        AccountManagment();
        goto Menu;
    // Logout
    case 12:
        system("cls");
        MainScreen();
        break;
    // Exit
    case 13:
        WriteToFile();
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
void login(){
    up:
        int counter=0;
    string username,password;
    cout<<"Enter Detail to Login (For trial use \n1.Manager (Username: admin and Password: admin) \n2. Cashier (Username: cashierAdmin and Password: cashierAdmin))"<<endl;
    cout<<"Username: ";
    cin>>username;
    for(int i=0;i<Accounts.size();i++){
    if(username==Accounts[i].userName){
    upPass:
    cout<<"Password: ";
    cin>>password;
    if(password==Accounts[i].password){
        cout<<"Login Successful"<<endl;
        if(Accounts[i].position=="Manager"){
        system("pause");
        system("cls");
        MainMenu();
        }else{
            CashierAccount();
        }
    }else{
        cout<<"Password does not match!!"<<endl;
        goto upPass;
    }
    }else{
        counter++;
    }
    }
    if(counter==Accounts.size()){
        cout<<"Account does not exist!!"<<endl;
        goto up;
    }
}
void signUp(){
    string position = accountCreation();
    system("cls");
    if(position=="Manager"){
        system("pause");
        system("cls");
        MainMenu();
        }else{
            CashierAccount();
        }
    MainMenu();
}
/// M A I N
int main()
{
    //Calls function to load products from file
    LoadProduct();
    loadAccount();
    InitializeSystemVariables();
    MainScreen();
}
