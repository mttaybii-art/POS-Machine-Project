#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// ABSTRACT PAYMENT CLASS
class Payment {
public:
    virtual void pay(float amount) = 0;
    virtual string getMethod() = 0;
    virtual ~Payment() {}
};

// CASH PAYMENT
class CashPayment : public Payment {
public:
    void pay(float amount) {
        cout << "Cash Payment Successful: Rs." << amount << endl;
    }

    string getMethod() {
        return "Cash";
    }
};

// CARD PAYMENT
class CardPayment : public Payment {
public:
    void pay(float amount) {
        cout << "Card Payment Successful: Rs." << amount << endl;
    }

    string getMethod() {
        return "Card";
    }
};

// RECEIPT CLASS
class Receipt {

private:
    string customerName;
    string phone;
    string productName;
    int quantity;
    float unitPrice;
    float totalBill;
    string paymentMethod;
    string dateTime;

public:

    void generate(string cname, string ph, string pname,
                  int qty, float price, float total, string payMethod) {

        customerName = cname;
        phone = ph;
        productName = pname;
        quantity = qty;
        unitPrice = price;
        totalBill = total;
        paymentMethod = payMethod;

        // GET SYSTEM TIME
        time_t now = time(0);
        dateTime = ctime(&now);
    }

    void printReceipt() {

        cout << "\n\n===================================";
        cout << "\n           SHOP RECEIPT             ";
        cout << "\n===================================";

        cout << "\nCustomer Name: " << customerName;
        cout << "\nPhone: " << phone;

        cout << "\n-----------------------------------";
        cout << "\nProduct: " << productName;
        cout << "\nQuantity: " << quantity;
        cout << "\nUnit Price: Rs." << unitPrice;

        cout << "\n-----------------------------------";
        cout << "\nTOTAL BILL: Rs." << totalBill;

        cout << "\nPayment Method: " << paymentMethod;

        cout << "\n-----------------------------------";
        cout << "\nDate & Time: " << dateTime;

        cout << "===================================";
        cout << "\n Thank You For Shopping With Us!";
        cout << "\n===================================\n";
    }
};

#endif

