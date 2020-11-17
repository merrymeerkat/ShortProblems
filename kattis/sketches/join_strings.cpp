#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector <string> words;

int main(){

    int n; cin >> n;
    string word;
    for (int i = 0; i < n; i++){
        cin >> word;
        words.push_back(word);
    }

    int a, b;
    for (int i = 1; i < n; i++){
        cin >> a >> b;
        words[a-1]+=words[b-1];
    }

    cout << words[a-1] << '\n';
}
