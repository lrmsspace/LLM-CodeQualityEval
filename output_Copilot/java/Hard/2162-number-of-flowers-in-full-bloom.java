/**https://leetcode.com/problems/number-of-flowers-in-full-bloom/ */
//You are given a 0-indexed 2D integer array flowers, where flowers[i] = [starti, endi] means the ith flower will be in full bloom from starti to endi (inclusive). You are also given a 0-indexed integer array people of size n, where people[i] is the time that the ith person will arrive to see the flowers.
//Return an integer array answer of size n, where answer[i] is the number of flowers that are in full bloom when the ith person arrives.
// 
//Example 1:
//Input: flowers = [[1,6],[3,7],[9,12],[4,13]], people = [2,3,7,11]
//Output: [1,2,2,2]
//Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
//For each person, we return the number of flowers in full bloom during their arrival.
//Example 2:
//Input: flowers = [[1,10],[3,3]], people = [3,3,2]
//Output: [2,2,1]
//Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
//For each person, we return the number of flowers in full bloom during their arrival.
// 
//Constraints:
//	1 <= flowers.length <= 5 * 104
//	flowers[i].length == 2
//	1 <= starti <= endi <= 109
//	1 <= people.length <= 5 * 104
//	1 <= people[i] <= 109
class Solution {
    public int[] fullBloomFlowers(int[][] flowers, int[] people) {
        int n = flowers.length, m = people.length;
        int[][] bloomTimes = new int[n + m][2];
        for (int i = 0; i < n; i++) {
            bloomTimes[i][0] = flowers[i][0];
            bloomTimes[i][1] = 1; // start of bloom
            bloomTimes[i + n][0] = flowers[i][1] + 1;
            bloomTimes[i + n][1] = -1; // end of bloom
        }
        for (int i = 0; i < m; i++) {
            bloomTimes[n + i][0] = people[i];
            bloomTimes[n + i][1] = 0; // person arrival
        }
        Arrays.sort(bloomTimes, (a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        
        int[] result = new int[m];
        int count = 0;
        for (int i = 0; i < n + m; i++) {
            if (bloomTimes[i][1] == 1) {
                count++;
            } else if (bloomTimes[i][1] == -1) {
                count--;
            } else {
                result[i - n] = count;
            }
        }
        
        return result;        
    }
}