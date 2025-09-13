# You are given a string num which represents a positive integer, and an integer t.
# A number is called zero-free if none of its digits are 0.
# Return a string representing the smallest zero-free number greater than or equal to num such that the product of its digits is divisible by t. If no such number exists, return "-1".
# Example 1:
# Input: num = "1234", t = 256
# Output: "1488"
# Explanation:
# The smallest zero-free number that is greater than 1234 and has the product of its digits divisible by 256 is 1488, with the product of its digits equal to 256.
# Example 2:
# Input: num = "12355", t = 50
# Output: "12355"
# Explanation:
# 12355 is already zero-free and has the product of its digits divisible by 50, with the product of its digits equal to 150.
# Example 3:
# Input: num = "11111", t = 26
# Output: "-1"
# Explanation:
# No number greater than 11111 has the product of its digits divisible by 26.
# Constraints:
# 2 <= num.length <= 2 * 105
# num consists only of digits in the range ['0', '9'].
# num does not contain leading zeros.
# 1 <= t <= 1014

class Solution(object):
    def smallestNumber(self, num, t):
        """
        :type num: str
        :type t: int
        :rtype: str
        """
        # 如果t是0，那么只有包含0的数才能满足条件，但题目要求zero-free
        if t == 0:
            return "-1"
        
        # 如果t是1，那么任何数都能满足条件，直接返回num本身
        if t == 1:
            return num
        
        # 将t分解为质因数
        from collections import defaultdict
        factors = {2:0, 3:0, 5:0, 7:0}
        
        temp_t = t
        for factor in [2, 3, 5, 7]:
            while temp_t % factor == 0:
                factors[factor] += 1
                temp_t //= factor
        
        # 如果剩余部分不为1，说明有大于7的质因数，无法用数字(1-9)的乘积得到
        if temp_t > 1:
            return "-1"
        
        # 将num字符串转换为数字列表
        digits = [int(d) for d in num]
        
        # 从后向前尝试修改数字
        for i in range(len(digits)-1, -1, -1):
            current_digit = digits[i]
            
            # 对于当前位，尝试所有可能的值
            for new_digit in range(current_digit+1, 10):
                if new_digit == 0:
                    continue  # 跳过0
                
                # 计算将当前位改为new_digit，并将后面所有位设为最小值(非0)
                new_digits = digits[:i] + [new_digit] + [1] * (len(digits)-i-1)
                
                # 计算新的数字的乘积的质因数分解
                new_factors = defaultdict(int)
                for d in new_digits:
                    for factor, count in self.factorize(d).items():
                        new_factors[factor] += count
                
                # 检查是否满足t的因数要求
                satisfied = True
                for factor, count in factors.items():
                    if new_factors.get(factor, 0) < count:
                        satisfied = False
                        break
                
                if satisfied:
                    # 构建结果字符串
                    return ''.join(str(d) for d in new_digits)
        
        # 如果没有找到更大的数能满足条件，检查当前数
        current_product_factors = defaultdict(int)
        for d in digits:
            for factor, count in self.factorize(d).items():
                current_product_factors[factor] += count
        
        satisfied = True
        for factor, count in factors.items():
            if current_product_factors.get(factor, 0) < count:
                satisfied = False
        
        if satisfied:
            return num
        
        return "-1"
    
    def factorize(self, n):
        """将n分解为基本质因数"""
        factors = {2:0, 3:0, 5:0, 7:0}
        primes = [2, 3, 5, 7]
        for p in primes:
            while n % p == 0:
                factors[p] += 1
                n //= p
        return factors