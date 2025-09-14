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
        int res = 0;
        for (int i = 0; i < s.length(); ++i) {
            vector<int> count(26);
            for (int j = i; j < s.length(); ++j) {
                ++count[s[j] - 'a'];
                int maxFreq = *max_element(count.begin(), count.end());
                int minFreq = *min_element(count.begin(), count.end());
                if (minFreq > 0) {
                    res += maxFreq - minFreq;
                }
            }
        }
        return res;
    }
};