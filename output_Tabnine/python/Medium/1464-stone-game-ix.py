#https://leetcode.com/problems/stone-game-ix/
#Alice and Bob continue their games with stones. There is a row of n stones, and each stone has an associated value. You are given an integer array stones, where stones[i] is the value of the ith stone.
#Alice and Bob take turns, with Alice starting first. On each turn, the player may remove any stone from stones. The player who removes a stone loses if the sum of the values of all removed stones is divisible by 3. Bob will win automatically if there are no remaining stones (even if it is Alice's turn).
#Assuming both players play optimally, return true if Alice wins and false if Bob wins.
# 
#Example 1:
#Input: stones = [2,1]
#Output: true
#Explanation: The game will be played as follows:
#- Turn 1: Alice can remove either stone.
#- Turn 2: Bob removes the remaining stone. 
#The sum of the removed stones is 1 + 2 = 3 and is divisible by 3. Therefore, Bob loses and Alice wins the game.
#Example 2:
#Input: stones = [2]
#Output: false
#Explanation: Alice will remove the only stone, and the sum of the values on the removed stones is 2. 
#Since all the stones are removed and the sum of values is not divisible by 3, Bob wins the game.
#Example 3:
#Input: stones = [5,1,2,4,3]
#Output: false
#Explanation: Bob will always win. One possible way for Bob to win is shown below:
#- Turn 1: Alice can remove the second stone with value 1. Sum of removed stones = 1.
#- Turn 2: Bob removes the fifth stone with value 3. Sum of removed stones = 1 + 3 = 4.
#- Turn 3: Alices removes the fourth stone with value 4. Sum of removed stones = 1 + 3 + 4 = 8.
#- Turn 4: Bob removes the third stone with value 2. Sum of removed stones = 1 + 3 + 4 + 2 = 10.
#- Turn 5: Alice removes the first stone with value 5. Sum of removed stones = 1 + 3 + 4 + 2 + 5 = 15.
#Alice loses the game because the sum of the removed stones (15) is divisible by 3. Bob wins the game.
# 
#Constraints:
#	1 <= stones.length <= 105
#	1 <= stones[i] <= 104
class Solution(object):
    def stoneGameIX(self, stones):
        """
        :type stones: List[int]
        :rtype: bool
        """
        # Count the frequency of each stone value
        freq = [0] * 105
        for stone in stones:
            freq[stone] += 1
        
        # Initialize the total sum and the maximum difference
        total = sum(stones)
        max_diff = total - max(stones)
        
        # Initialize the two variables to keep track of the remaining stones
        alice_count = freq.copy()
        bob_count = freq.copy()
        
        # Iterate through the stones from the smallest value to the largest
        for stone in range(1, 105):
            # If Alice can remove the stone, update the count and the total sum
            if alice_count[stone] > 0:
                alice_count[stone] -= 1
                alice_count[stone - 1] += 1
                alice_count[stone + 1] += 1
                total -= stone
            
            # If Bob can remove the stone, update the count
            if bob_count[stone] > 0:
                bob_count[stone] -= 1
                bob_count[stone - 1] += 1
                bob_count[stone + 1] += 1
                total -= stone
            
            # Calculate the current difference between Alice and Bob
            diff = abs(total - alice_count[stone] * stone - bob_count[stone] * stone)
            
            # Update the maximum difference if necessary
            max_diff = max(max_diff, diff)
        
        # Return true if Alice wins, false otherwise
        return max_diff % 3 == 0
        