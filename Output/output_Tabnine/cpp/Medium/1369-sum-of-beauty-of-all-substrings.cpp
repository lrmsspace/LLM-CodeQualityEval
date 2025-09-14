/**https://leetcode.com/problems/sum-of-beauty-of-all-substrings/ */
//The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.
//	For example, the beauty of "abaacc" is 3 - 1 = 2.
//Given a string s, return the sum of beauty of all of its substrings.
// 
//Example 1:
//Input: s = "aabcb"
//Output: 5
//Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
//Example 2:
//Input: s = "aabcbaa"
//Output: 17
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of only lowercase English letters.
class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int ans = 0;
        vector<int> freq(26, 0);
        
        for (int i = 0; i < n; ++i) {
            freq[s[i] - 'a']++;
            int maxCount = 0, minCount = INT_MAX;
            for (int j = 0; j < 26; ++j) {
                maxCount = max(maxCount, freq[j]);
                minCount = min(minCount, freq[j]);
            }
            ans += maxCount - minCount;
        }
        return ans;
        
    }
};