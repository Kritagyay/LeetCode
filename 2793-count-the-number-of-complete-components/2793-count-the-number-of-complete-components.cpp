class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
            vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        int completeCount = 0;

        function<void(int, unordered_set<int>&, int&)> dfs = [&](int node, unordered_set<int>& component, int& edgeCount) {
            visited[node] = true;
            component.insert(node);
            for (int neighbor : adj[node]) {
                edgeCount++; 
                if (!visited[neighbor]) {
                    dfs(neighbor, component, edgeCount);
                }
            }
        };

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                unordered_set<int> component;
                int edgeCount = 0;
                dfs(i, component, edgeCount);

                int size = component.size();
                if (edgeCount / 2 == size * (size - 1) / 2) {
                    completeCount++;
                }
            }
        }

        return completeCount;
    
    }
};