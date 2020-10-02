#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    string word, last_word;

    set <string> words;

    // Get first player's word
    cin >> last_word; words.insert(last_word);
    N--;

    int player;
    bool is_player2 = true;
    while (N--){
        cin >> word;
        
        player = (is_player2) ? 2 : 1;

        // check last char
        if (last_word.back() != word[0]){
            cout << "Player " << player << " lost\n";
            return 0;
        }

        // check if in set already
        if (words.find(word) != words.end()){
            cout << "Player " << player << " lost\n";
            return 0;
        }

        words.insert(word);
        last_word = word;
        is_player2 = !is_player2;
    }
    cout << "Fair Game\n";
    return 0;
}
