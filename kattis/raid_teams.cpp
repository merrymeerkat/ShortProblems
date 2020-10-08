#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

struct Player{
    int S1, S2, S3;
    string name;
};

/*class Compare{
    public:
        bool operator() (const Player a, const player b) const {
            if (a.S1 == b.S1){
                if (a.S2 == b.S2){
                    if (a.S3 == b.S3)
                        return (a.name).compare(b.name) < 0;
                    else
                        return a.S3 > b.S3;
                }
                else
                    return a.S2 > a.S2;
            }
            else {
                return a.S1 > b.S1;
            }
        }
};*/
// Is there a more efficient way to write these three compare classes?
// e.g. maybe only one compare class and then pass an argument to say which component we are comparing?
// (bc they only differ by S)

class Compare{
    public:
        bool operator() (const Player a, const Player b) const {
            if (a.S1 == b.S1)
                return (a.name).compare(b.name) < 0;
            else
                return (a.S1 > b.S1);
        }
};

class Compare2{
    public:
        bool operator() (const Player a, const Player b) const {
            if (a.S2 == b.S2)
                return (a.name).compare(b.name) < 0;
            else
                return (a.S2 > b.S2);
        }
};

class Compare3{
    public:
        bool operator() (const Player a, const Player b) const {
            if (a.S3 == b.S3)
                return (a.name).compare(b.name) < 0;
            else
                return (a.S3 > b.S3);
        }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    set <Player, Compare> set1;
    set <Player, Compare2> set2;
    set <Player, Compare3> set3;

    int N; cin >> N;
    int S1, S2, S3; string name;
    Player thisPlayer;
    int N_copy = N;

    while (N--){
        
        cin >> name >> S1 >> S2 >> S3;
        thisPlayer.S1 = S1; thisPlayer.S2 = S2; thisPlayer.S3 = S3;
        thisPlayer.name = name;

        set1.insert(thisPlayer);
        set2.insert(thisPlayer);
        set3.insert(thisPlayer);
    }

    N_copy /= 3;
    set <string> removed;
    string name1, name2, name3;
    string team[3];

    while (N_copy--){

        // Get highest first skill
        thisPlayer = *set1.begin();
        name1 = thisPlayer.name;
        while (removed.find(name1) != removed.end()){
            set1.erase(set1.begin());
            thisPlayer = *set1.begin();
            name1 = thisPlayer.name;
        }
        set1.erase(thisPlayer);
        removed.insert(name1);
        team[0] = name1;

        // Get highest second skill
        thisPlayer = *set2.begin();
        name2 = thisPlayer.name;
        while (removed.find(name2) != removed.end()){
            set2.erase(set2.begin());
            thisPlayer = *set2.begin();
            name2 = thisPlayer.name;
        }
        set2.erase(thisPlayer);
        removed.insert(name2);
        team[1] = name2;

        // Get highest third skill
        thisPlayer = *set3.begin();
        name3 = thisPlayer.name;
        while (removed.find(name3) != removed.end()){
            set3.erase(set3.begin());
            thisPlayer = *set3.begin();
            name3 = thisPlayer.name;
        }
        set3.erase(thisPlayer);
        removed.insert(name3);
        team[2] = name3;

        sort(team, team + 3);

        cout << team[0] << ' ' << team[1] << ' ' << team[2] << '\n';
    }


}
