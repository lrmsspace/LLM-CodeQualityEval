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
class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(),houses.end());
        int n=houses.size();
        int left=houses[0],right=houses[n-1];
        int mid,ans=INT_MAX;
        while(left<=right){
            mid=left+(right-left)/2;
            int cnt=0,sum=0;
            for(int i=0;i<n;i++){
                sum+=houses[i]-mid;
                if(sum<0){
                    cnt++;
                    sum=0;
                }
            }
            if(cnt<=k){
                ans=min(ans,sum*sum);
                right=mid-1;
            }
        }
        return ans;
    }
};