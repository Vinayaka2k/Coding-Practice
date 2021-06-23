class Solution {
public:
    void merge(vector<int> &arr, int l, int m, int r){
        int n1 = m-l+1;
        int n2 = r-m;
        int L[n1], R[n2];
        for(int i=0; i<n1; ++i){
            L[i] = arr[i+l];
        }
        for(int i=0; i<n2; ++i){
            R[i] = arr[i+m+1];
        }
        
        int i=0, j=0, k=l;
        while(i<n1 && j<n2){
            if(L[i]<=R[j]){
                arr[k] = L[i];
                ++i;
            }
            else{
                arr[k] = R[j];
                ++j;
            }
            ++k;
        }
        while(i<n1){
            arr[k] = L[i];
            ++k; ++i;
        }
        while(j<n2){
            arr[k] = R[j];
            ++j; ++k;
        }
    }
    
    void mergeSort(vector<int> &arr, int l, int r){
        if(l>=r)
            return;
        else{
            int m = l + (r-l)/2;
            mergeSort(arr, l, m);
            mergeSort(arr, m+1, r);
            merge(arr, l, m, r);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n-1);
        return nums;
    }
};