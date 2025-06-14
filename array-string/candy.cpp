#include <bits/stdc++.h>
using namespace std;

// 🟢 Approach: Greedy Two-Pass
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);

        // Left to Right: ensure each child has more candies than left neighbor if rating is higher
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Right to Left: ensure each child has more candies than right neighbor if rating is higher
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
