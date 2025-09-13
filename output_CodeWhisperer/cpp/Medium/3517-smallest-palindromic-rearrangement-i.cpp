/*
 You are given a palindromic string s.
 Return the lexicographically smallest palindromic permutation of s.
 Example 1:
 Input: s = "z"
 Output: "z"
 Explanation:
 A string of only one character is already the lexicographically smallest palindrome.
 Example 2:
 Input: s = "babab"
 Output: "abbba"
 Explanation:
 Rearranging "babab" → "abbba" gives the smallest lexicographic palindrome.
 Example 3:
 Input: s = "daccad"
 Output: "acddca"
 Explanation:
 Rearranging "daccad" → "acddca" gives the smallest lexicographic palindrome.
 Constraints:
 1 <= s.length <= 105
 s consists of lowercase English letters.
 s is guaranteed to be palindromic.
*/

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n-1;
        while(l < r){
            if(s[l] < s[r]){
                s[r] = s[l];
            }
            else if(s[l] > s[r]){
                s[l] = s[r];
            }
            l++;
            r--;
        }
        return s;        
    }
};