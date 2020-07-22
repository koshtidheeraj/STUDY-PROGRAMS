    // input array is input[30]
    // output array is output[30]

    int main() {

        int input[30]; 
        int output[30];
        int output_ind = 0;
        int even_odd_traversal = 0; // 0 for even , 1 for odd
        int i = 0, j = 28;
        if (input[i] < input[j])
            even_odd_traversal = 0;
        else
            even_odd_traversal = 1;
        while ( i < 30 || j > 0) {
            if (even_odd_traversal == 0) {
                // this while loop goes on till number at even index is less than current 
                // odd index number
                while(input[i] < input[j]) { 
                    output[output_ind] = input[i];
                    i += 2;
                    output_ind++;
                }
                even_odd_traversal = 1;
            } else {
                // this while loop goes on till number at odd index is less than current 
                // even index number
                while(input[j] < input[i]) {
                    output[output_ind] = input[j];
                    j-=2;
                    output_ind++;
                }
                even_odd_traversal = 0;
            }
        }
        return 0;
    }