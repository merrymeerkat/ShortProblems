#include <iostream>
 #include <algorithm>

 using namespace std;

 int main(){

     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

     int A, B, C; cin >> A >> B >> C;

     int start[3], end[3];

     for (int i = 0; i < 3; i++){
         cin >> start[i] >> end[i];
     }

     int min = *min_element(start, start + 3); int max = *max_element(end,       end + 3);

     int truck_counter; int total = 0;

     for (int i = min + 1; i <= max; i++){

         truck_counter = 0;
         if (i > start[0] && i <= end[0]){
             truck_counter++;
         }

         if (i > start[1] && i <= end[1]){
             truck_counter++;
         }

         if (i > start[2] && i <= end[2]){
             truck_counter++;
         }

         switch(truck_counter){
             case(1):
                 truck_counter *= A;
                 break;
             case(2):
                 truck_counter *= B;
                 break;
             case(3):
                 truck_counter *= C;
                 break;
         }

         total += truck_counter;

    }

    cout << total << '\n';

}
