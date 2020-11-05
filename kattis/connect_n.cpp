#include <iostream>

using namespace std;

int counter = 1;

int X, Y, N;
string board[110];

char col;
void DFS_col(int r, int c){
    
    // current colour
    col = board[r][c];   

    //cout << "counter is " << counter << endl;
    // check for win
    if (counter == N) return;

    //check bounds
    if (r + 1 >= X){
       return;
    } 
    
    //cout << "col is " << col << endl;

    if ((board[r+1][c] != 'O') && (board[r+1][c] == col))
        counter++;
    else
        counter = 1; // resets counter

     DFS_col(r+1, c);
}

void DFS_row(int r, int c){
    // current colour
    col = board[r][c];   

    //cout << "counter is " << counter << endl;
    // check for win
    if (counter == N) return;

    //check bounds
    if (c + 1 >= Y){
       return;
    } 
    
    if ((board[r][c+1] != 'O') && (board[r][c+1] == col))
        counter++;
    else
        counter = 1; // resets counter

     DFS_row(r, c+1);
}

// southwest (SW) diagonals
void DFS_SW(int r, int c){
    col = board[r][c];
    
    if (counter == N) return;

    // check bounds
    if ((c - 1 < 0) || (r + 1 >= X)) return;

    if ((board[r + 1][c - 1] != 'O') && (board[r+1][c-1] == col))
        counter++;
    else
        counter = 1; // resets counter

    DFS_SW(r + 1, c- 1);
}

// southeast (SE) diagonals
void DFS_SE(int r, int c){
    col = board[r][c];
    
    if (counter == N) return;

    // check bounds
    if ((r + 1 >= X) || (c + 1 >= Y)) return;

    if ((board[r + 1][c + 1] != 'O') && (board[r+1][c+1] == col))
        counter++;
    else
        counter = 1; // resets counter

    DFS_SE(r + 1, c+ 1);
}

int main(){

    cin >> X >> Y >> N;
    string colour;

    // Building board
    char space;
    for (int r = 0; r < X; r++){
        for (int c = 0; c < Y; c++){
            cin >> board[r][c];
        }
    }

    // Searching for wins

    // column
    for (int c = 0; c < Y; c++){
        //cout << "COLUMN " << c << endl;
        counter = 1;
        DFS_col(0, c);
        if (counter == N){
            colour = (col == 'R') ? "RED" : "BLUE";
            cout << colour << " WINS\n";
            return 0;    
        }
    }
    // row
    for (int r = 0; r < X; r++){
        counter = 1;
        DFS_row(r, 0);
         if (counter == N){
            colour = (col == 'R') ? "RED" : "BLUE";
            cout << colour << " WINS\n";
            return 0;
        }
    }

    // southwest diagonals
    // from top row
    for (int c = 0; c < Y; c++){
        counter = 1;
        DFS_SW(0, c);
        if (counter == N){
            colour = (col == 'R') ? "RED" : "BLUE";
            cout << colour << " WINS\n";
            return 0;
        }
    }
    // from rightmost column
    for (int r = 1; r < X; r++){
        counter = 1;
        DFS_SW(r, Y-1);
        if (counter == N){
            colour = (col == 'R') ? "RED" : "BLUE";
            cout << colour << " WINS\n";
            return 0;
        }
    }

    // southeast diagonals
    // from leftmost column
    for (int r = 0; r < X; r++){
        counter = 1;
        DFS_SE(r, 0);
        if (counter == N){
            colour = (col == 'R') ? "RED" : "BLUE";
            cout << colour << " WINS\n";
            return 0;
        }
    }
    // from top row
    for (int c = 0; c < Y; c++){
        counter = 1;
        DFS_SE(0, c);
        if (counter == N){
            colour = (col == 'R') ? "RED" : "BLUE";
            cout << colour << " WINS\n";
            return 0;
        }
    }

    cout << "NONE\n";
    return 0;
}
