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

int main(int argc, const char* argv[]) {
    
    cout << "Number of coins bigger than one cent? ";
    int n;
    cin >> n;
    
    int* coins = new int[n+1];
    getInput(coins, n);
    
    for (int i = 0; i < n+1; i++) {
        cout << coins[i] << " ";
    }
    cout << endl;
    
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
