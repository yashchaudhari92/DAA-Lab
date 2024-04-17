#include<iostream>
using namespace std;

#define max 100

// Function prototypes
void merge_sort(int arr[], int low, int up);
void merge(int arr[], int temp[], int low1, int up1, int low2, int up2);
void copy(int arr[], int temp[], int low, int up);

int main() {
    int i, n, arr[max];
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter array elements: " << endl;
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    merge_sort(arr, 0, n - 1);
    cout << "Sorted list: " << endl;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}

// Merge sort function
void merge_sort(int arr[], int low, int up) {
    int mid;
    int temp[max];
    if (low < up) {
        mid = (low + up) / 2;
        merge_sort(arr, low, mid); // Sort left sublist
        merge_sort(arr, mid + 1, up); // Sort right sublist
        merge(arr, temp, low, mid, mid + 1, up); // Merge the sorted sublists
        copy(arr, temp, low, up); // Copy the merged sublist back to the original array
    }
}

// Merge function to merge two sorted sublists
void merge(int arr[], int temp[], int low1, int up1, int low2, int up2) {
    int i = low1;
    int j = low2;
    int k = low1;
    // Merge elements from both sublists into temp array
    while ((i <= up1) && (j <= up2)) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    // Copy any remaining elements from first sublist
    while (i <= up1)
        temp[k++] = arr[i++];
    // Copy any remaining elements from second sublist
    while (j <= up2)
        temp[k++] = arr[j++];
}

// Function to copy elements from temp array back to original array
void copy(int arr[], int temp[], int low, int up) {
    int i;
    for (i = low; i <= up; i++)
        arr[i] = temp[i];
}


/*

Output :-

Yash@Yash-HP-Laptop-15s-fq5xxx:~/DAA_Lab$ g++ Merged_Sort_17.cpp
Yash@Yash-HP-Laptop-15s-fq5xxx:~/DAA_Lab$ ./a.out
enter the size of array:
7
enter array elements
9
7
6
8
2
1
10
sorted list is
1 2 6 7 8 9 10
Yash@Yash-HP-Laptop-15s-fq5xxx:~/DAA_Lab$



*/