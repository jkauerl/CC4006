#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin>>n;

    long long temp1;
    long long temp2;


    vector<vector<long long>> dp(n, vector<long long>(n));
    vector<long long> a(n);

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    for(int i=0; i<n; i++){
        dp[i][i]=a[i];
    }

    for(int i=n-1; i>=0; i--){
        for(int j=i+1; j<n; j++){
            if(i!=j){
                if(j-1==i){
                    dp[i][j]=max(dp[i][j-1], dp[i+1][j]);
                }
                else{
                    temp1= dp[i+1][j-1];
                    temp2=temp1;
                    if(temp1>dp[i][j-2]){
                        temp1=dp[i][j-2];
                    }
                    if(temp2>dp[i+2][j]){
                        temp2=dp[i+2][j];
                    }
                    dp[i][j]=max(a[j]+temp1, a[i]+temp2);
                }
            }
        }
    }

    cout<<dp[0][n-1];

}