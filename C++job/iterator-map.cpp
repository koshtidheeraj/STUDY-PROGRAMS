#include <iostream>
#include <map>
#include <string>
// #include <iterator> 

using namespace std;
int main() {
    map<std::string, int> map_inst;
    map_inst.insert(pair<std::string, int>("dheeraj",1));
    map_inst.insert(pair<std::string, int>("shweta",2));
    map_inst.insert(pair<std::string, int>("dheeraj",3));
    map_inst[string("dheeraj")] = 4;
    for(map<std::string, int>::iterator it = map_inst.begin(); it != map_inst.end(); it++) {
        cout << "first:" << it->first << " second:" << it->second << endl;
    }
    return 1;
}