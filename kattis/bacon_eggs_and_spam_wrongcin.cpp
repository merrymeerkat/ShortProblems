#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

/*struct Item(){
    string food;
    vector <string> people;
}*/
int main(){

    int n;
    string word, name;
    //Item item;
    vector <string> helper_vec;
    while (cin >> n){
        map <string, vector<string> > orders;
        cin >> name;
        for (int i = 0; i < n; i++){
            cin >> word;
            if (orders.find(word) != orders.end()){
                (orders[word]).push_back(word);
            }
            else{
                helper_vec.push_back(name);
                orders[word] = helper_vec;
                helper_vec.clear();
            }
            for (auto it = orders.begin(); it != orders.end(); it++){
                cout << it -> first;
                for (auto it2 = (it -> second).begin(); it2 != (it->second).end(); it2++){
                    cout << " " << *it2;
                }
                cout << '\n';
            }
            cout << '\n';
        }
    }
        
    

}
