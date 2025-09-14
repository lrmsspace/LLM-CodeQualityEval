/*
 You are given a string source of size n, a string pattern that is a subsequence of source, and a sorted integer array targetIndices that contains distinct numbers in the range [0, n - 1].
 We define an operation as removing a character at an index idx from source such that:
 idx is an element of targetIndices.
 pattern remains a subsequence of source after removing the character.
 Performing an operation does not change the indices of the other characters in source. For example, if you remove 'c' from "acb", the character at index 2 would still be 'b'.
 Return the maximum number of operations that can be performed.
 Example 1:
 Input: source = "abbaa", pattern = "aba", targetIndices = [0,1,2]
 Output: 1
 Explanation:
 We can't remove source[0] but we can do either of these two operations:
 Remove source[1], so that source becomes "a_baa".
 Remove source[2], so that source becomes "ab_aa".
 Example 2:
 Input: source = "bcda", pattern = "d", targetIndices = [0,3]
 Output: 2
 Explanation:
 We can remove source[0] and source[3] in two operations.
 Example 3:
 Input: source = "dda", pattern = "dda", targetIndices = [0,1,2]
 Output: 0
 Explanation:
 We can't remove any character from source.
 Example 4:
 Input: source = "yeyeykyded", pattern = "yeyyd", targetIndices = [0,2,3,4]
 Output: 2
 Explanation:
 We can remove source[2] and source[3] in two operations.
 Constraints:
 1 <= n == source.length <= 3 * 103
 1 <= pattern.length <= n
 1 <= targetIndices.length <= n
 targetIndices is sorted in ascending order.
 The input is generated such that targetIndices contains distinct elements in the range [0, n - 1].
 source and pattern consist only of lowercase English letters.
 The input is generated such that pattern appears as a subsequence in source.
*/

class Solution {
public:
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int n = source.size();
        int m = pattern.size();
        vector<bool> canRemove(n, false);
        
        // Check if pattern is a subsequence of source
        int j = 0;
        for (int i = 0; i < n && j < m; ++i) {
            if (source[i] == pattern[j]) {
                j++;
            }
        }
        
        if (j < m) return 0; // If pattern is not a subsequence, return 0
        
        // Mark removable indices
        for (int idx : targetIndices) {
            if (idx < n && source[idx] == pattern[0]) {
                canRemove[idx] = true;
            }
        }
        
        int removals = 0;
        for (int idx : targetIndices) {
            if (canRemove[idx]) {
                removals++;
                // Temporarily remove the character at idx
                string tempSource = source.substr(0, idx) + source.substr(idx + 1);
                
                // Check if pattern is still a subsequence
                j = 0;
                for (char c : tempSource) {
                    if (c == pattern[j]) {
                        j++;
                    }
                    if (j == m) break;
                }
                
                if (j < m) { // If pattern is not a subsequence after removal
                    removals--;
                    canRemove[idx] = false; // Mark it as not removable
                }
            }
        }
        
        return removals;
            
    }
};