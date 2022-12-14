#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;

    vector<int> values;
    int value;

    for(int i=0; i<n; i++){
        cin >> value;
        values.push_back(value);
    }

    for (int i=0; i<q; i++){
        int search;

        cin >> search;

        for(int k=0; k<n; k++){
            if(search==values[k]){
                cout << k << endl;
                break;
            }
            if((k==(n-1)) and (search!=values[k])){
                cout << -1 << endl;
            }
        }
    }




}