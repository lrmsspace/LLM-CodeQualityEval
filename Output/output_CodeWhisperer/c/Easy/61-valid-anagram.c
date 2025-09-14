/**https://leetcode.com/problems/valid-anagram/ */
//Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// 
//Example 1:
//Input: s = "anagram", t = "nagaram"
//Output: true
//Example 2:
//Input: s = "rat", t = "car"
//Output: false
// 
//Constraints:
//	1 <= s.length, t.length <= 5 * 104
//	s and t consist of lowercase English letters.
// 
//Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
bool isAnagram(char* s, char* t) {
    int sLen = strlen(s);
    int tLen = strlen(t);
    if(sLen != tLen){
        return false;
    }
    int* sCount = (int*)calloc(26, sizeof(int));
    int* tCount = (int*)calloc(26, sizeof(int));
    for(int i = 0; i < sLen; i++){
        sCount[s[i] - 'a']++;
        tCount[t[i] - 'a']++;
    }
    for(int i = 0; i < 26; i++){
        if(sCount[i] != tCount[i]){
            return false;
        }
    }
    return true;
    
}