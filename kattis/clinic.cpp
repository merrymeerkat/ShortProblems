#include <iostream>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

struct Node{
    long long priority;
    string name;
};

// Higher priority first. If priorities are equal, sort by name
class Compare{
    public:
        // not sure if need to pass by ref
        bool operator() (const Node &a, const Node &b) const {
            if (a.priority == b.priority){
                return (a.name).compare(b.name) < 0;
            }
            else
                return a.priority > b.priority;
        }
};

// calculate priority with reference to time = 0
long long get_priority(long long K, int entry_time, int severity){
    long long priority = (severity - (K * entry_time));
    return priority;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // Two maps: one maps (priority, name) to name, the other 
    // maps name to priority
    map <Node, string, Compare> mapKeyIsNode;
    map <string, int> mapKeyIsName;

    set <string> removed;

    int N; long long K; cin >> N >> K;

    int command, time, severity; long long priority;
    string patient_name, name; Node node;

    while (N--){
        
        cin >> command;

        switch(command){
            // Insert patient
            case(1):
                cin >> time >> patient_name >> severity;
                
                priority = get_priority(K, time, severity);
                node.priority = priority; node.name = patient_name; 

                mapKeyIsNode[node] = patient_name;
                mapKeyIsName[patient_name] = priority;
                break;
            // Treat
            case(2):
                cin >> time;
                if (mapKeyIsName.empty()){
                    cout << "doctor takes a break\n";
                }
                else{
                    name = mapKeyIsNode.begin() -> second;

                    // If patient has already left (e.g. is in "removed" set), pop and go to next
                    while (removed.find(name) != removed.end()){
                        mapKeyIsNode.erase(mapKeyIsNode.begin());
                        name = mapKeyIsNode.begin() -> second;
                    }    

                    // Pop correct patient and output his/her name
                    mapKeyIsNode.erase(mapKeyIsNode.begin());
                    mapKeyIsName.erase(name);
                    cout << name << '\n';
                }
                break;
            
            // Remove ("lazy deletion": just add name to a set of removed items)
            default:
                cin >> time >> name;
                removed.insert(name);
                // (alternatively, we can query this name's priority in MapKeyIsName,
                // then create a Node with name = name and priority = priority, and
                // delete this Node key from MapKeyIsNode, and delete the name key from MapKeyIsName.
                // These operations are also fast in map stl. The only problem is that
                // the kattis test cases (in particular, the second to last one) are
                // adapted to a "lazy deletion" method, so actual deletion may lead to wrong answer
                // for that particular test case--but this is a limitation of the design
                // of the test case, and not of the solution)
        
        }
    }
}
