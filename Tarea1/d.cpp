#include <bits/stdc++.h>

using namespace std;

int main() {
    int t=0;

    cin >> t;

    vector<int> results;

    vector<vector<int>> results2(t, vector<int>());

    for(int i=0; i<t; i++){
        int tests;
        cin >> tests;

        int cancelled_state=0;

        vector<int> guards;
        vector<int> guards_copy;
            
        for(int k=0; k<tests; k++){
            int toughness;
            cin >> toughness;
            guards.push_back(toughness);
        }
        guards_copy = guards;
        if(tests % 2 == 0){
            if(tests<4){
                results.push_back(-1);
            }
            else if(tests>3) {
                sort(guards.begin(), guards.end());
                int even, odd;
                even=0;
                odd=0;
                for(int k=0; k<(tests); k++){
                    if(k%2==0){
                        guards_copy[k]=guards[even];
                        even+=1;
                    }
                    if(k%2==1){
                        guards_copy[k]=guards[(tests/2)+odd];
                        odd+=1;
                    }
                }
                /* for(int x : guards_copy){
                    cout << x << ' ';
                }
                cout << endl; // o '\n' */
                while(cancelled_state==0){
                    for(int k=0; k<tests; k++){ // chequea si estan ordenados correctamente
                        if(k==0){
                            if(((guards_copy[tests-1]<guards_copy[k]) and (guards_copy[k]>guards_copy[k+1])) or ((guards_copy[tests-1]>guards_copy[k]) and (guards_copy[k]<guards_copy[k+1]))){
                                results2[i].push_back(guards_copy[k]);
                            }
                            else {
                                results.push_back(-1);
                                cancelled_state=1;
                                break;
                            }
                        }
                        else if(k==tests-1){
                            
                            if(((guards_copy[tests-2]<guards_copy[k]) and (guards_copy[k]>guards_copy[0])) or ((guards_copy[tests-2]>guards_copy[k]) and (guards_copy[k]<guards_copy[0]))){
                                results2[i].push_back(guards_copy[k]);
                            }
                            else {
                                results.push_back(-1);
                                cancelled_state=1;
                                break;
                            }
                        }
                        else if((k!=0) and (k!=tests-1)){
                            if(((guards_copy[k-1]<guards_copy[k]) and (guards_copy[k]>guards_copy[k+1])) or ((guards_copy[k-1]>guards_copy[k]) and (guards_copy[k]<guards_copy[k+1]))){
                                results2[i].push_back(guards_copy[k]);

                            }
                            else {
                                results.push_back(-1);
                                cancelled_state=1;
                                break;
                            }
                        }
                    }
                    break;
                }
                if(cancelled_state==0){
                    results.push_back(0);
                }
            }
        }
        else if(tests % 2 == 1){
            results.push_back(-1);
        }
    }
    /* for(int k=0; k<results[1].size(); k++){
        cout << results[1][k] << " ";
    }
    cout << endl; */

    /* for(int x : results){
        cout << x << ' ';
    }
    cout << endl; // o '\n' */


    for(int i=0; i<t; i++){
        if ((results[i] == -1)){
            cout << "NO\n";
        }
        else if(results[i] != -1){
            cout << "YES\n";
            for(int j=0; j<results2[i].size(); j++){
                cout << results2[i][j] << " ";
            }
            cout<< endl;
        }
    }
}