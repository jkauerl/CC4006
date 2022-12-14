#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    for(int k=0; k<t; k++){
        int n;
        cin >> n;

        vector<int> a(n);

        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        vector<int> p(n);
        
        int max_p=p[n-1];
        for(int i=n-2; i>-1; i--){
            if((i+a[i])<=(n-1)) {
                p[i]=a[i]+p[i+a[i]];
            }
            else if((i+a[i])>(n-1)) {
                p[i]=a[i];
            }
            if(p[i]>max_p) { 

                max_p=p[i];
            }
        }

        cout << max_p << endl;
    }
}