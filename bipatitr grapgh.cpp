class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<int> adj[V];
        for(int i=0; i<edges.size(); i++){
            int src = edges[i][0];
            int dest = edges[i][1];
            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }
        vector<int>colored(V, -1);
        int start = 0;
        queue<int> q;
        q.push(start);
        colored[start] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int neighbour:adj[node]){
                if(colored[neighbour]==-1){
                    colored[neighbour]=1-colored[node];
                    q.push(neighbour);
                }
                else{
                    if(colored[neighbour]==colored[node]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};


//