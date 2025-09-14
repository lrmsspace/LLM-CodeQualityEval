/**https://leetcode.com/problems/make-number-of-distinct-characters-equal/ */
//You are given two 0-indexed strings word1 and word2.
//A move consists of choosing two indices i and j such that 0 <= i < word1.length and 0 <= j < word2.length and swapping word1[i] with word2[j].
//Return true if it is possible to get the number of distinct characters in word1 and word2 to be equal with exactly one move. Return false otherwise.
// 
//Example 1:
//Input: word1 = "ac", word2 = "b"
//Output: false
//Explanation: Any pair of swaps would yield two distinct characters in the first string, and one in the second string.
//Example 2:
//Input: word1 = "abcc", word2 = "aab"
//Output: true
//Explanation: We swap index 2 of the first string with index 0 of the second string. The resulting strings are word1 = "abac" and word2 = "cab", which both have 3 distinct characters.
//Example 3:
//Input: word1 = "abcde", word2 = "fghij"
//Output: true
//Explanation: Both resulting strings will have 5 distinct characters, regardless of which indices we swap.
// 
//Constraints:
//	1 <= word1.length, word2.length <= 105
//	word1 and word2 consist of only lowercase English letters.
bool isItPossible(char* word1, char* word2) {
    int count1[26] = {0};
    int count2[26] = {0};
    int distinct1 = 0;
    int distinct2 = 0;
    for (int i = 0; word1[i] != '\0'; i++) {
        count1[word1[i] - 'a']++;
        if (count1[word1[i] - 'a'] == 1) distinct1++;
    }
    for (int i = 0; word2[i] != '\0'; i++) {
        count2[word2[i] - 'a']++;
        if (count2[word2[i] - 'a'] == 1) distinct2++;
    }
    for (int i = 0; i < 26; i++) {
        if (count1[i] == 0) continue;
        for (int j = 0; j < 26; j++) {
            if (count2[j] == 0) continue;
            if (i == j) {
                if (distinct1 == distinct2) return true;
            } else {
                int new_distinct1 = distinct1;
                int new_distinct2 = distinct2;
                if (count1[i] == 1) new_distinct1--;
                if (count2[i] == 0) new_distinct1++;
                if (count2[j] == 1) new_distinct2--;
                if (count1[j] == 0) new_distinct2++;
                if (new_distinct1 == new_distinct2) return true;
            }
        }
    }
    return false;
}