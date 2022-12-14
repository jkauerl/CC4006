#include <bits/stdc++.h>

using namespace std;

int main(){

    

    int n, u;

    vector<int> results;

    while(cin >> n >> u, n != -1){
        // procesar caso de prueba

        vector<int> population_per_city(n);
        for(int k=0; k<n; k++){
            cin >> population_per_city[k];
        }

        long long l, r, mid;
        l=1;
        r=5e6;
        vector<int> urns_per_city(n);

        while(l<r){
            mid = l+(r-l)/2;
            int total_urns=0;

            for(int i=0; i<n; i++){
                int urns_needed;
                urns_needed=(population_per_city[i]+mid-1)/mid;
                total_urns+=urns_needed;
            }
            if(total_urns<=u){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        results.push_back(l);
    }
    for(int i=0; i<results.size(); i++){
        cout << results[i]<< endl;
    }
}