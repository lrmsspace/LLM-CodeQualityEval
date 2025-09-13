/**https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/ */
//A string is considered beautiful if it satisfies the following conditions:
//	Each of the 5 English vowels ('a', 'e', 'i', 'o', 'u') must appear at least once in it.
//	The letters must be sorted in alphabetical order (i.e. all 'a's before 'e's, all 'e's before 'i's, etc.).
//For example, strings "aeiou" and "aaaaaaeiiiioou" are considered beautiful, but "uaeio", "aeoiu", and "aaaeeeooo" are not beautiful.
//Given a string word consisting of English vowels, return the length of the longest beautiful substring of word. If no such substring exists, return 0.
//A substring is a contiguous sequence of characters in a string.
// 
//Example 1:
//Input: word = "aeiaaioaaaaeiiiiouuuooaauuaeiu"
//Output: 13
//Explanation: The longest beautiful substring in word is "aaaaeiiiiouuu" of length 13.
//Example 2:
//Input: word = "aeeeiiiioooauuuaeiou"
//Output: 5
//Explanation: The longest beautiful substring in word is "aeiou" of length 5.
//Example 3:
//Input: word = "a"
//Output: 0
//Explanation: There is no beautiful substring, so return 0.
// 
//Constraints:
//	1 <= word.length <= 5 * 105
//	word consists of characters 'a', 'e', 'i', 'o', and 'u'.
class Solution {
    public int longestBeautifulSubstring(String word) {
        int max=0,i=0,j=0,count=0;
        while(j<word.length()){
            if(word.charAt(j)-'a'==j-count){
                j++;
                count++;
            }
            else if(count==5){
                max=Math.max(max,j-i);
                i=j;
                count=0;
            }
            else{
                i=j=++j;
                count=0;
            }
        }
        return max==0?0:Math.max(max,j-i);
    }
}