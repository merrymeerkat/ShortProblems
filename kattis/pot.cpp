#include <iostream>
#include <math.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;

    int p;
    int power;
    int sum = 0;
    while(N--){
    //for (int i = 0; i < N; ++i)
        cin >> p;

        // Getting last digit
        power = p % 10; 
        
        // Getting remaining digits
        p /= 10;

        sum += pow(p, power);    
    }

    cout << sum << "\n";

}
