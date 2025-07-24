#include <bits/stdc++.h>
using namespace std;

// 🔴 Approach 1: Brute Force using Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution1 {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums)
            freq[num]++;
        for (auto& [num, count] : freq)
            if (count == 1)
                return num;
        return -1; // Should never happen
    }
};


// 🟡 Approach 2: Sorting + Linear Scan
// Time Complexity: O(n log n)
// Space Complexity: O(1)

class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i += 3) {
            if (nums[i - 1] != nums[i])
                return nums[i - 1];
        }
        return nums[n - 1]; // Unique is at the end
    }
};


// 🟢 Approach 3: Bit Manipulation with Bitmasking
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution3 {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        return ones;
    }
};


// 🟢 Approach 4: Bitwise Counting (O(n * 32))
// Time Complexity: O(n * 32) ~ O(n)
// Space Complexity: O(1)

class Solution4 {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        // Check every bit position (0 to 31)
        for (int i = 0; i < 32; ++i) {
            int bitCount = 0;

            for (int num : nums) {
                if ((num >> i) & 1) {
                    bitCount++;
                }
            }

            // If bitCount is not divisible by 3, it belongs to the single number
            if (bitCount % 3 != 0) {
                result |= (1 << i);
            }
        }

        return result;
    }
};