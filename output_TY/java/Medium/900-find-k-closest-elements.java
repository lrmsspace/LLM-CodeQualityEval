/**https://leetcode.com/problems/find-k-closest-elements/ */
//Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.
//An integer a is closer to x than an integer b if:
//	|a - x| < |b - x|, or
//	|a - x| == |b - x| and a < b
// 
//Example 1:
//Input: arr = [1,2,3,4,5], k = 4, x = 3
//Output: [1,2,3,4]
//Example 2:
//Input: arr = [1,1,2,3,4,5], k = 4, x = -1
//Output: [1,1,2,3]
// 
//Constraints:
//	1 <= k <= arr.length
//	1 <= arr.length <= 104
//	arr is sorted in ascending order.
//	-104 <= arr[i], x <= 104
class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        List<Integer> result = new ArrayList<>();
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] == b[0] ? b[1] - a[1] : b[0] - a[0]);
        for(int i=0;i<arr.length;i++){
            pq.add(new int[]{Math.abs(arr[i]-x),arr[i]});
            if(pq.size()>k){
                pq.poll();
            }
        }
        while(!pq.isEmpty()){
            result.add(pq.poll()[1]);
        }
        Collections.sort(result);
        return result;
    }
}