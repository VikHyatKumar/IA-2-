/*In Depth First Search (or DFS) for a graph, we traverse all adjacent vertices one by one. 
When we traverse an adjacent vertex, we completely finish the traversal of all vertices
reachable through that adjacent vertex. This is similar to a tree, where we first completely 
traverse the left subtree and then move to the right subtree. The key difference is that, 
unlike trees, graphs may contain cycles (a node may be visited more than once). 
To avoid processing a node multiple times, we use a boolean visited array.

A standard DFS implementation puts each vertex of the graph into one of two categories:

1. Visited
2. Not Visited

The purpose of the algorithm is to mark each vertex as visited while avoiding cycles.

The DFS algorithm works as follows:
recursively visit each unvisited adjacent vertex, marking it as visited,
and then continue the process until all vertices reachable from the starting vertex have been visited.      

*/
#include<vector>
#include<iostream>
using namespace std;

void dfsRec(int node , vector<vector<int>> &adj, vector<int> &vis, vector<int> &ans ){
    vis[node] = 1;
    ans.push_back(node);

    for(auto it: adj[node]){
        if(!vis[it]){
            dfsRec(it, adj , vis, ans);
        }
    }
}
vector<int> dfs(int V, vector<vector<int>> &adj){
    vector<int> vis(V,0);

    int start = 0;
    vector<int> ans;
    dfsRec(start, adj ,vis,ans);
    return ans;
}

int main(){
    int V = 5;
    vector<vector<int>> adj = {
        {1, 2},    
        {0, 3, 4}, 
        {0, 4}, 
        {1}, 
        {1, 2}
    };

    vector<int> traversal = dfs(V, adj);

    cout << "DFS Traversal: ";
    for(int node : traversal) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}