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
    int m = 0;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int count = 0;
    int i = 0;
    
    while (count < n1 * n2) {
        for (int j = 0; j < len1; j++) {
            if (s1[j] == s2[i]) {
                i++;
                if (i == len2) {
                    count++;
                    i = 0;
                    m++;
                }
            }
        }
    }
    
    return m / n1;
    
}