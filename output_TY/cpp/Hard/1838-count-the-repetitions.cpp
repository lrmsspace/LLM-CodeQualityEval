/**https://leetcode.com/problems/count-the-repetitions/ */
//We define str = [s, n] as the string str which consists of the string s concatenated n times.
//	For example, str == ["abc", 3] =="abcabcabc".
//We define that string s1 can be obtained from string s2 if we can remove some characters from s2 such that it becomes s1.
//	For example, s1 = "abc" can be obtained from s2 = "abdbec" based on our definition by removing the bolded underlined characters.
//You are given two strings s1 and s2 and two integers n1 and n2. You have the two strings str1 = [s1, n1] and str2 = [s2, n2].
//Return the maximum integer m such that str = [str2, m] can be obtained from str1.
// 
//Example 1:
//Input: s1 = "acb", n1 = 4, s2 = "ab", n2 = 2
//Output: 2
//Example 2:
//Input: s1 = "acb", n1 = 1, s2 = "acb", n2 = 1
//Output: 1
// 
//Constraints:
//	1 <= s1.length, s2.length <= 100
//	s1 and s2 consist of lowercase English letters.
//	1 <= n1, n2 <= 106
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int s1_len = s1.size(), s2_len = s2.size();
        int s1_pos = 0, s2_pos = 0;
        int s1_cnt = 0, s2_cnt = 0;
        int s1_cnt_last = 0, s2_cnt_last = 0;
        int s1_pos_last = 0, s2_pos_last = 0;
        while (s1_cnt < n1) {
            if (s1[s1_pos] == s2[s2_pos]) {
                s2_pos++;
            }
            s1_pos++;
            s2_cnt++;
        }
        s1_cnt++;
        s1_pos %= s1_len;
        s2_pos %= s2_len;
        while (s1_cnt < n1) {
            s1_cnt_last = s1_cnt;
            s2_cnt_last = s2_cnt;
            while (s1_cnt < n1 && s1_pos != 0) {
                if (s1[s1_pos] == s2[s2_pos]) {
                    s2_pos++;
                }
                s1_pos++;
                s2_cnt++;
                s1_cnt++;
                s1_pos %=s1_len;
            }
        }
        return (n1 - 1) / s1_cnt * s2_cnt_last + s2_cnt - s2_cnt_last;
    }
};