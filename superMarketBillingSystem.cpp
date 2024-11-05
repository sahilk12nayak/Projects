#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
using namespace std;
#define ll long long

class Bill{
private:
    string Item;
    int Rate, Quantity;
public:
    Bill(): Item(""), Rate(0), Quantity(0){};
    //Member Function
    void setItem(string item){
        Item = item;
    }
    void setRate(int rate){
        Rate = rate;
    }
    void setQuant(int quant){
        Quantity = quant;
    }
    //Getter Function
    string getItem(){
        return Item;
    }
    int getRate(){
        return Rate;
    }
    int getQuant(){
        return Quantity;
    }

};

void addItem(Bill b){
    bool close = false;
    while(!close){
        int choice;
        cout << "\t1.Add." << endl;
        cout << "\t2.Close." << endl;
        cout << "\tEnter Choice: ";
        cin >> choice;

        if (choice==1){
            system("cls");
            string item;
            int rate, quant;
            cout << "\tEnter Item Name: ";
            cin >> item;
            b.setItem(item);

            cout << "\tEnter Rate of Item: ";
            cin >> rate;
            b.setRate(rate);

            cout << "\tEnter Quantity of Item: ";
            cin >> quant;
            b.setQuant(quant);

            ofstream out("C:/Bill.txt", ios::app);      //sent data in file, if we add 2nd item then first item will be replace thats why we add (scope operator)ios:: app
            if (!out){
                cout << "\tError: File can't open!" << endl;
            }
            else {
                out<< "\t" << b.getItem() << " : " << b.getRate() << " : " << b.getQuant() << endl << endl;
            }
            out.close();
            cout << "\tItem Added Successfully." << endl;
            Sleep(3000);        //It will take time to run next step in milisecond (3sec)
        }
        else if (choice==2){
            system("cls");
            close = true;
            cout << "\tBack to Main Menu!" << endl;
            Sleep(3000);
        }
    }
}

void printBill(){
    system("cls");
    int count = 0;
    bool close = false;
    while (!close){
        system("cls");
        int choice;
        cout << "\t1.Add Bill." << endl;
        cout << "\t2.Close Session." << endl;
        cout << "\tEnter Choice: ";
        cin >> choice;

        if (choice==1){
            string item;
            int quant;
            cout << "\tEnter item: ";
            cin >> item;
            cout << endl;
            cout << "\tEnter Quantity: ";
            cin >> quant;

            ifstream in("C:/Bill.txt");
            ofstream out("C:/Bill Temp.txt");

            string line;
            bool found = false;
            while (getline(in, line)){
                stringstream ss;        //using use of sstream header file
                ss << line;
                string itemName;
                int itemRate, itemQuant;
                char delimeter;     //it sets boundary or itemName, itemRate, itemQuantity (seperate using collon)
                ss >> itemName >> delimeter >> itemRate >> delimeter >> itemQuant;

                if (item==itemName){
                    found = true;
                    if (quant<=itemQuant){
                        int amount  = itemRate*quant;
                        cout << "\tItem | Rate | Quantity | Amount"  << endl;
                        cout << "\t" << itemName << "\t " << itemRate << "\t " << quant << "\t " << amount << endl;
                        int newQuant = itemQuant - quant;
                        itemQuant = newQuant;
                        count += amount;

                        out << "\t" << itemName << " : " << itemRate << " : " << itemQuant << endl << endl;
                    }
                    else {
                        //not quantity
                        cout << "\tSorry, " << item << "Ended!" << endl;
                    }
                }
                else {
                    //if not item found
                    out << line << endl;

                }

            }
            if (!found){
                cout << "\tItem Not Available!" << endl;
            }
            out.close();
            in.close();
            remove("C:/Bill.txt");
            rename("C:/Bill Temp.txt", "C:/Bill.txt");
        }
        else if (choice==2){
            close = true;
            cout << "\t Counting Total Bill" << endl;
        }
        Sleep(3000);
    }
    system("cls");
    cout << endl << endl;
    cout << "\t Total Bill ------------------ : " << count << endl << endl;
    cout << "\tThanks For Shooping!" << endl;
    Sleep(5000);
}

int main(){
    Bill b;
    bool exit = false;
    while (!exit){
        system("cls");      //It will hide previous outputs and display current output
        int val;
        cout << "\tWelcome To Super Market Billing System." << endl;
        cout << "\t***************************************" << endl;
        cout << "\t\t1.Add Item." << endl;
        cout << "\t\t2.Print Bill." << endl;
        cout << "\t\t3.Exit." << endl;
        cout << "\t\tEnter Choice: ";
        cin >> val;

        if (val==1){
            system("cls");
            addItem(b);
            Sleep(3000);
        }
        else if (val==2){
            printBill();
        }
        else if (val==3){
            system("cls");
            exit = true;
            cout << "\tGood Luck!" << endl;
            Sleep(3000);

        }
    }

    return 0;
}





