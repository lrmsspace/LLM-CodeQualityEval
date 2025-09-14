/**https://leetcode.com/problems/restore-ip-addresses/ */
//A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.
//	For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
//Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.
// 
//Example 1:
//Input: s = "25525511135"
//Output: ["255.255.11.135","255.255.111.35"]
//Example 2:
//Input: s = "0000"
//Output: ["0.0.0.0"]
//Example 3:
//Input: s = "101023"
//Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
// 
//Constraints:
//	1 <= s.length <= 20
//	s consists of digits only.
class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> result = new ArrayList<String>();
        StringBuilder sb = new StringBuilder();
        for(int i = 1; i <= 3; i++){
            for(int j = 1; j <= 3; j++){
                for(int k = 1; k <= 3; k++){
                    for(int l = 1; l <= 3; l++){
                        if(i + j + k + l == s.length()){
                            String s1 = s.substring(0, i);
                            String s2 = s.substring(i, i + j);
                            String s3 = s.substring(i + j, i + j + k);
                        }
                    }
                }
            }
        }
        return result;
    }
}