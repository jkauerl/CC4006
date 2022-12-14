#include <bits/stdc++.h>

int main(){
    int test;
    std::cin >> test;
    std::vector <std::vector <int>> resultados(test, std::vector <int>());
    for(int i = 0; i <test ; i++){
        int largo;
        std::cin >> largo;
        std::vector <int> b(largo);
        std::vector <int> a(largo);
        for(int j = 0; j<largo;j++){
            std::cin >> b[j];
        }
        std::vector <std::vector <std::pair<int,int>>> rangos(largo);
        for(int j = 0; j<largo;j++){
            int x,y;
            if(b[j] == 0){
                x = ((j+1)/(b[j]+1))+1;
                y = largo;
                rangos[x-1].push_back({y,j});
            }
            else{
                x = ((j+1)/(b[j]+1))+1;
                y = (j+1)/b[j];
                rangos[x-1].push_back({y,j});
            }
        } 
        //compara el segundo elemento de dos pares y devuelve si el segundo elemento del primer par es mayor al del segundo par
        auto comparar = [](std::pair<int, int> par1, std::pair<int, int> par2){
                    return par1.first > par2.first;
                };
        std::priority_queue <std::pair<int, int>,std::vector<std::pair<int,int>>,decltype(comparar)> posibilidades(comparar);
        for(int s = 0;s < largo; s++){
            for(int g = 0; g <rangos[s].size();g++){
                posibilidades.push({rangos[s][g].first,rangos[s][g].second});
            }
            if(posibilidades.size() != 0){
                a[posibilidades.top().second] = s + 1;
                posibilidades.pop();
            }
        }
        for(int j = 0; j<largo;j++){
            //std::cout << a[j] << ' ';
            resultados[i].push_back(a[j]);
        }
        //std::cout << '\n';
    }
    for(int i = 0; i<test;i++){
        for(int j = 0; j<resultados[i].size();j++){
            std::cout << resultados[i][j] << ' ';
        }
        std::cout << '\n';
    }
}