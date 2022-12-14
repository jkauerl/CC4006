#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;
    vector<int> results;


    for(int g=0; g<t; g++){
        int rounds;
        cin >> rounds;

        vector<vector<int>> scores(2, vector<int>());
        vector<vector<int>> total_scores(2, vector<int>(rounds));

        for(int k=0; k<2; k++){
            int points;
            for(int p=0; p<rounds; p++){
                cin >> points;
                scores[k].push_back(points);
            }
            sort(scores[k].begin(), scores[k].end(), greater <>());
            partial_sum(scores[k].begin(),scores[k].end(),total_scores[k].begin());
        }

        int final;
        final = rounds-floor(rounds/4);

        int amount1, amount2;
        amount1 =  total_scores[0][final-1];
        amount2 =  total_scores[1][final-1];

        int actual_round;
        actual_round=rounds;

        if(amount1<amount2){
            int new_rounds, counter, right_counter;
            new_rounds = 0;
            counter = 0;
            right_counter=1;

            while(amount1<amount2){
                actual_round+=1;
                new_rounds+=1;
                if(actual_round%4==0){
                    amount1=amount1+(100-scores[0][final-right_counter]);
                    right_counter+=1;
                    }
                if(actual_round%4!=0){
                    if(actual_round<4){
                        amount1+=100;
                    }
                    else if(actual_round>=4){
                        if(rounds>(final+counter)){
                            amount1=amount1+100;
                            amount2=amount2+scores[1][final+counter];
                            counter++;
                        }
                        else if(rounds<=(final+counter)){
                            amount1+=100;
                        }
                    }
                }
            }
            results.push_back(new_rounds);
        }
        else if(amount1>=amount2){
            results.push_back(0);
        }
    }
    for(int i=0; i<t; i++){
        cout << results[i] << endl;
    }
    return 0;
}