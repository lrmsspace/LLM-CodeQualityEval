#https://leetcode.com/problems/minimum-number-of-people-to-teach/
#On a social network consisting of m users and some friendships between users, two users can communicate with each other if they know a common language.
#You are given an integer n, an array languages, and an array friendships where:
#	There are n languages numbered 1 through n,
#	languages[i] is the set of languages the i​​​​​​th​​​​ user knows, and
#	friendships[i] = [u​​​​​​i​​​, v​​​​​​i] denotes a friendship between the users u​​​​​​​​​​​i​​​​​ and vi.
#You can choose one language and teach it to some users so that all friends can communicate with each other. Return the minimum number of users you need to teach.
#Note that friendships are not transitive, meaning if x is a friend of y and y is a friend of z, this doesn't guarantee that x is a friend of z.
# 
#Example 1:
#Input: n = 2, languages = [[1],[2],[1,2]], friendships = [[1,2],[1,3],[2,3]]
#Output: 1
#Explanation: You can either teach user 1 the second language or user 2 the first language.
#Example 2:
#Input: n = 3, languages = [[2],[1,3],[1,2],[3]], friendships = [[1,4],[1,2],[3,4],[2,3]]
#Output: 2
#Explanation: Teach the third language to users 1 and 3, yielding two users to teach.
# 
#Constraints:
#	2 <= n <= 500
#	languages.length == m
#	1 <= m <= 500
#	1 <= languages[i].length <= n
#	1 <= languages[i][j] <= n
#	1 <= u​​​​​​i < v​​​​​​i <= languages.length
#	1 <= friendships.length <= 500
#	All tuples (u​​​​​i, v​​​​​​i) are unique
#	languages[i] contains only unique values
class Solution(object):
    def minimumTeachings(self, n, languages, friendships):
        """
        :type n: int
        :type languages: List[List[int]]
        :type friendships: List[List[int]]
        :rtype: int
        """
        # Create an adjacency list for the friendships
        adj_list = [set() for _ in range(n)]
        for u, v in friendships:
            adj_list[u-1].add(v-1)
            adj_list[v-1].add(u-1)
        
        # Count the number of languages each user knows
        languages_count = [len(languages[i]) for i in range(n)]
        
        # Sort the languages based on the number of users they know
        languages.sort(key=lambda x: languages_count[x[0]-1])
        
        # Initialize the minimum number of users to teach
        min_users = n
        
        # Iterate over the sorted languages
        for i in range(len(languages)):
            language = languages[i][0] - 1
            
            # Check if the language can be taught to any user
            if languages_count[language] == 0:
                continue
        
        # Iterate over the remaining users
        for i in range(n):
            user = i
            
            # Check if the user has already been taught the language
            if languages_count[user] == 0:
                continue
            
            # Check if the user can be taught the language to all friends
            can_teach = True
            for friend in adj_list[user]:
                if languages_count[friend] == 0 or languages[friend][0]!= language:
                    can_teach = False
                    break
            
            # If the user can be taught the language to all friends, update the minimum number of users
            if can_teach:
                min_users = min(min_users, languages_count[user])
        
        return min_users
        