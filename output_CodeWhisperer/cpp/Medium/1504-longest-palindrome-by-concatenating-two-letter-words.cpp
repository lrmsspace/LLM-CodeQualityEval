/**https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/ */
//You are given an array of strings words. Each element of words consists of two lowercase English letters.
//Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.
//Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.
//A palindrome is a string that reads the same forward and backward.
// 
//Example 1:
//Input: words = ["lc","cl","gg"]
//Output: 6
//Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
//Note that "clgglc" is another longest palindrome that can be created.
//Example 2:
//Input: words = ["ab","ty","yt","lc","cl","ab"]
//Output: 8
//Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
//Note that "lcyttycl" is another longest palindrome that can be created.
//Example 3:
//Input: words = ["cc","ll","xx"]
//Output: 2
//Explanation: One longest palindrome is "cc", of length 2.
//Note that "ll" is another longest palindrome that can be created, and so is "xx".
// 
//Constraints:
//	1 <= words.length <= 105
//	words[i].length == 2
//	words[i] consists of lowercase English letters.
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        unordered_map<string, int> cnt;
        for (string w : words) {
            string r = w;
            reverse(r.begin(), r.end());
            if (cnt[r] > 0) {
                ans += 4;
                cnt[r]--;
            } else {
                cnt[w]++;
            }
        }
        for (auto& [k, v] : cnt) {
            if (k[0] == k[1] && v > 0) {
                ans += 2;
                break;
            }
        }
        return ans;     
    }
};