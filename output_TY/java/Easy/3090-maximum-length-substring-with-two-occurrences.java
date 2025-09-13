/*
 Given a string s, return the maximum length of a substring such that it contains at most two occurrences of each character.
 Example 1:
 Input: s = "bcbbbcba"
 Output: 4
 Explanation:
 The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".
 Example 2:
 Input: s = "aaaa"
 Output: 2
 Explanation:
 The following substring has a length of 2 and contains at most two occurrences of each character: "aaaa".
 Constraints:
 2 <= s.length <= 100
 s consists only of lowercase English letters.
*/

class Solution {
    public int maximumLengthSubstring(String s) {
        int maxLength = 0;
        int count = 0;
        int i = 0;
        int j = 0;
        int n = s.length();
        HashMap<Character, Integer> map = new HashMap<>();
        
        while(i < n && j < n){
            if(map.containsKey(s.charAt(j))){
                map.put(s.charAt(j), map.get(s.charAt(j)) + 1);
            }
            else{
                map.put(s.charAt(j), 1);
            }
            
            if(map.size() <= 2){
                count = j - i + 1;
            }
        }
        while(j < n){
            if(map.containsKey(s.charAt(j))){
                map.put(s.charAt(j), map.get(s.charAt(j)) + 1);
            }
            else{
                map.put(s.charAt(j), 1);
            }
            
            if(map.size() <= 2){
                count = Math.max(count, j - i + 1);
            }
            
            if(map.containsKey(s.charAt(i))){
                map.put(s.charAt(i), map.get(s.charAt(i)) - 1);
            }
        }
        return count;
        
    }
}