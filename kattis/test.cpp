#include <iostream>
#include <set>

using namespace std;

int main(){

    set <int> bosta;

    bosta.insert(1);
    bosta.insert(2);
    bosta.insert(3);
    bosta.insert(4);
    
    bosta.erase(1);
    cout << 'a' << endl;
    bosta.erase(bosta.find(3));
    cout << 'b' << endl;
    bosta.erase(bosta.find(5));
    cout << 'c' << endl;
    for (auto it = bosta.begin(); it != bosta.end(); it++){
        cout << *it << endl;
    }
}
