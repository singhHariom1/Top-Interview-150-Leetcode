#include <bits/stdc++.h>
using namespace std;

// 🟠 Approach 1: Using Map (Brute Force)
// Time Complexity: O(n log n)+O(n)
// Space Complexity: O(n)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> freq;
        for(int num:nums){
            freq[num]++;
        }
        int i=0;
        for(auto it:freq){
            if(it.second==1){
                nums[i++]=it.first;
            }else if(it.second>=2){
                nums[i++]=it.first;
                nums[i++]=it.first;
            }
        }
        return i;
    }
};


// 🟢 Approach 2: Optimal In-Place (Two Pointers)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (i < 2 || nums[j] != nums[i - 2]) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};

// Try generalizing it so that you keep at most k duplicates.
// ✨ Hint: Replace 2 with k, and change nums[i - 2] accordingly to nums[i - k].