/**https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/ */
//A company is organizing a meeting and has a list of n employees, waiting to be invited. They have arranged for a large circular table, capable of seating any number of employees.
//The employees are numbered from 0 to n - 1. Each employee has a favorite person and they will attend the meeting only if they can sit next to their favorite person at the table. The favorite person of an employee is not themself.
//Given a 0-indexed integer array favorite, where favorite[i] denotes the favorite person of the ith employee, return the maximum number of employees that can be invited to the meeting.
// 
//Example 1:
//Input: favorite = [2,2,1,2]
//Output: 3
//Explanation:
//The above figure shows how the company can invite employees 0, 1, and 2, and seat them at the round table.
//All employees cannot be invited because employee 2 cannot sit beside employees 0, 1, and 3, simultaneously.
//Note that the company can also invite employees 1, 2, and 3, and give them their desired seats.
//The maximum number of employees that can be invited to the meeting is 3. 
//Example 2:
//Input: favorite = [1,2,0]
//Output: 3
//Explanation: 
//Each employee is the favorite person of at least one other employee, and the only way the company can invite them is if they invite every employee.
//The seating arrangement will be the same as that in the figure given in example 1:
//- Employee 0 will sit between employees 2 and 1.
//- Employee 1 will sit between employees 0 and 2.
//- Employee 2 will sit between employees 1 and 0.
//The maximum number of employees that can be invited to the meeting is 3.
//Example 3:
//Input: favorite = [3,0,1,4,1]
//Output: 4
//Explanation:
//The above figure shows how the company will invite employees 0, 1, 3, and 4, and seat them at the round table.
//Employee 2 cannot be invited because the two spots next to their favorite employee 1 are taken.
//So the company leaves them out of the meeting.
//The maximum number of employees that can be invited to the meeting is 4.
// 
//Constraints:
//	n == favorite.length
//	2 <= n <= 105
//	0 <= favorite[i] <= n - 1
//	favorite[i] != i
class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> indegree(n, 0);
        vector<int> indegree2(n, 0);
        vector<int> indegree3(n, 0);
        vector<int> indegree4(n, 0);
        vector<int> indegree5(n, 0);
        vector<int> indegree6(n, 0);
        vector<int> indegree7(n, 0);
        vector<int> indegree8(n, 0);
        vector<int> indegree9(n, 0);
        vector<int> indegree10(n, 0);
        for (int i = 0; i < n; i++){
            indegree[favorite[i]]++;
        }
        for (int i = 0; i < n; i++){
            if (indegree[i] == 2){
                indegree2[i]++;
            }
            else
            if (indegree[i] == 3){
                indegree3[i]++;
            }
            else
            if (indegree[i] == 4){
                indegree4[i]++;
            }
            else
            if (indegree[i] == 5){
                indegree5[i]++;
            }
            else
            if (indegree[i] == 6){
                indegree6[i]++;
            }
            else
            if (indegree[i] == 7){
                indegree7[i]++;
            }
            else
            if(indegree[i] == 8){
                indegree8[i]++;
            }
        }
        for (int i = 0; i < n; i++){
            if (indegree[i] == 9){
                indegree9[i]++;
            }
            else
            if (indegree[i] == 10){
                indegree10[i]++;
            }
        }
        return max(max(max(max(max(max(max(max(max(max(max(indegree2.size(), indegree3.size()), indegree4.size()), indegree5.size()), indegree6.size()), indegree7.size()), indegree8.size()), indegree9.size()), indegree10.size()), indegree.size()), 0);

    }
};