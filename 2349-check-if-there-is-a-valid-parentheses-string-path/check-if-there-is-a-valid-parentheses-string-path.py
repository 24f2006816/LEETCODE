class Solution:
    def hasValidPath(self, grid):
        m = len(grid)
        n = len(grid[0])

        if (m + n - 1) % 2:
            return False

        if grid[0][0] == ')' or grid[m - 1][n - 1] == '(':
            return False

        memo = {}

        def dfs(r, c, balance):
            if balance < 0:
                return False

            remaining = (m - 1 - r) + (n - 1 - c)

            if balance > remaining:
                return False

            if r == m - 1 and c == n - 1:
                return balance == 0

            state = (r, c, balance)

            if state in memo:
                return memo[state]

            ans = False

            if r + 1 < m:
                nb = balance + (1 if grid[r + 1][c] == '(' else -1)
                ans |= dfs(r + 1, c, nb)

            if c + 1 < n:
                nb = balance + (1 if grid[r][c + 1] == '(' else -1)
                ans |= dfs(r, c + 1, nb)

            memo[state] = ans
            return ans

        return dfs(0, 0, 1)