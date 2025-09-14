/**https://leetcode.com/problems/isomorphic-strings/ */
//Given two strings s and t, determine if they are isomorphic.
//Two strings s and t are isomorphic if the characters in s can be replaced to get t.
//All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
// 
//Example 1:
//Input: s = "egg", t = "add"
//Output: true
//Explanation:
//The strings s and t can be made identical by:
//	Mapping 'e' to 'a'.
//	Mapping 'g' to 'd'.
//Example 2:
//Input: s = "foo", t = "bar"
//Output: false
//Explanation:
//The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.
//Example 3:
//Input: s = "paper", t = "title"
//Output: true
// 
//Constraints:
//	1 <= s.length <= 5 * 104
//	t.length == s.length
//	s and t consist of any valid ascii character.
bool isIsomorphic(char* s, char* t) {
    // Initialize two arrays to store the mappings
    int mapS[256] = {0};
    int mapT[256] = {0};
    
    // Iterate through the strings
    for (int i = 0; s[i]; i++) {
        // If the characters map to different values, return false
        if (mapS[s[i]]!= mapT[t[i]]) {
            return false;
        }
        
        // If the characters map to the same value, update the mapping
        mapS[s[i]] = i + 1;
        mapT[t[i]] = i + 1;
    }
    
    // If all characters have been mapped correctly, return true
    return true;
    
}