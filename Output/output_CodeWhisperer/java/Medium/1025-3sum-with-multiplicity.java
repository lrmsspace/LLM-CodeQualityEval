/**https://leetcode.com/problems/3sum-with-multiplicity/ */
//Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.
//As the answer can be very large, return it modulo 109 + 7.
// 
//Example 1:
//Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
//Output: 20
//Explanation: 
//Enumerating by the values (arr[i], arr[j], arr[k]):
//(1, 2, 5) occurs 8 times;
//(1, 3, 4) occurs 8 times;
//(2, 2, 4) occurs 2 times;
//(2, 3, 3) occurs 2 times.
//Example 2:
//Input: arr = [1,1,2,2,2,2], target = 5
//Output: 12
//Explanation: 
//arr[i] = 1, arr[j] = arr[k] = 2 occurs 12 times:
//We choose one 1 from [1,1] in 2 ways,
//and two 2s from [2,2,2,2] in 6 ways.
//Example 3:
//Input: arr = [2,1,3], target = 6
//Output: 1
//Explanation: (1, 2, 3) occured one time in the array so we return 1.
// 
//Constraints:
//	3 <= arr.length <= 3000
//	0 <= arr[i] <= 100
//	0 <= target <= 300
class Solution {
    public int threeSumMulti(int[] arr, int target) {
        int MOD = 1_000_000_007;
        
        // Initializing as long saves us the trouble of
        // managing count[x] * count[y] * count[z] <= INT_MAX,
        // i.e. managing the possibility of integer overflow.
        long[] count = new long[101];
        for (int x : arr) count[x]++;
        
        long res = 0;
        // We use i <= 100, because we need to consider:
        // [target, target, target] and [target, target, target]
        for (int x = 0; x <= 100; ++x)
            for (int y = x; y <= 100; ++y) {
                int z = target - x - y;
                if (y < z || z < 0 || z > 100) continue;
                if (x == y && y == z)
                    res += count[x] * (count[x] - 1) * (count[x] - 2) / 6;
                else if (x == y && y != z)
                    res += count[x] * (count[x] - 1) / 2 * count[z];
                else if (y < z)
                    res += count[x] * count[y] * count[z];
                res %= MOD;
            }
        
        return (int) res;      
    }
}