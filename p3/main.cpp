//
//  P3 part A. Optimal matrix multiplication
//  Arthur Chen and Anubhav Roy Bhattacharya
//

#include <iostream>
#include <string>

using namespace std;

void addParent(int*, int*, int, int, int **);

int main(int argc, const char * argv[]) {
    int n;
    
    cout << "Number of matrices? ";
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
    
    int **m = new int *[n+1];
    int **s = new int *[n+1];

    for (int i=0; i<n+1; i++){
        m[i] = new int[n+1];
        s[i] = new int[n+1];
    }
    
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
                if (q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    int *f = new int[n+1];
    int *b = new int[n+1];
    addParent(f, b, 1, n, s);
    f[1]--;
    b[n]--;
    
    string str;

    for (int i=1; i<=n;i++){
        for (int j=0; j<f[i]; j++){
            str.append("(");
        }
        str.append("A"+to_string(i));
        for (int k=0; k<b[i]; k++){
            str.append(")");
        }
    }

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
    
    cout << endl;
    cout << "Optimal grouping:" << endl;
    cout << str << endl;
    cout << endl;
    cout << "Total cost: " << m[1][n] << " multiplications." << endl;
    
    delete[] f;
    delete[] b;

    for (int i=0; i<n+1; i++){
        delete[] m[i];
        delete[] s[i];
    }
    delete[] m;
    delete[] s;
    
    return 0;
}

void addParent(int *f, int *b, int i, int j, int **s){
    if ((j - i) < 1) return;

    int parent_pos = s[i][j];
    f[i]++;
    b[j]++;
    if (parent_pos == j)  return;
    addParent(f, b, i, parent_pos, s);
    addParent(f, b, parent_pos+1, j, s);
}


