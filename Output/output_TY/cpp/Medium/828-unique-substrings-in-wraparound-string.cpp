/**https://leetcode.com/problems/unique-substrings-in-wraparound-string/ */
//We define the string base to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so base will look like this:
//	"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
//Given a string s, return the number of unique non-empty substrings of s are present in base.
// 
//Example 1:
//Input: s = "a"
//Output: 1
//Explanation: Only the substring "a" of s is in base.
//Example 2:
//Input: s = "cac"
//Output: 2
//Explanation: There are two substrings ("a", "c") of s in base.
//Example 3:
//Input: s = "zab"
//Output: 6
//Explanation: There are six substrings ("z", "a", "b", "za", "ab", and "zab") of s in base.
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of lowercase English letters.
class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int ans = 0;
        int pre = 0;
        int pre_len = 0;
        for(int i = 0; i < s.size(); i++){
            if(i > 0 && (s[i] - s[i - 1] + 26) % 26 == 1){
                pre_len++;
            }
            else{
                pre_len = 1;
            }
        }
        for(int i = 0; i < s.size(); i++){
            int cur = pre_len;
            for(int j = i + 1; j < s.size(); j++){
                if(s[j] - s[j - 1] + 26) % 26 == 1){
                    cur++;
                }
                else{
                    break;
                }
            }
            ans += cur - pre;
            }
            pre = cur;
            pre_len = cur;
            return ans;
    }
};