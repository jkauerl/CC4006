#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    vector<vector<int>> permutation(t, vector<int>());

    for(int k=0; k<t; k++){
        int n;
        cin >> n;
        
        vector<int> floor_permutation;
        vector<int> original_values(n);
        vector<vector<pair<int,int>>> ranges(n);

        auto compare = [](pair<int,int> pair1, pair<int,int> pair2){
            return pair1.first > pair2.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> possible_values(compare);


        int values;
        for(int i=0; i<n; i++){
            cin >> values;
            floor_permutation.push_back(values);
        }

        for(int j=0; j<n; j++){
            if(floor_permutation[j]==0){
                ranges[(j+1)/(floor_permutation[j]+1)].push_back(make_pair(n, j));
            }
            else{
                ranges[(j+1)/(floor_permutation[j]+1)].push_back(make_pair((j+1)/floor_permutation[j], j));
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<ranges[i].size(); j++){;
                possible_values.push(make_pair(ranges[i][j].first, ranges[i][j].second));
            }
            if(possible_values.size() != 0){
                original_values[possible_values.top().second] = i + 1;
                possible_values.pop();
            }
        }
        for(int i=0; i<n; i++){
            permutation[k].push_back(original_values[i]);
        }
    }
    for(int k=0; k<t; k++){
        for(int i=0; i<permutation[k].size(); i++){
            cout << permutation[k][i] << " ";
        }   
        cout << endl;
    }
}