/**https://leetcode.com/problems/sort-characters-by-frequency/ */
//Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
//Return the sorted string. If there are multiple answers, return any of them.
// 
//Example 1:
//Input: s = "tree"
//Output: "eert"
//Explanation: 'e' appears twice while 'r' and 't' both appear once.
//So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
//Example 2:
//Input: s = "cccaaa"
//Output: "aaaccc"
//Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
//Note that "cacaca" is incorrect, as the same characters must be together.
//Example 3:
//Input: s = "Aabb"
//Output: "bbAa"
//Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
//Note that 'A' and 'a' are treated as two different characters.
// 
//Constraints:
//	1 <= s.length <= 5 * 105
//	s consists of uppercase and lowercase English letters and digits.
char* frequencySort(char* s) {
    int* count = (int*)calloc(128, sizeof(int));
    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i]]++;
    }
    char* result = (char*)malloc((strlen(s) + 1) * sizeof(char));
    int index = 0;
    while (1) {
        int max = 0;
        char c = 0;
        for (int i = 0; i < 128; i++) {
            if (count[i] > max) {
                max = count[i];
                c = i;
            }
        }
        if (max == 0) {
            break;
        }
        for (int i = 0; i < max; i++) {
            result[index++] = c;
        }
        count[c] = 0;
    }
    result[index] = '\0';
    return result;
}