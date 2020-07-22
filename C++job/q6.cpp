// use phone number column to find top 10 customers then 

int main () {

    float phone_number[100]; // phone number array
    char* names[100]; // names array
    // We use phone number to count top 10 customers then we will get corresponsing name
    map<float,int> phone_vs_count;
    set<int> phone_nums;

    for (int i = 0; i < 100 ; i++) {  // O(n)
        bool success = phone_nums.insert(phone_number[i]);
        if (success) {
            // success means this number is not previously searched
            // so add it to map with count 1
            phone_vs_count->insert(phone_number[i],1);
        } else {
            // set insert failure means this number already searched so increase
            // map count against that number
            phone_vs_count[phone_number[i]] = phone_vs_count[phone_number[i]]++
        }
    }

    // Now create multimap of count vs phone_number
    multimap<int, float> count_vs_phone;
    iterator it = phone_vs_count::iterator();
    while(it->next != nullptr) {
        count_vs_phone.insert(it->second, it->first);
    }

    //  create priority queue of descendin order and then insert count values 
    // from map and then take out first 10 counts.
    priority_queue<int> count_queue;
    iterator it = phone_vs_count::iterator();
    while(it->next != nullptr) {
        count_queue.insert(it->second);
    }

    // get top 10 elements from count_queue and search corresponding elements in 
    // count_vs_phone multimap
    for (i = 0 ; i< 10; i++) {
        ele = count_queue -> get();
        cout << "top element is" << count_vs_phone[ele];
    } 
}