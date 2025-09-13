/**https://leetcode.com/problems/keyboard-row/ */
//Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.
//Note that the strings are case-insensitive, both lowercased and uppercased of the same letter are treated as if they are at the same row.
//In the American keyboard:
//	the first row consists of the characters "qwertyuiop",
//	the second row consists of the characters "asdfghjkl", and
//	the third row consists of the characters "zxcvbnm".
// 
//Example 1:
//Input: words = ["Hello","Alaska","Dad","Peace"]
//Output: ["Alaska","Dad"]
//Explanation:
//Both "a" and "A" are in the 2nd row of the American keyboard due to case insensitivity.
//Example 2:
//Input: words = ["omk"]
//Output: []
//Example 3:
//Input: words = ["adsdf","sfd"]
//Output: ["adsdf","sfd"]
// 
//Constraints:
//	1 <= words.length <= 20
//	1 <= words[i].length <= 100
//	words[i] consists of English letters (both lowercase and uppercase). 
class Solution {
    public String[] findWords(String[] words) {
        String[] keyboard = new String[]{"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        List<String> res = new ArrayList<>();
        for (String word : words) {
            boolean flag = true;
            int row = 0;
            for (int i = 0; i < 3; i++) {
                if (keyboard[i].indexOf(Character.toLowerCase(word.charAt(0))) != -1) {
                    row = i;
                    break;
                }
            }
            for (int i = 1; i < word.length(); i++) {
                if (keyboard[row].indexOf(Character.toLowerCase(word.charAt(i))) == -1) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res.add(word);
            }
        }
        return res.toArray(new String[res.size()]);        
    }
}