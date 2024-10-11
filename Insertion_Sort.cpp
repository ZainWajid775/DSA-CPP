#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n) 
{
    int key , j;

    for(int i = 1 ; i <= n-1 ; i++)
    {
        key = arr[i];       //Element to be inserted
        j = i-1;

        //While the intger being compared is greater than the previous, move the integers to the right and insert the one being compared at its correct position
        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key; 
    }
}

void print(int arr[], int size) 
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {5,4,3,2,1};
    insertion_sort(arr , 5);
    print(arr , 5);
}

