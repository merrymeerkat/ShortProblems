#include <iostream>
#include <queue>

using namespace std;

char get_char(int r, int c){

    char ch;
    // even col and even row || odd col and odd row
    if (r % 2 == (c % 2))
        ch = '#';
    else
        ch = '.';
    
    return ch;
}


int main(){
    
    int M, N, U, R, L, D;
    cin >> M >> N >> U >> L >> R>> D;

    string word;
    queue <string> words;
    for (int i = 0; i < M; i++){
        cin >> word;
        words.push(word);
    }

    // top
    int width = L + R + N;
    int r = 0;
    for (; r< U; ++r){
        for (int c = 0; c < width; ++c){
            cout << get_char(r, c);
        }
        cout << '\n';
    }
    // middle
    for (; r < U + M; r++){
        int c = 0;
        for (; c < L; c++)
            cout << get_char(r, c);
        cout << words.front();
        words.pop();
        c += N;
        for (; c < L + N + R; c++)
            cout << get_char(r, c);
        cout << '\n';
    }
    // bottom
    for (; r < U + M +  D; ++r){
        for (int c = 0; c < width; c++)
            cout << get_char(r, c);
        cout << '\n';
    }
}
