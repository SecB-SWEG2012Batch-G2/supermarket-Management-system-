#include <iostream>
#include <iomanip>
#include <windows.h>
#include <stdio.h>
using namespace std;

int NumberOfProducts = 100;
float Quantity[100],TotalPrice = 0,Cash;
    int NumberofBoughtItems,ProductNo[100],amount,Location[100];
    bool ProductFound;
struct Date{
    int dd,mm,yy;};
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
}Products[9999];
void PrintReceipt(){
        system("cls");
        cout<<setfill(' ')<<setw(30)<<"Receipt\n";
        cout<<setfill(' ')<<"Item No"<<setw(15)<<"Name \t"<<setw(8)<<"Quantity"<<setw(8)<<"Price"<<setw(10)<<"Amount\n";
    for(int i=0;i<NumberofBoughtItems;i++){
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
    cout<<setfill(' ')<<setw(47)<<"Cash: "; cin>>Cash;
    cout<<setfill(' ')<<setw(47)<<"Change: "<<Cash-TotalPrice<<endl;
    cout<<setfill(' ')<<setw(30)<<"Thank You For Your Purchase" << endl;
     for(int i=0;i<NumberofBoughtItems;i++){
            int N;
        N=Location[i];
       Products[N].Quantity=Products[N].Quantity-Quantity[i];
       Products[N].Sales = Products[N].Sales + Quantity[i];
    }
   system("pause");
   system("cls");
}
void ProductSampleData(){
Products[301].ProductNumber= 301;
Products[302].ProductNumber = 302;
Products[303]={303, "HB Pencil", "Stationeries", "Pencil", {11,01,2021},{12,12,2040},240,"Pieces",4.5,3};
Products[304]={304, "Dot Pencil", "Stationeries", "Pencil", {01,04,2021},{12,12,2040},240,"Pieces",3,3};
Products[305]={305, "Bic Pen", "Stationeries", "Pen", {11,01,2021},{12,12,2040},240,"Pieces",10.5,3};
Products[306]={306, "Lexi Pen", "Stationeries", "Pen", {11,01,2021},{12,12,2040},240,"Pieces",12,3};
Products[307]={307, "Link Pen", "Stationeries", "Pen", {11,01,2021},{12,12,2040},240,"Pieces",10,3};
Products[308]={308,};
Products[309]={309,};
Products[310]={310,};
Products[311]={311,};
Products[312]={312,};
Products[313]={313,};
Products[314]={314,};
Products[315]={315,};
Products[316]={316,};
Products[317]={317,};
Products[318]={318,};
Products[319]={319,};
Products[320]={320,};
Products[321]={321,};
Products[322]={322,};
Products[323]={323,};
Products[324]={324,};
Products[325]={325,};
Products[326]={326,};
Products[327]={327,};
Products[328]={328,};
Products[329]={329,};
Products[330]={330,};
}
struct Account{
    string UserName;
    string Password;
};

Account ManAccounts[3];
Account Cashaccounts[5];

void ManagerAccount(){
    cout<<"Successful";
}
void CashierAccount(){
    ProductSampleData();
    cout<<setfill(' ') << setw(50) <<"Welcome to CartShop\n\n";
    amount=1000;
    cout<<"\tEnter The Details of The Items Below \n \tIf You Finish Your Purchase  at Any Time Enter 0 \n";
    for(int i=0;i<amount;i++){
        ProductFound=false;
        MainMenu :
        cout<<"Item "<<i+1<<":\n";
        ProductNum:
        cout<<"\tProduct Number: "; cin>>ProductNo[i];
        for(int j=0;j<500;j++){
        switch(ProductNo[i]){
            case 0:
                char opt;
                 Finish:
                NumberofBoughtItems=i;
                  cout<<"\tHave You Finished Your Purchase(Y/N)\n";
                    cin>>opt;
                    opt=(char)toupper(opt);
                      switch(opt){
                      case 'N':
                        system("pause");
                        goto MainMenu;
                        break;
                       case 'Y':
                        PrintReceipt();
                        break;
                     default:
                          cout<<"\t Error: Invalid Input Try again\n";
                            goto Finish;
                            break;
                      }
        case 1 ... 9999:
            if(ProductNo[i]==Products[j].ProductNumber){
                Location[i]=j;
                ProductFound=true;
                NumberofBoughtItems=i+1;
            }
            break;
        default :
             cout<<"\tInvalid Number. Try Again!\n";
           goto ProductNum;
            break;
        }
        }
        if(ProductFound==false){
                                cout<<"\tCouldn't Find The Product. Try Again!\n";
                            goto ProductNum;
                            }
        cout<<"\t\t Quantity: ";cin>>Quantity[i];
        cout << "\t-" << setfill('-') << setw(50) << "-" << endl;
    }
}

void EmployeeAccount(){

}
void ManagerLogin(){
    int AccountLocation;
    string UserName, Password;
    bool UsernameFound,PasswordCorrect;
    Login:
    cout<<"UserName: "; cin>>UserName;
    for(int i=0;i<10;i++){
        if(UserName==ManAccounts[i].UserName){
            AccountLocation=i;
            UsernameFound=true;
            break;
        } else {
            UsernameFound=false;
            }
    }
        if(UsernameFound==false){
            cout<<"User Name Not found. Try Again!\n";
            goto Login;
            }
            else if(UsernameFound==true) {
                EnterPassword:
                cout<<"Password: "; cin>>Password;

                if(Password==ManAccounts[AccountLocation].Password){
                    system("cls");
                ManagerAccount();
                }
                else{

                    cout<<"Incorrect Password. Try Again\n";
                    goto EnterPassword;
                }
            }

        }

void CashierLogin(){
    int AccountLocation;
    string UserName, Password;
    bool UsernameFound,PasswordCorrect;
    Login:
    cout<<"UserName: "; cin>>UserName;
    for(int i=0;i<10;i++){
        if(UserName==Cashaccounts[i].UserName){
            AccountLocation=i;
            UsernameFound=true;
            break;
        } else {
            UsernameFound=false;
            }
    }
        if(UsernameFound==false){
            cout<<"User Name Not found. Try Again!\n";
            goto Login;
            }
            else if(UsernameFound==true) {
                EnterPassword:
                cout<<"Password: "; cin>>Password;

                if(Password==Cashaccounts[AccountLocation].Password){
                    system("cls");
                CashierAccount();
                }
                else{

                    cout<<"Incorrect Password. Try Again\n";
                    goto EnterPassword;
                }
            }
}

int main(){
    ManAccounts[0].UserName="Manager";
    ManAccounts[0].Password="Password";
    ManAccounts[3].UserName="manager";
    ManAccounts[3].Password="password";
    Cashaccounts[2].UserName="Cashier";
    Cashaccounts[2].Password="Password##";
    Cashaccounts[3].UserName="cashier";
    Cashaccounts[3].Password="password";
    int UserLoginChoice;
    cout<<"1. Manager \n";
    cout<<"2.Employee\n";
    cout<<"3.Cashier\n";
    LoginChoice:
    cout<<"Choice "; cin>>UserLoginChoice;
    switch(UserLoginChoice){
        case 1:
            system("cls");
            ManagerLogin();
            break;
        case 2:
            system("cls");
            EmployeeAccount();
            break;
        case 3:
            system("cls");
            CashierLogin();
            break;
        default:
            cout<<"Invalid Choice\n";
            goto LoginChoice;
 }

    return 0;
}


