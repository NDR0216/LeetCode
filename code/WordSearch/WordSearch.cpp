class Solution {
public:
    vector<vector<char>> board;
    string word;
    bool** visited;
    
    bool DFS(int i,int j, int idx, bool** visited) {
        if (idx == word.length()) {	// match!!! return true
            return true;
        }
        if (i < 0 || i >=board.size() || j < 0 || j >=board[0].size() || word[idx] != board[i][j] || visited[i][j]) {
                return false;
        }

        visited[i][j] = true;

        if (DFS(i-1, j, idx+1, visited)) {	// up
            return true;
        }
        if (DFS(i+1, j, idx+1, visited)) {	// down
            return true;
        }
        if (DFS(i, j-1, idx+1, visited)) {	// left
            return true;
        }
        if (DFS(i, j+1, idx+1, visited)) {	// right
            return true;
        }
        
        visited[i][j] = false;
        return false; // all directions do not match, return false
    }

    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        this->word = word;
        
        // board is m * n, m rows, n columns
        // m = board.size()
        // n = board[0].size()

        // initialize visited array to all false        
        visited = new bool*[board.size()];
        for (int i = 0; i < board.size(); i++) {
            visited[i] = new bool[board[0].size()];
            for (int j = 0; j < board[0].size(); j++) {
                visited[i][j] = false;
            }
        }

        // iterate for each character in the board
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (DFS(i, j, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};
