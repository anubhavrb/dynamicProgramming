//
//  main.cpp
//  p3
//
//  P3 part A. Optimal matrix multiplication
//  Arthur Chen and Anubhav Roy Bhattacharya
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    using namespace std;
    int n;
    
    cout << "number of matrices? ";
    cin >> n;
    int p[n+1];
    if (n < 1){
        cout << "Bad n" << endl;
        return 0;
    }
    cout << "Dimension of matrix " << 1 << ": ";
    cin >> p[0] >> p[1];
    
    for (int i=2; i< n+1; i++){
        cout << "Dimension of matrix " << i << ": " << p[i-1] << " x " ;
        cin >> p[i];
    }
    cout << endl;
    
    int m[n+1][n+1];
    int s[n+1][n+1];
    
    for (int i=0; i < n+1; i++){
        for (int j=0; j < n+1; j++){
            m[i][j] = 0;
            s[i][j] = 0;
        }
     }
    
    int j, q;
    for (int l=1; l <= n-1; l++){
        for (int i=1; i <= n-l; i++){
            j = i+l;
            m[i][j] = numeric_limits<int>::max();
            for (int k = i; k <= j - 1; k++){
                q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                //cout << "At index i, j = " << i << " " << j << ", q = " << q << endl;
                if (q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    /*int front[2], back[2];
    for (int i = n; i > 0; i--){
        front[0] = 1;
        front[1] = m[1][i];
        back[0] = m[1][i] + 1;
        back[1] = ;
        
    }*/
    
    cout << "Table m[i, j]:" << endl;
    for (int i=1; i < n+1; i++){
        for (int j=1; j < n+1; j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Table s[i, j]:" << endl;
    for (int i=1; i < n+1; i++){
        for (int j=1; j < n+1; j++){
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}



