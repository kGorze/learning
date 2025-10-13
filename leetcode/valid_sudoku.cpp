#include <vector>
#include <unordered_set>
#include <cstdio>

using Board = std::vector<std::vector<char>>;

bool valid_sudoku(const Board& board) {
    auto to_int = [](char ch) -> int {
        if (ch == '.') return 0;            // empty cell
        if (ch >= '1' && ch <= '9') return ch - '0';
        return -1; // invalid character
    };
    
    // rows and columns
    for (int i = 0; i < 9; ++i) {
        std::unordered_set<int> r, c;
        for (int j = 0; j < 9; ++j) {
            int vr = to_int(board[i][j]);
            int vc = to_int(board[j][i]);
            if (vr == -1 || vc == -1) return false;

            if (vr != 0) {
                if (vr < 1 || vr > 9) return false;
                if (r.count(vr)) return false;
                r.insert(vr);
            }
            if (vc != 0) {
                if (vc < 1 || vc > 9) return false;
                if (c.count(vc)) return false;
                c.insert(vc);
            }
        }
    }

    // 3x3 subgrids
    for (int br = 0; br < 9; br += 3) {
        for (int bc = 0; bc < 9; bc += 3) {
            std::unordered_set<int> b;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int v = to_int(board[br + i][bc + j]);
                    if (v == -1) return false;
                    if (v == 0) continue;
                    if (v < 1 || v > 9) return false;
                    if (b.count(v)) return false;
                    b.insert(v);
                }
            }
        }
    }
    return true;
}

int main() {
    Board board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},

        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},

        {'0','6','.','.','.','.','2','8','.'},
        {'0','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'},
    };

    printf(valid_sudoku(board) ? "valid\n" : "invalid\n");
}