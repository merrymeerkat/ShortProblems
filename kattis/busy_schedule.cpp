#include <iostream>
#include <set>
#include <string>

using namespace std;

struct Time{
    string number;
    string m;
};

class Compare {
    public:
        bool operator() (const Time a, const Time b) const {
            if ((a.m).compare(b.m) != 0){
                return (a.m).compare(b.m) < 0;
            }
            else {
                // Convert string into time
                // But first check if time has 4 digits (e.g. 12:00) or 3 (e.g. 3:00)
                int time_a, time_b;
                if ((a.number).size() == 5)
                    time_a = ((stoi((a.number).substr(0,2)))*60 + stoi((a.number).substr(3,2))) % 720;
                else {
                    time_a = ((stoi((a.number).substr(0,1)))*60 + stoi((a.number).substr(2,2))) % 720;
                }
                if ((b.number).size() == 5)
                    time_b = ((stoi((b.number).substr(0,2)))*60 + stoi((b.number).substr(3,2))) % 720;
                else {
                    time_b = ((stoi((b.number).substr(0,1)))*60 + stoi((b.number).substr(2,2))) % 720;
                }
                return time_a < time_b;
            
            }        
    }
}; 

int main(){
 
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    string this_number, this_m;
    Time this_time;
    multiset <Time, Compare> times;

    while (n != 0){

        for (int i = 0; i < n; i++){
            cin >> this_number >> this_m;
            this_time.number = this_number; this_time.m = this_m;
            times.insert(this_time);
        }

        // Output times in order
        for (auto it = times.begin(); it != times.end(); it++){
            cout << ((*it).number) << ' ' << ((*it).m) << '\n';
        }
        
        times.clear();
        cin >> n;
        
        if (n != 0)
            cout << '\n';
    }

}


