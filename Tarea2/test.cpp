#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<int> results;

    results.push_back(1);
    results.push_back(2);
    results.push_back(3);

    for(int i=0; i<results.size(); i++){

        cout<< results[i]<< " ";
    }
    cout << endl;

    cout<<"add 1"<< endl;
    results.push_back(1);

    for(int i=0; i<results.size(); i++){

        cout<< results[i]<< " ";
    }
    cout << endl;


    cout<< "add max of the same vector";
    int maximum_value;
    maximum_value=*max_element(results.begin(), results.end());
    cout<< maximum_value<< endl;
    // results.push_back(max_element(results.begin(), results.end()));

    for(int i=0; i<results.size(); i++){
        cout<< results[i]<< " ";
    }
    cout << endl;



}