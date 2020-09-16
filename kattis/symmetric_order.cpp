#include <iostream>
#include <string>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    
    string input[15];
    string output[15];

    int idx = 1;
    while (N != 0){
      
        for (int i = 0; i < N; i++){
        cin >> input[i];
        }

        int count = 0;
            for (int i = 0; i < N; i++){
                if (i % 2 == 0){
                    output[count] = input[i];
                }
                else{
                    output[N - 1 - count] = input[i];
                    count++;
                }
            }
        
        cout << "SET " << idx << "\n";
        for (int i = 0; i < N; i++)
             cout << output[i] << "\n";

        idx++;

        cin >> N;
    }

  return 0;
}
