/**https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/ */
//You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.
//We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
// 
//Example 1:
//Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
//Output: [20,24]
//Explanation: 
//List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
//List 2: [0, 9, 12, 20], 20 is in range [20,24].
//List 3: [5, 18, 22, 30], 22 is in range [20,24].
//Example 2:
//Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
//Output: [1,1]
// 
//Constraints:
//	nums.length == k
//	1 <= k <= 3500
//	1 <= nums[i].length <= 50
//	-105 <= nums[i][j] <= 105
//	nums[i] is sorted in non-decreasing order.
class Solution {
    public int[] smallestRange(List<List<Integer>> nums) {
        PriorityQueue<int[]> pq=new PriorityQueue<>((a,b)->a[0]-b[0]);
        int max=Integer.MIN_VALUE;
        for(int i=0;i<nums.size();i++){
            pq.add(new int[]{nums.get(i).get(0),i,0});
            max=Math.max(max,nums.get(i).get(0));
        }
        int[] res=new int[]{pq.peek()[0],max};
        while(pq.size()==nums.size()){
            int[] cur=pq.poll();
            if(res[1]-res[0]>max-cur[0]){
                res[0]=cur[0];
                res[1]=max;
            }
        }  
        return res;
    }
}