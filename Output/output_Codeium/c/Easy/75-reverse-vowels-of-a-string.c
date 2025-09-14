/**https://leetcode.com/problems/reverse-vowels-of-a-string/ */
//Given a string s, reverse only all the vowels in the string and return it.
//The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.
// 
//Example 1:
//Input: s = "IceCreAm"
//Output: "AceCreIm"
//Explanation:
//The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".
//Example 2:
//Input: s = "leetcode"
//Output: "leotcede"
// 
//Constraints:
//	1 <= s.length <= 3 * 105
//	s consist of printable ASCII characters.
bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
char* reverseVowels(char* s) {
    int l = 0, r = strlen(s) - 1;
    char t;
    while (l < r) {
        if (!isVowel(s[l])) l++;
        else if (!isVowel(s[r])) r--;
        else {
            t = s[l];
            s[l] = s[r];
            s[r] = t;
            l++;
            r--;
        }
    }
    return s;
}

    
