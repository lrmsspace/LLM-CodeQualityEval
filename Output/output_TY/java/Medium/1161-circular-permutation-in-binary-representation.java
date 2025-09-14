/**https://leetcode.com/problems/circular-permutation-in-binary-representation/ */
//Given 2 integers n and start. Your task is return any permutation p of (0,1,2.....,2^n -1) such that :
//	p[0] = start
//	p[i] and p[i+1] differ by only one bit in their binary representation.
//	p[0] and p[2^n -1] must also differ by only one bit in their binary representation.
// 
//Example 1:
//Input: n = 2, start = 3
//Output: [3,2,0,1]
//Explanation: The binary representation of the permutation is (11,10,00,01). 
//All the adjacent element differ by one bit. Another valid permutation is [3,1,0,2]
//Example 2:
//Input: n = 3, start = 2
//Output: [2,6,7,5,4,0,1,3]
//Explanation: The binary representation of the permutation is (010,110,111,101,100,000,001,011).
// 
//Constraints:
//	1 <= n <= 16
//	0 <= start < 2 ^ n
class Solution {

    public List<Integer> circularPermutation(int n, int start) {
        List<Integer> result = new ArrayList<>();
        result.add(0);
        for (int i = 0; i < n; i++) {
            int size = result.size();
            for (int j = size - 1; j >= 0; j--) {
                result.add(result.get(j) | (1 << i));
            }
        }
        int index = result.indexOf(start);
        List<Integer> result2 = new ArrayList<>();
        for (int i = index; i < result.size(); i++) {
            result2.add(result.get(i));
        }
        for (int i = 0; i < index; i++) {
            result2.add(result.get(i));
        }
        return result2;
        

    }

}