#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){

    int n;
    string food, name;
    vector <string> helper_vec;
    vector <string> orders;
    map <string, vector <string> > total_orders;

    string line; getline(cin, line);
    int customers = stoi(line);

    do{
        // For each customer in a day
        for (int i = 0; i < customers; i++){
           
            getline(cin, line);
            istringstream wordstream(line);
            wordstream >> name;
            
            while (wordstream >> food){
                if (total_orders.find(food) != total_orders.end()){
                    (total_orders[food]).push_back(name);
                }
                else {
                    total_orders.insert({food, {name}});
                }
            }
        }

        // Printing
        for (auto it = total_orders.begin(); it != total_orders.end(); it++){
            cout << it -> first;
            sort((it -> second).begin(), (it -> second).end());
            for (auto it2 = (it -> second).begin(); it2 != (it->second).end(); it2++){
                cout << " " << *it2;
            }
            cout << '\n';
        }

        total_orders.clear();
        getline(cin, line);
        customers = stoi(line);
        if (customers)
            cout << '\n';

        // for as many days as there are
    }while (customers);
}

