#include <bits/stdc++.h>

using namespace std;

int main(){

    int N, M;
    
    while(cin >> N >> M, N != 0){
        // procesar caso de prueba


        vector<vector<int>> boxes(N, vector<int>(M));
        vector<vector<int>> dp(N, vector<int>(M));

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin >> boxes[i][j];
            }
        }

        vector<int> total_chocolates_rows(N);
        vector<int> dp2(N);
        int max_chocolate_per_row;


        for(int j=0; j<N; j++){
            for(int i=M-1; i>-1; i--){
                if(i==(M-1)){
                    dp[j][i] = boxes[j][i];
                }
                else if(i==(M-2)){
                    dp[j][i] = max(dp[j][i+1], boxes[j][i]);                    
                }
                else {
                    dp[j][i] = max(dp[j][i+1], dp[j][i+2]+boxes[j][i]);
                }
            }
            max_chocolate_per_row = *max_element(dp[j].begin(), dp[j].end());
            total_chocolates_rows[j]=max_chocolate_per_row;
        }
        for(int i=N-1; i>-1; i--){           
            if(i==(N-1)){
                dp2[i] = total_chocolates_rows[i];
            }
            else if(i==(N-2)){
                dp2[i] = max(dp2[i+1], total_chocolates_rows[i]);                    
            }
            else {
                dp2[i] = max(dp2[i+1], dp2[i+2]+total_chocolates_rows[i]);
            }
        }
        cout<<*max_element(dp2.begin(), dp2.end())<<endl;
    }
}