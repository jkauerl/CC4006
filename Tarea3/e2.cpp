#include <bits/stdc++.h>
using namespace std;

int main(){

    long long n;
    cin >> n;

    vector <long long> arreglo(n);
    vector < vector <long long> > dp(n, vector <long long> (n));

    for (int i = 0; i < n; i++){
        cin >> arreglo[i];
        dp[i][i] = arreglo[i];    
    }
    
    for (int i = 0; i < n-1; i++){
        dp[i][i+1] = max( dp[i][i], dp[i+1][i+1] );
    }
    
    for (int i = n - 3; i >= 0 ; i--){
        for (int j = i + 2; j < n; j++){

            long long ai;
            ai = arreglo[j] + min(dp[i][j-2], dp[i+1][j-1]);

            long long aj;
            aj = arreglo[i] + min(dp[i+1][j-1], dp[i+2][j]);

            dp[i][j] = max(ai, aj);
        }   
    }
    
    cout << dp[0][n-1];
    
}