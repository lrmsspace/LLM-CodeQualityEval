#https://leetcode.com/problems/find-players-with-zero-or-one-losses/
#You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the player winneri defeated player loseri in a match.
#Return a list answer of size 2 where:
#	answer[0] is a list of all players that have not lost any matches.
#	answer[1] is a list of all players that have lost exactly one match.
#The values in the two lists should be returned in increasing order.
#Note:
#	You should only consider the players that have played at least one match.
#	The testcases will be generated such that no two matches will have the same outcome.
# 
#Example 1:
#Input: matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
#Output: [[1,2,10],[4,5,7,8]]
#Explanation:
#Players 1, 2, and 10 have not lost any matches.
#Players 4, 5, 7, and 8 each have lost one match.
#Players 3, 6, and 9 each have lost two matches.
#Thus, answer[0] = [1,2,10] and answer[1] = [4,5,7,8].
#Example 2:
#Input: matches = [[2,3],[1,3],[5,4],[6,4]]
#Output: [[1,2,5,6],[]]
#Explanation:
#Players 1, 2, 5, and 6 have not lost any matches.
#Players 3 and 4 each have lost two matches.
#Thus, answer[0] = [1,2,5,6] and answer[1] = [].
# 
#Constraints:
#	1 <= matches.length <= 105
#	matches[i].length == 2
#	1 <= winneri, loseri <= 105
#	winneri != loseri
#	All matches[i] are unique.
class Solution(object):
    def findWinners(self, matches):
        """
        :type matches: List[List[int]]
        :rtype: List[List[int]]
        """
        from collections import defaultdict

        # 统计每个玩家的输赢情况
        win_count = defaultdict(int)
        lose_count = defaultdict(int)

        for winner, loser in matches:
            win_count[winner] += 1
            lose_count[loser] += 1

        # 找到没有输过的玩家和只输过一场的玩家
        no_loss = []
        one_loss = []

        for player in set(win_count.keys()).union(set(lose_count.keys())):
            if lose_count[player] == 0:
                no_loss.append(player)
            elif lose_count[player] == 1:
                one_loss.append(player)

        return [sorted(no_loss), sorted(one_loss)]        