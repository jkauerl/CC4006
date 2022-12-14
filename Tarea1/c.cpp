#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;



    vector<vector<int>> results(t, vector<int>());

    for(int k=0; k<t; k++){
        int n,m;
        cin >> n;
        cin >> m;

        vector<vector<int>> grid(n, vector<int>());
        vector<int> index;
        int stop_counter=0;

        for(int i=0; i<n; i++){
            int value;
            for(int j=0; j<m; j++){
                cin >> value;
                grid[i].push_back(value);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m-1; j++){
                if(grid[i][j]>grid[i][j+1]){
                    stop_counter+=1;
                }
            }
        }
        if(stop_counter==0){
            results[k].push_back(1);
            results[k].push_back(1);
            continue;
        }
        vector<vector<int>> grid_sorted(n, vector<int>());
        grid_sorted = grid;
        for(int i=0; i<n; i++){
            sort(grid_sorted[i].begin(), grid_sorted[i].end());
        }
        stop_counter=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] != grid_sorted[i][j]){
                    index.push_back(j);
                    stop_counter+=1;
                }
            }
            if(stop_counter>1){
                break;
            }

        }
        stop_counter=0;
        for(int i=0; i<n; i++){
            if(index.size()>=3){
                stop_counter+=1;
            }
            else if((index.size()<3)){
                swap(grid[i][index[0]], grid[i][index[1]]);
            }
            else if((index.size()==1)){
                swap(grid[i][index[0]], grid[i][index[0]+1]);
            }
        }
        if(stop_counter>0){
            results[k].push_back(-1);
            continue;
        }
        stop_counter=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m-1; j++){
                if(grid[i][j]>grid[i][j+1]){
                    stop_counter+=1;
                }
            }
        }
        if(stop_counter>0){
            results[k].push_back(-1);
            continue;
        }
        if(stop_counter==0){
            results[k].push_back(index[0]+1);
            results[k].push_back(index[1]+1);
        }
    }
    for(int i=0; i<t; i++){
        for(int j=0; j<results[i].size(); j++){
            cout << results[i][j] << " ";
            }
        cout << endl;
    }
}