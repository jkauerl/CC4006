#include <bits/stdc++.h>

using namespace std;

int main(){


    int n;

    cin>>n;

    vector<int> a(n);

    for(int i=0; i<n; i++){
        cin>>a[i];
    }


    vector<vector<int>> dp(n+1, vector<int>(n+1));

    for(int i=0; i<n; i++){
        dp[i][i] = 1;
    }

    for(int i=n-1; i>-1; i--){
        for(int j=i;  j<n; j++){
            if(i!=j){
                dp[i][j]=1+dp[i+1][j];
                for(int k=(i+1); k<=j; k++){
                    if(a[i]==a[k]){
                        if(k==i+1){
                            dp[i][j]=1+dp[i+2][j];
                        }
                        else if(dp[i][j]>(dp[i+1][k-1]+dp[k+1][j])){
                            dp[i][j]=dp[i+1][k-1]+dp[k+1][j];
                        }
                    }
                }
            }
        }
    }
    cout<<dp[0][n-1];
}