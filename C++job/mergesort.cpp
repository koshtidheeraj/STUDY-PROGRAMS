#include <iostream>

using namespace std;

void merge(int* input,  int l, int mid, int h) {
    // create temporary copy of 2 arrays
    left_part int[mid-l];
    for (int i =0; i< (mid-l); i++) {
        left_part[i] = input[l+i];
    }
    right_part int[h-(mid+1)];
    for (int i =0; i< (h-(mid+1)); i++) {
        right_part[i] = input[mid+1+i];
    }
    int i=0,j=0,k = l;
    while (i < sizeof(left_part) && j < sizeof(right_part))
    {
        if(left_part[j] < right_part[j]) {
            input[k++] = left_part[j++];
        } else {
           input[k++] = right_part[j++]; 
        }
    }
    
}

void mergesort(int* input, int l, int h) {
    if(l < h) {
        int mid = (l+h)/2;
        mergesort(input, l,mid);
        mergesort(input, mid+1,h);
        merge(input, l, mid, h);
    }
}

int main() {
    int input[] = {9,8,7,6,5,4,3,2,1};
    mergesort(input, 0, (sizeof(input)/sizeof(input[0]))-1);
}

