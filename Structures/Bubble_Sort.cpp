#include <iostream>
using namespace std;

void bubble_sort(int arr[] , int size)
{
    int iterations = 0;   

    //Outer loops runs n-1 as the comparision is done with i+1 index
    for(int i = 0 ; i < size - 1 ; i++)
    {
        bool swap = false;

        //Inner loops runs until it reaches the index i is at
        //Also -1 to account for last index
        for(int j = 0 ; j < size - i - 1 ; j++)
        {
            if(arr[j] < arr[j + 1])
            {
                //Swap the elements
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                //For improved bubble sort
                //If no swaps are performed within an iteration, array is sorted
                swap = true;
            }
        }

        if(!swap)
        {
            break;
        }

        iterations = i;
    }

    cout << "Outer Loop Iterations : " << iterations + 1 << endl;
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
    int arr[] = {5,4,3,2,1};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr , size); 
    display(arr , size);
}