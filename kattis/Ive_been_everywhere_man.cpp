#include <iostream>
#include <set>

using namespace std;

int main(){
    int TC; cin >> TC;
    int n;

    string city;
    set <string> cities;
    
    while (TC--){
        cin >> n;
        while (n--){
            cin >> city;
            cities.insert(city);
        }
        cout << cities.size() << '\n';
        cities.clear();
    }

}
