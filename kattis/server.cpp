#include <iostream>
#include <queue>

using namespace std;

int main(){

   int n, T; cin >> n >> T;

   int t;
   queue <int> tasks;
   while(n--){
       cin >> t;
       tasks.push(t);
   }

   int curr;
   int counter = 0;
   while (T > 0){
        curr = tasks.front();
        tasks.pop();
        T -= curr;
        counter++;
        if (T < 0)
            counter--;
   }

   cout << counter << '\n';

   return 0;
}
