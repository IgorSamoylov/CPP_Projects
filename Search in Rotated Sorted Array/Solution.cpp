#include "Header.h"


int Solution::search(vector<int>& nums, int target) {

	cout << "Vector: " << " target " << target << endl;
	for_each(nums.begin(), nums.end(), [](int n) {cout << n << endl; });

	this->nums = nums;

	length = nums.size();

	if (nums[0] == target) return 0;
	if (nums[length - 1] == target) return length - 1;

	this->target = target;

	//if (length < 5) return easySearch();

	int pivot = find_critical_point();
	//if (begin == -1) throw "Not found critical point!";
	cout << "POINT: " << pivot << endl;

	if (target == nums[pivot]) return pivot;
	if (target > nums[pivot] && target < nums[length - 1]) return binary_search(pivot + 1, length - 1);
	else return binary_search(0, pivot - 1);

}

int Solution::binary_search(int left, int right) {
	int mid;

	while (right > left) {
		if (nums[left] == target) return left;
		if (nums[right] == target) return right;

		mid = (left + right) / 2 + 1;
		if (nums[mid] == target) return mid;

		if (nums[mid] > target) right = mid - 1;
		else left = mid + 1;
	}
	return -1;
}


int Solution::find_critical_point() {
	int left = 0, right = length - 1;
	
	int point, shift;

	//if (nums[length - 1] < nums[length - 2]) return length - 1;
	//if (nums[0] > nums[1]) return 1;

	int mid;

	while (right > left) {
		if (nums[right] < nums[right - 1]) return right;
		if (nums[left] > nums[left + 1]) return left + 1;

		mid = (left + right) / 2 ;
		if (nums[mid] > nums[mid + 1]) return mid + 1;

		if (nums[mid] > nums[0]) left = mid + 1 ;
		else right = mid;
	}
	
	return 0;
}

int Solution::easySearch() {

	for (int i = 0; i < length; i++) {
		if (nums[i] == target) return i;
	}
	return -1;
}







/*
* vector<int>::iterator Solution::findCriticalPoint(vector<int>::iterator begin, vector<int>::iterator end) {

	vector<int>::iterator middle = begin + distance(begin, end) / 2;

	if (*(middle + 1) < *middle) return middle;

	if (*middle < *begin) findCriticalPoint(begin, end - 1);
	else findCriticalPoint(begin + 1, end);
}
*
*
int Solution::findCriticalPoint(vector<int>::iterator begin, vector<int>::iterator end, int middleIndex) {
	if (*begin == nums[middleIndex] || *begin == nums[middleIndex - 1]) return middleIndex;

	if (*begin > nums[middleIndex]) findCriticalPoint(begin, begin + middleIndex, int(middleIndex / 2));
	else {
		begin += middleIndex;
		findCriticalPoint(begin, end, distance(begin, end) / 2);
	};

}

 rotate(nums.begin(), nums.begin() + shift, nums.end());
	cout << " Array: " << endl;
	for_each(nums.begin(), nums.end(), [](int n) {cout << n << endl; });
	cout << " End " << endl;

	size_t i = length / 2;
	size_t point = i;

	while (nums[i] != target) {
		if (point > 1) {
			if (point % 2 == 1) point = point / 2 + 1;
			else point /= 2;
		}
		else return -1;

		if (target < nums[i]) i -= point;
		else i += point;

	}
	cout << " Point: " << point << " Shift  " << shift << endl;

	int result = point + shift - 1;

	return result;




	int Solution::binary_search(int begin, int end) {
	int distance;
	int point;

	while (true) {
		distance = end - begin;
		if (distance == 0) {
			if (nums[begin] == target) return begin;
			return -1;
		}
		if (distance == 1) {
			if (nums[begin] == target) return begin;
			if (nums[end] == target) return end;
			return -1;
		}

		if (distance % 2 == 1) {
			point = begin + distance / 2 + 1;
		}
		else point = begin + distance / 2;

		if (nums[point] == target) return point;
		if (nums[point] > target)  end = point - 1;
		else begin = point + 1;
	}
	return -1;
}


int Solution::binary_search(int begin, int end) {
	int distance, point, shift;
	if (nums[begin] == target) return begin;
	if (nums[end] == target) return end;

	distance = end - begin;
	shift = round(distance / 2);
	point = begin + shift;
	while (point > begin && point < end) {

		if (nums[point] == target) return point;
		if (nums[point] > target)  point -= shift;
		else point += shift;

		if (shift != 0) shift = round(shift / 2);
		else shift = 1;
	}
	return -1;
}


int Solution::find_critical_point() {
	int point, shift;

	if (nums[length - 1] < nums[length - 2]) return length - 1;
	if (nums[0] > nums[1]) return 1;

	point = round(length / 2);
	shift = round(point / 2);

	while (point > 0 && point < length - 1) {

		if (nums[point] > nums[point + 1]) return point + 1;


		if (nums[point] > nums[0]) point += shift;
		else point -= shift;

		if (shift != 0) shift = round(shift / 2);
		else shift = 1;
	}
	return 0;
}
*/