#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

char MenuChoice[11];
char ChosenFunction[31];

//Universal structure Date
struct Date{
    int DD, MM, YY;
};

//Super Structure
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
    MainMenu();


    return 0;
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
