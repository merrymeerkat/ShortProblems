#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <map>

using namespace std;

// struct to store infection level and order of arrival of kittens
struct Node{
    int infectionLevel;
    int order;
};

// Kittens with higher infection level have higher priority.
// If two have the same infection level, then the 
// one who arrived first (lower order value) has priority.
class Compare{
    public:
        // not sure if need to pass by ref
        bool operator() (const Node &a, const Node &b) const {
            if (a.infectionLevel == b.infectionLevel){
                return a.order < b.order;
            }
            else
                return a.infectionLevel > b.infectionLevel;
        }
};


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // Maps (one maps cat name to infection level and order, 
    // the other does the opposite)
    map <string, Node> mapKeyIsName;
    map <Node, string, Compare> mapKeyIsNode;

    Node node, new_node;

    int N, command, infLevel;
    string catName;

    cin >> N;

    int ordr = 0;
    int current_il, current_order;

    while(N--){
        cin  >> command;
        switch(command){
            // Arrive at clinic
            case(0):
                cin >> catName >> infLevel;
                node.infectionLevel = infLevel; node.order = ordr;

                // add to maps 1 and 2
                mapKeyIsName[catName] = node;
                mapKeyIsNode[node] = catName;
                ordr++;
                
                break;

            // Update infection level
            case(1):
                cin >> catName >> infLevel;
                
                node = mapKeyIsName[catName];
                current_il = node.infectionLevel;

                // New node (updated infection level)
                new_node.order = node.order;
                new_node.infectionLevel = current_il + infLevel;
                
                // Update map 1
                mapKeyIsName[catName] = new_node;

                // Update map 2
                mapKeyIsNode.erase(node); // this erasing is optional
                mapKeyIsNode[new_node] = catName;
                break;
              
            // Treat kitty
            case(2):
                // they don't always treat the highest priority first (how rude...)
                cin >> catName;

                node = mapKeyIsName[catName];

                // Erase from both maps
                // (it is not absolutely necessary to remove from mapName,
                // but it's nice to save some memory)
                mapKeyIsName.erase(catName);
                mapKeyIsNode.erase(node);
                break; 
            
            // See first priority
            default:
                if(mapKeyIsNode.size() == 0)
                    cout << "The clinic is empty\n";
                else{
                    cout << mapKeyIsNode.begin() -> second << '\n';
                }    
        }  
    }
	return 0;
}
