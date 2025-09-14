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
/**
 * @param {string} s
 * @return {string[]}
 */
var restoreIpAddresses = function(s) {
    let result = [];
    let ip = [];
    for(let i = 1; i <= 3; i++){
        for(let j = 1; j <= 3; j++){
            for(let k = 1; k <= 3; k++){
                for(let l = 1; l <= 3; l++){
                    if(i + j + k + l === s.length){
                        let a = s.substring(0, i);
                        let b = s.substring(i, i + j);
                        let c = s.substring(i + j, i + j + k);
                        let d = s.substring(i + j + k, s.length);
                        if(a.length >= 1 && a.length <= 3 && b  <= 3 && c <= 3 && d <= 3 && a[0] !== '0' && b[0] !== '0' && c[0] !== '0' && d[0] !== '0')
                            ip = [a, b, c, d];
                    }
                }
            }
        }
    }
    if(ip.length === 4){
        let ipStr = ip[0] + '.' + ip[1] + '.' + ip[2] + '.' + ip[3];
        result.push(ipStr);
    }
    return result;
};