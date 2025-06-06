#include <bits/stdc++.h>
using namespace std;


// 🟢 Approach: Greedy (Track farthest reachable index)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        int n = nums.size();

        for (int i = 0; i <= farthest; i++) {
            farthest = max(farthest, i + nums[i]);
            if (farthest >= n - 1)
                return true;
        }
        return false;
    }
};