#include <iostream>
using namespace std;

void bubble_sort(int arr[] , int n)
{
    bool swap;
    
    for(int i = 0 ; i < n-1 ; i++)
    {
        for(int j = 0 ; j < n-i-1 ; j++)
        {
            swap = false;
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swap = true;
            }
        }
        if(!swap)
        {
            break;
        }
    }

}

int main()
{
    int array[] = {5,4,3,2,1};
    int size = sizeof(array)/sizeof(array[0]);
    cout << size << endl;
    bubble_sort(array , size);
    for(int i = 0 ; i < 5 ; i++)
    {
        cout << array[i];
    }
}