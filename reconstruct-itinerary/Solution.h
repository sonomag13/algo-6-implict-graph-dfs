// LeetCode 332. Reconstruct Itinerary
// Hard

#include <deque>
#include <vector>

using namespace std; 

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        // build a graph between depart and destinies
        for (auto & ticket : tickets) {
            string depart = ticket[0];
            string destiny = ticket[1];
            trips[depart].push_back(destiny);
        }
        
        // order the destinies lexically
        for (auto & trip : trips) {
            auto & destinies = trip.second;
            sort(destinies.begin(), destinies.end());
        }
        
        // start dfs
        dfs(start); 
        
        // reverse the route since the deepest desitiny enters the vector first
        reverse(route.begin(), route.end());
        
        return route; 
        
    }
    
private:    
    const string start = "JFK"; 
    unordered_map<string, deque<string>> trips; // deque is used for the sake to pop front
    vector<string> route; 
    
    void dfs(const string & depart) {
        
        auto & destinies = trips[depart];
        
        // traverse all the destinies in the lexical order
        while (!destinies.empty()) {
            string dest = destinies.front();
            destinies.pop_front();
            dfs(dest); 
        }
        
        // the deepest desitiy without another destiny will be pushed into the 
        // route first
        route.push_back(depart);
        
    }    
    
};