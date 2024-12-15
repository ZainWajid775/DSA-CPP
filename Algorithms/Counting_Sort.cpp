#include <iostream>

using namespace std;

void count_sort(int arr[] , int size)
{

    // Find max element
    int max = arr[0];
    for(int i = 1 ; i < size ; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }

    // Initliase count array with 0
    int count[max + 1];
    for(int i = 0 ; i <= max ; i++)
    {
        count[i] = 0;
    }

    // Count the frequency of each element
    // Index in count array is the value of the element in the input array
    for(int i = 0 ; i < size ; i++)
    {
        count[arr[i]]++; 
    }

    // Calculate the prefix sum
    for(int i = 1 ; i <= max ; i++)
    {
        count[i] += count[i - 1];
    }

    // Create a temporary array to store the sorted array
    int temp_sorted[size];

    // Loop over the input array in reverse order
    for(int i = size - 1 ; i >= 0 ; i--)
    {
        temp_sorted[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements back into the original array
    for (int i = 0; i < size; i++)
    {
        arr[i] = temp_sorted[i];
    }

}

int main()
{   
    int arr[] = {10 , 9 , 8 , 7 , 6 , 5 , 4 , 3 , 2 , 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    count_sort(arr , size);

    for(int i = 0 ; i < size ; i++)
    {
        cout << arr[i] << " ";
    }
}   