/*Write a function template for selection sort that inputs, sorts and outputs an
integer array and a float array.*/

#include<iostream>
using namespace std;

template<class T>
void sort(T *arr, int n)
{
    for(int i = 0; i<n; i++)
    {
        for(int j = i; j<n; j++)
        {
            if(arr[j]<arr[i])
            {
                swap(arr[j], arr[i]);
            }
        }
    }
}
template <class T>
void Display(T *arr, int n)
{
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int n = 5;
    int arr1[n] = {5,6,4,78,1};
    float arr2[n] = {6.5,2.3,4.8,78,1.9};
    sort(arr1, n);
    sort(arr2, n);

    Display(arr1, n);
    cout<<endl;
    Display(arr2, n);
    return 0;
}