/**https://leetcode.com/problems/count-the-number-of-vowel-strings-in-range/ */
//You are given a 0-indexed array of string words and two integers left and right.
//A string is called a vowel string if it starts with a vowel character and ends with a vowel character where vowel characters are 'a', 'e', 'i', 'o', and 'u'.
//Return the number of vowel strings words[i] where i belongs to the inclusive range [left, right].
// 
//Example 1:
//Input: words = ["are","amy","u"], left = 0, right = 2
//Output: 2
//Explanation: 
//- "are" is a vowel string because it starts with 'a' and ends with 'e'.
//- "amy" is not a vowel string because it does not end with a vowel.
//- "u" is a vowel string because it starts with 'u' and ends with 'u'.
//The number of vowel strings in the mentioned range is 2.
//Example 2:
//Input: words = ["hey","aeo","mu","ooo","artro"], left = 1, right = 4
//Output: 3
//Explanation: 
//- "aeo" is a vowel string because it starts with 'a' and ends with 'o'.
//- "mu" is not a vowel string because it does not start with a vowel.
//- "ooo" is a vowel string because it starts with 'o' and ends with 'o'.
//- "artro" is a vowel string because it starts with 'a' and ends with 'o'.
//The number of vowel strings in the mentioned range is 3.
// 
//Constraints:
//	1 <= words.length <= 1000
//	1 <= words[i].length <= 10
//	words[i] consists of only lowercase English letters.
//	0 <= left <= right < words.length
int vowelStrings(char ** words, int wordsSize, int left, int right){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, a, b, c, d, e, f, g, h, count = 0;
    for (i = left; i <= right; i++) {
        for (j = 0; words[i][j] != '\0'; j++) {
            if (words[i][j] == 'a' || words[i][j] == 'e' || words[i][j] == 'i' || words[i][j] == 'o' || words[i][j] == 'u') {
                if (words[i][j + 1] == 'a' || words[i][j + 1] == 'e' || words[i][j + 1] == 'i' || words[i][j + 1] == 'o' || words[i][j + 1] == 'u') {
                    count++;
                }
            }
        }
    }
    return count;
}