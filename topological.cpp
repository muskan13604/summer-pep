class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> result;
        vector<int> adj[V];
        vector<int> indegree(V, 0);
        for(int i=0; i < edges.size(); i++){
            int src = edges[i][0];
            int dest = edges[i][1];
            adj[src].push_back(dest);
            indegree[dest]++;
        }
        queue<int>q;
        for(int i=0; i <V; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);
            
            for(int neighbour:adj[node]){
                indegree[neighbour]--;
                if( indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }
            return result;
    }
};