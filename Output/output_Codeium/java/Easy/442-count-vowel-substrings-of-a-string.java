/**https://leetcode.com/problems/count-vowel-substrings-of-a-string/ */
//A substring is a contiguous (non-empty) sequence of characters within a string.
//A vowel substring is a substring that only consists of vowels ('a', 'e', 'i', 'o', and 'u') and has all five vowels present in it.
//Given a string word, return the number of vowel substrings in word.
// 
//Example 1:
//Input: word = "aeiouu"
//Output: 2
//Explanation: The vowel substrings of word are as follows (underlined):
//- "aeiouu"
//- "aeiouu"
//Example 2:
//Input: word = "unicornarihan"
//Output: 0
//Explanation: Not all 5 vowels are present, so there are no vowel substrings.
//Example 3:
//Input: word = "cuaieuouac"
//Output: 7
//Explanation: The vowel substrings of word are as follows (underlined):
//- "cuaieuouac"
//- "cuaieuouac"
//- "cuaieuouac"
//- "cuaieuouac"
//- "cuaieuouac"
//- "cuaieuouac"
//- "cuaieuouac"
// 
//Constraints:
//	1 <= word.length <= 100
//	word consists of lowercase English letters only.
class Solution {
    public int countVowelSubstrings(String word) {
        int count = 0;
        for (int i = 0; i < word.length() - 4; i++) {
            boolean[] seen = new boolean[5];
            for (int j = i; j < word.length(); j++) {
                switch (word.charAt(j)) {
                    case 'a':
                        seen[0] = true;
                        break;
                    case 'e':
                        seen[1] = true;
                        break;
                    case 'i':
                        seen[2] = true;
                        break;
                    case 'o':
                        seen[3] = true;
                        break;
                    case 'u':
                        seen[4] = true;
                        break;
                }
                if (seen[0] && seen[1] && seen[2] && seen[3] && seen[4]) {
                    count++;
                }
            }
        }
        
        return count;
    }
}