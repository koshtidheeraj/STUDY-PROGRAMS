#include <iostream>
void quicksort(int input[],int start, int end) {
    if (start != end) {
        int i = start-1,j=start, pivot=end;
        while(j<pivot) {
            if(input[j] < pivot) {
                i++;
                int temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
            j++;
        }
        i++;
        int temp = input[i];
        input[i] = input[j];
        input[j] = temp;
        quicksort(input,start,i);
        quicksort(input,i+1,end);
    }
}
int main() {
    input int[50];
    quicksort(input, 0, sizeof(input)-1);
}