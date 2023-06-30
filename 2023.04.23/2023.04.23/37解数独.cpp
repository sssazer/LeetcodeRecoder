#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<unordered_set<int>> colShows; // 记录每一列出现过的元素
    vector<unordered_set<int>> rowShows; // 记录每一行出现过的元素
    vector<unordered_set<int>> squareShows; // 记录每一个3x3宫内出现过的元素
    // vector<vector<char>> result;

    bool traceback(vector<vector<char>>& board, int row, int col) {
        // cout << "row: " << row << " col: " << col << endl;
        if (row >= board.size() || col >= board.size()) {
            // cout << "find it" << endl;
            // result = board;
            return true;
        }
        if (board[row][col] != '.') { // 如果数独中这个位置本来就有数字了，就直接遍历下一个位置
            if (col + 1 >= board.size()) {
                if(traceback(board, row + 1, 0)) return true;
            }
            else {
                if (traceback(board, row, col + 1)) return true;;
            }
            return false;
        }
        for (int i = 1; i <= 9; i++) { // 将1~9分别放入空白位置中，看能否成立
            if (colShows[col].find(i) == colShows[col].end() && rowShows[row].find(i) == rowShows[row].end() && squareShows[row / 3 * 3 + col / 3].find(i) == squareShows[row / 3 * 3 + col / 3].end()) { // 如果这个数字满足要求1.2.3.
                unordered_set<int>::iterator cit = colShows[col].insert(i).first;
                unordered_set<int>::iterator rit = rowShows[row].insert(i).first;
                unordered_set<int>::iterator sit = squareShows[row / 3 * 3 + col / 3].insert(i).first;
                board[row][col] = i + '0';
				if (col + 1 >= board.size()) {
                    if (traceback(board, row + 1, 0)) return true;
				}
				else {
					if(traceback(board, row, col + 1)) return true;
				}
                // 回溯
                colShows[col].erase(cit);
                rowShows[row].erase(rit);
                squareShows[row / 3 * 3 + col / 3].erase(sit);
                board[row][col] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        colShows = vector<unordered_set<int>>(9, unordered_set<int>());
        rowShows = vector<unordered_set<int>>(9, unordered_set<int>());
        squareShows = vector<unordered_set<int>>(9, unordered_set<int>());
        for (int i = 0; i < board.size(); i++) { // 遍历board，把已经存在的数字的位置记录下来
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] != '.') {
                    colShows[j].insert(board[i][j] - '0');
                    rowShows[i].insert(board[i][j] - '0');
                    squareShows[i / 3 * 3+ j / 3].insert(board[i][j] - '0');
                }
            }
        }
        traceback(board, 0, 0);
        // cout << "res:" << res << endl;
        // cout << "result:" << result.size() << endl;
        // board = result;
    }
};

int main() {

    Solution s;
    vector<vector<char>> board = { 
        {'5','3','.','.','7','.','.','.','.'} ,
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    s.solveSudoku(board);
    cout << board.size() << endl;
	return 0;
}