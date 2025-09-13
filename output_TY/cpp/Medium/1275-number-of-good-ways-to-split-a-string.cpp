/**https://leetcode.com/problems/number-of-good-ways-to-split-a-string/ */
//You are given a string s.
//A split is called good if you can split s into two non-empty strings sleft and sright where their concatenation is equal to s (i.e., sleft + sright = s) and the number of distinct letters in sleft and sright is the same.
//Return the number of good splits you can make in s.
// 
//Example 1:
//Input: s = "aacaba"
//Output: 2
//Explanation: There are 5 ways to split "aacaba" and 2 of them are good. 
//("a", "acaba") Left string and right string contains 1 and 3 different letters respectively.
//("aa", "caba") Left string and right string contains 1 and 3 different letters respectively.
//("aac", "aba") Left string and right string contains 2 and 2 different letters respectively (good split).
//("aaca", "ba") Left string and right string contains 2 and 2 different letters respectively (good split).
//("aacab", "a") Left string and right string contains 3 and 1 different letters respectively.
//Example 2:
//Input: s = "abcd"
//Output: 1
//Explanation: Split the string as follows ("ab", "cd").
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of only lowercase English letters.
class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        vector<int> left(n, 0), right(n, 0);
        unordered_map<char, int> leftMap, rightMap;
        for(int i = 0; i < n; i++)
        {
            rightMap[s[i]]++;
            right[i] = rightMap.size();
        }
        for(int i = n - 1; i >= 0; i--)
        {
            leftMap[s[i]]++;
            left[i] = leftMap.size();
        }
        int ans = 0;
        for(int i = 0; i < n - 1; i++)
        {
            if(left[i] == right[i + 1])
                ans++;
        }
        return ans;
    }
};