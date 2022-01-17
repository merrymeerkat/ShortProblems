#include <iostream>
#include <unordered_map>

using namespace std;

int main(){

    int N, M;
    cin >> M >> N;

    unordered_map <string, int> mp;
    while(M--){
        string word; int val;
        cin >> word >> val;
        mp[word] = val;
    }

    for (int i = 0; i < N; i++){
        string word;
        cin >> word;
        int total = 0;
        while(word != "."){
            if (mp.find(word) != mp.end()){
                total += mp[word];
            }
            cin >> word;
        }
        cout << total << '\n';
    }

    return 0;
}
