#include <iostream>
using namespace std;

struct Date{
    int DD, MM, YY;
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
    int Sales=0;
}Products[9999];

//Function that loops through the products array to find searched item
void Search(int SearchedProduct){

int i;
for( i = 1; i<9999; i++){

    if( SearchedProduct == Products[i].ProductNumber && Products[i].ProductNumber != 0){
        cout<<"Product Number: " <<Products[i].ProductNumber<<endl;
        cout<<"Product Name: " <<Products[i].ProductName<<endl;
        cout<<"Product Category: " <<Products[i].Category<<endl;
        cout<<"Product Type: " <<Products[i].ProductType<<endl;
        cout<<"Production Date: " <<Products[i].ProductionDate.DD<<"/"<<Products[i].ProductionDate.MM<<"/"<<Products[i].ProductionDate.YY<<endl;
        cout<<"Expiration Date: " <<Products[i].ExpireDate.DD<<"/"<<Products[i].ExpireDate.MM<<"/"<<Products[i].ExpireDate.YY<<endl;
        cout<<"Product Quantity in stock: " <<Products[i].Quantity<<endl;
        cout<<"Product Measurement Unit: " <<Products[i].MeasurementUnit<<endl;
        cout<<"Product Unit price: " <<Products[i].UnitPrice<<endl;
        cout<<"Product Rating: " <<Products[i].Rating<<endl;
        i = 9999;
    }
    else if(Products[i].ProductNumber == 0){
       i = 9999;
       cout<<"Product Not found"<<endl;
    }
}



}

int main(){

//Products[i] = {ProductNumber ,"ProductName ", " Category", "ProductType ",{date}, {10,9,21},Quantity ,"MeasurementUnit ", ,Rating };

//Products[i] = { ," ", " ", " ",{date}, {10,9,21}, ," ", , };

//Initializing Bread and Bakery sample data
Products[1] = {1 ,"Banana Bread ", "Bread and Bakery ", "Bread ",{6,9,21}, {10,9,21}, 200,"Loafes ",22 ,4.9 };
Products[2] = {2 ,"Whole Wheat ", "Bread and Bakery ", "Bread ",{6,9,21}, {10,9,21},200 ,"Loafes ",3 ,2.5 };
Products[3] = {3 ,"Sourdough ", "Bread and Bakery ", "Bread ",{6,9,21}, {10,9,21}, 200,"Loafes ",4 ,4.7 };
Products[4] = {4 ,"Baguette ", "Bread and Bakery ", "Bread ",{6,9,21}, {10,9,21},200 ,"Loafes ",10 ,3 };
Products[5] = {5 ,"Difo Dabo ", "Bread and Bakery ", "Bread ",{6,9,21}, {10,9,21}, 200," Loafes",20 ,4.9 };
Products[6] = {6 ,"White Bread ", "Bread and Bakery ", "Bread ",{6,9,21}, {10,9,21}, 200,"Loafes ",3 ,2.8 };
Products[7] = {7 ,"Carrot Cake ", "Bread and Bakery ", "Bread ",{6,9,21}, {10,9,21},200 ,"Loafes ",20 ,4.1 };
Products[8] = {8 ,"Bagels ", "Bread and Bakery ", "Bread ",{6,9,21}, {10,9,21}, 200," Loafes",12 ,3.9 };
Products[9] = {9 ,"Chocolate Chip ", "Bread and Bakery ", "Cookies ",{6,9,21}, {10,9,21},200 ,"Killograms ",30 ,4.8 };
Products[10] = {10 ,"Shortbead Cookie ", "Bread and Bakery ", "Cookies ",{6,9,21}, {10,9,21}, 200,"Killograms ",28 ,4 };
Products[11] = {11 ,"Peanut Butter200 ", "Bread and Bakery ", "Cookies ",{6,9,21}, {10,9,21},200 ,"Killograms ",28 ,2.5 };

//Initialising Pasta and rice sample data
Products[12] = {12,"Short Pasta ", "Pasta and Rice ", "Pasta ",{6,9,21}, {10,9,21}, 100,"Killograms ",25 ,4.3 };
Products[13] = {13,"Long Pasta ", "Pasta and Rice ", "Pasta ",{6,9,21}, {10,9,21}, 100,"Killograms ",25 ,4.3 };
Products[14] = {14,"Macaroni ", "Pasta and Rice ", "Pasta ",{6,9,21}, {10,9,21}, 100,"Killograms ",24 ,4 };
Products[15] = {15,"Fettuccine", "Pasta and Rice ", "Pasta ",{6,9,21}, {10,9,21},100 ,"Killograms ",28 ,2.5 };
Products[16] = {16,"Lasagna", "Pasta and Rice ", "Pasta ",{6,9,21}, {10,9,21}, 100,"Killograms ",32 ,5 };
Products[17] = {17,"Spaghetti", "Pasta and Rice ", "Pasta ",{6,9,21}, {10,9,21}, 100," Killograms",30 ,4.9 };
Products[18] = {18,"Brown Rice ", "Pasta and Rice ", "Rice ",{6,9,21}, {10,9,21}, 100,"Killograms ",30 ,4.7 };
Products[19] = {19,"White Rice ", "Pasta and Rice ", "Rice ",{6,9,21}, {10,9,21},100 ," Killograms",27 ,2.5 };

//Initialising Dairy and meat sample data
Products[20] = {20 ,"Beef ", "Dairy and Meat ", "Meat ",{6,9,21}, {10,9,21},100 ,"Killogram ",250 ,4.9 };
Products[21] = {21 ,"Pork ", "Dairy and Meat ", "Meat ",{6,9,21}, {10,9,21},100 ,"Killogram ", 200,2.5 };
Products[22] = {22 ,"Mutton ", "Dairy and Meat ", "Meat ",{6,9,21}, {10,9,21},100 ,"Killogram ",260 , 4.4};
Products[23] = {23 ,"Chicken ", "Dairy and Meat ", "Meat ",{6,9,21}, {10,9,21},100 ,"Killogram ",300 ,4.9 };
Products[24] = {24 ,"Turkey", "Dairy and Meat ", "Meat ",{6,9,21}, {10,9,21},100 ,"Killogram ",280 ,3.9 };
Products[25] = {25 ,"Butter ", "Dairy and Meat ", "Dairy ",{6,9,21}, {10,9,21},100 ,"Killograms ",450 ,5 };
Products[26] = {26 ,"Milk ", "Dairy and Meat ", "Dairy ",{6,9,21}, {10,9,21}, 100,"Liters ",40 ,4.9 };
Products[27] = {27 ,"Mozzarella ", "Dairy and Meat ", "Cheese ",{6,9,21}, {10,9,21},100 ,"Killogram ",320 ,4.5 };
Products[28] = {28 ,"Cheddar ", "Dairy and Meat ", "Cheese ",{6,9,21}, {10,9,21},100 ,"Killogram ",300 ,4.9 };
Products[29] = {29 ,"Parmesan ", "Dairy and Meat ", "Cheese ",{6,9,21}, {10,9,21},100 ,"Killogram ",360 ,4.4 };
Products[30] = {30 ,"Gouda ", "Dairy and Meat ", "Cheese ",{6,9,21}, {10,9,21},100 ,"Killogram ",380 ,5 };
Products[31] = {31 ,"Yoghurt ", "Dairy and Meat ", "Dairy ",{6,9,21}, {10,9,21},100 ,"Litres ",60 ,4.9 };
Products[32] = {32 ,"Powdered Milk ", "Dairy and Meat ", "Dairy ",{6,9,21}, {10,9,21},100 ,"Killogram ",1200 ,4.6 };
Products[33] = {33 ,"Ice Cream", "Dairy and Meat ", "Dairy ",{6,9,21}, {10,9,21},100 ,"Killogram ",300 ,5 };

int ProductNumberSearch;//Search Key
Search:cout<<"Enter the Product number of the item you would like to seach."<<endl;
cout<<"Product Number: "; cin>>ProductNumberSearch;

Search(ProductNumberSearch);//Calling Search function

int Choice, InvalidChoiceCounter= 0;
Option:cout<<"\n1. Search For another product. "<<endl;
       cout<<"2. Exit "<<endl;
       cout<<"Choice: "; cin>>Choice;

switch(Choice){
    case 1:
        goto Search;
    break;
    case 2:
        return 0;//We can make it go to the main menu when we merge it all
    break;
    default:
    InvalidChoiceCounter++;
    cout<<"Invalid Choice."<<endl;

    if(InvalidChoiceCounter >= 3){
        break;//We can make it go to the main menu when we merge it all
    }
     goto Option;
}


}
