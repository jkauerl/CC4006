#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    for(int k=0; k<t; k++){
        int n;
        cin >> n;

        long long result=0;

        vector<long long> values(n);
        vector<long long> indices;
        
        for(int i=0; i<n; i++){
            cin >> values[i];
            if(values[i]<(i+1)){
                indices.push_back(i+1);
            }
        }
        for(int i=0; i<indices.size(); i++){

            int l, r, mid;
            l=0;
            r=indices.size();
            while(l<r){
                mid=l+(r-l)/2;
                if(values[indices[i]-1]<(indices[mid]+1)){
                    r=mid;
                }
                else{
                    l=mid+1;
                }
            }

            result+=l;
        }
        cout << result << endl;
    }
}