//Quick Sort
#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];		//Pivot Element
    int i = low - 1;			//index of smaller element
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) 
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);	//place pivot in correct position
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        //recursively sort element before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    quickSort(arr, 0, n - 1);
    
    cout << "Sorted array using Quick Sort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}

