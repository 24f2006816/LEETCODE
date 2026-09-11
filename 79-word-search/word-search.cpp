class Solution {
public:
    int rows, cols;

    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int index) {
        // Entire word found
        if (index == word.length()) {
            return true;
        }

        // Out of bounds
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return false;
        }

        // Wrong character or already visited
        if (board[r][c] != word[index]) {
            return false;
        }

        // Mark as visited
        char temp = board[r][c];
        board[r][c] = '#';

        // Explore 4 directions
        bool found =
            dfs(board, word, r + 1, c, index + 1) ||
            dfs(board, word, r - 1, c, index + 1) ||
            dfs(board, word, r, c + 1, index + 1) ||
            dfs(board, word, r, c - 1, index + 1);

        // Backtrack
        board[r][c] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};