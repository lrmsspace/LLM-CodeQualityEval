# You are given an integer array receiver of length n and an integer k. n players are playing a ball-passing game.
# You choose the starting player, i. The game proceeds as follows: player i passes the ball to player receiver[i], who then passes it to receiver[receiver[i]], and so on, for k passes in total. The game's score is the sum of the indices of the players who touched the ball, including repetitions, i.e. i + receiver[i] + receiver[receiver[i]] + ... + receiver(k)[i].
# Return the maximum possible score.
# Notes:
# receiver may contain duplicates.
# receiver[i] may be equal to i.
# Example 1:
# Input: receiver = [2,0,1], k = 4
# Output: 6
# Explanation:
# Starting with player i = 2 the initial score is 2:
# Pass
# Sender Index
# Receiver Index
# Score
# 1
# 2
# 1
# 3
# 2
# 1
# 0
# 3
# 3
# 0
# 2
# 5
# 4
# 2
# 1
# 6
# Example 2:
# Input: receiver = [1,1,1,2,3], k = 3
# Output: 10
# Explanation:
# Starting with player i = 4 the initial score is 4:
# Pass
# Sender Index
# Receiver Index
# Score
# 1
# 4
# 3
# 7
# 2
# 3
# 2
# 9
# 3
# 2
# 1
# 10
# Constraints:
# 1 <= receiver.length == n <= 105
# 0 <= receiver[i] <= n - 1
# 1 <= k <= 1010

class Solution(object):
    def getMaxFunctionValue(self, receiver, k):
        """
        :type receiver: List[int]
        :type k: int
        :rtype: int
        """
        n = len(receiver)
        visited = [False] * n
        max_score = 0

        for i in range(n):
            if not visited[i]:
                cycle_sum = 0
                cycle_length = 0
                current = i

                # Find the cycle starting from i
                while not visited[current]:
                    visited[current] = True
                    cycle_sum += current
                    cycle_length += 1
                    current = receiver[current]

                # Calculate the maximum score for this cycle
                if cycle_length > 0:
                    full_cycles = k // cycle_length
                    remaining_passes = k % cycle_length
                    cycle_score = full_cycles * cycle_sum

                    # Add the score for the remaining passes
                    current = i
                    for _ in range(remaining_passes):
                        cycle_score += current
                        current = receiver[current]

                    max_score = max(max_score, cycle_score)

        return max_score        