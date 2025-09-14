#https://leetcode.com/problems/find-the-town-judge/
#In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.
#If the town judge exists, then:
#	The town judge trusts nobody.
#	Everybody (except for the town judge) trusts the town judge.
#	There is exactly one person that satisfies properties 1 and 2.
#You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. If a trust relationship does not exist in trust array, then such a trust relationship does not exist.
#Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.
# 
#Example 1:
#Input: n = 2, trust = [[1,2]]
#Output: 2
#Example 2:
#Input: n = 3, trust = [[1,3],[2,3]]
#Output: 3
#Example 3:
#Input: n = 3, trust = [[1,3],[2,3],[3,1]]
#Output: -1
# 
#Constraints:
#	1 <= n <= 1000
#	0 <= trust.length <= 104
#	trust[i].length == 2
#	All the pairs of trust are unique.
#	ai != bi
#	1 <= ai, bi <= n
class Solution(object):
    def findJudge(self, n, trust):
        """
        :type n: int
        :type trust: List[List[int]]
        :rtype: int
        """
        # Initialize the trust count array
        trust_count = [0] * (n + 1)
        
        # Count the number of trusts each person receives
        for a, b in trust:
            trust_count[b] += 1
        
        # Find the person who trusts nobody (i.e., has a trust count of 0)
        for i in range(1, n + 1):
            if trust_count[i] == 0:
                judge = i
                break
        
        # Check if the judge exists and can be identified
        if judge is None:
            return -1
        
        # Check if the judge trusts everyone else
        for a, b in trust:
            if b == judge:
                return -1
        
        return judge
        