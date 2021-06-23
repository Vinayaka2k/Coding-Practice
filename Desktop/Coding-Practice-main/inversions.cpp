#include<bits/stdc++.h>
using namespace std;
int merge(vector<int>& arr, int low, int mid, int high){
		int inv_count = 0;
		
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

int mergeSort(vector<int>& arr, int low, int high){
	int inv_count = 0;
	if(low < high){
			int mid = low+(high-low)/2;
			inv_count += mergeSort(arr, low, mid) + mergeSort(arr, mid+1, high) + merge(arr, low, mid, high);
		}
	return inv_count;
}

int main() {
        vector<int> nums = {4,1,2,7,3,9,5,8};
        int n = nums.size();
        mergeSort(nums, 0, n-1);
        for(int i=0; i<n; ++i)
        	cout << nums[i] << " ";
        cout << endl;
    }
