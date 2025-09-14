/**https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/ */
//Given an integer n, return any array containing n unique integers such that they add up to 0.
// 
//Example 1:
//Input: n = 5
//Output: [-7,-1,1,3,4]
//Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
//Example 2:
//Input: n = 3
//Output: [-1,0,1]
//Example 3:
//Input: n = 1
//Output: [0]
// 
//Constraints:
//	1 <= n <= 1000
class Solution {
    public int[] sumZero(int n) {
        int[] result = new int[n];
        int sum = 0;
        for(int i=0;i<n-1;i++){
            result[i] = i+1;
            sum += i+1;
        }
        result[n-1] = -sum;
        return result;      
    }
}