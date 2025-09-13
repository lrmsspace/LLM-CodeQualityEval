#https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/
#There are n items each belonging to zero or one of m groups where group[i] is the group that the i-th item belongs to and it's equal to -1 if the i-th item belongs to no group. The items and the groups are zero indexed. A group can have no item belonging to it.
#Return a sorted list of the items such that:
#	The items that belong to the same group are next to each other in the sorted list.
#	There are some relations between these items where beforeItems[i] is a list containing all the items that should come before the i-th item in the sorted array (to the left of the i-th item).
#Return any solution if there is more than one solution and return an empty list if there is no solution.
# 
#Example 1:
#Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3,6],[],[],[]]
#Output: [6,3,4,1,5,2,0,7]
#Example 2:
#Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3],[],[4],[]]
#Output: []
#Explanation: This is the same as example 1 except that 4 needs to be before 6 in the sorted list.
# 
#Constraints:
#	1 <= m <= n <= 3 * 104
#	group.length == beforeItems.length == n
#	-1 <= group[i] <= m - 1
#	0 <= beforeItems[i].length <= n - 1
#	0 <= beforeItems[i][j] <= n - 1
#	i != beforeItems[i][j]
#	beforeItems[i] does not contain duplicates elements.
class Solution(object):
    def sortItems(self, n, m, group, beforeItems):
        """
        :type n: int
        :type m: int
        :type group: List[int]
        :type beforeItems: List[List[int]]
        :rtype: List[int]
        """
        group_id = m
        for i in range(n):
            if group[i] == -1:
                group[i] = group_id
                group_id += 1
        g_num = group_id
        g_in = [0] * g_num
        g_out = [[] for _ in range(g_num)]
        item_in = [0] * n
        item_out = [[] for _ in range(n)]
        for i in range(n):
            for j in beforeItems[i]:
                if group[i] == group[j]:
                    item_in[i] += 1
                    item_out[j].append(i)
                else:
                    g_in[group[i]] += 1
                    g_out[group[j]].append(group[i])
        g_q = [i for i in range(g_num) if g_in[i] == 0]
        g_q = sorted(g_q)
        i_q = [i for i in range(n) if item_in[i] == 0]
        i_q = sorted(i_q)
        g_s = []
        i_s = []
        while g_q or i_q:
            if g_q:
                g = g_q.pop(0)
                g_s.append(g)
                for gg in g_out[g]:
                    g_in[gg] -= 1
                    if g_in[gg] == 0:
                        g_q.append(gg)
                        g_q = sorted(g_q)
            if i_q:
                i = i_q.pop(0)
                i_s.append(i)
                for ii in item_out[i]:
                    item_in[ii] -= 1
                    if item_in[ii] == 0:
                        i_q.append(ii)
                        i_q = sorted(i_q)
        return i_s + g_s if len(i_s) + len(g_s) == n else []