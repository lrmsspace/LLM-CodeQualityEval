/**https://leetcode.com/problems/find-common-characters/ */
//Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.
// 
//Example 1:
//Input: words = ["bella","label","roller"]
//Output: ["e","l","l"]
//Example 2:
//Input: words = ["cool","lock","cook"]
//Output: ["c","o"]
// 
//Constraints:
//	1 <= words.length <= 100
//	1 <= words[i].length <= 100
//	words[i] consists of lowercase English letters.
class Solution {
    public List<String> commonChars(String[] words) {
        List<String> result = new ArrayList<>();
        int[] count = new int[26];
        
        for (String word : words) {
            int[] temp = new int[26];
            for (char c : word.toCharArray()) {
                temp[c - 'a']++;
            }
            if (count[0] == 0) {
                System.arraycopy(temp, 0, count, 0, 26);
            } else {
                for (int i = 0; i < 26; i++) {
                    count[i] = Math.min(count[i], temp[i]);
                }
            }
        }
        
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < count[i]; j++) {
                result.add(String.valueOf((char) (i + 'a')));
            }
        }
        
        return result;
        
    }
}