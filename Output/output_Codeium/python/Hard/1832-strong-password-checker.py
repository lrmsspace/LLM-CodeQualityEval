#https://leetcode.com/problems/strong-password-checker/
#A password is considered strong if the below conditions are all met:
#	It has at least 6 characters and at most 20 characters.
#	It contains at least one lowercase letter, at least one uppercase letter, and at least one digit.
#	It does not contain three repeating characters in a row (i.e., "Baaabb0" is weak, but "Baaba0" is strong).
#Given a string password, return the minimum number of steps required to make password strong. if password is already strong, return 0.
#In one step, you can:
#	Insert one character to password,
#	Delete one character from password, or
#	Replace one character of password with another character.
# 
#Example 1:
#Input: password = "a"
#Output: 5
#Example 2:
#Input: password = "aA1"
#Output: 3
#Example 3:
#Input: password = "1337C0d3"
#Output: 0
# 
#Constraints:
#	1 <= password.length <= 50
#	password consists of letters, digits, dot '.' or exclamation mark '!'.
class Solution(object):
    def strongPasswordChecker(self, password):
        """
        :type password: str
        :rtype: int
        """
        missing_type = 3
        if any('a' <= c <= 'z' for c in password): missing_type -= 1
        if any('A' <= c <= 'Z' for c in password): missing_type -= 1
        if any(c.isdigit() for c in password): missing_type -= 1

        if len(password) < 6:
            return max(missing_type, 6 - len(password))
        elif len(password) <= 20:
            if missing_type > 0: return missing_type
            l, count, consecutive = 1, 1, '.!0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'
            for i in range(1, len(password)):
                if password[i] == password[i-1]:
                    count += 1
                else:
                    if count >= 3: l += count - 2
                    count = 1
            if count >= 3: l += count - 2
            return l
        else:
            hasLower, hasUpper, hasDigit = False, False, False
            for c in password:
                if c.islower(): hasLower = True
                if c.isupper(): hasUpper = True
                if c.isdigit(): hasDigit = True
            if not (hasLower and hasUpper and hasDigit): return len(password) - 20 + 1
            l, count, consecutive = 1, 1, '.!0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'
            for i in range(1, len(password)):
                if password[i] == password[i-1]:
                    count += 1
                else:
                    if count >= 3: l += count - 2
                    count = 1
            if count >= 3: l += count - 2
            return max(l, len(password) - 20)
