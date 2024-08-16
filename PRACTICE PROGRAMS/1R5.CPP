

#include <iostream>
using namespace std;
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
int minimum_sum_product(int a[], int n) {
    bubbleSort(a, n);
    int sum = 0;
    for (int i = 0; i < n / 2; ++i) {
        sum += a[i] * a[n - i - 1];
    }
    return sum;
}
int main() {
    int a[10],n;
    cout<<"Enter the no of elements of the array:";
    cin>>n;
    cout<<"Enter the elements of the array:";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int sum = minimum_sum_product(a, n);
    cout << "Minimum sum of the product of consecutive pair elements: " << sum << endl;
    cout << "Sorted a[] for minimum sum: ";
    for (int i = 0; i < n / 2; ++i) {
        if (i != 0) cout << ", ";
        cout << a[n - i - 1] << ", " << a[i];
    }
    return 0;
}
