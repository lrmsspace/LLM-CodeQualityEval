/**https://leetcode.com/problems/daily-temperatures/ */
//Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.
// 
//Example 1:
//Input: temperatures = [73,74,75,71,69,72,76,73]
//Output: [1,1,4,2,1,1,0,0]
//Example 2:
//Input: temperatures = [30,40,50,60]
//Output: [1,1,1,0]
//Example 3:
//Input: temperatures = [30,60,90]
//Output: [1,1,0]
// 
//Constraints:
//	1 <= temperatures.length <= 105
//	30 <= temperatures[i] <= 100
class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        int[] result = new int[n];
        Stack<Integer> stack = new Stack<>(); // Stack to store indices of temperatures

        for (int i = 0; i < n; i++) {
            // Pop elements from the stack while the current temperature is greater than the temperature at the index stored at the top of the stack
            while (!stack.isEmpty() && temperatures[i] > temperatures[stack.peek()]) {
                int index = stack.pop(); // Get the index of the temperature that is less than the current temperature
                result[index] = i - index; // Calculate the number of days until a warmer temperature
            }
            stack.push(i); // Push the current index onto the stack
        }

        return result; // Return the result array        
    }
}