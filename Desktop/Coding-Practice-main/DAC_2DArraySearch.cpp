class Solution {
public:
    bool search(vector<vector<int>>& arr, int fromRow, int toRow, int fromCol, int toCol, int key){
        if(fromRow > toRow || fromCol > toCol)
            return false;
        
        int x = fromRow + (toRow-fromRow)/2;
        int y = fromCol + (toCol - fromCol)/2;
        int mid_ele = arr[x][y];
        
        if(key == mid_ele){
            cout << fromRow << "," << toRow << " " << fromCol << "," << toCol << endl;
            return true;
        }
        else if(key > mid_ele)
            return search(arr, x+1, toRow, fromCol, toCol, key) || 
                search(arr, fromRow, x, y+1, toCol, key);
        else
            return search(arr, fromRow, x-1, fromCol, toCol, key) ||
                search(arr, x, toRow, fromCol, y-1, key);
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        return search(matrix, 0, m-1, 0, n-1, target);
    }
};