class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
                const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);
        
        
        for (auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        
        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;

        while (!pq.empty()) {
            auto [currTime, node] = pq.top();
            pq.pop();

            if (currTime > dist[node]) continue; 

            for (auto [neighbor, time] : adj[node]) {
                long long newTime = currTime + time;
                
                if (newTime < dist[neighbor]) { 
                    
                    dist[neighbor] = newTime;
                    ways[neighbor] = ways[node];
                    pq.push({newTime, neighbor});
                } 
                else if (newTime == dist[neighbor]) { 
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};