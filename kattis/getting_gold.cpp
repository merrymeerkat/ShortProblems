#include <iostream>

using namespace std;

struct Pos{
    int r;
    int c;
};

int W, H;
int dc[4] = {-1, 0, 1, 0};
int dr[4] = {0,1,0,-1};
int counter = 0;
int nr, nc;
string map[50];


void flood_fill(int r, int c){

    //bool safe = true;
    cout << "we are at r " << r << ", c " << c << endl;

    //cout << "pos: r " << r << ", c " << c << endl;
    if (map[r][c] == 'G'){
        cout <<  "gold!" << endl;
        counter++;
    }

    // mark as visited (check)
    map[r][c] = '#';

    // if we sense a trap, we stop
    for (int i = 0; i < 4; i++){
        
        nr = r + dr[i]; nc = c + dc[i];
        cout << "r " << r << ", c " << c; 
        cout << "peeking at r " << nr << ", c " << nc << endl;
        if ((nr < 0) || (nc < 0) || (nr >= H) || (nc >= W))
            continue;
        
        if (map[nr][nc] == 'T'){
            cout << "trap!\n";
            return;
        }
    }

    /*if (((r + 1 < H) && map[r+1][c] == 'T') || ((c+1 < W) && map[r][c+1] == 'T') || ((r - 1 >= 0) && map[r-1][c] == 'T') || ((c - 1 >= 0 && map[r][c-1] == 'T'))){
        return;
    } */

    for (int i = 0; i < 4; i++){
            nr = r + dr[i]; nc = c + dc[i];
            
            cout << "r " << r << ", c " << c; 
            
            cout << "peeking at r " << nr << ", c " << nc << endl;

            if ((nr < 0) || (nc < 0) || (nr >= H) || (nc >= W))
                continue;

            if (map[nr][nc] != '#'){
                cout << "lets flood fill at r " << nr << ", c " << nc << endl;
                flood_fill(nr, nc);
            }
    }
}


int main(){
    cin >> W >> H;

    //string map[H];

    for (int r = 0; r < H; r++){
        cin >> map[r];
    }

    // Find player
    Pos player_pos;
    for (int r = 0; r < H; ++r){
        for (int c = 0; c < W; ++c){
            if (map[r][c] == 'P'){
                player_pos.r = r;
                player_pos.c = c;
            }
        }
    }

    flood_fill(player_pos.r, player_pos.c);

    cout << counter << '\n';
    
    return 0;

}
