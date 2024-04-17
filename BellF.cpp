#include <iostream>
using namespace std;

#define max 100
#define infinity 9999
#define nil -1
#define true 1
#define false 0

int n; // Number of vertices in graph
int adj[max][max]; // Adjacency matrix to represent the graph
int predecessor[max]; // Array to store predecessors in shortest path
int pathlength[max]; // Array to store shortest path lengths
int ispresent_in_queue[max]; // Array to track if a vertex is present in the queue
int queue[max]; // Queue for BFS traversal
int front, rear; // Front and rear pointers for the queue

// Function prototypes
int create_graph();
int bellman_ford(int s);
void initialize_queue();
void insert_queue(int added_item);
int is_empty_queue();
int delete_queue();
int find_path(int s, int v);

int main() {
    int s, flag, v;
    create_graph();
    cout << "Enter the source vertex: ";
    cin >> s;
    flag = bellman_ford(s);
    if (flag == -1) {
        cout << "Error: negative cycle in graph" << endl;
        exit(1);
    }
    while (1) {
        cout << "Enter destination vertex (-1 to exit): ";
        cin >> v;
        if (v == -1)
            break;
        if ((v < 0) || (v >= n))
            cout << "This vertex does not exist" << endl;
        else if (v == s)
            cout << "Source and destination vertices are the same" << endl;
        else if (pathlength[v] == infinity)
            cout << "There is no path from source to destination vertex" << endl;
        else
            find_path(s, v);
    }
    return 0;
}

// Function to create a graph
int create_graph() {
    int max_e, i, origin, destination, wt, j;
    cout << "Enter number of vertices in the graph: ";
    cin >> n;
    max_e = n * (n - 1);
    for (i = 0; i < max_e; i++) {
        cout << "Enter the origin and destination of edge " << i+1 << ": ";
        cin >> origin >> destination;
        cout << "Enter the weight of the edge: ";
        cin >> wt;
        adj[origin][destination] = wt;
    }
    // Print the adjacency matrix
    cout << "Adjacency matrix of the graph:" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << adj[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}

// Bellman-Ford algorithm for finding shortest paths
int bellman_ford(int s) {
    int k = 0, i, current;
    // Initialize path lengths, predecessors, and queue presence flags
    for (i = 0; i < n; i++) {
        predecessor[i] = nil;
        pathlength[i] = infinity;
        ispresent_in_queue[i] = false;
    }
    initialize_queue();
    // Initialize source vertex
    pathlength[s] = 0;
    insert_queue(s);
    ispresent_in_queue[s] = true;
    while (!is_empty_queue()) {
        current = delete_queue();
        ispresent_in_queue[current] = false;
        if (s == current)
            k++;
        if (k >= n)
            return -1; // Negative cycle reachable from source vertex
        // Relax edges
        for (i = 0; i < n; i++) {
            if (adj[current][i] != 0) {
                if (pathlength[i] > adj[current][i] + pathlength[current]) {
                    pathlength[i] = adj[current][i] + pathlength[current];
                    predecessor[i] = current;
                    if (!ispresent_in_queue[i]) {
                        insert_queue(i);
                        ispresent_in_queue[i] = true;
                    }
                }
            }
        }
    }
    return 1;
}

// Initialize queue
void initialize_queue() {
    int i;
    for (i = 0; i < max; i++) {
        queue[i] = 0;
    }
    rear = -1;
    front = -1;
}

// Insert an item into the queue
void insert_queue(int added_item) {
    if (rear == max - 1) {
        cout << "Queue is overflow" << endl;
        exit(1);
    } else {
        if (front == -1)
            front = 0;
        rear += 1;
        queue[rear] = added_item;
    }
}

// Check if the queue is empty
int is_empty_queue() {
    if ((front == -1) || (front > rear))
        return 1;
    else
        return 0;
}

// Delete an item from the queue
int delete_queue() {
    int d;
    if (is_empty_queue()) {
        cout << "Queue is underflow" << endl;
        exit(1);
    } else {
        d = queue[front];
        front = front + 1;
    }
    return d;
}

// Find the shortest path from source to destination
int find_path(int s, int v) {
    int i, u;
    int path[max];
    int shortdist = 0;
    int count = 0;
    // Trace back the path
    while (v != s) {
        count++;
        path[count] = v;
        u = predecessor[v];
        shortdist += adj[u][v];
        v = u;
    }
    count++;
    path[count] = s;
    cout << "Shortest path is: ";
    for (i = count; i >= 1; i--) {
        cout << path[i] << " ";
    }
    cout << endl;
    cout << "Shortest distance is: " << shortdist << endl;
    return 0;
}

/*
Output :-

Yash@Yash-HP-Laptop-15s-fq5xxx:~/DAA_Lab$ g++ belmon_ford_17.cpp
Yash@Yash-HP-Laptop-15s-fq5xxx:~/DAA_Lab$ ./a.out
enter vertices of graph
3
enter the origin and destination of graph
0
0
enter the weight
6
enter the origin and destination of graph
0
1
enter the weight
7
enter the origin and destination of graph
0
2
enter the weight
10
enter the origin and destination of graph
1
1
enter the weight
1
enter the origin and destination of graph
1
2
enter the weight
-11
enter the origin and destination of graph
2
0
enter the weight
5
6  7  10  
0  1  -11  
5  0  0  
enter the source vertex
0
enter destination vertex : -1 for exit
2
shortest path is
012
shortest distance is = -4
enter destination vertex : -1 for exit
-1
Yash@Yash-HP-Laptop-15s-fq5xxx:~/DAA_Lab$


*/