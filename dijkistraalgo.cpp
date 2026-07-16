class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

        // Step 1: Create adjacency list
        vector<pair<int,int>> adj[V];

        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});   // Undirected graph
        }

        // Step 2: Distance array
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // Step 3: Min Heap
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        pq.push({0, src});

        // Step 4: Dijkstra
        while(!pq.empty()){

            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(d > dist[node]) continue;

            for(auto &it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;

                if(dist[node] + wt < dist[adjNode]){
                    dist[adjNode] = dist[node] + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};