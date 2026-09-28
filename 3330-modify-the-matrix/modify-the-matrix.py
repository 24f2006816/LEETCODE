class Solution:
    def modifiedMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        m = len(matrix)
        n = len(matrix[0])

        col_max = [0]*n

        for j in range(n):
            for i in range(m):
                col_max[j] = max(col_max[j], matrix[i][j])

        for i in range(m):
            for j in range(n):
                if matrix[i][j] == -1:
                    matrix[i][j] = col_max[j]

        return matrix