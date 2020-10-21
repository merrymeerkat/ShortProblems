#include <iostream>
#include <set>

using namespace std;

struct Moose{
    int yr;
    int str;
};

class Compare_year{
    public:
        bool operator() (const Moose a, const Moose b) const {
            if (a.yr == b.yr){
                return (a.str > b.str);
            }
            else
                return (a.yr < b.yr);
        }
};

class Compare_strength{
    public:
        bool operator() (const Moose a, const Moose b) const {
            return (a.str > b.str);
        }
};

multiset <Moose, Compare_year> all;
set <Moose, Compare_strength> tournament;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int k, n; cin >> k >> n;

    int Karl_yr, Karl_str;
    cin >> Karl_yr >> Karl_str;
    Moose this_moose;
    this_moose.yr = Karl_yr; this_moose.str = Karl_str;
    // Insert Karl into set
    all.insert(this_moose);

    // Get other moose
    int yr, str;
    int moose = k + n - 2;
    for (int i = 0; i < moose; i++){
        cin >> yr >> str;
        this_moose.yr = yr; this_moose.str = str;
        all.insert(this_moose);
    }

    // Initial year
    int year = (*all.begin()).yr;

    // Getting first k players into tournament
    while (k--){
        this_moose = *all.begin(); tournament.insert(this_moose); all.erase(this_moose);
    }

    Moose winner;
    //n--;
    while(n--){
        winner = *tournament.begin(); tournament.erase(winner);
        if (winner.yr == Karl_yr && winner.str == Karl_str){
            cout << year << '\n';
            return 0;
        }
        this_moose = *all.begin(); tournament.insert(this_moose); all.erase(this_moose);
        year++;
    }

    cout << "unknown" << '\n';
}

