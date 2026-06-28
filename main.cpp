#include <iostream>

#include "People.h"
#include "Business.h"
#include "System.h"

using namespace std;

// Error Beep
void beepError() {
    cout << "\a";
    cout << "\n Invalid Option! Try Again.\n";
}

// Welcome Screen
void welcomeScreen() {

    cout << "\n=====================================\n";
    cout << "        WELCOME TO SHOP POS SYSTEM     \n";
    cout << "=====================================\n";

    cout << "\n   University POS Project";
    cout << "\n   Version 3.0\n";

    cout << "\n-------------------------------------\n";
    cout << " Press Enter To Continue...";
    cin.ignore();
    cin.get();
}

int main() {

    welcomeScreen();

    Owner owner("Admin");
    owner.showRole();

    Inventory inventory;

    float totalProfit = 0;
    int choice;

    while(true) {

        cout << "\n\n===== SHOP POS MENU =====";
        cout << "\n1. New Sale";
        cout << "\n2. Show Products";
        cout << "\n3. Add Product";
        cout << "\n4. Update Product";
        cout << "\n5. Today Profit Report";
        cout << "\n0. Exit";

        cout << "\nSelect Option: ";
        cin >> choice;

        // EXIT
        if(choice == 0) {
            cout << "\nSystem Closed Successfully.\n";
            break;
        }

        if(choice < 0 || choice > 5) {
            beepError();
            continue;
        }

        // NEW SALE 
        if(choice == 1) {

            inventory.showInventory();

            int p, qty;

            cout << "\nSelect Product Number: ";
            cin >> p;

            if(p < 1 || p > inventory.getCount()) {
                beepError();
                continue;
            }

            cout << "Enter Quantity: ";
            cin >> qty;

            if(qty <= 0) {
                beepError();
                continue;
            }

            Product &prod = inventory.getProduct(p - 1);

            if(qty > prod.getStock()) {
                cout << "\nNot Enough Stock Available!\n";
                continue;
            }

            // CUSTOMER INFO
            string cname, phone;

            cout << "\nEnter Customer Full Name: ";
            cin.ignore();
            getline(cin, cname);

            cout << "Enter Phone Number: ";
            cin >> phone;

            float bill = prod.getSale() * qty;
            float profit = (prod.getSale() - prod.getCost()) * qty;

            prod.reduceStock(qty);
            totalProfit += profit;

            // PAYMENT
            Payment* pay;
            CashPayment cash;
            CardPayment card;

            int payChoice;

            cout << "\nSelect Payment Method";
            cout << "\n1. Cash";
            cout << "\n2. Card";
            cout << "\nChoice: ";
            cin >> payChoice;

            if(payChoice == 1) {
                pay = &cash;
            }
            else if(payChoice == 2) {
                pay = &card;
            }
            else {
                beepError();
                continue;
            }

            pay->pay(bill);

            // RECEIPT GENERATION
            Receipt receipt;

            receipt.generate(
                cname,
                phone,
                prod.getName(),
                qty,
                prod.getSale(),
                bill,
                pay->getMethod()
            );

            receipt.printReceipt();

            cout << "\nProfit: Rs." << profit << endl;
        }

        // SHOW PRODUCTS
        if(choice == 2) {
            inventory.showInventory();
        }

        // ADD PRODUCT
        if(choice == 3) {
            inventory.addProduct();
        }

        // UPDATE PRODUCT
        if(choice == 4) {
            inventory.updateProduct();
        }

        // PROFIT REPORT
        if(choice == 5) {

            cout << "\n====== TODAY REPORT ======";
            cout << "\nTotal Profit: Rs." << totalProfit << endl;
        }
    }

    cout << "\nThank You For Using POS System\n";

    return 0;
}
