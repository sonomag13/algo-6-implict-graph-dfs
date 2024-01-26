#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


int dfs(int node, const vector<vector<int>> & graph, vector<bool> & visited, vector<int> & counts) {
    
    int numCut = 0;
    counts[node] = 1;
    visited[node] = true;  // mark the current node visited
    
    for (auto neighbor : graph[node]) {
        if (visited[neighbor]) {
            continue; 
        }
        visited[neighbor] = true; 
    
        numCut += dfs(neighbor, graph, visited, counts); 
        counts[node] += counts[neighbor];  
        if (counts[neighbor] % 2 == 0) {
            /**
             * the tree under neighbor (neighbor is included) has even 
             * number of nodes, such that the edge between neighbor and 
             * its parent can be removed. 
             * 
             * Otherwise, such a sub-tree cannot be removed, and will keep
             * being attached to its parent
             */ 
            ++numCut;
        }
        
    }
    
    return numCut; 
}

// Complete the evenForest function below.
int evenForest(int t_nodes, int t_edges, vector<int> t_from, vector<int> t_to) {
    
    vector<vector<int>> graph(t_nodes + 1, vector<int>{});
    
    for (int i = 0; i < t_from.size(); ++i) {
        int n1 = t_from[i];
        int n2 = t_to[i];
        graph[n1].push_back(n2);
        graph[n2].push_back(n1); 
    }
    
    vector<bool> visited(t_nodes + 1, false);
    visited[0] = true; 
    vector<int> counts(t_nodes + 1, 0);
    
    int start = 10; 
    
    int numCut = dfs(start, graph, visited, counts);
    
    return numCut;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_nodes_edges_temp;
    getline(cin, t_nodes_edges_temp);

    vector<string> t_nodes_edges = split(rtrim(t_nodes_edges_temp));

    int t_nodes = stoi(t_nodes_edges[0]);
    int t_edges = stoi(t_nodes_edges[1]);

    vector<int> t_from(t_edges);
    vector<int> t_to(t_edges);

    for (int i = 0; i < t_edges; i++) {
        string t_from_to_temp;
        getline(cin, t_from_to_temp);

        vector<string> t_from_to = split(rtrim(t_from_to_temp));

        int t_from_temp = stoi(t_from_to[0]);
        int t_to_temp = stoi(t_from_to[1]);

        t_from[i] = t_from_temp;
        t_to[i] = t_to_temp;
    }

    int res = evenForest(t_nodes, t_edges, t_from, t_to);

    fout << res << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
