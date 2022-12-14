cout<< "add max of the same vector";
    int maximum_value;
    maximum_value=max_element(results.begin(), results.end());
    cout<< maximum_value<< endl;
    // results.push_back(max_element(results.begin(), results.end()));

    for(int i=0; i<results.size(); i++){
        cout<< results[i]<< " ";
    }
    cout << endl;