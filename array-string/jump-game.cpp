#include <bits/stdc++.h>
using namespace std;

// 🟢 Approach 1: Forward Greedy (Track Farthest Reachable Index)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution_ForwardGreedy {
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

// 🟢 Approach 2: Reverse Greedy (Shrink the Goal Backwards)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution_ReverseGreedy {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;

        for (int i = goal - 1; i >= 0; i--) {
            if (i + nums[i] >= goal)
                goal = i;
        }

        return goal == 0;
    }
};
