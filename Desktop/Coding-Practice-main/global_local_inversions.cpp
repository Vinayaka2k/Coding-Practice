class Solution {
public:
    long merge(vector<int>& arr, int low, int mid, int high){
            long inv_count = 0;

            int n1 = mid-low+1;
            int n2 = high-mid;

            int L[n1]; int R[n2];

            for(int i=0; i<n1; ++i){
                L[i] = arr[i+low];
            }
            for(int i=0; i<n2; ++i){
                R[i] = arr[mid+1+i];
            }

            int i=0;
            int k=low;
            int j=0;

            while(i<n1 && j<n2){
                if(L[i] <= R[j]){
                    arr[k] = L[i];
                    ++i;
                }
                else{
                    arr[k] = R[j];
                    ++j;
                    inv_count += n1-i;
                }
                ++k;
            }

            while(i<n1){
                arr[k] = L[i];
                ++i;
                ++k;
            }

            while(j<n2){
                arr[k] = R[j];
                ++j;
                ++k;
            }

        return inv_count;
    }

    long mergeSort(vector<int>& arr, int low, int high){
        long inv_count = 0;
        if(low < high){
                int mid = low+(high-low)/2;
                inv_count += mergeSort(arr, low, mid) + mergeSort(arr, mid+1, high) +                       merge(arr, low, mid, high);
            }
        return inv_count;
    }

    long localInversions(vector<int>& arr, int n){
        long inv_count = 0;
        for(int i=0; i<n-1; ++i){
            if(arr[i]>arr[i+1])
                inv_count++;
        }    
        return inv_count;
    }
    
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        long local = localInversions(nums, n);
        long global = mergeSort(nums, 0, n-1);
        cout << global << " " << local;
        return global == local;
    }
};