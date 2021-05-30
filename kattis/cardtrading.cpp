#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, T, K; cin >> N >> T >> K;
    
    int num;
    vector <int> num_type;
    num_type.assign(T, 0);
    for (int i = 0; i < N; i++){
        cin >> num;
        num_type[num-1]++;
    }

    vector <int> buy;
    vector <int> sell;
    vector <int> val; // (buy + sell) * num cards
    //buy.assign(T, 0);
    //sell.assign(T,0);
    int num2;
    for (int i = 0; i < N; i++){
        cin >> num >> num2;
        buy.push_back(num);
        sell.push_back(num2);
        val.push_back((num + num2)/num_type[i]);
    }




}
