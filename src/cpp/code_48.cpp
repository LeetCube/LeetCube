// 48. Rotate Image (Medium)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        map<int, vector<int>> rows;
        map<int, vector<int>> cols;
        for (int i = 0; i < matrix.size(); i++) {
            rows[i] = matrix[i];
            cols[i] = col(matrix, i);
        }

        int n = matrix.size();
        vector<int> temp;
        vector<int> col_;
        for (int i = 0; i < n; i++) {
            
            temp = rows[i];
            matrix[i] = cols[i]; 
            col(matrix, i) = temp;
        }
    }

    vector<int> col(vector<vector<int>>& matrix, int k) {
        vector<int> col;
        int n = matrix.size();
        for (int j = n-1; j >= 0; j--) { 
            col.push_back(matrix[j][k]); 
        }
        return col; 
    }
};
