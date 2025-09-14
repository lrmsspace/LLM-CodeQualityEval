# Alice and Bob are playing a fantasy battle game consisting of n rounds where they summon one of three magical creatures each round: a Fire Dragon, a Water Serpent, or an Earth Golem. In each round, players simultaneously summon their creature and are awarded points as follows:
# If one player summons a Fire Dragon and the other summons an Earth Golem, the player who summoned the Fire Dragon is awarded a point.
# If one player summons a Water Serpent and the other summons a Fire Dragon, the player who summoned the Water Serpent is awarded a point.
# If one player summons an Earth Golem and the other summons a Water Serpent, the player who summoned the Earth Golem is awarded a point.
# If both players summon the same creature, no player is awarded a point.
# You are given a string s consisting of n characters 'F', 'W', and 'E', representing the sequence of creatures Alice will summon in each round:
# If s[i] == 'F', Alice summons a Fire Dragon.
# If s[i] == 'W', Alice summons a Water Serpent.
# If s[i] == 'E', Alice summons an Earth Golem.
# Bob’s sequence of moves is unknown, but it is guaranteed that Bob will never summon the same creature in two consecutive rounds. Bob beats Alice if the total number of points awarded to Bob after n rounds is strictly greater than the points awarded to Alice.
# Return the number of distinct sequences Bob can use to beat Alice.
# Since the answer may be very large, return it modulo 109 + 7.
# Example 1:
# Input: s = "FFF"
# Output: 3
# Explanation:
# Bob can beat Alice by making one of the following sequences of moves: "WFW", "FWF", or "WEW". Note that other winning sequences like "WWE" or "EWW" are invalid since Bob cannot make the same move twice in a row.
# Example 2:
# Input: s = "FWEFW"
# Output: 18
# Explanation:
# Bob can beat Alice by making one of the following sequences of moves: "FWFWF", "FWFWE", "FWEFE", "FWEWE", "FEFWF", "FEFWE", "FEFEW", "FEWFE", "WFEFE", "WFEWE", "WEFWF", "WEFWE", "WEFEF", "WEFEW", "WEWFW", "WEWFE", "EWFWE", or "EWEWE".
# Constraints:
# 1 <= s.length <= 1000
# s[i] is one of 'F', 'W', or 'E'.

class Solution(object):
    def countWinningSequences(self, s):
        """
        :type s: str
        :rtype: int
        """
        MOD = 10**9 + 7
        n = len(s)
        
        # Mapping from char to index
        ch_to_idx = {'F':0, 'W':1, 'E':2}
        idx_to_ch = {0:'F', 1:'W', 2:'E'}
        
        # dp[i % 2][last][diff + 1000]: number of ways at round i, ending with "last", score difference "diff"
        dp = [[[0] * 2001 for _ in range(3)] for _ in range(2)]
        
        # Initialize base case: before any rounds, one way with diff = 0
        dp[0][0][1000] = 1  # We can start with any first move
        
        for i in range(n):
            curr = i % 2
            next = (i + 1) % 2
            for last in range(3):
                for diff in range(1000 - i - 1, 1000 + i + 1 + 1):
                    if dp[curr][last][diff] == 0:
                        continue
                    # Try all possible moves for Bob this round
                    for curr_move in range(3):
                        if curr_move == last:
                            continue  # Bob cannot use same move twice in a row
                        alice_move = ch_to_idx[s[i]]
                        
                        # Determine who gets the point
                        b_win = (curr_move == 0 and alice_move == 2) or \
                                (curr_move == 1 and alice_move == 0) or \
                                (curr_move == 2 and alice_move == 1)
                        a_win = (alice_move == 0 and curr_move == 2) or \
                                (alice_move == 1 and curr_move == 0) or \
                                (alice_move == 2 and curr_move == 1)

                        new_diff = diff
                        if b_win:
                            new_diff += 1
                        elif a_win:
                            new_diff -= 1
                        
                        dp[next][curr_move][new_diff] = (
                            dp[next][curr_move][new_diff] + dp[curr][last][diff]
                        ) % MOD
        
        # Sum up all states where final score difference > 0
        res = 0
        final = n % 2
        for last in range(3):
            for diff in range(1001, 2001):  # > 0 => diff + 1000 > 1000
                res = (res + dp[final][last][diff]) % MOD
        return res