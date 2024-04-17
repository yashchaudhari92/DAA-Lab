#include<iostream>
using namespace std;

// Function prototypes
void quick(int a[], int l, int up);
int partition(int a[], int l, int up);

int main() {
    int n;
    // Input the size of the array
    cout << "Enter the size of an array: " << endl;
    cin >> n;
    int arr[n];
    // Input array elements
    cout << "Enter array elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Set initial boundaries for the quicksort
    int low = 0;
    int up = n - 1;
    // Call quicksort function
    quick(arr, low, up);

    // Output sorted elements
    cout << "Sorted elements are:" << endl;
    for (int i = 0; i <= up; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// Quicksort function
void quick(int a[], int l, int up) {
    // Base case: if the lower index is greater than or equal to the upper index, return
    if (l >= up) {
        return;
    }
    // Partition the array and recursively call quicksort on the left and right sublists
    int pvtloc = partition(a, l, up);
    quick(a, l, pvtloc - 1); // Left sublist
    quick(a, pvtloc + 1, up); // Right sublist
}

// Partition function to rearrange elements around a pivot
int partition(int a[], int l, int up) {
    // Base case: if the lower index is greater than or equal to the upper index, return the lower index
    if (l >= up) {
        return l;
    }
    // Initialization
    int temp, pvt;
    int i = l + 1;
    int j = up;
    pvt = a[l]; // Choose the first element as pivot
    // Partitioning process
    while (i <= j) {
        while (a[i] < pvt) {
            i++;
        }
        while (a[j] > pvt) {
            j--;
        }
        if (i < j) {
            // Swap elements if they are out of place
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        } else {
            i++;
        }
    }
    // Swap pivot with element at position j
    temp = a[l];
    a[l] = a[j];
    a[j] = temp;
    return j; // Return the pivot's final position
}

/*

Output :-

Yash@Yash-HP-Laptop-15s-fq5xxx:~/DAA_Lab$ g++ quick_sort_17.cpp
Yash@Yash-HP-Laptop-15s-fq5xxx:~/DAA_Lab$ ./a.out
enter the size of an array
7
enter array elements
9
6
8
7
4
1
5
sorted elements are
1 4 5 6 7 8 9
Yash@Yash-HP-Laptop-15s-fq5xxx:~/DAA_Lab$


*/