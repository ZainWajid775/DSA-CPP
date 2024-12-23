#include <iostream>
using namespace std;

void insertion_sort(int arr[] , int size)
{
    //Outer loop starts from one as it has to compare ith index with ones below it
    for(int i = 1 ; i < size ; i++)
    {
        //Store ith index
        int key = arr[i];

        //J runs backwards comparing indexes below key
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        //Insert value at its correct index in that loop
        arr[j + 1] = key;

    }
}

void display(int arr[] , int size)
{
    cout << "Array : ";
    for(int i = 0 ; i < size ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {10,9,8,7,6,5,4,3,2,1,0};
    int size = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, size);
    display(arr , size);
}