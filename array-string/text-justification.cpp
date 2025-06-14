#include <bits/stdc++.h>
using namespace std;

// 🟠 Approach 1: Greedy Line Packing + Smart Space Distribution
// Time Complexity: O(n * k), where n = number of words, k = maxWidth
// Space Complexity: O(1) extra space, excluding the result

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;  // Stores the final justified lines
        int i = 0, n = words.size();

        while (i < n) {
            int lineLen = 0;   // Total character count of words in current line (excluding spaces)
            int j = i;         // Pointer to find how many words can fit in the current line

            // 🔄 Step 1: Try to greedily fit as many words as possible in the current line
            while (j < n && lineLen + words[j].size() + (j - i) <= maxWidth) {
                lineLen += words[j].size();  // Add the word length
                j++;  // Move to next word
            }

            int totalWords = j - i;                 // Number of words in current line
            int totalSpaces = maxWidth - lineLen;   // Total extra spaces needed to fill the line
            string line = "";                       // Start building the current line

            // 🟢 Step 2: Handle last line OR lines with only one word
            if (j == n || totalWords == 1) {
                // Append all words separated by single spaces
                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k != j - 1) line += ' ';
                }
                // Pad the remaining space at the end to reach maxWidth
                line += string(maxWidth - line.size(), ' ');
            }

            // 🔵 Step 3: Fully justify lines with multiple words
            else {
                int spacesPerGap = totalSpaces / (totalWords - 1);   // Minimum spaces per gap
                int extraSpaces = totalSpaces % (totalWords - 1);    // Extra spaces to distribute from the left

                for (int k = i; k < j; ++k) {
                    line += words[k];  // Append the word
                    if (k != j - 1) {
                        // Add required spaces after the word
                        int spacesToInsert = spacesPerGap + (extraSpaces > 0 ? 1 : 0);
                        line += string(spacesToInsert, ' ');
                        if (extraSpaces > 0) extraSpaces--;  // Use up one extra space
                    }
                }
            }

            result.push_back(line);  // Add the built line to the result
            i = j;  // Move to next chunk of words
        }

        return result;
    }
};
