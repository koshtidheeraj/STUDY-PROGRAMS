// https://www.geeksforgeeks.org/proxy-design-pattern/
// https://refactoring.guru/design-patterns/proxy

// When we have big object and operating on that object is costly then we use proxy
// before real object and delegate operation to real object in case proxy is not able to
// handle it or it is utmost necessary to invoke operation in real object.

#include <iostream>
#include <vector>
using namespace std;

class internet {
    public:
        void invokeInternet() {cout<<"actual internet invoked"<<endl;}
};  // this is the big object on which invoking an operation is costly so we will
    // create instance of this object in proxy calss and call this function if proxy
    // class is not able to handle request.

class internetProxy {
    public:
    internet net;
    vector<char*> blockedsites;
    void addblockedwebsite(char* site) {
        blockedsites.push_back(site);
    }
    void getWebsite(char* site) {
        for (char* eachsite : blockedsites) {
            if (eachsite != site) {
                net.invokeInternet(); // proxy will invoke costly object in case website
                                      // is not blocked
            }            
        }
    }
};
int main() {
    internetProxy proxy;
    proxy.addblockedwebsite("google");
    proxy.addblockedwebsite("rediffmail");
    proxy.getWebsite("yahoo");
    return 1;
}