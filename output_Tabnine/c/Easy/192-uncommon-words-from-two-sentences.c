/**https://leetcode.com/problems/uncommon-words-from-two-sentences/ */
//A sentence is a string of single-space separated words where each word consists only of lowercase letters.
//A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.
//Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.
// 
//Example 1:
//Input: s1 = "this apple is sweet", s2 = "this apple is sour"
//Output: ["sweet","sour"]
//Explanation:
//The word "sweet" appears only in s1, while the word "sour" appears only in s2.
//Example 2:
//Input: s1 = "apple apple", s2 = "banana"
//Output: ["banana"]
// 
//Constraints:
//	1 <= s1.length, s2.length <= 200
//	s1 and s2 consist of lowercase English letters and spaces.
//	s1 and s2 do not have leading or trailing spaces.
//	All the words in s1 and s2 are separated by a single space.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** uncommonFromSentences(char* s1, char* s2, int* returnSize) {
    char** result = malloc(sizeof(char*) * 100);
    int count[26] = {0};
    char* p1 = s1, *p2 = s2;
    
    //Count the frequency of each word in s1 and s2

    while (*p1) {
        if (*p1!='') {
            count[(*p1) - 'a']++;
        }
        p1++;
    }
    
    while (*p2) {
        if (*p2!='') {
            count[(*p2) - 'a']++;
        }
        p2++;
    }
    
    int index = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] == 1) {
            result[index] = malloc(sizeof(char) * 20);
            sprintf(result[index], "%s", (i == 0? "a" : (i + 'a')));
            index++;
        }
    }
    
    *returnSize = index;
    return result;
}