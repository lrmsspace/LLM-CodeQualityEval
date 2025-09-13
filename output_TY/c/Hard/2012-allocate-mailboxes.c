/**https://leetcode.com/problems/allocate-mailboxes/ */
//Given the array houses where houses[i] is the location of the ith house along a street and an integer k, allocate k mailboxes in the street.
//Return the minimum total distance between each house and its nearest mailbox.
//The test cases are generated so that the answer fits in a 32-bit integer.
// 
//Example 1:
//Input: houses = [1,4,8,10,20], k = 3
//Output: 5
//Explanation: Allocate mailboxes in position 3, 9 and 20.
//Minimum total distance from each houses to nearest mailboxes is |3-1| + |4-3| + |9-8| + |10-9| + |20-20| = 5 
//Example 2:
//Input: houses = [2,3,5,12,18], k = 2
//Output: 9
//Explanation: Allocate mailboxes in position 3 and 14.
//Minimum total distance from each houses to nearest mailboxes is |2-3| + |3-3| + |5-3| + |12-14| + |18-14| = 9.
// 
//Constraints:
//	1 <= k <= houses.length <= 100
//	1 <= houses[i] <= 104
//	All the integers of houses are unique.
int minDistance(int* houses, int housesSize, int k){
    int i, j, n, m, min, sum, mid, left, right, mid_sum, mid_min, mid_left, mid_right;
    n = housesSize;
    m = n - k + 1;
    for (i = 0; i < n; i++) {
        houses[i] -= 1;
    }
    for (i = 0; i < m; i++) {
        min = INT_MAX;
        sum = 0;
        for (j = i; j < n; j++) {
            sum += houses[j] - houses[i];
            if (sum < min) {
                min = sum;
            }
        }
        if (min < mid_min) {
            mid_min = min;
            mid_left =i;
        }
    }
    mid = mid_left + (m - 1) / 2;
    left = mid_left;
    right = mid_left + m - 1;
    while (left < right) {
        mid_sum = 0;
        mid_min = INT_MAX;
        mid_left = 0;
        mid_right = 0;
        mid = (left + right) / 2;
        for (i = left; i <= right; i++) {
            mid_sum += houses[i] - houses[mid];
            if (mid_sum < mid_min) {
                mid_min = mid_sum;
            }
        }
    }
    return mid_min;
}