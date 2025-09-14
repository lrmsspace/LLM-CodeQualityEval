/**https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/ */
//A string is good if there are no repeated characters.
//Given a string s​​​​​, return the number of good substrings of length three in s​​​​​​.
//Note that if there are multiple occurrences of the same substring, every occurrence should be counted.
//A substring is a contiguous sequence of characters in a string.
// 
//Example 1:
//Input: s = "xyzzaz"
//Output: 1
//Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz". 
//The only good substring of length 3 is "xyz".
//Example 2:
//Input: s = "aababcabc"
//Output: 4
//Explanation: There are 7 substrings of size 3: "aab", "aba", "bab", "abc", "bca", "cab", and "abc".
//The good substrings are "abc", "bca", "cab", and "abc".
// 
//Constraints:
//	1 <= s.length <= 100
//	s​​​​​​ consists of lowercase English letters.
class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.length();
        vector<int> count(26, 0);
        int ans = 0;
        for (int i = 0; i < 3; ++i) {
            count[s[i] - 'a']++;
        }
        if (count[s[0] - 'a'] == 1 && count[s[1] - 'a'] == 1 && count[s[2] - 'a'] == 1) {
            ans++;
        }
        for (int i = 3; i < n; ++i) {
            count[s[i - 3] - 'a']--;
            count[s[i] - 'a']++;
            if (count[s[i - 3] - 'a'] == 1 && count[s[i] - 'a'] == 1) {
                ans++;
            }
        }
        return ans;
        
    }
};