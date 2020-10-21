#include <iostream>
#include <queue>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int C; cin >> C;
    int n; cin >> n;

    int leave, enter, stay;
    queue <int> train;
    while (n--){
        cin >> leave >> enter >> stay;
        
        while (leave > 0){
            //cout << "LE ";
            if (!train.empty()){
                train.pop();
                leave--;
            }
            else{
                //cout << "CANT LEAVE ";
                cout << "impossible\n";
                return 0;
            }
        }

        while (enter > 0){
            if (train.size() < C){
                train.push(1); 
                enter--;
                //cout << "EN ";
            }
            else {
              //  cout << "CANT ENTER ";
                cout << "impossible\n";
                return 0;
            }
        }

        if (stay > 0 && train.size() < C){
            //cout << "CANT STAY ";
            cout << "impossible\n";    
            return 0;

        }
    }

    if (!train.empty())
        cout << "impossible\n";
    else
        cout << "possible\n";
}
