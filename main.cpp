// Diffie-Hellman-Algorithm
//
// Purpose is to implement the Diffie-Hellman Algorithm of encryption in C++ 
// for my group's final project in CS111
//
// steps taken from: https://www.javatpoint.com/diffie-hellman-algorithm-in-java

#include <iostream>
#include <cassert>
#include <cmath>
#include <string>
using namespace std;

int PubVal(int x, int y, int z) {
    // x = public key 1, y = public key 2, z = private key (this is what changes)
    // cout << x << ", " << y << ", " << z << endl;
    int temp = pow(y, z);
    return temp % x;
}

int SymmetricKey(int x, int y, int z) {
    // x = public value 1, y = priv key, z = public key 1
    // cout << x << ", " << y << ", " << z << endl;
    int temp = pow(x, y);
    return temp % z;
}

int main(int argc, char *argv[]) {

    // cout << "You have entered " << argc
    //      << " arguments:" << "\n";
  
    // for (int i = 0; i < argc; ++i)
    //     cout << argv[i] << "\n";
    // cout << argc << endl;

    if (argc != 5) {
        cout << "Wrong amount of arguments! Exiting..." << endl;
        return 0;
    }
    for (int i = 1; i < argc; ++i) {
        if (!isdigit(*argv[i])) {
            cout << "Argument \'" << *argv[i] << "\' is not a number! Exiting..." << endl;
        }
    }

    int pubkey_1 = stoi(argv[1]);
    int pubkey_2 = stoi(argv[2]);

    int priv_1 = stoi(argv[3]);
    int priv_2 = stoi(argv[4]);

    int pubval_1 = PubVal(pubkey_1, pubkey_2, priv_1);
    int pubval_2 = PubVal(pubkey_1, pubkey_2, priv_2);
    // cout << "pub: " << pubval_1 << ", " << pubval_2 << endl;

    int symm_1 = SymmetricKey(pubval_2, priv_1, pubkey_1);
    int symm_2 = SymmetricKey(pubval_1, priv_2, pubkey_1);
    assert(symm_1 == symm_2);


    cout << "The secret code is: " << symm_1 << endl;

    return 0;
}