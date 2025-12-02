#include <bits/stdc++.h>
using namespace std;

// 🔴 Approach 1: Brute Force (Greedy)
// Time Complexity: O(k * n)
// Space Complexity: O(n) (for visited array)

class Solution_BruteForce {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<bool> visited(n, false);
        
        for (int i = 0; i < k; i++) {
            int idx = -1;
            int maxProfit = -1;
            
            // Find the best affordable project
            for (int j = 0; j < n; j++) {
                if (!visited[j] && capital[j] <= w) {
                    if (profits[j] > maxProfit) {
                        maxProfit = profits[j];
                        idx = j;
                    }
                }
            }
            
            if (idx == -1) break; // No affordable project found
            
            w += maxProfit;
            visited[idx] = true;
        }
        
        return w;
    }
};


// 🟢 Approach 2: Two Heaps (Optimal)
// Time Complexity: O(n log n + k log n)
// Space Complexity: O(n)

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects;
        
        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }
        
        // Sort projects by capital required
        sort(projects.begin(), projects.end());
        
        priority_queue<int> maxProfitHeap;
        int i = 0;
        
        while (k--) {
            // Add all affordable projects to the heap
            while (i < n && projects[i].first <= w) {
                maxProfitHeap.push(projects[i].second);
                i++;
            }
            
            if (maxProfitHeap.empty()) break;
            
            w += maxProfitHeap.top();
            maxProfitHeap.pop();
        }
        
        return w;
    }
};
