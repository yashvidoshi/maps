class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<unordered_map<int, int>> rowMap(9), colMap(9), boxMap(9);
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }
                int num = board[i][j] - '0';
                int box_no = (i / 3) * 3 + (j / 3);

                if (++rowMap[i][num] > 1 || ++colMap[j][num] > 1 || ++boxMap[box_no][num] > 1)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
