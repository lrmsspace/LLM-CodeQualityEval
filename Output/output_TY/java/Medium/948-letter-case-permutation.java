/**https://leetcode.com/problems/letter-case-permutation/ */
//Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.
//Return a list of all possible strings we could create. Return the output in any order.
// 
//Example 1:
//Input: s = "a1b2"
//Output: ["a1b2","a1B2","A1b2","A1B2"]
//Example 2:
//Input: s = "3z4"
//Output: ["3z4","3Z4"]
// 
//Constraints:
//	1 <= s.length <= 12
//	s consists of lowercase English letters, uppercase English letters, and digits.
class Solution {
    public List<String> letterCasePermutation(String s) {
        List<String> result = new ArrayList<>();
        result.add(s);
        for(int i=0;i<s.length();i++){
            char ch = s.charAt(i);
            if(Character.isDigit(ch)) continue;
            int n = result.size();
            for(int j=0;j<n;j++){
                String str = result.get(j);
                char ch1 = str.charAt(i);
                if(Character.isUpperCase(ch1)){
                    String str1 = str.substring(0,i)+Character.toLowerCase(ch1)+str.substring(i+1);
                }
            }
        }
        return result;
    }
}