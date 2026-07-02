// iterative solution

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int row = 0;
        int col = n - 1;   

        while (row < m && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            }
            else if (matrix[row][col] > target) {
                col--;     
            }
            else {
                row++;      
            }
        }

        return false;
    }
};


//recursively
class Solution {
public:
    bool solve(vector<vector<int>>& matrix, int row, int col, int target) {
        int m = matrix.size();


        if (row >= m || col < 0)
            return false;


        if (matrix[row][col] == target)
            return true;

        
        if (matrix[row][col] > target)
            return solve(matrix, row, col - 1, target);

        
        return solve(matrix, row + 1, col, target);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();

        return solve(matrix, 0, n - 1, target);
    }
};