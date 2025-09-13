/*
import java.util.ArrayList;
 You are given a positive integer n.
 A binary string x is valid if all substrings of x of length 2 contain at least one "1".
 Return all valid strings with length n, in any order.
 Example 1:
 Input: n = 3
 Output: ["010","011","101","110","111"]
 Explanation:
 The valid strings of length 3 are: "010", "011", "101", "110", and "111".
 Example 2:
 Input: n = 1
 Output: ["0","1"]
 Explanation:
 The valid strings of length 1 are: "0" and "1".
 Constraints:
 1 <= n <= 18
*/

class Solution {
    public List<String> validStrings(int n) {
        List<String> res = new ArrayList<>();
        if(n == 1) {
            res.add("0");
            res.add("1");
            return res;
        }
        List<String> pre = validStrings(n-1);
        for(String s: pre) {
            if(s.charAt(s.length()-1) == '1') {
                res.add(s+"0");
            }
            res.add(s+"1");
        }
        return res;        
    }
}