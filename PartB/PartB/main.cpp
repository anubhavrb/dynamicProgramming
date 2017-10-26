//
//  change.cpp
//  p3
//
//  P3 Part B. Optimal change making.
//  Arthur Chen and Anubhav Roy Bhattacharya
//


#include <iostream>
#include <vector>
using namespace std;

void getInput(int*, int);
void greedyChange(const int*, const int, const int);
void optimalChange(const int*, const int, const int, vector<vector<int>>&);


int main(int argc, const char* argv[]) {
    
    cout << "Number of coins bigger than one cent? ";
    int n;
    cin >> n;
    
    int* coins = new int[n+1];
    getInput(coins, n);
    
    vector<vector<int>> v (n+2);

    int amt;
    cout << "Enter amount to test, or enter -1 to exit: ";
    cin >> amt;
    while (amt >= 0) {
        if (amt == 0) {
            cout << "  Greedy:\n    Number of coins: 0" << endl;
            cout << "  Optimal:\n    Number of coins: 0" << endl;
            cout << "  Greed is optimal!" << endl;
        }
        else {
            greedyChange(coins, n+1, amt);
            optimalChange(coins, n+2, amt, v);
        }
        cout << "Enter amount to test, or enter -1 to exit: ";
        cin >> amt;
    }
    
    delete[] coins;
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
void greedyChange(const int* coins, const int n, const int amt) {
    
    int sum = 0;
    int numCoins = 0;
    cout << "  Greedy: ";
    int i;
    while (sum != amt) {
        for (i = n-1; i >= 0; i--) {
            if (sum + coins[i] <= amt) {
                sum = sum + coins[i];
                cout << coins[i] << " ";
                numCoins++;
                break;
            }
        }
    }
    cout << endl;
    cout << "    Number of coins: " << numCoins << endl;
}

void optimalChange(const int* coins, const int n, const int amt, vector<vector<int>>& v){
    for (int i=0; i<n; i++){
        if (amt > v[i].size())	v[i].resize(amt+1);
    }
    /*
		1	2	3	4	5	6	7	8	m ..... amt
	1	1	2	3	0	1	0	1	
	2	0	0	0	1	1	0	0
	3	0	0	0	0	0	1	1	
	4	
	5	
	
	*/
    vector<int> coin;
    vector<int> index;
    cout << "  Optimal: ";
    int v1 ,v2;
    for (int i=1; i<n; i++){
        for (int m=0; m<=amt; m++){
            //set the first row, base case
            if (i==1)   v[1][m] = m;
            else{
                v2 = v[i-1][m];
                if (coins[i-1] <= m){
                    v1 = v[i][m - coins[i-1]] + 1;
                    //cout << coins[i-1];
                    if (v1 < v2){
                        coin.push_back(coins[i-1]);
                        index.push_back(m);
                    }
                    v[i][m] = min(v1, v2);
                }
                else{
                    v[i][m] = v2;
                }
            }
        }
    }
    
    for (int i=0; i<n; i++){
        for (int j=0; j<amt+1; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Number of coins: " << v[n-1][amt] << endl;

}
