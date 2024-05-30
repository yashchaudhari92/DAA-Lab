#include <iostream>
using namespace std;
#define MAX 10
#define TEMP 0
#define PERM 1
#define infinity 999
#define NIL -1
struct edge
{
  int u;
  int v;
};
int n;
int adj[MAX][MAX];
int predecessor[MAX];
int status[MAX];
int length[MAX];
void create_graph();
void maketree(int r, struct edge tree[MAX]);
int min_temp();
int main()
{
  int wt_tree = 0;
  int i, root;
  struct edge tree[MAX];
  create_graph();
  cout << "Enter root vertex : ";
  cin >> root;
  maketree(root, tree);
  cout << "Edges to be included in spanning tree are : \n ";
  for (i = 1; i <= n - 1; i++)
  {
    cout << tree[i].u << "  ";
    cout << tree[i].v;
    cout << "\n";
    wt_tree += adj[tree[i].u][tree[i].v];
  }
  cout << "Weight of spanning tree is :" << wt_tree;
  return 0;
}
void maketree(int r, struct edge tree[MAX])
{
  int current, i;
  int count = 0;
  for (i = 0; i < n; i++)
  {
    predecessor[i] = NIL;
    length[i] = infinity;
    status[i] = TEMP;
  }
  length[r] = 0;
  while (1)
  {
    current = min_temp();
    if (current == NIL)
    {
      if (count == n - 1)
        return;
      else
      {
        cout << "Graph is not connected , No spanning tree is possible \n";
        exit(1);
      }
    }
    status[current] = PERM;
    if (current != r)
    {
      count++;
      tree[count].u = predecessor[current];
      tree[count].v = current;
    }
    for (i = 0; i < n; i++)
      if (adj[current][i] > 0 && status[i] == TEMP)
        if (adj[current][i] < length[i])
        {
          predecessor[i] = current;
          length[i] = adj[current][i];
        }
  }
}
int min_temp()
{
  int i;
  int min = infinity;
  int k = -1;
  for (i = 0; i < n; i++)
  {
    if (status[i] == TEMP && length[i] < min)
    {
      min = length[i];
      k = i;
    }
  }
  return k;
}
void create_graph()
{
  int i, max_edges, origin, destin, wt;
  cout << "Enter number of vertices : ";
  cin >> n;
  max_edges = n * (n - 1) / 2;
  for (i = 1; i <= max_edges; i++)
  {
    cout << "Enter edge (-1 -1 to quit) " << i << ": ";
    cin >> origin >> destin;
    if ((origin == -1) && (destin == -1))
      break;
    cout << "Enter weight for this edge : ";
    cin >> wt;
    if (origin >= n || destin >= n || origin < 0 || destin < 0)
    {
      cout << "Invalid edge! \n";
      i--;
    }
    else
    {
      adj[origin][destin] = wt;
      adj[destin][origin] = wt;
    }
  }
}


/*

Output :

Yash@Yash-HP-Laptop-15s-fq5xxx:~$ cd Yash_Daa_Lab
Yash@Yash-HP-Laptop-15s-fq5xxx:~/Yash_Daa_Lab$ g++ prims.cpp
Yash@Yash-HP-Laptop-15s-fq5xxx:~/Yash_Daa_Lab$ ./a.out
Enter number of vertices : 4
Enter edge (-1 -1 to quit) 1: 1 0
Enter weight for this edge : 5
Enter edge (-1 -1 to quit) 2: 0 2
Enter weight for this edge : 6
Enter edge (-1 -1 to quit) 3: 1 3
Enter weight for this edge : 7
Enter edge (-1 -1 to quit) 4: 3 2
Enter weight for this edge : 8
Enter edge (-1 -1 to quit) 5: 0 3
Enter weight for this edge : 9
Enter edge (-1 -1 to quit) 6: 1 2
Enter weight for this edge : 10
Enter root vertex : 0
Edges to be included in spanning tree are :
 0  1
0  2
1  3
Yash@Yash-HP-Laptop-15s-fq5xxx:~/Yash_Daa_Lab$


*/