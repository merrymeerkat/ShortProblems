#include <iostream>
#include <vector>

using namespace std;

int main(){

    int k;
    int N; cin >> N;
    for (int j = 1; j <= N; j++){
        vector <int> students;
        int size = 1; int counter = 0;
        int stu;
        cin >> k;
        cout << "TEST CASE " << j << endl;
        cin >> stu; students.push_back(stu);
        for (int i = 0; i < 19; i++){
            cin >> stu;
            cout << "stu is " << stu << endl;
            for (int pos = students.size()-1; pos >= 0; pos--){
                if (stu > students[pos]){
                    cout << "inserting " << stu << " in pos " << pos << endl;
                    students.insert(students.begin() + pos, stu);
                   break;
                }
                else{
                    cout << "incr counter\n";
                    counter++;
                }
            }
        }
        cout << endl << " oi " << endl;
        for (auto c : students)
            cout << c << " ";
        cout << endl;
        cout << j << " " << counter << '\n';
    }
}
