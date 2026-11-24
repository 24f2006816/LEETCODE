class Solution(object):
    def maxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def gcd(a, b):
            while b:
                a, b = b, a % b
            return a

        def lcm(a, b):
            return a * b // gcd(a, b)

        n = len(nums)
        max_len = 0

        for i in range(n):
            product = 1
            current_gcd = 0
            current_lcm = 1
            for j in range(i, n):
                product *= nums[j]
                current_gcd = gcd(current_gcd, nums[j])  # Update GCD
                current_lcm = lcm(current_lcm, nums[j])  # Update LCM
                
                if product == current_gcd * current_lcm:
                    max_len = max(max_len, j - i + 1)

        return max_len

# Example Usage
nums = [1, 2, 1, 2, 1, 1, 1]
solution = Solution()
print(solution.maxLength(nums))  # Output: 5