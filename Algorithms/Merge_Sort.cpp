#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of the left subarray
    int n2 = right - mid;    // Size of the right subarray

    // Create temporary arrays
    int leftArr[n1], rightArr[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) 
    {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) 
    {
        rightArr[i] = arr[mid + 1 + i];
    }

    // Merge the two arrays back into arr[]
    //I is index of left array and J is of right array
    //K is the current index of arr
    //Increment the array from which element is added and then increment k
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) 
    {
        if (leftArr[i] <= rightArr[j]) 
        {
            arr[k] = leftArr[i];
            i++;
        } 
        else 
        {
            arr[k] = rightArr[j];
            j++;
        }

        k++;
    }

    // Copy any remaining elements of leftArr[]
    while (i < n1) 
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy any remaining elements of rightArr[]
    while (j < n2) 
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Recursive Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) 
    {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to print the array
void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size;

    // Input the size of the array
    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];

    // Input the array elements
    cout << "Enter the elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Perform Merge Sort
    mergeSort(arr, 0, size - 1);

    // Output the sorted array
    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}
