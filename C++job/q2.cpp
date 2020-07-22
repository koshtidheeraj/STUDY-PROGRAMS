int main(){

    // firstly sort the array with divide and conqure algorithm 
    // which will be of complexity O(nlogn)
    // and then traverse array once to find pairs with given difference.
    // so total time comlexity is O(n)+O(nlogn) = O(nLogn)

    int difference = 12;
    int input[50];
    sort(input); // Here input is now sorted in O(nLogn)
    
    int prev_ind=0, next_index=0;
    while (next_index < 50) {
        if (input[next_index]-input[prev_ind] == 12) {
            cout << "pair is = " << input[prev_ind] << "," << input[next_index] << endl;
            prev_ind ++;
        } else {
            next_index++;
        }
    }   
}