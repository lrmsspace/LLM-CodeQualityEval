#https://leetcode.com/problems/count-days-spent-together/
#Alice and Bob are traveling to Rome for separate business meetings.
#You are given 4 strings arriveAlice, leaveAlice, arriveBob, and leaveBob. Alice will be in the city from the dates arriveAlice to leaveAlice (inclusive), while Bob will be in the city from the dates arriveBob to leaveBob (inclusive). Each will be a 5-character string in the format "MM-DD", corresponding to the month and day of the date.
#Return the total number of days that Alice and Bob are in Rome together.
#You can assume that all dates occur in the same calendar year, which is not a leap year. Note that the number of days per month can be represented as: [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31].
# 
#Example 1:
#Input: arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19"
#Output: 3
#Explanation: Alice will be in Rome from August 15 to August 18. Bob will be in Rome from August 16 to August 19. They are both in Rome together on August 16th, 17th, and 18th, so the answer is 3.
#Example 2:
#Input: arriveAlice = "10-01", leaveAlice = "10-31", arriveBob = "11-01", leaveBob = "12-31"
#Output: 0
#Explanation: There is no day when Alice and Bob are in Rome together, so we return 0.
# 
#Constraints:
#	All dates are provided in the format "MM-DD".
#	Alice and Bob's arrival dates are earlier than or equal to their leaving dates.
#	The given dates are valid dates of a non-leap year.
class Solution(object):
    def countDaysTogether(self, arriveAlice, leaveAlice, arriveBob, leaveBob):
        """
        :type arriveAlice: str
        :type leaveAlice: str
        :type arriveBob: str
        :type leaveBob: str
        :rtype: int
        """
        alice_start, alice_end = map(int,arriveAlice.split("-")), map(int,leaveAlice.split("-"))
        bob_start, bob_end = map(int,arriveBob.split("-")), map(int,leaveBob.split("-"))
        alice_start, alice_end = alice_start[2], alice_end[2]
        bob_start, bob_end = bob_start[2], bob_end[2]
        
        if alice_start > bob_end or bob_start > alice_end:
            return 0
        
        return min(alice_end, bob_end) - max(alice_start, bob_start) + 1