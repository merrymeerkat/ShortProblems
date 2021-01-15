#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef pair<string,int> psi;

struct Compare{
    bool operator()(const psi &A, const psi &B){
    if (A.second == B.second)
        return((A.first).compare(B.first) < 0);
    else
        return(A.second > B.second);
    }
};

int main(){

    set <string> users;
    unordered_map <string, int> word_freq;
    unordered_map <string, set <string> > word_users;

    int M; cin >> M;
    cin.get();
    string line, word, name;
    while(M--){
        getline(cin, line);
        stringstream ss(line);
        ss >> name;
        users.insert(name);
        while (ss >> word){
            word_freq[word]++;
            word_users[word].insert(name);
        }
    }

    vector <pair <string, int> > ans;
    int num_users = users.size();
    for (auto el : word_users){
        if ((el.second).size() == num_users){//word is a keyword
            ans.push_back({el.first, word_freq[el.first]});
        }
    }

    sort(ans.begin(), ans.end(), Compare());

    for (auto a : ans){
        cout << a.first << '\n';
    }
    if (ans.empty()){
        cout << "ALL CLEAR\n";
    }
    return 0;
}
