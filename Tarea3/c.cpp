#include <bits/stdc++.h>

using namespace std;

int main(){

    string commands;
    int changes;
    
    getline(cin, commands);
    cin>>changes;
    
    int n;
    n=commands.size();

    cout<<commands<<endl;
    cout<<changes<<endl;
    cout<<n<<endl;

    int dp[n][n][changes][2];

    dp[0][0][0][0]=3;
    cout<<dp[0][0][0][0]<<endl;

    for(int i=0; i<n; i++){
        
    }

}