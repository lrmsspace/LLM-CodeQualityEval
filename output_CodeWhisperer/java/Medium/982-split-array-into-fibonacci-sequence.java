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
        for (int i = 1; i < num.length() - 1; i++) {
            for (int j = i + 1; j < num.length(); j++) {
                if (num.charAt(0) == '0' && i > 1) break;
                if (num.charAt(i) == '0' && j > i + 1) break;
                long a = Long.parseLong(num.substring(0, i));
                long b = Long.parseLong(num.substring(i, j));
                if (b > Integer.MAX_VALUE) break;
                res.add((int)a);
                res.add((int)b);
                int k = j;
                while (k < num.length()) {
                    long next = a + b;
                    if (next > Integer.MAX_VALUE) break;
                    String nextStr = String.valueOf(next);
                    if (num.startsWith(nextStr, k)) {
                        k += nextStr.length();
                        a = b;
                        b = next;
                        res.add((int)next);
                    } else {
                        break;
                    }
                }
                if (k == num.length() && res.size() >= 3) return res;
                res.clear();
            }
        }
        return res;       
    }
}