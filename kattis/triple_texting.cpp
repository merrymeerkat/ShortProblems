#include <iostream>
#include <string>

using namespace std;

int main(){

    string str; cin >> str;

    int size = str.size()/3;

    string str1, str2, str3;
    str1 = str.substr(0, size);
    str2 = str.substr(size, size);
    str3 = str.substr(size*2, size);

    if (str1.compare(str2) == 0)
        cout << str1 << '\n';

    else if (str1.compare(str3) == 0)
        cout << str1 << '\n';

    else
        cout << str2 << '\n';

    return 0;
}
