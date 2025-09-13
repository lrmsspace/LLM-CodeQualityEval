/**https://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/ */
//You are given two strings a and b that consist of lowercase letters. In one operation, you can change any character in a or b to any lowercase letter.
//Your goal is to satisfy one of the following three conditions:
//	Every letter in a is strictly less than every letter in b in the alphabet.
//	Every letter in b is strictly less than every letter in a in the alphabet.
//	Both a and b consist of only one distinct letter.
//Return the minimum number of operations needed to achieve your goal.
// 
//Example 1:
//Input: a = "aba", b = "caa"
//Output: 2
//Explanation: Consider the best way to make each condition true:
//1) Change b to "ccc" in 2 operations, then every letter in a is less than every letter in b.
//2) Change a to "bbb" and b to "aaa" in 3 operations, then every letter in b is less than every letter in a.
//3) Change a to "aaa" and b to "aaa" in 2 operations, then a and b consist of one distinct letter.
//The best way was done in 2 operations (either condition 1 or condition 3).
//Example 2:
//Input: a = "dabadd", b = "cda"
//Output: 3
//Explanation: The best way is to make condition 1 true by changing b to "eee".
// 
//Constraints:
//	1 <= a.length, b.length <= 105
//	a and b consist only of lowercase letters.
int minCharacters(char * a, char * b){
    int a_freq[26] = {0}, b_freq[26] = {0}, i, j, ans = INT_MAX;
    for (i = 0; a[i]; i++) a_freq[a[i] - 'a']++;
    for (i = 0; b[i]; i++) b_freq[b[i] - 'a']++;
    for (i = 0; i < 26; i++) {
        ans = min(ans, a_freq[i] + sum(b_freq, i + 1));
        ans = min(ans, b_freq[i] + sum(a_freq, i + 1));
    }
    return ans;
}