#include <iostream>

using namespace std;

int main(){
    
    int d, m; cin >> d >> m;

    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int total_days = 0;

    // Adding month days
    for (int i = 0; i < m - 1; i++){
        total_days += days[i];
    }

    total_days += d;

    int mod_day = (total_days % 7) - 1;

    switch (mod_day){
        case (-1):
            cout << "Wednesday" << '\n';
            break;
        case 0:
            cout << "Thursday" << '\n';
            break;
        case 1:
            cout << "Friday" << '\n';
            break;
        case 2:
            cout << "Saturday" << '\n';
            break;
        case 3:
            cout << "Sunday" << '\n';
            break;
        case 4:
            cout << "Monday" << '\n';
            break;
        case 5:
            cout << "Tuesday" << '\n';
            break;
    }

    return 0;
}
