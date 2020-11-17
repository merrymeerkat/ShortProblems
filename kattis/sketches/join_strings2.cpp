#include <iostream>
#include <list>

using namespace std;

list <string> words;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    string word;
    auto its[n];
    for (int i = 0; i < n; ++i){

        cin >> word;
        its[i] = words.push_back(word);

    }
    n--;
    int a, b;
    while (n--){
        cin >> a >> b;
        words.insert(words.begin() + a, *(words.begin() + b));
        words.insert(words.begin() + b, "");
        words.erase(words.begin() + b);
    }

    for (auto s : words){
        cout << s;
    }


}
