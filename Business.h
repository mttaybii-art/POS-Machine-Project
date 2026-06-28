#ifndef BUSINESS_H
#define BUSINESS_H

#include <iostream>
#include <string>

using namespace std;

// PRODUCT CLASS
class Product {

private:
    string name;
    float costPrice;
    float salePrice;
    int stock;

public:
    Product() {
        name = "";
        costPrice = 0;
        salePrice = 0;
        stock = 0;
    }

    Product(string n, float c, float s, int st) {

        name = n;
        costPrice = c;
        salePrice = s;
        stock = st;
    }

    string getName() { return name; }
    float getCost() { return costPrice; }
    float getSale() { return salePrice; }
    int getStock() { return stock; }

    void setSale(float s) { salePrice = s; }
    void setStock(int s) { stock = s; }

    void reduceStock(int q) {
        stock -= q;
    }

    void display() {

        cout << name
             << "\tRs." << salePrice
             << "\tStock: " << stock << endl;
    }

    bool isEmpty() {
        return name == "";
    }
};

// INVENTORY CLASS
class Inventory {

private:
    Product products[10];   // Increased size
    int count;

public:
    Inventory() {

        count = 3;

        products[0] = Product("Laptop", 50000, 60000, 10);
        products[1] = Product("Mobile", 20000, 25000, 15);
        products[2] = Product("Headphone", 2000, 3000, 20);
    }

    // SHOW INVENTORY
    void showInventory() {

        cout << "\n===== COMPANY INVENTORY =====\n";

        for(int i = 0; i < count; i++) {

            cout << i+1 << ". ";
            products[i].display();

            if(products[i].getStock() <= 5)
                cout << "  LOW STOCK ALERT!\n";
        }
    }

    // ADD PRODUCT
    void addProduct() {

        if(count >= 10) {
            cout << "\nInventory Full!\n";
            return;
        }

        string name;
        float cost, sale;
        int stock;

        cout << "\nEnter Product Name: ";
        cin >> name;

        cout << "Enter Cost Price: ";
        cin >> cost;

        cout << "Enter Sale Price: ";
        cin >> sale;

        cout << "Enter Stock Quantity: ";
        cin >> stock;

        products[count] = Product(name, cost, sale, stock);
        count++;

        cout << "\nProduct Added Successfully!\n";
    }

    // UPDATE PRODUCT
    void updateProduct() {

        showInventory();

        int choice;
        cout << "\nSelect Product Number To Update: ";
        cin >> choice;

        if(choice < 1 || choice > count) {
            cout << "\nInvalid Product Selection!\n";
            return;
        }

        Product &p = products[choice - 1];

        int opt;

        cout << "\n1. Update Price";
        cout << "\n2. Update Stock";
        cout << "\nSelect Option: ";
        cin >> opt;

        if(opt == 1) {

            float newPrice;
            cout << "Enter New Sale Price: ";
            cin >> newPrice;

            p.setSale(newPrice);
            cout << "\nPrice Updated Successfully!\n";
        }

        else if(opt == 2) {

            int newStock;
            cout << "Enter New Stock Quantity: ";
            cin >> newStock;

            p.setStock(newStock);
            cout << "\nStock Updated Successfully!\n";
        }

        else {
            cout << "\nInvalid Update Option!\n";
        }
    }

    Product& getProduct(int index) {
        return products[index];
    }

    int getCount() {
        return count;
    }
};

#endif

