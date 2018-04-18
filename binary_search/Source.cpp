#include <iostream>
using namespace std;

template <class T>
int binary_search(T arr[], int n, int target)
{
	auto l = 0;
	auto r = n - 1;
	while (l <= r)
	{
		auto mid = l + (r - l) / 2;
		if (arr[mid] == target)
			return mid;
		if (arr[mid] > target)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}

template <class T>
int finding(T arr[], int l, int r, T target)
{
	if (l > r)
		return -1;
	int mid = l + (r - l) / 2;
	if (arr[mid] == target)
		return mid;
	if (target < arr[mid])
		return finding(arr, l, mid - 1, target);
	return finding(arr, mid + 1, r, target);
}

template <class T>
int binary_search_recursion(T arr[], int n, T target)
{
	int l = 0;
	int r = n - 1;
	return finding(arr, l, r, target);
}

template <class T>
int finding_floor(T arr[], int l, int r, T target, int& floor)
{
	if (l > r)
		return floor;
	int mid = l + (r - l) / 2;
	if (arr[mid] == target)
	{
		while (arr[mid - 1] == target)
		{
			mid--;
		}
		floor = mid;
		return floor;
	}
	if (target < arr[mid])
		return finding_floor(arr, l, mid - 1, target, floor);
	floor = mid;
	return finding_floor(arr, mid + 1, r, target, floor);
}

template <class T>
int binary_search_floor(T arr[], int n, T target)
{
	int floor;
	int l = 0;
	int r = n - 1;
	finding_floor(arr, l, r, target, floor);
	return floor;
}

template <class T>
int finding_ceil(T arr[], int l, int r, T target, int& ceil)
{
	if (l > r)
		return ceil;
	int mid = l + (r - l) / 2;
	if (arr[mid] == target)
	{
		ceil = mid;
		while (arr[ceil + 1] == target)
		{
			ceil++;
		}
		return ceil;
	}
	if (target < arr[mid])
	{
		ceil = mid;
		finding_ceil(arr, l, mid - 1, target, ceil);
	}
	else
		finding_ceil(arr, mid + 1, r, target, ceil);
}

template <class T>
int binary_search_ceil(T arr[], int n, T target)
{
	int ceil;
	int l = 0;
	int r = n - 1;
	finding_ceil(arr, l, r, target, ceil);
	return ceil;
}

int main(int argc, char* argv[])
{
	int arr[]{1, 2, 3, 3, 4, 6, 8, 9, 10, 49};
	cout << binary_search_floor(arr, 9, 7) << endl;
	cout << binary_search_ceil(arr, 9, 7) << endl;
	system("pause");
}
