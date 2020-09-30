#include <iostream>
#include <string>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string word; char c; long long possibilities;


    //while (scanf("%c", &c) != EOF){
      while((c = getchar()) != EOF){
        if (c != '\n'){
            word += c;
            cout << c << endl;           
        }
        else{
            int character_count[128] = { 0 };
            
            cout << c << endl;
    
            possibilities = 1;

            for (int i = 0; i < word.size(); i++){
                character_count[(int)(word[i]) - 1]++;
            }

            long long mult = 1;
            for (int i = 0; i < 128; i++){
                if (character_count[i] > 0){
                    possibilities *= mult;
                    mult++;
                }
                if (character_count[i] > 1){
                    possibilities /= (long long) character_count[i];
                }
            }
            
            cout << possibilities << '\n';
            word.clear();
        }
    }

    cout << (int) 'a';
}
