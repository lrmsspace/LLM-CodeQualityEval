/**https://leetcode.com/problems/split-array-into-fibonacci-sequence/ */
//You are given a string of digits num, such as "123456579". We can split it into a Fibonacci-like sequence [123, 456, 579].
//Formally, a Fibonacci-like sequence is a list f of non-negative integers such that:
//	0 <= f[i] < 231, (that is, each integer fits in a 32-bit signed integer type),
//	f.length >= 3, and
//	f[i] + f[i + 1] == f[i + 2] for all 0 <= i < f.length - 2.
//Note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number 0 itself.
//Return any Fibonacci-like sequence split from num, or return [] if it cannot be done.
// 
//Example 1:
//Input: num = "1101111"
//Output: [11,0,11,11]
//Explanation: The output [110, 1, 111] would also be accepted.
//Example 2:
//Input: num = "112358130"
//Output: []
//Explanation: The task is impossible.
//Example 3:
//Input: num = "0123"
//Output: []
//Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not valid.
// 
//Constraints:
//	1 <= num.length <= 200
//	num contains only digits.
class Solution {
    public List<Integer> splitIntoFibonacci(String num) {
        List<Integer> res = new ArrayList<>();
        backtrack(res, num, 0);
        return res;
    }
    
    private boolean backtrack(List<Integer> res, String num, int start) {
        if (start == num.length()) {
            return res.size() >= 3;
        }
        for (int i = start; i < num.length(); i++) {
            if (i > start && num.charAt(start) == '0') {
                break;
            }
            long n = Long.parseLong(num.substring(start, i + 1));
            if (n > Integer.MAX_VALUE) {
                break;
            }
            if (res.size() >= 2 && n > res.get(res.size() - 1) + res.get(res.size() - 2)) {
                break;
            }
            if (res.size() <= 1 || n == res.get(res.size() - 1) + res.get(res.size() - 2)) {
                res.add((int) n);
                if (backtrack(res, num, i + 1)) {
                    return true;
                }
                res.remove(res.size() - 1);
            }
        }
        return false;
    }
    }
}