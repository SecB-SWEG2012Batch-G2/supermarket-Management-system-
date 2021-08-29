#include<iostream>
#include<iomanip>
using namespace std;
struct Date{
    int dd,mm,yy;};
struct Snacks{
    int SerialNumber;
    float Price;
    Date ExpireDate;
}Candy[100],Chips[100];
struct Beverages{
    int SerialNumber;
    float Price;
    Date ExpireDate;
}Tea[100],Coffee[100],Soda[100],Juice[100],Water[100];
struct Cereals{
    int SerialNumber;
    float Price;
    Date ExpireDate;
}Wheat[100],Barley[100],Rice[100],Oats[100],Maize[100];
struct CookingOil{
    int SerialNumber;
    float Price;
    Date ExpireDate;
}OliveOil[100],CoconutOil[100],PalmOil[100],SesameSeedOil[100],SoyaBeanOil[100],SunflowerSeedOil[100],GroundnutSeedOil[100];
struct CannedFoods{
    int SerialNumber;
    float Price;
    Date ExpireDate;
};
struct BreadandBakery{
    int SerialNumber;
    float Price;
    Date ExpireDate;
};
struct PastaandRice{
    int SerialNumber;
    float Price;
    Date ExpireDate;
};
struct AnimalProducts{
    int SerialNumber;
    float Price;
    Date ExpireDate;
};
struct FreezerFoods{
    int SerialNumber;
    float Price;
    Date ExpireDate;
}Fish[100],Chicken[100];
struct Produce{
    int SerialNumber;
    float Price;
    Date ExpireDate;
};
struct Stationeries{
    int SerialNumber;
    float Price;
    Date ExpireDate;
};
struct KitchenUtensils{
    int SerialNumber;
    float Price;
    Date ExpireDate;
};
struct SanitaryProducts{
    int SerialNumber;
    float Price;
    Date ExpireDate;
};
struct HealthandBodyCare{
    int SerialNumber;
    float Price;
    Date ExpireDate;
};
/* int GetChoice(){
while(!std::cin.good())
{


std::cout<<"Error:Incorrect Input!Try Again.";
std::cin.clear();
std::cin.ignore(INT_MAX, '\n');
std::cout<<"Type: ";
std::cin>>;
return Type;
}
}
*/
int main(){
    Tea[54].SerialNumber=1111;
    Candy[80].SerialNumber=1234;
    int amount,Quantity[100],Type[100],Serialno[100];
    float Totalprice,Price[100];
    bool ItemFound;
    char op;
    int Foundnum;
    MainMenu:
    cout << "\t*" << setfill('*') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(32) << "W E L C O M E !" << setfill(' ') << setw(18) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill('-') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(44) << " Please Select The Product You'd Like To Purchase" << setfill(' ') << setw(1) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(33) << "1. Snacks \t \t 8. Animal Products" << setfill(' ') << setw(8) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(33) << "2. Beverages \t\t 9. Freezer Foods" << setfill(' ') << setw(10) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(33) << " 3. Cereals \t\t 10. Fruits and Vegetable" << setfill(' ') << setw(2) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(33) << " 4. Cooking Oil \t 11. Stationeries" << setfill(' ') << setw(10) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(33) << " 5. Canned Foods \t 12. Kitchen Utensils" << setfill(' ') << setw(6) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(33) << " 6. Bread and Bakery \t 13. Sanitary Products" << setfill(' ') << setw(5) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(33) << " 7. Pasta and Rice \t 14. Health and Body Care" << setfill(' ') << setw(2) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(25) << "15. Exit" << setfill(' ') << setw(25) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill('*') << setw(50) << "*" << endl;
    cout<<endl;
    cout<<"\tFrom The List Above How many products Do You Have\n";
    cout<<"\t Amount: ";cin>>std::setw(3)>>amount;

    for(int i=0;i<amount;i++){

        cout<<"\t Item "<<i+1<<":\n";
        type:
        cout<<"\t\t Type: ";cin>>std::setw(2)>>Type[i];
        if(Type[i]>0&&Type[i]<=15){

        }
        else {
                cout<<"Invalid Input\n";goto type;
        }
        Serial:
        cout<<"\t\t Serial Number: "; cin>>Serialno[i];
        ItemFound=false;
                        for(int j=0;j<100;j++){
                            switch(Type[i]){
                                case 1:
                                    if(Serialno[i]==Candy[j].SerialNumber){
                                        Price[i]=Candy[j].Price;
                                        ItemFound=true;
                                        break;
                                        }
                                        else if(Serialno[i]==Chips[j].SerialNumber){
                                        Price[i]=Chips[j].Price;
                                        ItemFound=true;
                                        break;
                                        }
                                    break;
                                case 2:
                                     if(Serialno[i]==Tea[j].SerialNumber){
                                        Price[i]=Tea[j].Price;
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==Coffee[j].SerialNumber){
                                        Price[i]=Coffee[j].Price;
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==Juice[j].SerialNumber){
                                        Price[i]=Juice[j].Price;
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==Water[j].SerialNumber){
                                        Price[i]=Water[j].Price;
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==Soda[j].SerialNumber){
                                        Price[i]=Soda[j].Price;
                                        ItemFound=true;
                                        }
                                    break;
                                case 3:
                                    if(Serialno[i]==Barley[j].SerialNumber){
                                        Price[i]=Barley[j].Price;
                                            ItemFound=true;
                                        }
                                        else if(Serialno[i]==Wheat[j].SerialNumber){
                                        Price[i]=Wheat[j].Price;
                                            ItemFound=true;
                                        }
                                        else if(Serialno[i]==Rice[j].SerialNumber){
                                        Price[i]=Rice[j].Price;
                                            ItemFound=true;
                                        }
                                        else if(Serialno[i]==Oats[j].SerialNumber){
                                        Price[i]=Oats[j].Price;
                                            ItemFound=true;
                                        }
                                        else if(Serialno[i]==Maize[j].SerialNumber){
                                        Price[i]=Maize[j].Price;
                                            ItemFound=true;
                                        }
                                    break;
                                case 4:
                                    if(Serialno[i]==OliveOil[j].SerialNumber){
                                        Price[i]=OliveOil[j].Price;
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==CoconutOil[j].SerialNumber){
                                        Price[i]=CoconutOil[j].Price;
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==PalmOil[j].SerialNumber){
                                        Price[i]=PalmOil[j].Price;
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==SesameSeedOil[j].SerialNumber){
                                        Price[i]=SesameSeedOil[j].Price;
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==SoyaBeanOil[j].SerialNumber){
                                        Price[i]=SoyaBeanOil[j].Price;
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==SunflowerSeedOil[j].SerialNumber){
                                        Price[i]=SunflowerSeedOil[j].Price;
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==GroundnutSeedOil[j].SerialNumber){
                                        Price[i]=GroundnutSeedOil[j].Price;
                                        ItemFound=true;
                                        }
                                    break;
                                /*case 5:
                                    if(Serialno[i]==CannedFoods.SerialNumber[j]){
                                        Price[i]=CannedFoods.Price[j]
                                            ItemFound=true;
                                        }
                                        else if(Serialno[i]==CannedFoods.SerialNumber[j]){
                                        Price[i]=CannedFoods.Price[j]
                                            ItemFound=true;
                                        }
                                        else if(Serialno[i]==CannedFoods.SerialNumber[j]){
                                        Price[i]=CannedFoods.Price[j]
                                            ItemFound=true;
                                        }
                                        else if(Serialno[i]==CannedFoods.SerialNumber[j]){
                                        Price[i]=CannedFoods.Price[j]
                                            ItemFound=true;
                                        }
                                        else if(Serialno[i]==CannedFoods.SerialNumber[j]){
                                        Price[i]=CannedFoods.Price[j]
                                            ItemFound=true;
                                        }
                                    break;
                                case 6:
                                    if(Serialno[i]==BreadandBakery.SerialNumber[j]){
                                        Price[i]=BreadandBakery.Price[j]
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==BreadandBakery.SerialNumber[j]){
                                        Price[i]=BreadandBakery.Price[j]
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==BreadandBakery.SerialNumber[j]){
                                        Price[i]=BreadandBakery.Price[j]
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==BreadandBakery.SerialNumber[j]){
                                        Price[i]=BreadandBakery.Price[j]
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==BreadandBakery.SerialNumber[j]){
                                        Price[i]=BreadandBakery.Price[j]
                                        ItemFound=true;
                                        }
                                    break;
                                case 7:
                                    if(Serialno[i]==PastaandRice.SerialNumber[j]){
                                        Price[i]=PastaandRice.Price[j]
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==PastaandRice.SerialNumber[j]){
                                        Price[i]=PastaandRice.Price[j]
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==PastaandRice.SerialNumber[j]){
                                        Price[i]=PastaandRice.Price[j]
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==PastaandRice.SerialNumber[j]){
                                        Price[i]=PastaandRice.Price[j]
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==PastaandRice.SerialNumber[j]){
                                        Price[i]=PastaandRice.Price[j]
                                        ItemFound=true;
                                        }
                                    break;
                                case 8:
                                    if(Serialno[i]==AnimalProducts.SerialNumber[j]){
                                        Price[i]=AnimalProducts.Price[j]
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==AnimalProducts.SerialNumber[j]){
                                        Price[i]=AnimalProducts.Price[j]
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==AnimalProducts.SerialNumber[j]){
                                        Price[i]=AnimalProducts.Price[j]
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==AnimalProducts.SerialNumber[j]){
                                        Price[i]=AnimalProducts.Price[j]
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==AnimalProducts.SerialNumber[j]){
                                        Price[i]=AnimalProducts.Price[j]
                                        ItemFound=true;
                                        }
                                    break;
                                case 9:
                                    if(Serialno[i]==FreezerFoods.SerialNumber[j]){
                                        Price[i]=FreezerFoods.Price[j]
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==FreezerFoods.SerialNumber[j]){
                                        Price[i]=FreezerFoods.Price[j]
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==FreezerFoods.SerialNumber[j]){
                                        Price[i]=FreezerFoods.Price[j]
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==FreezerFoods.SerialNumber[j]){
                                        Price[i]=FreezerFoods.Price[j]
                                        ItemFound=true;
                                        }
                                    break;
                                case 10:
                                    if(Serialno[i]==Produce.SerialNumber[j]){
                                        Price[i]=Produce.Price[j]
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==Produce.SerialNumber[j]){
                                        Price[i]=Produce.Price[j]
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==Produce.SerialNumber[j]){
                                        Price[i]=Produce.Price[j]
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==Produce.SerialNumber[j]){
                                        Price[i]=Produce.Price[j]
                                        ItemFound=true;
                                        }
                                    break;
                                case 11:
                                     if(Serialno[i]==Stationeries.SerialNumber[j]){
                                        Price[i]=Stationeries.Price[j]
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==Stationeries.SerialNumber[j]){
                                        Price[i]=Stationeries.Price[j]
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==Stationeries.SerialNumber[j]){
                                        Price[i]=Stationeries.Price[j]
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==Stationeries.SerialNumber[j]){
                                        Price[i]=Stationeries.Price[j]
                                        ItemFound=true;
                                        }
                                    break;
                                case 12:
                                    if(Serialno[i]==KitchenUtensils.SerialNumber[j]){
                                        Price[i]=KitchenUtensils.Price[j]
                                        ItemFound=true;
                                    }
                                    else if(Serialno[i]==KitchenUtensils.SerialNumber[j]){
                                        Price[i]=KitchenUtensils.Price[j]
                                        ItemFound=true;
                                    }
                                    else if(Serialno[i]==KitchenUtensils.SerialNumber[j]){
                                        Price[i]=KitchenUtensils.Price[j]
                                        ItemFound=true;
                                    }
                                    else if(Serialno[i]==KitchenUtensils.SerialNumber[j]){
                                        Price[i]=KitchenUtensils.Price[j]
                                        ItemFound=true;
                                    }
                                    break;
                                case 13:
                                    if(Serialno[i]==SanitaryProducts.SerialNumber[j]){
                                        Price[i]=SanitaryProducts.Price[j]
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==SanitaryProducts.SerialNumber[j]){
                                        Price[i]=SanitaryProducts.Price[j]
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==SanitaryProducts.SerialNumber[j]){
                                        Price[i]=SanitaryProducts.Price[j]
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==SanitaryProducts.SerialNumber[j]){
                                        Price[i]=SanitaryProducts.Price[j]
                                        ItemFound=true;
                                        }
                                    break;
                                case 14:
                                    if(Serialno[i]==HealthandBodyCare.SerialNumber[j]){
                                        Price[i]=HealthandBodyCare.Price[j]
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==HealthandBodyCare.SerialNumber[j]){
                                        Price[i]=HealthandBodyCare.Price[j]
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==HealthandBodyCare.SerialNumber[j]){
                                        Price[i]=HealthandBodyCare.Price[j]
                                        ItemFound=true;
                                        }
                                        else if(Serialno[i]==HealthandBodyCare.SerialNumber[j]){
                                        Price[i]=HealthandBodyCare.Price[j]
                                        ItemFound=true;
                                        }
                                    break;
                                    */

                                default:
                                    cout<<"\tInvalid Input. Try Again!\n";
                                    goto type;

                            }
                        }


                            if(ItemFound==false){
                                cout<<"\tCouldn't Find The Serial Number. Try Again!\n";
                            goto Serial;
                            }



        cout<<"\t\t Quantity: ";cin>>Quantity[i];
        cout << "\t-" << setfill('-') << setw(50) << "-" << endl;

Totalprice=+Price[i]*Quantity[i];
    }


Finish:
cout<<"\tHave You finished your purchase(Y/N)\n";
cin>>op;
op=(char) toupper(op);
switch(op){
    case 'N':
        system("pause");
                system("cls");
    goto MainMenu;
    break;
    case 'Y':
    cout<<"\tThank You for Your Purchase\n";
    break;
    default:
        cout<<"\t Error: Invalid Input Try again\n";
        goto Finish;

        break;
}







}
