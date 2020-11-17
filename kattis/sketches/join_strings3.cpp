#include <iostream>
#include <vector>
#include <list>

using namespace std;

typedef list <char> lc;
vector <lc> words;

int main(){
    
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    words.assign(n, lc());

    cin.get();
    char c;
    for (int i = 0; i < n; i++){
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
        //auto it = words[a-1].begin();
        words[a-1].splice(words[a-1].end(), words[b-1]);
        //words[a-1].push_back(words[b-1]);
        words[b-1] = empty;
        // also try out the set idea (might be faster)
    }

    for (auto lst : words){
        for (auto c : lst){
            cout << c;
        }
    }
    cout << '\n';
}
