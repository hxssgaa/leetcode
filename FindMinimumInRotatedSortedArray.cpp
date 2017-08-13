/*
	Find Minimum in Rotated Sorted Array

	Suppose a sorted array is rotated at some pivot unknown to you beforehand.

	(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

	Find the minimum element.

	实际上这个题就是考察二分法的while(low < high)的查找使用
	一般这样的题可以利用A[mid]与A[low]或者A[high]的关系来查找

 */

int findMin(vector<int>& nums) {
	int low = 0;
	int high = nums.size()-1;
	while (low < high) {
		int mid = (low + high) / 2;
		if (nums[high] <= nums[mid]) {
			low = mid+1;
		} else {
			high = mid;
		}
	}
	return nums[low];
}

//findMin2运行了重复元素的出现，实际上只是多加了nums[mid]==nums[high]的处理，
//在这个时候不知道是不是走上下边界，那么只需要high--即可
int findMin2(vector<int>& nums) {
	int low = 0;
	int high = nums.size()-1;
	while (low < high) {
		int mid = (low + high) / 2;
		if (nums[high] < nums[mid]) {
			low = mid+1;
		} else if (nums[high] > nums[mid]){
			high = mid;
		} else {
		    high--;
		}
	}
	return nums[low];
}