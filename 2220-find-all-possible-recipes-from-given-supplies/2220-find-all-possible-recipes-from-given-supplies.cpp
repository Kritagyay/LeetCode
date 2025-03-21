class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            unordered_map<string, vector<string>> graph;  
    unordered_map<string, int> in_degree;         
    unordered_set<string> available(supplies.begin(), supplies.end()); 

    for (const string& recipe : recipes) {
        in_degree[recipe] = 0;
    }

    for (int i = 0; i < recipes.size(); i++) {
        for (const string& ing : ingredients[i]) {
            if (!available.count(ing)) { 
                graph[ing].push_back(recipes[i]);
                in_degree[recipes[i]]++;
            }
        }
    }

    queue<string> q;
    for (const string& recipe : recipes) {
        if (in_degree[recipe] == 0) {
            q.push(recipe);
        }
    }

    vector<string> result;
    while (!q.empty()) {
        string recipe = q.front();
        q.pop();
        result.push_back(recipe);  
        available.insert(recipe);  

        for (const string& dependent : graph[recipe]) {
            if (--in_degree[dependent] == 0) {
                q.push(dependent);
            }
        }
    }

    return result;
    }
};