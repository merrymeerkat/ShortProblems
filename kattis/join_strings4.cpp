#include <iostream>
#include <vector>
#include <list>
#include <set>

using namespace std;

typedef list <char> lc;
vector <lc> words;
set <int> remaining;

int main(){
    int n; cin >> n;
    words.assign(n, lc());

    cin.get();
    char c;
    for (int i = 0; i < n; i++){
        remaining.insert(i);
        c = getchar();
        while (c != '\n'){
            words[i].push_back(c);
            c = getchar();
        }
    }

    /*for (auto l : words){
        for (auto c : l){
            cout << c;
        }
        //cout << endl;
    }*/

    lc empty;
    //n--;
    int a, b;
    for (int i = 1; i < n; i++){
    //while (n--){
        cin >> a >> b;
        remaining.erase(b-1);
        //auto it = words[a-1].begin();
        words[a-1].splice(words[a-1].end(), words[b-1]);
        //words[a-1].push_back(words[b-1]);
        words[b-1] = empty;
        // also try out the set idea (might be faster)
    }

    /*
    for (auto lst : words){
        for (auto c : lst){
            cout << c;
        }
    }*/
   // auto it = remaining.begin();
    int idx = *(remaining.begin());
    for (auto c : words[idx])
        cout << c;
    cout << '\n';
}
