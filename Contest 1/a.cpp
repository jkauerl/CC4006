#include <bits/stdc++.h>

using namespace std;

int main(){

    long long n,m;
    cin>>n>>m;

    vector<long long> a(n);
    vector<long long> b(m);

    for(long long i=0; i<n; i++){
        cin>>a[i];
    }
    for(long long i=0; i<m; i++){
        cin>>b[i];
    }

    sort(a.begin(), a.end());

    long long l, r, mid;
    
    for(long long i=0; i<m; i++){
        l=0;
        r=n-1;
        while(l<r){
            mid = l+(r-l)/2;
            if(a[mid]>b[i]){
                r=mid;
            }
            else{
                l=mid+1;
            }

        }
        cout<<l<< " ";
    }
}