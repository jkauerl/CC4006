#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    for(int i=0; i<q; i++){
        int instruction;
        cin>>instruction;
        int k;
        cin>>k;
        k--;
        if(instruction==1){
            int x;
            cin>>x;
            a[k]=x;
        }
        if(instruction==2){
            vector<int> price(n);
            int min_value=0;
            for(int j=0; j<n; j++){
                price[j]=a[j]+abs(k-j);
            }
            cout<<*min_element(price.begin(), price.end())<<endl;
        }
    }
}