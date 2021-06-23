class Solution {
public:

    void maxHeapify(int* arr, int i, int n){
        int left = 2*i+1;
        int right = 2*i+2;
        int largest = i;

        if(left<n && arr[left]>arr[largest])
            largest = left;
        if(right<n && arr[right]>arr[largest])
            largest = right;
        if(largest != i)
        {
            swap(&arr[i], &arr[largest]);
            maxHeapify(arr, largest, n);
        }
    }
    
    int getMax(int* arr, int n){
       return arr[0];
    }
    
    void buildHeap(int* arr, int n){
        for(int i=n/2-1; i>=0; --i)
            maxHeapify(arr, i, n);
    }

    void replaceElement(int* arr, int out, int in, unordered_map<int,int>& m){
        int out_index = m.find(out);
        arr[out_index] = in;
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int* arr = (int*)malloc(sizeof(int)* k);
        unordered_map<int,int> m;
        
        for(int i=0; i<k; ++i)
        {
            arr[i] = nums[i];
            m.insert(nums[i], i);
        }
        buildHeap(arr, k);   
        cout << getMax(arr, k);
        
        for(int i=1; i<=n-k; ++i){
            cout << getMax(arr, k) << " ";
            replaceElement(arr, nums[i-1], nums[i+k-1], m);
            Maxheapify(arr, k);
        }
    }
};