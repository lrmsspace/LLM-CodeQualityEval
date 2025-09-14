/**https://leetcode.com/problems/first-unique-character-in-a-string/ */
//Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
// 
//Example 1:
//Input: s = "leetcode"
//Output: 0
//Explanation:
//The character 'l' at index 0 is the first character that does not occur at any other index.
//Example 2:
//Input: s = "loveleetcode"
//Output: 2
//Example 3:
//Input: s = "aabb"
//Output: -1
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of only lowercase English letters.
int firstUniqChar(char* s) {
    int* count = (int*)calloc(26, sizeof(int));
    int i = 0;
    while (s[i] != '\0') {
        count[s[i] - 'a']++;
        i++;
    }
    i = 0;
    while (s[i] != '\0') {
        if (count[s[i] - 'a'] == 1) {
            return i;
        }
        i++;
    }
    return -1;  
    
}