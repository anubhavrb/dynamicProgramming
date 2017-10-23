//
//  change.cpp
//  p3
//
//  P3 Part B. Optimal change making.
//  Arthur Chen and Anubhav Roy Bhattacharya
//


#include <iostream>
using namespace std;

void getInput(int*, int);
void greedyChange(int*, int, int);

int main(int argc, const char* argv[]) {
    
    cout << "Number of coins bigger than one cent? ";
    int n;
    cin >> n;
    
    int* coins = new int[n+1];
    getInput(coins, n);
    
    int amt;
    cout << "Enter amount to test, or enter -1 to exit: ";
    cin >> amt;
    while (amt != -1) {
        if (amt == 0) {
            cout << "  Greedy: 0\n    Number of coins: 0" << endl;
            cout << "  Optimal: 0\n    Number of coins: 0" << endl;
            cout << "  Greed is optimal!" << endl;
        }
        else if (amt < -1) {
            cout << "Invalid amount!" << endl;
            
        }
        else {
            greedyChange(coins, n+1, amt);
            
        }
        cout << "Enter amount to test, or enter -1 to exit: ";
        cin >> amt;
    }
    cout << "Thank you for playing!" << endl;
    return 0;
}

// Function to get denominations of coins from user
void getInput(int* coins, int n) {
    coins[0] = 1;
    cout << "Enter the values of these coins in increasing order." << endl;
    cout << "Coin value 1: 1" << endl;
    for (int i = 1; i <= n; i++) {
        cout << "Coin value " << (i+1) << ": ";
        cin >> coins[i];
    }
}

// Function to make change using the greedy approach.
void greedyChange(int* coins, int n, int amt) {
    
}
