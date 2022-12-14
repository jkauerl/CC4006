#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    int n, a;
    for(int i = 0; i < t; i++){
        std::cin >> n;
        std::vector <int> arreglo (n);
        std::vector<int> resta;
        std::vector <int> indices;
        long long res = 0;
        for(int j = 1; j <= n; j++){
            std::cin >> arreglo[j-1];
        }
        for(int j=0; j<n; j++){
            resta.push_back(arreglo[j]-(j+1));
            indices.push_back(j+1);
        }

        std::sort(resta.begin(), resta.end());
        for(int j = 0; j < indices.size(); j++){
            int r,l,mid;
            l=0;
            r=indices.size();
            while(l<r){
                mid=l+(r-l)/2;
                if(resta[j]<(indices[mid]-mid+1)){
                    l=mid;
                }
                else{
                    l=mid+1;
                }


            }
            res+=1;


        }
        std::cout << res << "\n";
    }
    // return 0;
}

