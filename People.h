#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>
#include <string>

using namespace std;

// ABSTRACT USER CLASS
class User {

protected:
    string name;

public:
    User(string n) {
        name = n;
    }

    virtual void showRole() = 0;

    virtual ~User() {}
};

// OWNER CLASS
class Owner : public User {

public:
    Owner(string n) : User(n) {}

    void showRole() {
        cout << "\nLogged In As OWNER: " << name << endl;
    }
};

#endif

