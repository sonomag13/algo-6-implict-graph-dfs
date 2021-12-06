// LeetCode 797. All Paths From Source to Target
// Medium

#incldue <vector>

using namespace std; 

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {        
        // to find all the paths from vertex 0 to vertx n-1 
        
        numVer = graph.size();                
        
        vector<int> path{0}; 
        dfs(graph, 0, path); 
        
        return paths; 
        
    }

private:
    int numVer; 
    typedef vector<vector<int>> Graph;
    typedef vector<int> Path;
    vector<Path> paths; 
    
    void dfs(const Graph & graph, const int currVer, Path path) {
        // since the problem specified the graph is acyclic, we do not need 
        // to use a visited vector to check if a vetex has been visited
        
        // base case
        if (currVer == numVer - 1) {
            paths.push_back(path);
        }
        
        for (int i = 0; i < graph[currVer].size(); ++i) {            
            int nextVer = graph[currVer][i];
            path.push_back(nextVer);
            dfs(graph, nextVer, path);
            // pop back for the path with a different next vertex
            path.pop_back(); 
            
        }
        
    }
    
};