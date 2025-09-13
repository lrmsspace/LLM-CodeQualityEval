/**https://leetcode.com/problems/find-the-maximum-achievable-number/ */
//Given two integers, num and t. A number is achievable if it can become equal to num after applying the following operation:
//	Increase or decrease the number by 1, and simultaneously increase or decrease num by 1.
//Return the maximum achievable number after applying the operation at most t times.
// 
//Example 1:
//Input: num = 4, t = 1
//Output: 6
//Explanation:
//Apply the following operation once to make the maximum achievable number equal to num:
//	Decrease the maximum achievable number by 1, and increase num by 1.
//Example 2:
//Input: num = 3, t = 2
//Output: 7
//Explanation:
//Apply the following operation twice to make the maximum achievable number equal to num:
//	Decrease the maximum achievable number by 1, and increase num by 1.
// 
//Constraints:
//	1 <= num, t <= 50
int theMaximumAchievableX(int num, int t) {
    int maxNum = num + 2 * t; // Initial maximum achievable number
    int minNum = num - 2 * t; // Initial minimum achievable number
    
    // Binary search to find the maximum achievable number
    while (minNum <= maxNum) {
        int mid = minNum + (maxNum - minNum) / 2;
        
        if (canAchieve(mid, num, t)) {
            minNum = mid + 1; // Update minimum achievable number
        } else {
            maxNum = mid - 1; // Update maximum achievable number
        }
    }
    
    return maxNum - 1; // Return the maximum achievable number
    
}