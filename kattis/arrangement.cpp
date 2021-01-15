#include <iostream>

using namespace std;

int main(){
    int rooms, teams;
    cin >> rooms >> teams;

    int num_per_room = teams / rooms;
    int num_big_rooms = teams % rooms;

    rooms -= num_big_rooms;

    while(num_big_rooms--){
        for (int i = 0; i < (num_per_room + 1); i++)
            cout << '*';
        cout << '\n';
    }
    while(rooms--){
        for (int i = 0; i < num_per_room; i++)
            cout << '*';
        cout << '\n';
    }
}
