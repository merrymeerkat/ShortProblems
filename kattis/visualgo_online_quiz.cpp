#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct VW{
    int vertex;
    int weight;
};

typedef vector<int> vi;
typedef vector<int, int> vii;
//vector<vector<int,int>> AL(100000);
vector <vector<VW> > AL(100000);
vi visited;
int V, E, S, T, u, v, w;
VW vw;
vector <int> solutions;

void DFS(int s, int t, int counter){
    //visited[s] = 1;
    //cout << "turning " << s << endl;
    for (auto i: AL[s]){
        cout << "for "<< i.vertex <<"in "<< s << endl;
        if (i.vertex == t){
            solutions.push_back(counter+(i.weight));
            cout << "t is " << t << endl;
            cout << "pushing " << (counter+(i.weight)) << endl;
        }
        else if (!visited[(i.vertex)]){
            cout << " gon do dfs with " << i.vertex << endl;
            DFS((i.vertex), t, (counter+(i.weight)));
        }
    } 
    visited[s] = 1;
    cout << "turning " << s << endl;
}

int main(){
    cin >> V >> E;
    //AL.assign(V, vii());
    visited.assign(V, 0);
    while (E--){
        cin >> u >> v >> w;
        vw.vertex = v; vw.weight = w;
        //AL[u].push_back((make_pair(v,w)));
        AL[u].push_back(vw);
    }
    cin >> S >> T;
    DFS(S, T, 0);


    // bs
    for (auto it = solutions.begin(); it != solutions.end(); it++){
        cout << "banana " << *it << endl;
    }
    int count = 0;
    int shortest = *min_element(solutions.begin(), solutions.end());
    cout << shortest;
    for (auto it = solutions.begin(); it != solutions.end(); it++){
        cout << " sol " << *it << endl;
        if (*it == shortest){
            count++;
        }
    }
    cout << "VISITED: ";
    for (auto it = visited.begin(); it != visited.end(); it++){
        cout << *it;
    }
    cout << endl;
    cout << count << '\n';
}
