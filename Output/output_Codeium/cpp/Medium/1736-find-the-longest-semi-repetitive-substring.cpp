/**https://leetcode.com/problems/find-the-longest-semi-repetitive-substring/ */
//You are given a digit string s that consists of digits from 0 to 9.
//A string is called semi-repetitive if there is at most one adjacent pair of the same digit. For example, "0010", "002020", "0123", "2002", and "54944" are semi-repetitive while the following are not: "00101022" (adjacent same digit pairs are 00 and 22), and "1101234883" (adjacent same digit pairs are 11 and 88).
//Return the length of the longest semi-repetitive substring of s.
// 
//Example 1:
//Input: s = "52233"
//Output: 4
//Explanation:
//The longest semi-repetitive substring is "5223". Picking the whole string "52233" has two adjacent same digit pairs 22 and 33, but at most one is allowed.
//Example 2:
//Input: s = "5494"
//Output: 4
//Explanation:
//s is a semi-repetitive string.
//Example 3:
//Input: s = "1111111"
//Output: 2
//Explanation:
//The longest semi-repetitive substring is "11". Picking the substring "111" has two adjacent same digit pairs, but at most one is allowed.
// 
//Constraints:
//	1 <= s.length <= 50
//	'0' <= s[i] <= '9'
class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int res = 0, j = 0, count[10] = {0};
        unordered_map<int, int> map;
        map[0] = -1;
        for (int i = 0; i < s.length(); ++i) {
            int cur = count[s[i] - '0']++;
            if (map.find(cur) != map.end()) {
                res = max(res, i - map[cur]);
                j = max(j, map[cur] + 1);
            } else {
                map[cur] = i;
            }
            for (int k = 0; k < 10; ++k) {
                if (count[k] > 0) {
                    count[k] = max(0, count[k] - 1);
                }
            }
        }
        return res;
    }
};