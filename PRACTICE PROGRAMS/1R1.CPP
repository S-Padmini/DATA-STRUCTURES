#include<iostream>
using namespace std;
int main()
{
    int arr[10],n;
    cout<<"\n\nProgram to count the number of unique elements in an array ";
    cout<<"\n\nEnter the no of elements of the array:";
    cin>>n;
    cout<<"\n\nEnter the elements of the array:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int count=1;
    for(int i=1;i<n;i++)
    {
        int j=0;
        for(j=0;j<i;j++)
            if(arr[i]==arr[j])
               break;
        if(i==j)
            count++;
    }
    cout<<"The no of unique elements in the array:"<<count;
    return 0;
}
