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
int greedyChange(const int*, const int, const int);
int optimalChange(const int*, const int, const int, vector<vector<int> >&);


int main(int argc, const char* argv[]) {
    
    cout << "Number of coins bigger than one cent? ";
    int n;
    cin >> n;
    
    int* coins = new int[n+1];
    getInput(coins, n);
    
    vector<vector<int> > v (n+2);

    int amt;
    cout << "Enter amount to test, or enter -1 to exit: ";
    cin >> amt;
    int num1, num2;
    while (amt >= 0) {
        if (amt == 0) {
            cout << "  Greedy:\n    Number of coins: 0" << endl;
            cout << "  Optimal:\n    Number of coins: 0" << endl;
            cout << "  Greed is optimal!" << endl;
        }
        else {
            num1 = greedyChange(coins, n+1, amt);
            cout << "    Number of coins: " << num1 << endl;
            num2 = optimalChange(coins, n+2, amt, v);
            cout << "    Number of coins: " << num2 << endl;
            
            if (num1 <= num2) {
                cout << "  Greed is optimal!" << endl;
            }
            else {
                cout << "  Greed is not optimal!" << endl;
            }
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
int greedyChange(const int* coins, const int n, const int amt) {
    
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
    return numCoins;
}

int optimalChange(const int* coins, const int n, const int amt, vector< vector<int> >& v){
    for (int i=0; i<n; i++){
        if (amt > v[i].size())	v[i].resize(amt+1);
    }

    int rec[n][amt+1];  //2D-array for printing solution
    for (int i=0; i<n; i++){
        for (int j=0; j<amt+1; j++){
            rec[i][j]=0;
        }
    }

    cout << "  Optimal: ";
    int v1 ,v2;
    for (int i=1; i<n; i++){
        for (int m=0; m<=amt; m++){
            if (i==1)   v[1][m] = m;    //set the first row, base case
            else
            {
                v2 = v[i-1][m]; //number of k-1 coins to solve problem
                if (coins[i-1] <= m)
                {
                    v1 = v[i][m - coins[i-1]] + 1;  //number of k coins to solve problem
                    if (v1 <= v2)
                    {
                        v[i][m] = v1;
                        rec[i][m] = coins[i-1];    //set rec because an extra coin is being used
                    } 
                    else v[i][m] = v2;
                }
                else
                {
                    v[i][m] = v2;
                }
                if (v[i][m] == 1) rec[i][m] = m;   //set rec because only one coin is being used
            }
        }
    }


    int m = amt, index = n-1;
    for (int i=0; i<v[n-1][amt]; i++){
        if (rec[index][m] != 0)
        {
            cout << rec[index][m] << " ";
            m-=rec[index][m];
        }
        else
        {
            i--;
            index--;
        }
    }
    cout << endl;
    return v[n-1][amt];
}
