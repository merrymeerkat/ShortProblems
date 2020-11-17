#include <iostream>
#include <queue>

using namespace std;

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
    int r = 0;
    for (; r < U; r++){
        if (r % 2 == 0){
            for (int cc = 0; cc < (R + N + L); cc++){
                if (cc % 2 == 0)
                    cout << '#';
                else 
                    cout << '.';
            }
        }
        else{
            for (int cc = 0; cc < (R + N + L); cc++){
                if (cc % 2 == 0)
                    cout << '.';
                else 
                    cout << '#';

            }
        }
        cout << '\n';
    }

    //cout << "r is " << r << endl;
    // middle rows
    for (; r < U + M; r++){
        if (r % 2 == 0){
            for (int l = 0; l < L; l++){
            //cout << "r is " << r << endl;
                if (l % 2 == 0)
                    cout << '#';
                else
                    cout << '.';
            }
        }
        else{
            for (int l = 0; l < L; l++){
            //cout << "r is " << r << endl;
                if (l % 2 == 0)
                    cout << '.';
                else
                    cout << '#';
            }
        }
        cout << words.front();
        words.pop();
        if (r % 2 == 0){
            for (int l = 0; l < R; l++){
            //cout << "r is " << r << endl;
                if (l % 2 == 0)
                    cout << '#';
                else
                    cout << '.';
            }
        }
        else{
            for (int l = 0; l < R; l++){
            //cout << "r is " << r << endl;
                if (l % 2 == 0)
                    cout << '.';
                else
                    cout << '#';
            }
        }
        cout << '\n';
    }

    // bottom rows
    for (; r <U + M + D; r++){
        if (r % 2 == 0){
            for (int cc = 0; cc < (R + N + L); cc++){
                if (cc % 2 == 0)
                    cout << '#';
                else
                    cout << '.';    
            }
        }
        else{
            for (int cc = 0; cc < (R + N + L); cc++){
                if (cc % 2 == 0)
                    cout << '.';
                else
                    cout << '#';    
            }
        }
        cout << '\n';
    }
}
