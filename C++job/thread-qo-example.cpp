#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

class base_parser{
public:
    
    base_parser(pubsub* ps) {
        domnode* root;
        pubsub_inst = ps;
        promise<domnode> p;
    }

    virtual void start_parse() = 0;
    virtual void  getRequest(style_id sid, promise<domnode>& dp) = 0;
protected:
    domnode *root;
    pubsub *pubsub_inst;    
};

class style_parser: public base_parser{
public:
    style_parser(pubsub* ps): base_parser(ps) {
        ps->register(*this)
    }
       
    void getRequest(style_id sid, promise<domnode>& dp) {
        // search sid in root
        dp->set_value(domnode_of_sid);
    }
};
class document_parser: public base_parser{
    document_parser(pubsub* ps): base_parser(ps) {
        ps->register(*this)
    }

    void start_parse() {
        // document parser start parser and it gets style Id
        // Now it wants domnode of that
        domnode* = pubsub->get_object_of_style();
        domnode(sid, dp);
        future<domnode> f = dp->get_future();
        f.get(); // this will wait till dp is set domnode in style_parser::getrequest
    }
       
    void getRequest(style_id sid, promise<domnode>& dp) {
        // search sid in root
        dp->set_value(domnode_of_sid);
    }
};
int main () {
    PublisherSubscriber pubsub;
    style_parser s_parser(&pubsub);
    document_parser d_parser(&pubsub);
    std::thread t1(s_parser.start_parse);
    std::thread t2(d_parser.start_parse);
    t1.join();
    t2.join();
    return 0;
}