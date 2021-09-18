/// L I B R A R I E S
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cctype>

/// N A M E S P A C E
using namespace std;

/// Global Variables
float Quantity[100], TotalPrice = 0, Cash;
int NumberofBoughtItems, ProductNo[100], amount, Location[100];
bool ProductFound;
int NumberOfProducts = 80, FlagDelete = 0, FlagEdit = 0;

/// Prototype functions
int MainMenu(void);

/// Theming Functions
// Resizes the console window
void ResizeWindow()
{
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1600, 800, TRUE);
}

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

    //Creation of New Product
    void CreateProduct(){
        cout<<"\n Please Enter The Product Number : "<<NumberOfProducts + 1;
        NumberOfProducts++;
        ProductNumber = NumberOfProducts;
        //cin>>ProductNumber;

        cout<<"\n Please Enter The Product Name : ";
        cin>>ProductName;

        cout<<"\n Please Enter The Category Of The Product : ";
        cin>>Category;

        cout<<"\n Please Enter The Product Type : ";
        cin>>ProductType;

        cout<<"\n Please Enter The Production Date : ";
        cin>>ProductionDate.Day;

        if(ProductionDate.Day == 0){ //In case of  a null value on Production Date
            ProductionDate.Month=0;
            ProductionDate.Year=0;
        }

        else{
            cin>>ProductionDate.Month;
            cin>>ProductionDate.Year;
        }

        cout<<"\n Please Enter The Expired Date : ";
        cin>>ExpireDate.Day;

        if(ExpireDate.Day == 0){ //In case of  a null value on Expire Date
            ExpireDate.Month=0;
            ExpireDate.Year=0;
        }


        else{
            cin>>ExpireDate.Month;
            cin>>ExpireDate.Year;
        }

        cout<<"\n Please Enter The Quantity: ";
        cin>>Quantity;

        cout<<"\n Please Enter The Measurement Unit: ";
        cin>>MeasurementUnit;

        cout<<"\n Please Enter The Unit Price: ";
        cin>>UnitPrice;

        cout<<"\n Please Enter The Rating: ";
        cin>>Rating;

        cout<<"\n Please Enter The Number of Sales: ";
        cin>>Sales;

    }

} Products[9999];

// A function to create a new product
void InputProduct(int Count)
{
    for(int i = 0; i < Count; i++){
        Products[NumberOfProducts + i].CreateProduct();
    }
    NumberOfProducts += Count;
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
    system("pause");
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
    for( i = 1; i < 9999; i++)
    {
        if( SearchedProduct == Products[i].ProductNumber && Products[i].ProductNumber != 0)
        {
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
            i = 9999;
            FlagDelete = 1;
            FlagEdit = 1;
            cout<<"\n**********Product Not found**********\n"<<endl;
        }
    }
    system("pause");
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
        cout << endl << " \t ---- \t Item Edited Successfully! \t ----" << endl << endl;
    }
    FlagEdit = 0;
    system("pause");
    system("color 0F");
    system("cls");

}

// This function asks for a serial number of an item and then it allows you to delete it from the stock
void DeleteItem()
{
    // Print Full Table For reference to edit
    //PrintInTableFormat();
    // Enter Serial Number of a product to edit
AskDeletion:
    int SerialNumber;
    cout << endl << " Enter Serial Number Of Item you want to delete: ";

    while(!(cin>>SerialNumber))    // INPUT VALIDATION FOR
    {
        cout<< "\nInvalid input.\n\n";
        cin.clear();
        cin.ignore(20, '\n');
    }
    Search(SerialNumber);

    if( !(FlagDelete))
    {
        Product *Item = &Products[SerialNumber];
        cout << endl << " Are you sure you want to delete this item? (Y/N): ";
        cout<< endl << "1. Yes.";
        cout<< endl << "2. No."<<endl;
        system("color 0C");
        int ConfirmDeletion;
        while(!(cin>>ConfirmDeletion))    // INPUT VALIDATION FOR
        {
            cout<< "\nInvalid input.\n\n";
            cin.clear();
            cin.ignore(20, '\n');
        }
        if(ConfirmDeletion == 1)
        {
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
            system("color 0A");
            cout << endl << " \t ---- \t Item Deleted Successfully! \t ----" << endl << endl;
            system("pause");
            system("cls");
        }
        else if (ConfirmDeletion == 2)
        {
            system("color 0E");
            //goto AskDeletion;
        }
    }
    FlagDelete = 0;
    system("color 0F");
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

// Initialize product sample to show demo
void ProductSampleData()
{
    //Initializing Bread and Bakery sample data
    Products[1] = {1 ,"Banana Bread ", "Bread and Bakery", "Bread ",{6,9,21}, {10,9,21}, 200,"Loafs ",22 ,4.9 };
    Products[2] = {2 ,"Whole Wheat ", "Bread and Bakery", "Bread ",{6,9,21}, {10,9,21},200 ,"Loafs",3 ,2.5 };
    Products[3] = {3 ,"Sourdough ", "Bread and Bakery", "Bread ",{6,9,21}, {10,9,21}, 200,"Loafs",4 ,4.7 };
    Products[4] = {4 ,"Baguette ", "Bread and Bakery", "Bread ",{6,9,21}, {10,9,21},200 ,"Loafs",10 ,3 };
    Products[5] = {5 ,"Difo Dabo ", "Bread and Bakery", "Bread ",{6,9,21}, {10,9,21}, 200," Loafs",20 ,4.9 };
    Products[6] = {6 ,"White Bread ", "Bread and Bakery", "Bread ",{6,9,21}, {10,9,21}, 200,"Loafs",3 ,2.8 };
    Products[7] = {7 ,"Carrot Cake ", "Bread and Bakery", "Bread ",{6,9,21}, {10,9,21},200 ,"Loafs",20 ,4.1 };
    Products[8] = {8 ,"Bagels ", "Bread and Bakery", "Bread ",{6,9,21}, {10,9,21}, 200," Loafs",12 ,3.9 };
    Products[9] = {9 ,"Chocolate Chip ", "Bread and Bakery", "Cookies ",{6,9,21}, {10,9,21},200 ,"Kilogram ",30 ,4.8 };
    Products[10] = {10 ,"Shortbread Cookie ", "Bread and Bakery", "Cookies ",{6,9,21}, {10,9,21}, 200,"Kilogram ",28 ,4 };
    Products[11] = {11 ,"Peanut Butter ", "Bread and Bakery", "Cookies ",{6,9,21}, {10,9,21},200 ,"Kilogram ",28 ,2.5 };

    //Initializing Pasta and rice sample data
    Products[12] = {12,"Short Pasta ", "Pasta and Rice", "Pasta ",{6,9,21}, {10,9,21}, 100,"Kilogram ",25 ,4.3 };
    Products[13] = {13,"Long Pasta ", "Pasta and Rice", "Pasta ",{6,9,21}, {10,9,21}, 100,"Kilogram ",25 ,4.3 };
    Products[14] = {14,"Macaroni ", "Pasta and Rice", "Pasta ",{6,9,21}, {10,9,21}, 100,"Kilogram ",24 ,4 };
    Products[15] = {15,"Fettuccine", "Pasta and Rice", "Pasta ",{6,9,21}, {10,9,21},100 ,"Kilogram ",28 ,2.5 };
    Products[16] = {16,"Lasagna", "Pasta and Rice", "Pasta ",{6,9,21}, {10,9,21}, 100,"Kilogram ",32 ,5 };
    Products[17] = {17,"Spaghetti", "Pasta and Rice", "Pasta ",{6,9,21}, {10,9,21}, 100," Kilogram",30 ,4.9 };
    Products[18] = {18,"Brown Rice ", "Pasta and Rice", "Rice ",{6,9,21}, {10,9,21}, 100,"Kilogram ",30 ,4.7 };
    Products[19] = {19,"White Rice ", "Pasta and Rice", "Rice ",{6,9,21}, {10,9,21},100 ," Kilogram",27 ,2.5 };

    //Initializing Dairy and meat sample data
    Products[20] = {20 ,"Beef ", "Dairy and Meat", "Meat ",{6,9,21}, {10,9,21},100 ,"Kilogram ",250 ,4.9 };
    Products[21] = {21 ,"Pork ", "Dairy and Meat", "Meat ",{6,9,21}, {10,9,21},100 ,"Kilogram ", 200,2.5 };
    Products[22] = {22 ,"Mutton ", "Dairy and Meat", "Meat ",{6,9,21}, {10,9,21},100 ,"Kilogram ",260 , 4.4};
    Products[23] = {23 ,"Chicken ", "Dairy and Meat", "Meat ",{6,9,21}, {10,9,21},100 ,"Kilogram ",300 ,4.9 };
    Products[24] = {24 ,"Turkey", "Dairy and Meat", "Meat ",{6,9,21}, {10,9,21},100 ,"Kilogram ",280 ,3.9 };
    Products[25] = {25 ,"Butter ", "Dairy and Meat", "Dairy ",{6,9,21}, {10,9,21},100 ,"Kilogram ",450 ,5 };
    Products[26] = {26 ,"Milk ", "Dairy and Meat ", "Dairy ",{6,9,21}, {10,9,21}, 100,"Liters ",40 ,4.9 };
    Products[27] = {27 ,"Mozzarella ", "Dairy and Meat ", "Cheese ",{6,9,21}, {10,9,21},100 ,"Kilogram ",320 ,4.5 };
    Products[28] = {28 ,"Cheddar ", "Dairy and Meat ", "Cheese ",{6,9,21}, {10,9,21},100 ,"Kilogram ",300 ,4.9 };
    Products[29] = {29 ,"Parmesan ", "Dairy and Meat", "Cheese ",{6,9,21}, {10,9,21},100 ,"Kilogram ",360 ,4.4 };
    Products[30] = {30 ,"Gouda ", "Dairy and Meat ", "Cheese ",{6,9,21}, {10,9,21},100 ,"Kilogram ",380 ,5 };
    Products[31] = {31 ,"Yoghurt ", "Dairy and Meat ", "Dairy ",{6,9,21}, {10,9,21},100 ,"Liters ",60 ,4.9 };
    Products[32] = {32 ,"Powdered Milk ", "Dairy and Meat ", "Dairy ",{6,9,21}, {10,9,21},100 ,"Kilogram ",1200 ,4.6 };
    Products[33] = {33 ,"Ice Cream", "Dairy and Meat ", "Dairy ",{6,9,21}, {10,9,21},100 ,"Kilogram ",300 ,5 };

     //Initializing Beverages and Drinkssample data
    Products[34] = {34,"Beer ", "Beverages and Drinks", "Beverage ",{6,9,21}, {0,0,0},103,"Milliliter ", 200,2.5 };
    Products[35] = {35,"Cider ", "Beverages and Drinks", "Beverage ",{6,9,21}, {10,9,21},103,"Milliliter ",260, 4.4};
    Products[36] = {36,"Hard Soda ", "Beverages and Drinks", "Beverage ",{3,12,21}, {10,9,21},100,"Milliliter ",300,4.9 };
    Products[37] = {37,"Wine", "Beverages and Drinks", "Beverage ",{10,12,21}, {10,9,21},102,"Milliliter ",280,3.9 };
    Products[38] = {38,"Barley ", "Beverages and Drinks", "Beverage ",{6,9,21}, {10,9,26},101,"Milliliters ",450,5 };
    Products[39] = {39,"Turkish ", "Beverages and Drinks", "Beverage ",{6,9,21}, {10,9,27}, 106,"Liters ",40,4.9 };
    Products[40] = {40,"Moka ", "Beverages and Drinks", "Beverage ",{6,9,21}, {10,9,25},100,"Milliliter ",320,4.5 };
    Products[41] = {41,"Kamora ", "Beverages and Drinks", "Soft Drinks ",{6,9,21}, {10,9,21},107,"Milliliter ",300,4.9 };
    Products[42] = {42,"Amarula ", "Beverages and Drinks", "Soft Drinks ",{6,9,20}, {10,9,21},108,"Milliliter ",360,4.4 };
    Products[43] = {43,"Carolans ", "Beverages and Drinks", "Soft Drinks ",{6,9,21}, {10,9,21},109,"Milliliter ",380,5 };
    Products[44] = {44,"Rosolio ", "Beverages and Drinks", "Soft Drinks ",{3,9,21}, {10,9,21},234,"Litres ",60,4.9 };
    Products[45] = {45,"Aurum ", "Beverages and Drinks", "Soft Drinks ",{6,9,21}, {10,9,21},257,"Milliliter ",1200,4.6 };
    Products[46] = {46,"Cointreau", "Beverages and Drinks", "Soft Drinks ",{6,9,21}, {10,9,21},234,"Milliliter ",300,5};
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
    Products[60] = {60,"Spoon","Kitchen Utensils","Spoon",{10,11,17},{14,10,20},40,"Items",30.45,2.5};
    Products[61] = {61,"Napkins","Sanitary","Baby Wipes",{20,12,18},{15,11,21},12,"Packages",40.00,4.5};
    Products[62] = {62,"Lotion","Health And Bodycare","Nivea",{30,10,19},{16,12,22},10,"Bottle",99.39,5.0};

     //Initializing Cereal sample data
    Products[63] = {63,"Barely","Cereal","Barely",{10,11,2020},{10,9,21},40,"Kg",14.45,3.5};
    Products[64] = {64,"Wheat","Cereal","Wheat",{20,12,2018},{10,9,21},52,"Kg",12.00,4.5};
    Products[65] = {65,"Oats","Cereal","Oats",{30,10,2019},{10,9,21},50,"Kg",120.39,5.0};
    Products[66] = {66,"Sorghum","Cereal","Sorghum",{23,12,2019},{10,9,21},45,"Kg",13,3.0};
    Products[67] = {67,"Millets","Cereal","Millets",{12, 12, 2013},{10,9,21},45,"Kg",25,2.9};

    //Initializing Cooking Oils sample data
    Products[68] = {68,"Jazzle Berry","Cooking Oil","Cotton seed",{12, 7, 2018},{12, 7, 2022},90,"Liter",95,2.9};
    Products[69] = {69,"New Star","Cooking Oil","Vegetable Oil",{22, 8, 2018},{27, 9, 2022},120,"Liter",130,4.5};
    Products[70] = {70,"Oracle","Cooking Oil","Peanut Oil",{17, 1, 2018},{12, 5, 2022},100,"Liter",117,5};
    Products[71] = {71,"Tena","Cooking Oil","Sunflower Oil",{1, 1, 2020},{12, 1, 2023},100,"Liter",136,5};
    Products[72] = {72,"Flawless","Cooking Oil","Avocado Oil",{9, 11, 2020},{12, 12, 2022},45,"Liter",200,5};

    //Initializing Canned Foods sample data
    Products[73] = {73,"Campell","Canned Foods","Soup",{19, 3, 2020},{19, 3, 2022},100,"Can",85,5};
    Products[74] = {74,"Campell","Canned Foods","Fruits",{21, 5, 2021},{20, 5, 2024},100,"Can",95,4.5};
    Products[75] = {75,"Heinz","Canned Foods","Baked beans",{27, 3, 2022},{29, 3, 2024},100,"Can",80,3.5};
    Products[76] = {76,"American Garden","Canned Foods","Sweet Corn",{1, 1, 2020},{1, 1, 2024},100,"Can",90,3.9};
    Products[77] = {77,"Healthy Choice","Canned Foods","Pasta Sauce",{29, 5, 2020},{1, 6, 2024},100,"Can",75,4.4};
    Products[78] = {78,"Eden Foods","Canned Foods","Mushrooms",{11, 2, 2020},{11, 2, 2024},100,"Can",80,4};
    Products[79] = {79,"Green Giants","Canned Foods","Green Peas",{29, 7, 2020},{29, 7, 2024},100,"Can",80,3.2};
}

/// Welcome Screen
/*
    This function contains a simple ASCII art generated from
    PatorJK.com specifically used the Text 2 ASCII generator app (https://patorjk.com/software/taag/#p=display&f=Univers&t=CartShop)
    website along with a simple welcome header.
*/
void welcomeScreen()
{
    //system("cls");
    cout << "\n\n" << endl;
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
    cout << "\t\t\t\t\t\t*" << setfill('*') << setw(50) << "*" << endl;
    cout << "\t\t\t\t\t\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t\t\t\t\t\t*" << setfill(' ') << setw(32) << "W E L C O M E !" << setfill(' ') << setw(18) << "*" << endl;
    cout << "\t\t\t\t\t\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t\t\t\t\t\t*" << setfill('-') << setw(50) << "*" << endl;
    cout << endl;
    //system("pause");
    //system("cls");
}

void appHeader(string title)
{
    //char capitalTitle = title;
    for_each(title.begin(), title.end(), [](char & c){
        c = ::toupper(c);
    });
    cout << "\t" << title << "\n" << setw(180) << setfill('-')  << "\n" << endl;
}

/// Main Menu
// Main Menu to allow navigation
int MainMenu()
{
    int Choice, InvalidChoiceCounter= 0;
    Menu:
    welcomeScreen();
    //system("cls");
    cout<<"\t\t\t\t\t\t\t1. Print all Products. "<<endl;
    cout<<"\t\t\t\t\t\t\t2. Search for product. "<<endl;
    cout<<"\t\t\t\t\t\t\t3. Delete Item from Stock. "<<endl;
    cout<<"\t\t\t\t\t\t\t4. Edit a Product "<<endl;
    cout<<"\t\t\t\t\t\t\t5. Sorting Functions "<<endl;
    cout<<"\t\t\t\t\t\t\t6. Sales. "<<endl;
    cout<<"\t\t\t\t\t\t\t7. Enter a new Product. "<<endl;
    cout<<"\t\t\t\t\t\t\t8. Exit "<<endl;
    cout<<"\n\n\t\t\t\t\t\t\tChoice: ";

    // Error handling for main menu choice
    while(!(cin>>Choice))
    {
        cout<< "\n\t\t\t\t\t\t\tInvalid input.\n\n";
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
            PrintInTableFormat();
            cout << endl << endl << endl;
            system("cls");
            goto Menu;
        // Search for an item in stock
        case 2:
            appHeader("Search");
            int ProductNumberSearch; // Search Key
            cout << "\n\t\t\t\t\tEnter the Product number of the item you would like to search." << endl;
            cout << "\n\t\t\t\t\t\t\tProduct Number: ";

            // Error handling for product numbers
            while(!(cin >> ProductNumberSearch))
            {
                cout << "\n\t\t\t\t\t\t\tInvalid input.\n\n";
                cin.clear();
                cin.ignore(20, '\n');
                cout << "Re-enter Product Number: ";

                InvalidChoiceCounter++;
                if(InvalidChoiceCounter >= 3)
                {
                    InvalidChoiceCounter = 0;
                    goto Menu; //We can make it go to the main menu when we merge it all
                }
            }

            Search(ProductNumberSearch); //Calling Search function
            system("cls");
            goto Menu;
            break;
        // Delete an item from stock
        case 3:
            DeleteItem();
            goto Menu;
        // Edit an item from stock
        case 4:
            //system("cls");
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
                        sort(Products, Products+NumberOfProducts, CompareUsingUnitPriceAscending);
                        PrintInTableFormat();
                    }
                    else if(OrderChoice == 2)
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
                case 2:
                    if(OrderChoice == 1)
                    {
                        sort(Products, Products+NumberOfProducts, CompareUsingRatingAscending);
                        PrintInTableFormat();
                    }
                    else if(OrderChoice == 2)
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
                case 3:
                    if(OrderChoice == 1)
                    {
                        sort(Products, Products+NumberOfProducts, CompareUsingProductionDateAscending);
                        PrintInTableFormat();
                    }
                    else if(OrderChoice == 2)
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
                case 4:
                    if(OrderChoice == 1)
                    {
                        sort(Products, Products+NumberOfProducts, CompareUsingExpirationDateAscending);
                        PrintInTableFormat();
                    }
                    else if(OrderChoice == 2)
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
                case 5:
                    if(OrderChoice == 1)
                    {
                        sort(Products, Products+NumberOfProducts, CompareUsingQuantityAscending);
                        PrintInTableFormat();
                    }
                    else if(OrderChoice == 2)
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
                case 6:
                    if(OrderChoice == 1)
                    {
                        sort(Products, Products+NumberOfProducts, CompareUsingSalesAscending);
                        PrintInTableFormat();
                    }
                    else if(OrderChoice == 2)
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
        // Exit
        case 8:
            return 0; //We can make it go to the main menu when we merge it all
            break;
        // Error handling for all other options
        default:
            cout<<"\n\t\t\t\t\t\t\tInvalid Choice."<<endl;
            system("pause");
            system("cls");
            goto Menu;
        }
}

/// Initialization
// A simple function to call and initiate system variables to help in demo and general settings
void initializeSystemVariables()
{
    //system("color 0b");
    //system("cls");
    ProductSampleData();
}


/// M A I N
int main()
{
    initializeSystemVariables();
    MainMenu();
}


