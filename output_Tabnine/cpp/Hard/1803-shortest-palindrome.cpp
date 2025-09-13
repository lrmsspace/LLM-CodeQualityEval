/**https://leetcode.com/problems/shortest-palindrome/ */
//You are given a string s. You can convert s to a palindrome by adding characters in front of it.
//Return the shortest palindrome you can find by performing this transformation.
// 
//Example 1:
//Input: s = "aacecaaa"
//Output: "aaacecaaa"
//Example 2:
//Input: s = "abcd"
//Output: "dcbabcd"
// 
//Constraints:
//	0 <= s.length <= 5 * 104
//	s consists of lowercase English letters only.
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string concat_s = s + "#" + rev_s;
        
        int len = concat_s.size();
        vector<int> lps(len, 0);
        int center = 0, right = 0;
        
        for (int i = 1; i < len; ++i) {
            int mir = 2 * center - i;
            if (i < right)
                lps[i] = min(right - i, lps[mir]);
            
            while (concat_s[i + 1 + lps[i]] == concat_s[i - 1 - lps[i]])
                ++lps[i];
            
            if (i + lps[i] > right) {
                center = i;
                right = i + lps[i];
            }
        }
        
        int start_index = lps[len - 1];
        return rev_s.substr(start_index) + s;
        
    }
};