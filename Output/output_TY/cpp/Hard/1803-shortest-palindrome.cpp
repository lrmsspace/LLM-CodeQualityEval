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
            if(n == 0) return "";
            string rev = s;
            reverse(rev.begin(), rev.end());
            string res = s + "#" + rev;
            vector<int> pi(n + 1, 0);
            for(int i = 1; i < n; i++){
                int j = pi[i - 1];
                while(j > 0 && res[i] != res[j]) j = pi[j - 1];
                if(res[i] == res[j]) j++;
                pi[i] = j;
            }
            return rev.substr(0, n - pi[n - 1])+ s;
    }
};