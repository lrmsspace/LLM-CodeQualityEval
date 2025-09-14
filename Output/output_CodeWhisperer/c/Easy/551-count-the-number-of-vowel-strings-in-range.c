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
int vowelStrings(char** words, int wordsSize, int left, int right) {
    int count = 0;
    for (int i = left; i <= right; i++) {
        char* word = words[i];
        int len = strlen(word);
        if ((word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u') && (word[len - 1] == 'a' || word[len - 1] == 'e' || word[len - 1] == 'i' || word[len - 1] == 'o' || word[len - 1] == 'u')) {
            count++;
        }
    }
    return count;
    
}