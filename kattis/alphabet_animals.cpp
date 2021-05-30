#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string wrd; cin >> wrd;
    int len = wrd.size();
    char star = wrd[len - 1]; // STAR is our letter of interest

    int N; cin >> N;
    vector <string> valid;
    set <char> first;
    unordered_map <char, int> count;
    for (int i = 0; i < N; i++){
        cin >> wrd;
        if (wrd[0] == star)
            valid.push_back(wrd);
        first.insert(wrd[0]);
        count[wrd[0]]++;
    }

    char last;
    vector <string> great;
    for (auto w : valid){
        len = w.size();
        last = w[len-1];
        // if a valid word ends with a letter that is not a starting letter of any other word, this is a "great" ("!") word
        if (first.find(last) == first.end()){
            great.push_back(w);
            continue;
        }
        // this is to account for when the last letter of a valid word is in the "first" list, but only because that very same valid word starts with that letter (in which case the word is still great, since
        // we can't use the same word twice)
        if (w[0] == last){
            if (count[w[0]] == 1)
                great.push_back(w);
        }
    }
    
    if (!great.empty()){
        cout << great[0] << "!\n";
    }
    else if (!valid.empty()){
        cout << valid[0] << '\n';
    }
    else
        cout << "?\n";

}
