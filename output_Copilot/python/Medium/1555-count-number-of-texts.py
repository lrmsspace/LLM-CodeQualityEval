#https://leetcode.com/problems/count-number-of-texts/
#Alice is texting Bob using her phone. The mapping of digits to letters is shown in the figure below.
#In order to add a letter, Alice has to press the key of the corresponding digit i times, where i is the position of the letter in the key.
#	For example, to add the letter 's', Alice has to press '7' four times. Similarly, to add the letter 'k', Alice has to press '5' twice.
#	Note that the digits '0' and '1' do not map to any letters, so Alice does not use them.
#However, due to an error in transmission, Bob did not receive Alice's text message but received a string of pressed keys instead.
#	For example, when Alice sent the message "bob", Bob received the string "2266622".
#Given a string pressedKeys representing the string received by Bob, return the total number of possible text messages Alice could have sent.
#Since the answer may be very large, return it modulo 109 + 7.
# 
#Example 1:
#Input: pressedKeys = "22233"
#Output: 8
#Explanation:
#The possible text messages Alice could have sent are:
#"aaadd", "abdd", "badd", "cdd", "aaae", "abe", "bae", and "ce".
#Since there are 8 possible messages, we return 8.
#Example 2:
#Input: pressedKeys = "222222222222222222222222222222222222"
#Output: 82876089
#Explanation:
#There are 2082876103 possible text messages Alice could have sent.
#Since we need to return the answer modulo 109 + 7, we return 2082876103 % (109 + 7) = 82876089.
# 
#Constraints:
#	1 <= pressedKeys.length <= 105
#	pressedKeys only consists of digits from '2' - '9'.
class Solution(object):
    def countTexts(self, pressedKeys):
        """
        :type pressedKeys: str
        :rtype: int
        """
        dp = [0] * (len(pressedKeys) + 1)
        dp[0] = 1
        mod = 10 ** 9 + 7

        for i in range(1, len(pressedKeys) + 1):
            if pressedKeys[i - 1] == '7' or pressedKeys[i - 1] == '9':
                dp[i] = dp[i - 1]
                if i >= 2 and pressedKeys[i - 1] == pressedKeys[i - 2]:
                    dp[i] += dp[i - 2]
                if i >= 3 and pressedKeys[i - 1] == pressedKeys[i - 2] == pressedKeys[i - 3]:
                    dp[i] += dp[i - 3]
                if i >= 4 and pressedKeys[i - 1] == pressedKeys[i - 2] == pressedKeys[i - 3] == pressedKeys[i - 4]:
                    dp[i] += dp[i - 4]
            else:
                dp[i] = dp[i - 1]
                if i >= 2 and pressedKeys[i - 1] == pressedKeys[i - 2]:
                    dp[i] += dp[i - 2]
                if i >= 3 and pressedKeys[i - 1] == pressedKeys[i - 2] == pressedKeys[i - 3]:
                    dp[i] += dp[i - 3]

            dp[i] %= mod

        return dp[len(pressedKeys)] % mod        