/*
 You are given a binary array nums of length n, a positive integer k and a non-negative integer maxChanges.
 Alice plays a game, where the goal is for Alice to pick up k ones from nums using the minimum number of moves. When the game starts, Alice picks up any index aliceIndex in the range [0, n - 1] and stands there. If nums[aliceIndex] == 1 , Alice picks up the one and nums[aliceIndex] becomes 0(this does not count as a move). After this, Alice can make any number of moves (including zero) where in each move Alice must perform exactly one of the following actions:
 Select any index j != aliceIndex such that nums[j] == 0 and set nums[j] = 1. This action can be performed at most maxChanges times.
 Select any two adjacent indices x and y (|x - y| == 1) such that nums[x] == 1, nums[y] == 0, then swap their values (set nums[y] = 1 and nums[x] = 0). If y == aliceIndex, Alice picks up the one after this move and nums[y] becomes 0.
 Return the minimum number of moves required by Alice to pick exactly k ones.
 Example 1:
 Input: nums = [1,1,0,0,0,1,1,0,0,1], k = 3, maxChanges = 1
 Output: 3
 Explanation: Alice can pick up 3 ones in 3 moves, if Alice performs the following actions in each move when standing at aliceIndex == 1:
 At the start of the game Alice picks up the one and nums[1] becomes 0. nums becomes [1,0,0,0,0,1,1,0,0,1].
 Select j == 2 and perform an action of the first type. nums becomes [1,0,1,0,0,1,1,0,0,1]
 Select x == 2 and y == 1, and perform an action of the second type. nums becomes [1,1,0,0,0,1,1,0,0,1]. As y == aliceIndex, Alice picks up the one and nums becomes [1,0,0,0,0,1,1,0,0,1].
 Select x == 0 and y == 1, and perform an action of the second type. nums becomes [0,1,0,0,0,1,1,0,0,1]. As y == aliceIndex, Alice picks up the one and nums becomes [0,0,0,0,0,1,1,0,0,1].
 Note that it may be possible for Alice to pick up 3 ones using some other sequence of 3 moves.
 Example 2:
 Input: nums = [0,0,0,0], k = 2, maxChanges = 3
 Output: 4
 Explanation: Alice can pick up 2 ones in 4 moves, if Alice performs the following actions in each move when standing at aliceIndex == 0:
 Select j == 1 and perform an action of the first type. nums becomes [0,1,0,0].
 Select x == 1 and y == 0, and perform an action of the second type. nums becomes [1,0,0,0]. As y == aliceIndex, Alice picks up the one and nums becomes [0,0,0,0].
 Select j == 1 again and perform an action of the first type. nums becomes [0,1,0,0].
 Select x == 1 and y == 0 again, and perform an action of the second type. nums becomes [1,0,0,0]. As y == aliceIndex, Alice picks up the one and nums becomes [0,0,0,0].
 Constraints:
 2 <= n <= 105
 0 <= nums[i] <= 1
 1 <= k <= 105
 0 <= maxChanges <= 105
 maxChanges + sum(nums) >= k
*/

long long minimumMoves(int* nums, int numsSize, int k, int maxChanges) {
    long long ans = 0;
    int cnt = 0, n = numsSize, i, j, l, r;
    
    // Count the number of ones in the array
    for (i = 0; i < n; i++) {
        if (nums[i] == 1) {
            cnt++;
        }
    }
    
    // If there are not enough ones, return -1
    if (cnt < k) {
        return -1;
    }
    
    // Initialize the left and right pointers
    l = 0;
    r = 0;
    
    // Loop until we have picked k ones
    while (k > 0) {
        // Move the right pointer to find the next one
        while (r < n && nums[r] == 0) {
            r++;
        }
        
        // If we reached the end of the array, break
        if (r == n) {
            break;
        }
        
        // If we can pick this one, do it
        if (nums[r] == 1) {
            ans += r - l; // Count the moves to reach this one
            k--;
            nums[r] = 0; // Pick up the one
            cnt--;
        }
        
        // Move the left pointer to find the next zero
        while (l < n && nums[l] == 1) {
            l++;
        }
        
        // If we reached the end of the array, break
        if (l == n) {
            break;
        }
        
        // If we can change a zero to one, do it
        if (maxChanges > 0 && cnt < k) {
            nums[l] = 1; // Change zero to one
            maxChanges--;
            cnt++;
            ans++; // Count this as a move
        }
        
        r++; // Move to the next position
    }
    
    return ans;    
}