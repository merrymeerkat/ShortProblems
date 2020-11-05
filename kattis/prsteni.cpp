#include <iostream>
#include <vector>

using namespace std;

int get_gcd(int a, int b){

    int max, min, gcd;

    if (a >= b){
        min = b;
        max = a;
    }
    else{
        min = a;
        max = b;
    }

    //int remainder = (max % min);

    gcd = min;
    while ((max % gcd != 0) || (min % gcd != 0)){
        gcd--;
    }

    return gcd;
}

int main(){

    int N; cin >> N;

    int first, measure;
    vector <int> rings;
    cin >> first; // measure of the first ring
    N--;
    while (N--){
        cin >> measure; // read rest into vector
        rings.push_back(measure);
    }

    int gcd;
    for (auto it = rings.begin(); it != rings.end(); it++){
        gcd = get_gcd(*it, first);
        cout << first/gcd << '/' << *it/gcd << '\n';
    }

    return 0;
}
