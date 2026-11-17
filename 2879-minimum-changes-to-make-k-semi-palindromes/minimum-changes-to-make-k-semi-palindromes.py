
class Solution:
    def minimumChanges(self, s: str, k: int) -> int:
        n = len(s)

        # Step 1: Precompute substring costs
        cost = [[0] * n for _ in range(n)]

        for l in range(n):
            for r in range(l + 1, n):
                length = r - l + 1
                best = float('inf')

                for d in range(1, length):
                    if length % d != 0:
                        continue

                    changes = 0

                    # Divide indices into d groups
                    for offset in range(d):
                        count = (length - 1 - offset) // d + 1

                        # Check palindrome condition
                        for t in range(count // 2):
                            left = l + offset + t * d
                            right = l + offset + (count - 1 - t) * d

                            if s[left] != s[right]:
                                changes += 1

                    best = min(best, changes)

                cost[l][r] = best

        # Step 2: DP
        INF = float('inf')
        dp = [[INF] * (k + 1) for _ in range(n + 1)]

        dp[0][0] = 0

        for groups in range(1, k + 1):
            for i in range(2 * groups, n + 1):
                for p in range(2 * (groups - 1), i - 1):

                    dp[i][groups] = min(
                        dp[i][groups],
                        dp[p][groups - 1] + cost[p][i - 1]
                    )

        return dp[n][k]
