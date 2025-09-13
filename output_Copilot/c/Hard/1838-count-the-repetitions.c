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
int getMaxRepetitions(char* s1, int n1, char* s2, int n2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    int cnt1 = 0, cnt2 = 0;
    int i = 0, j = 0;
    while (cnt1 < n1) {
        if (s1[i] == s2[j]) {
            j++;
            if (j == len2) {
                j = 0;
                cnt2++;
            }
        }
        i++;
        if (i == len1) {
            i = 0;
            cnt1++;
        }
    }
    return cnt2 / n2;    
}