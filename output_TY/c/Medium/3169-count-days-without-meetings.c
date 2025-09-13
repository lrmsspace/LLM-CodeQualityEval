/*
 You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).
 Return the count of days when the employee is available for work but no meetings are scheduled.
 Note: The meetings may overlap.
 Example 1:
 Input: days = 10, meetings = [[5,7],[1,3],[9,10]]
 Output: 2
 Explanation:
 There is no meeting scheduled on the 4th and 8th days.
 Example 2:
 Input: days = 5, meetings = [[2,4],[1,3]]
 Output: 1
 Explanation:
 There is no meeting scheduled on the 5th day.
 Example 3:
 Input: days = 6, meetings = [[1,6]]
 Output: 0
 Explanation:
 Meetings are scheduled for all working days.
 Constraints:
 1 <= days <= 109
 1 <= meetings.length <= 105
 meetings[i].length == 2
 1 <= meetings[i][0] <= meetings[i][1] <= days
*/

int countDays(int days, int** meetings, int meetingsSize, int* meetingsColSize) {
    
    int i, j, k, count = 0, flag = 0;
    int* arr = (int*)malloc(sizeof(int) * days);
    memset(arr, 0, sizeof(int) * days);
    
    for (i = 0; i < meetingsSize; i++) {
        for (j = meetings[i][0]; j <= meetings[i][1]; j++) {
            arr[j - 1] = 1;
        }
    }
    
    for (i = 0; i < days; i++) {
        if (arr[i] == 0) {
            flag = 1;
        }
        if (flag == 1 && arr[i] == 1) {
            count++;
}
    }
    return count;
}