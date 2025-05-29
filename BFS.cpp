/*
BFS(Breadth First Search):- Breadth First Search (BFS)  is a fundamental  graph traversal algorithm. It begins with a node, 
then first traverses all its adjacent nodes. Once all adjacent are visited, then their adjacent are traversed. 

BFS is different from DFS in a way that closest vertices are visited before others. We mainly traverse vertices level by level.

Popular graph algorithms like Dijkstra's shortest path, Kahn's Algorithm, and Prim's algorithm are based on BFS. 
 
BFS itself can be used to detect cycle in a directed and undirected graph, find shortest path in an unweighted graph and
many more problems.


*/
#include<vector>
#include<queue>
#include <iostream>
using namespace std;
vector<int> bfs( vector<vector<int>>& adj){
    int v = adj.size();
    vector<int> vis(v,0);
    vis[0] = 1;
    queue<int> q;
    q.push(0);

    vector<int> bfs;
    while(!q.empty()){
        int node  = q.front();
        q.pop();
        bfs.push_back(node);


        for(int x : adj[node]){
            if(!vis[x]){
                vis[x] = 1;
                q.push(x);
            }
        }
    }
    return bfs;
}

int main(){
    vector<vector<int>> adj = {{1,2}, {0,2,3},{0,1,4}, {1,4}, {2,3}};
    
    vector<int> traversal = bfs(adj);
    cout << "BFS Traversal: ";
    for(int node : traversal) {
        cout << node << " ";
    }
    cout << endl;
    
    return 0;
}