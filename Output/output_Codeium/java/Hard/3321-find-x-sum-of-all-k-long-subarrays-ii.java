/*
 You are given an array nums of n integers and two integers k and x.
 The x-sum of an array is calculated by the following procedure:
 Count the occurrences of all elements in the array.
 Keep only the occurrences of the top x most frequent elements. If two elements have the same number of occurrences, the element with the bigger value is considered more frequent.
 Calculate the sum of the resulting array.
 Note that if an array has less than x distinct elements, its x-sum is the sum of the array.
 Return an integer array answer of length n - k + 1 where answer[i] is the x-sum of the subarray nums[i..i + k - 1].
 Example 1:
 Input: nums = [1,1,2,2,3,4,2,3], k = 6, x = 2
 Output: [6,10,12]
 Explanation:
 For subarray [1, 1, 2, 2, 3, 4], only elements 1 and 2 will be kept in the resulting array. Hence, answer[0] = 1 + 1 + 2 + 2.
 For subarray [1, 2, 2, 3, 4, 2], only elements 2 and 4 will be kept in the resulting array. Hence, answer[1] = 2 + 2 + 2 + 4. Note that 4 is kept in the array since it is bigger than 3 and 1 which occur the same number of times.
 For subarray [2, 2, 3, 4, 2, 3], only elements 2 and 3 are kept in the resulting array. Hence, answer[2] = 2 + 2 + 2 + 3 + 3.
 Example 2:
 Input: nums = [3,8,7,8,7,5], k = 2, x = 2
 Output: [11,15,15,15,12]
 Explanation:
 Since k == x, answer[i] is equal to the sum of the subarray nums[i..i + k - 1].
 Constraints:
 nums.length == n
 1 <= n <= 105
 1 <= nums[i] <= 109
 1 <= x <= k <= nums.length
*/

class Solution {
    public long[] findXSum(int[] nums, int k, int x) {
        int n = nums.length;
        long[] answer = new long[n - k + 1];
        Map<Integer, Integer> countMap = new HashMap<>();
        PriorityQueue<int[]> maxHeap = new PriorityQueue<>(
            (a, b) -> a[1] != b[1] ? b[1] - a[1] : b[0] - a[0]
        );
        
        for (int i = 0; i < k; i++) {
            countMap.put(nums[i], countMap.getOrDefault(nums[i], 0) + 1);
        }
        
        for (Map.Entry<Integer, Integer> entry : countMap.entrySet()) {
            maxHeap.offer(new int[]{entry.getKey(), entry.getValue()});
        }
        
        answer[0] = calculateXSum(maxHeap, x);
        
        for (int i = k; i < n; i++) {
            int outElem = nums[i - k];
            int inElem = nums[i];
            
            countMap.put(outElem, countMap.get(outElem) - 1);
            if (countMap.get(outElem) == 0) {
                countMap.remove(outElem);
            }
            
            countMap.put(inElem, countMap.getOrDefault(inElem, 0) + 1);
            
            maxHeap.clear();
            for (Map.Entry<Integer, Integer> entry : countMap.entrySet()) {
                maxHeap.offer(new int[]{entry.getKey(), entry.getValue()});
            }
            
            answer[i - k + 1] = calculateXSum(maxHeap, x);
        }
        
        return answer;
    }
    
    private long calculateXSum(PriorityQueue<int[]> maxHeap, int x) {
        long sum = 0;
        List<int[]> tempList = new ArrayList<>();
        
        while (x > 0 && !maxHeap.isEmpty()) {
            int[] top = maxHeap.poll();
            int freq = Math.min(top[1], x);
            sum += (long) top[0] * freq;
            x -= freq;
            tempList.add(new int[]{top[0], top[1] - freq});
        }
        
        maxHeap.addAll(tempList);
        return sum;
    }
}