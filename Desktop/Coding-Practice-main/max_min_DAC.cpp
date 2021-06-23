int DACFindMin(int *arr, int l, int r){
	if(l == r){
		return arr[l];
	else if(l == r-1)
		return min(arr[l], arr[r]);
	else	{
		int m = l+(r-1)/2;
		int left = DACFindMin(arr, l, m);
		int right = DACFindMin(arr, m+1, r);
		return min(left, right);
		}
	}
}

// similarly for max
// t(n) = 2 t(n/2)