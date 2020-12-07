#pragma once

#include <iostream>
#include <thread>
#include <windows.h>
#include <intrin.h>

int get_core_count() {
	SYSTEM_INFO system_info;
	GetSystemInfo(&system_info);
	int core_count = system_info.dwNumberOfProcessors;
	return core_count;
}

std::string get_cpu_name()
{
	int cpu_information[4] = { -1 };
	char cpu_string[0x40];
	__cpuid(cpu_information, 0x80000000);
	unsigned int nExIds = cpu_information[0];

	memset(cpu_string, 0, sizeof(cpu_string));

	for (int i = 0x80000000; i <= nExIds; ++i)
	{
		__cpuid(cpu_information, i);
		if (i == 0x80000002)
			memcpy(cpu_string, cpu_information, sizeof(cpu_information));
		else if (i == 0x80000003)
			memcpy(cpu_string + 16, cpu_information, sizeof(cpu_information));
		else if (i == 0x80000004)
			memcpy(cpu_string + 32, cpu_information, sizeof(cpu_information));
	}
	return cpu_string;
}

int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++)
	{ 
		if (arr[j] < pivot)
		{
			i++; 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void heap(int arr[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i) {
		swap(&arr[i], &arr[largest]);
		heap(arr, n, largest);
	}
}

void selection_sort(int arr[], int n)
{
	int i, j, min_idx;
  
	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		swap(&arr[min_idx], &arr[i]);
	}
}

void bubble_sort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
 
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

void recursive_bubble_sort(int arr[], int n)
{

	if (n == 1)
		return;

	for (int i = 0; i < n - 1; i++)
		if (arr[i] > arr[i + 1])
			swap(&arr[i], &arr[i + 1]);

	recursive_bubble_sort(arr, n - 1);
}

void insertion_sort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void recursive_insertion_sort(int arr[], int n)
{
	if (n <= 1)
		return;

	recursive_insertion_sort(arr, n - 1);

	int last = arr[n - 1];
	int j = n - 2;

	while (j >= 0 && arr[j] > last)
	{
		arr[j + 1] = arr[j];
		j--;
	}
	arr[j + 1] = last;
}

void quick_sort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}

void heap_sort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heap(arr, n, i);

	for (int i = n - 1; i > 0; i--) {
		swap(&arr[0], &arr[i]);
		heap(arr, i, 0);
	}
}


