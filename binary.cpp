#include <iostream>
using namespace std;

int main() {
    int array[10], i, search;
    
    // Input array elements
    cout << "Enter array elements:" << endl;
    for (i = 0; i < 10; i++) {
        cin >> array[i];
    }
    
    cout << "Enter the element you want to search:" << endl;
    cin >> search;
    
    // Binary search algorithm
    int l = 0; // Lower bound of the search range
    int up = 9; // Upper bound of the search range
    int mid = (l + up) / 2; // Midpoint of the search range
    
    while (l <= up) {
        if (search > array[mid]) {
            l = mid + 1; // Update lower bound if the search element is greater than the middle element
        } else if (search == array[mid]) {
            cout << "Element found at index " << mid << endl; // Element found
            break;
        } else {
            up = mid - 1; // Update upper bound if the search element is less than the middle element
        }
        mid = (l + up) / 2; // Update midpoint
    }
    
    if (l > up) {
        cout << "Element not found" << endl; // Element not found
    }
    
    return 0;
}


/*

Output :-

Yash@Yash-HP-Laptop-15s-fq5xxx:~/DAA_Lab$ g++ Binary_search_17.cpp
Yash@Yash-HP-Laptop-15s-fq5xxx:~/DAA_Lab$ ./a.out
enter array elements
8
9
4
6
2
7
-2
5
10
1
enter element you want to search
10
element found
Yash@Yash-HP-Laptop-15s-fq5xxx:~/DAA_Lab$


*/