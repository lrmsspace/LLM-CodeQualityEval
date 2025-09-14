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
        # Create a set to store the languages known by each user
        language_set = [set(lang) for lang in languages]

        # Create a set to store the users who need to be taught a language
        users_to_teach = set()

        # Iterate through each friendship
        for u, v in friendships:
            u -= 1
            v -= 1
            # Check if the users can communicate        
            if language_set[u].isdisjoint(language_set[v]):
                # If they can't, add both users to the set of users to teach
                users_to_teach.add(u)
                users_to_teach.add(v)
        # If there are no users to teach, return 0
        if not users_to_teach:
            return 0
        # Create a dictionary to count the number of users who know each language
        language_count = [0] * (n + 1)
        # Iterate through the users who need to be taught a language
        for user in users_to_teach:
            # Increment the count for each language known by the user
            for lang in language_set[user]:
                language_count[lang] += 1
        # Find the maximum count of users who know a language
        max_count = max(language_count)
        # Return the number of users to teach minus the maximum count
        return len(users_to_teach) - max_count  