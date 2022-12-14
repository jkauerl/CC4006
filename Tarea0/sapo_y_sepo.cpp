#include  <iostream>

using namespace std;

int main(){

    int entero = 0;

    cin >> entero;

    if ((entero % 2) != 0)
        cout << "NO\n";
    else 
        for (int i=1; i < (entero/2); i++){
            if ( (entero/i) == (entero/2)) 
                cout << "YES\n";



        }




}