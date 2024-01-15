#include <iostream>
#include <numeric>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'cutTheTree' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY data
 *  2. 2D_INTEGER_ARRAY edges
 */

unordered_map<int, int> mapNodeSum;  // make a memo of the sum under a certain node

int dfs(const vector<int> & data, unordered_map<int, vector<int>> & mapNodes, vector<bool> & visited, int node) {

    if (mapNodeSum.find(node) != mapNodeSum.end()) {
        return mapNodeSum[node];  // check if the sum has been calculated before
    }

    int sum = data[node];
    visited[node] = true;

    for (auto neighbor : mapNodes[node]) {
        if (!visited[neighbor]) {
            visited[neighbor] = true;
            sum += dfs(data, mapNodes, visited, neighbor);
        }
    }

    mapNodeSum.insert(make_pair(node, sum));

    return sum;
}

void insertNode(int node1, int node2, unordered_map<int, vector<int>> & mapNodes) {
    // use a dictionary (aka. unordered_map) to represent the node and its neighbors

    if (mapNodes.find(node1) == mapNodes.end()) {
        mapNodes.insert(make_pair(node1, vector<int>{node2}));
    }
    else {
        mapNodes[node1].push_back(node2);
    }
}

int cutTheTree(vector<int> data, vector<vector<int>> edges) {

    unordered_map<int, vector<int>> mapNodes; // a map of nodes
    for (auto & edge : edges) {
        int node1 = edge[0] - 1;  // recast to 0-index
        int node2 = edge[1] - 1;
        insertNode(node1, node2, mapNodes);
        insertNode(node2, node1, mapNodes);
    }

    int sum0 = accumulate(data.begin(), data.end(), decltype(data)::value_type(0));
    int minDelta = INT_MAX;
    int num = data.size();

    for (auto & edge : edges) {
        int node1 = edge[0] - 1;
        int node2 = edge[1] - 1;

        /**
         * Now we have node 1 and node 2. We mark node 1 as visited such that there is no path from
         * Node 2 to Node 1 any more.
         *
         * Then we do DFS to calculate the sum under node 2.
         */
        vector<bool> visited(num, false);
        visited[node1] = true;
        int sum = dfs(data, mapNodes, visited, node2);

        /**
         * For any tree without a circle, delete an edge will break the tree into two smaller trees, the sume will be
         *
         *              sum0 = sum1 + sum2
         *
         * It is easy to calculate sum0. If somehow we can calculate sum1, then
         *
         *              sum2 = sum0 - sum1
         *
         * such that
         *
         *              delta = abs(sum2 - sum1) = abs(sum0 - 2 * sum1)
         *
         */
        minDelta = min(minDelta, abs(sum0 - 2 * sum));
    }

    return minDelta;
}

int main() {

    vector<int> data = {205, 573, 985, 242, 830, 514, 592, 263, 142, 915};
    vector<vector<int>> edges = {{2, 8},
                                 {10, 5},
                                 {1,7},
                                 {6, 9},
                                 {4, 3},
                                 {8, 10},
                                 {5, 1},
                                 {7, 6},
                                 {9, 4}};

    int minDelta = cutTheTree(data, edges);

    cout << "minDelta = " << minDelta << '\n';

    return 0;
}
