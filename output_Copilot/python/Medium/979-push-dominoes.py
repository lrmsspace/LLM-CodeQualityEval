#https://leetcode.com/problems/push-dominoes/
#There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.
#After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.
#When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.
#For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.
#You are given a string dominoes representing the initial state where:
#	dominoes[i] = 'L', if the ith domino has been pushed to the left,
#	dominoes[i] = 'R', if the ith domino has been pushed to the right, and
#	dominoes[i] = '.', if the ith domino has not been pushed.
#Return a string representing the final state.
# 
#Example 1:
#Input: dominoes = "RR.L"
#Output: "RR.L"
#Explanation: The first domino expends no additional force on the second domino.
#Example 2:
#Input: dominoes = ".L.R...LR..L.."
#Output: "LL.RR.LLRRLL.."
# 
#Constraints:
#	n == dominoes.length
#	1 <= n <= 105
#	dominoes[i] is either 'L', 'R', or '.'.
class Solution(object):
    def pushDominoes(self, dominoes):
        """
        :type dominoes: str
        :rtype: str
        """
        dominoes = list(dominoes)
        n = len(dominoes)
        left = [0] * n
        right = [0] * n

        # 计算每个点向左推的力
        for i in range(n):
            if dominoes[i] == 'R':
                j = i + 1
                while j < n and dominoes[j] == '.':
                    left[j] += 1
                    j += 1

        # 计算每个点向右推的力
        for i in range(n - 1, -1, -1):
            if dominoes[i] == 'L':
                j = i - 1
                while j >= 0 and dominoes[j] == '.':
                    right[j] += 1
                    j -= 1

        # 更新每个点的状态
        for i in range(n):
            if left[i] > right[i]:
                dominoes[i] = 'L'
            elif left[i] < right[i]:
                dominoes[i] = 'R'
            else:
                dominoes[i] = '.'

        return ''.join(dominoes)        