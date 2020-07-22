#include <any>
#include <map>

int json_merge(map<pair<string,std::any>> a, map<pair<string,std::any>> b) {
// b is getting merged to a

    for (auto it = b.begin(); it != b.end(); it++) {
        string key = it.first;
       
        if (a[key] != null) {
  // Check if key is map
  if (string::endswith(key,"map")) {
     json_merge(std::any_cast<map<string,std::any>> a[key],
   std::any_cast<map<string,std::any>> b[key]);
           } else {
  // key's value is integer now
              a[key] = std::any_cast<int>b[key];
           }
        } else {
            a.insert(pair<string,std::any>>(key, b[key]));
        }
        }
    }
}

main() {
map<pair<string,std::any>> a;
map<pair<string,std::any>> b;
json_merge(a,b);
}