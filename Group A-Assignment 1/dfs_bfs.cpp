/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int data;
    vector<TreeNode *> children;
};

void printDFS(TreeNode *root, bool *visited)
{
    if (root == nullptr || visited[root->data])
    {
        return;
    }

    cout << root->data << " ";
    visited[root->data] = true;

    for (auto child : root->children)
    {
        printDFS(child, visited);
    }
}

void printBFS(TreeNode *root, bool *visited)
{
    queue<TreeNode *> pendingVertices;
    pendingVertices.push(root);
    visited[root->data] = true;

    while (!pendingVertices.empty())
    {
        auto currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout << currentVertex->data << " ";

        for (auto child : currentVertex->children)
        {
            if (!visited[child->data])
            {
                pendingVertices.push(child);
                visited[child->data] = true;
            }
        }
    }
}

void BFS(TreeNode *root)
{
    bool *visited = new bool[100]; // Assuming the maximum number of nodes is 100 (modify based on your requirement)
    for (int i = 0; i < 100; i++)
    {
        visited[i] = false;
    }
    printBFS(root, visited);
    delete[] visited;
}

int main()
{
    int n; // Number of nodes
    int e; // Number of edges
    cin >> n >> e;

    vector<TreeNode *> nodes(n);
    for (int i = 0; i < n; i++)
    {
        nodes[i] = new TreeNode{i + 1}; // Assuming node values are 1, 2, ..., n
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        nodes[f - 1]->children.push_back(nodes[s - 1]);
        nodes[s - 1]->children.push_back(nodes[f - 1]);
    }

    bool *visited = new bool[100]; // Assuming the maximum number of nodes is 100 (modify based on your requirement)
    for (int i = 0; i < 100; i++)
    {
        visited[i] = false;
    }

    printDFS(nodes[0], visited);
    BFS(nodes[0]);

    // Deallocate memory
    for (auto node : nodes)
    {
        delete node;
    }

    return 0;
}
*/

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void print(int **edges, int n, int sv, bool *visited)
{
    cout << sv << " ";
    visited[sv] = true; // marked the starting vertex true
    for (int i = 0; i < n; i++)
    { // Running the loop over all n nodes and checking if there is an edge between sv and i
        if (i == sv)
        {
            continue;
        }
        if (edges[sv][i] == 1)
        { // As the edge is found, we then checked if the node i was visited or not
            if (visited[i])
            {
                continue;
            }
            print(edges, n, i, visited); // Otherwise, recursively called over node i taking it as starting vertex
        }
    }
}

void printBFS(int **edges, int n, int sv, bool *visited)
{
    queue<int> pendingVertices; // queue
    pendingVertices.push(sv);   // starting vertex directly pushed
    visited[sv] = true;
    while (!pendingVertices.empty())
    {                                                // until the size of queue is not 0
        int currentVertex = pendingVertices.front(); // stored the top of queue
        pendingVertices.pop();                       // deleted that top element
        cout << currentVertex << " ";
        for (int i = 0; i < n; i++)
        { // now checked for its vertices
            if (i == currentVertex)
            {
                continue;
            }
            if (edges[currentVertex][i] == 1 && !visited[i])
            {
                pendingVertices.push(i); // if found, then inserted into queue
                visited[i] = true;
            }
        }
    }
}
void BFS(int **edges, int n)
{
    bool *visited = new bool[n]; // visited array to keep the track of nodes
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    printBFS(edges, n, 0, visited); // starting vertex = 0
    delete[] visited;               // deleted the visited array
}
int main()
{
    int n; // Number of nodes
    int e; // Number of edges
    cin >> n >> e;
    int **edges = new int *[n]; // adjacency matrix of size n*n
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0; // 0 indicates that there is no edge between i and j
        }
    }
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;   // Nodes having edges between them
        edges[f][s] = 1; // marking f to s as 1
        edges[s][f] = 1; // also, marking s to f as 1
    }

    bool *visited = new bool[n]; // this is used to keep the track of nodes if we have visited them or not.
    for (int i = 0; i < n; i++)
    {
        visited[i] = false; // Marking all the nodes as false which means not visited
    }

    print(edges, n, 0, visited); // starting vertex is taken as 0
    BFS(edges, n);

    // delete the memory
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}
