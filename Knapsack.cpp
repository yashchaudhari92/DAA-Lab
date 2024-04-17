#include<iostream>
using namespace std;

// Function to solve the knapsack problem
void knapsack(int n, float weight[], float profit[], float capacity);

int main() {
    float weight[20], profit[20], capacity;
    int num, i, j;
    float ratio[20], temp;

    // Input the number of objects
    cout << "Enter the number of objects: ";
    cin >> num;

    // Input the weights and profits of each object
    cout << "Enter the weights and profits of each object:" << endl;
    for (i = 0; i < num; i++) {
        cin >> weight[i] >> profit[i];
    }

    // Input the capacity of the knapsack
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    // Calculate the profit-to-weight ratio for each object
    for (i = 0; i < num; i++) {
        ratio[i] = profit[i] / weight[i];
    }

    // Sort the objects based on their profit-to-weight ratio in non-increasing order
    for (i = 0; i < num; i++) {
        for (j = i + 1; j < num; j++) {
            if (ratio[i] < ratio[j]) {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    // Call the knapsack function to find the optimal solution
    knapsack(num, weight, profit, capacity);
    return 0;
}

// Function to solve the knapsack problem
void knapsack(int n, float weight[], float profit[], float capacity) {
    float x[20], tp = 0;
    int i, j, u;
    u = capacity;

    // Initialize the solution vector x to all zeros
    for (i = 0; i < n; i++) {
        x[i] = 0.0;
    }

    // Greedily fill the knapsack
    for (i = 0; i < n; i++) {
        if (weight[i] > u)
            break;
        else {
            x[i] = 1.0;
            tp = tp + profit[i];
            u = u - weight[i];
        }
    }

    // Fill the knapsack partially with the next object if there is remaining capacity
    if (i < n) {
        x[i] = u / weight[i];
    }

    // Calculate the total profit and print the solution vector
    tp = tp + (x[i] * profit[i]);
    cout << "The result vector is = ";
    for (i = 0; i < n; i++)
        cout << x[i] << "  ,  ";
    cout << endl << "Maximum profit is = " << tp << endl;
}

/*

Output :- 

Yash@Yash-HP-Laptop-15s-fq5xxx:~/DAA_Lab$ g++ knapsack_17.cpp
Yash@Yash-HP-Laptop-15s-fq5xxx:~/DAA_Lab$ ./a.out
enter the number of objects
3
enter the weights and profits of each object
18 30
15 21
10 18
enter the capacity of knapsack
20
the result vector is = 1  ,  0.555556  ,  0  ,  
maximum profit is = 34.6667
Yash@Yash-HP-Laptop-15s-fq5xxx:~/DAA_Lab$


*/