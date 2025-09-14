/**https://leetcode.com/problems/validate-ip-address/ */
//Given a string queryIP, return "IPv4" if IP is a valid IPv4 address, "IPv6" if IP is a valid IPv6 address or "Neither" if IP is not a correct IP of any type.
//A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <= xi <= 255 and xi cannot contain leading zeros. For example, "192.168.1.1" and "192.168.1.0" are valid IPv4 addresses while "192.168.01.1", "192.168.1.00", and "192.168@1.1" are invalid IPv4 addresses.
//A valid IPv6 address is an IP in the form "x1:x2:x3:x4:x5:x6:x7:x8" where:
//	1 <= xi.length <= 4
//	xi is a hexadecimal string which may contain digits, lowercase English letter ('a' to 'f') and upper-case English letters ('A' to 'F').
//	Leading zeros are allowed in xi.
//For example, "2001:0db8:85a3:0000:0000:8a2e:0370:7334" and "2001:db8:85a3:0:0:8A2E:0370:7334" are valid IPv6 addresses, while "2001:0db8:85a3::8A2E:037j:7334" and "02001:0db8:85a3:0000:0000:8a2e:0370:7334" are invalid IPv6 addresses.
// 
//Example 1:
//Input: queryIP = "172.16.254.1"
//Output: "IPv4"
//Explanation: This is a valid IPv4 address, return "IPv4".
//Example 2:
//Input: queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
//Output: "IPv6"
//Explanation: This is a valid IPv6 address, return "IPv6".
//Example 3:
//Input: queryIP = "256.256.256.256"
//Output: "Neither"
//Explanation: This is neither a IPv4 address nor a IPv6 address.
// 
//Constraints:
//	queryIP consists only of English letters, digits and the characters '.' and ':'.
class Solution {
    public String validIPAddress(String queryIP) {
        String[] parts = queryIP.split("[.:]");
        if (parts.length == 4) {
            for (String part : parts) {
                if (!isValidIPv4Part(part)) {
                    return "Neither";
                }
            }
            return "IPv4";
        } else if (parts.length == 8) {
            for (String part : parts) {
                if (!isValidIPv6Part(part)) {
                    return "Neither";
                }
            }
            return "IPv6";
        } else {
            return "Neither";
        }
        
    }
    
    private boolean isValidIPv4Part(String part) {
        if (part.length() > 3 || part.length() == 0) {
            return false;
        }
        int num = Integer.parseInt(part);
        if (num > 255) {
            return false;
        }
        if (part.length() > 1 && part.charAt(0) == '0') {
            return false;
        }
        return true;
    }
    
    private boolean isValidIPv6Part(String part) {
        if (part.length() > 4 || part.length() == 0) {
            return false;
        }
        try {
            Integer.parseInt(part, 16);
        } catch (NumberFormatException e) {
            return false;
        }
        return true;
    }
}