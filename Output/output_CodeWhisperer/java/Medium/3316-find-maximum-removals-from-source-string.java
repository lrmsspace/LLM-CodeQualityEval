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
    public int maxRemovals(String source, String pattern, int[] targetIndices) {
    int left = 0;
    int right = targetIndices.length;
    
    while (left < right) {
        int mid = left + (right - left + 1) / 2;
        
        // Try removing mid number of characters
        boolean[] removed = new boolean[source.length()];
        for (int i = 0; i < mid; i++) {
            removed[targetIndices[i]] = true;
        }
        
        // Check if pattern is still subsequence after removal
        if (isSubsequence(source, pattern, removed)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    
    return left;
}

private boolean isSubsequence(String source, String pattern, boolean[] removed) {
    int i = 0; // source index
    int j = 0; // pattern index
    
    while (i < source.length() && j < pattern.length()) {
        if (!removed[i] && source.charAt(i) == pattern.charAt(j)) {
            j++;
        }
        i++;
    }
    
    return j == pattern.length();
}                    
    
}