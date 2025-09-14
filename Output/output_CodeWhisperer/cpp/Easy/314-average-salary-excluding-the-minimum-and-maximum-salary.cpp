/**https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/ */
//You are given an array of unique integers salary where salary[i] is the salary of the ith employee.
//Return the average salary of employees excluding the minimum and maximum salary. Answers within 10-5 of the actual answer will be accepted.
// 
//Example 1:
//Input: salary = [4000,3000,1000,2000]
//Output: 2500.00000
//Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
//Average salary excluding minimum and maximum salary is (2000+3000) / 2 = 2500
//Example 2:
//Input: salary = [1000,2000,3000]
//Output: 2000.00000
//Explanation: Minimum salary and maximum salary are 1000 and 3000 respectively.
//Average salary excluding minimum and maximum salary is (2000) / 1 = 2000
// 
//Constraints:
//	3 <= salary.length <= 100
//	1000 <= salary[i] <= 106
//	All the integers of salary are unique.
class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        int sum = 0;
        int min = INT_MAX;
        int max = INT_MIN;
        for (int i = 0; i < n; i++) {
            sum += salary[i];
            if (salary[i] < min) {
                min = salary[i];
            }
            if (salary[i] > max) {
                max = salary[i];
            }
        }
        return (double)(sum - min - max) / (n - 2);      
    }
};