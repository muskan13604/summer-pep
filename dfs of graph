class Solution {
public:
    void DFS(int start, vector<int> &visited, vector<vector<int>> &adj, vector<int> &result) {
        visited[start] = 1;
        result.push_back(start);

        // Traverse all adjacent vertices
        for (int neighbour : adj[start]) {
            if (!visited[neighbour]) {
                DFS(neighbour, visited, adj, result);
            }
        }
    }

    vector<int> dfs(vector<vector<int>> &adj) {
        int V = adj.size();

        vector<int> visited(V, 0);
        vector<int> result;

        int start = 0;

        DFS(start, visited, adj, result);

        return result;
    }
};