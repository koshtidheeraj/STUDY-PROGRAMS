int main(){

    // firstly sort the array with divide and conqure algorithm 
    // which will be of complexity O(nlogn)
    // and then traverse array once to find duplicate element which is of O(n)
    // so total time comlexity is O(n)+O(nlogn) = O(nLogn)

    int input[50];
    sort(input); // Here input is now sorted in O(nLogn)
    for (int i= 0; i <49; i++) {
        if(input[i] == input[i+1]) {
            break;
        }
    }
    cout << "duplicate value is = " << input[i] << endl;
}