/**https://leetcode.com/problems/lexicographically-smallest-beautiful-string/ */
//A string is beautiful if:
//	It consists of the first k letters of the English lowercase alphabet.
//	It does not contain any substring of length 2 or more which is a palindrome.
//You are given a beautiful string s of length n and a positive integer k.
//Return the lexicographically smallest string of length n, which is larger than s and is beautiful. If there is no such string, return an empty string.
//A string a is lexicographically larger than a string b (of the same length) if in the first position where a and b differ, a has a character strictly larger than the corresponding character in b.
//	For example, "abcd" is lexicographically larger than "abcc" because the first position they differ is at the fourth character, and d is greater than c.
// 
//Example 1:
//Input: s = "abcz", k = 26
//Output: "abda"
//Explanation: The string "abda" is beautiful and lexicographically larger than the string "abcz".
//It can be proven that there is no string that is lexicographically larger than the string "abcz", beautiful, and lexicographically smaller than the string "abda".
//Example 2:
//Input: s = "dc", k = 4
//Output: ""
//Explanation: It can be proven that there is no string that is lexicographically larger than the string "dc" and is beautiful.
// 
//Constraints:
//	1 <= n == s.length <= 105
//	4 <= k <= 26
//	s is a beautiful string.
char* smallestBeautifulString(char* s, int k) {
    int n = strlen(s);
    int count[26] = {0};
    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
    }
    
    int minIndex = -1;
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0 && (minIndex == -1 || count[i] < count[minIndex])) {
            minIndex = i;
        }
    }
    
    if (minIndex == -1) {
        return "";
    }
    
    char* result = (char*)malloc((n + 1) * sizeof(char));
    result[n] = '\0';
    result[n - 1] = 'a' + minIndex;
    count[minIndex]--;
    
    for (int i = n - 2; i >= 0; i--) {
        int nextIndex = -1;
        for (int j = 0; j < 26; j++) {
            if (count[j] > 0 && (nextIndex == -1 || count[j] < count[nextIndex] || (count[j] == count[nextIndex] && 'a' + j < result[i + 1]))) {
                nextIndex = j;
            }
        }
        
        if (nextIndex == -1) {
            return "";
        }
        
        result[i] = 'a' + nextIndex;
        count[nextIndex]--;
    }
    
    return result;
    
}