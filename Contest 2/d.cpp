#include <bits/stdc++.h>

using namespace std;

int main(){
    int casos;
    cin >> casos;

    vector<pair<int,int>> domino_original(casos);
    vector<vector<int>> domino(casos, vector<int>(3));


    for(int i=0; i<casos; i++){
        cin>>domino_original[i].first;
        cin>>domino_original[i].second;
        vector<int> valor = {domino_original[i].first, domino_original[i].second, i};
        domino[i] = valor;
    }


    sort(domino.begin(), domino.end());

    /* for(int i=0; i<casos; i++){
        cout<<domino[i].first<<" ";
    }
    cout<<endl; */

    vector<int> dp(casos + 1);

    dp[casos]=0;
    dp[casos-1]=1;

    for(int i=casos-2; i>=0; i--){
        int contador = 0;
        int j = i;
        while(j != casos){
            if(domino[j][0] < domino[i][0] + domino[i][1] - 1){
                contador += 1;
            }
            else{
                break;
            }
            j++;
        } 
        dp[i]=contador;
        if(j-1 != i) {
            dp[i] += dp[j-1] -1;
        }
    }


    for(int i=0; i<dp.size()-1; i++){

        cout<<dp[i]<<" ";
    }
    cout<<endl;

}