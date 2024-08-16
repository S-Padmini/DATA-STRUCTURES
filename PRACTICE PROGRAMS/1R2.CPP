#include <iostream>
using namespace std;

int find_Occurance(int arr[], int n, int key) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            count++;
        }
    }
    return count;
}

int main() {
    cout<<"  Program to search the number of occurrences of a given element in an array";
    int arr[] = {32, 18, 75, 4, 34, 56, 4, 2};

    int key = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    int occurs=find_Occurance(arr,n,key);
    cout<<" \n\n Number of occurrences of " <<key<<" in the array: "<<occurs<< endl;
}
