class Solution:
    def numberOfSubarrays(self, nums: List[int]) -> int:
        ans = 0
        st = []

        for x in nums:
            while st and st[-1][0] < x:
                st.pop()

            if st and st[-1][0] == x:
                ans += st[-1][1]
                st[-1][1] += 1
            else:
                st.append([x,1])
            
            ans += 1
        return ans