#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Neighb {
    int val;
    int goods; // amount of goods this neighbour gives you
};

typedef vector <int> vi;
typedef vector <Neighb> vn;
//vector <vn> AL_rec;
vector <vn> AL_giv;
vi min_goods; // min amount of goods each island needs
vi goods_received; // amount of goods each island is effectively receiving
vi visited;
queue <int> q;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N; cin >> N;
    //AL_rec.assign(N + 1, vn());
    AL_giv.assign(N + 1, vn());
    min_goods.assign(N + 1, 0);
    goods_received.assign(N + 1, 0);
    visited.assign(N + 1, 0);

    int min_good, n;
    int neighb, goods;
    Neighb receiver, giver;

    // for each island
    for (int i = 1; i <= N; ++i){
        cin >> min_good >> n;
        min_goods[i] = min_good;
        // get neighbours
        for (int j = 0; j < n; j++){
            cin >> neighb >> goods;
           // giver.val = neighb; giver.goods = goods;
            receiver.val = i; receiver.goods = goods;
           // AL_rec[i].push_back(giver);
            AL_giv[neighb].push_back(receiver);
            goods_received[i] += goods;
        }
    }

    //tests
    //
    
    /*for (int i = 1; i <= N; i++){
        cout << i << " : ";
        cout << "min: " << min_goods[i];
        cout << " rec: " << goods_received[i] << endl;
    }*/



    // Incunabula collapses
    q.push(1);
    visited[1] = 1;
    int dead = 1;

    int collapsed;
    while (!q.empty()){
        collapsed = q.front(); q.pop();
        visited[collapsed] = 1;
            for (auto it = AL_giv[collapsed].begin(); it != AL_giv[collapsed].end(); it++){
            neighb = (*it).val;
            if (!visited[neighb]){
                goods = (*it).goods;
                goods_received[neighb] -= goods;
                if (goods_received[neighb] < min_goods[neighb]){
                    // neighbour collapses
                    q.push(neighb);
                    dead++;
                }
            }

            /*neighb = (*it).val;
          //  if (!visited[neighb]){
            goods = (*it).goods;
            goods_received[neighb] -= goods;
            if (goods_received[neighb] < min_goods[neighb]){
                // neighbour collapses
                q.push(neighb);
                dead++;
            }
           // }*/
        // second try
           /* neighb = (*it).val;
            goods = (*it).goods;
            if (goods_received[neighb] >= min_goods[neighb]){
                goods_received[neighb] -= goods;
                if (goods_received[neighb] < min_goods[neighb]){
                    q.push(neighb);
                    dead++;
                }
            }*/
        // third try

        }
    }

    cout << N - dead << '\n';
    
    return 0;
}


