#include <bits/stdc++.h>

using namespace std;

int main(){

long long n,m;

cin >> n >> m;

if(n<m){
    cout<<n<<endl;
}
else{
    long long l,r, mid;

    l=m;
    r=m+3e9;

    long long grains_left=0;

    while(l<r){
        mid = l+(r-l)/2;

        grains_left=n-m-(((mid-m)*((mid-m)+1)))/2;

        if(grains_left<=0){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    cout<<l<<endl;

}
}