#pragma once
#include <iostream>
#include <thread>
#include <windows.h>
#include <intrin.h>
#include <chrono>
#include <algorithm>
#include "fn.hpp"

using namespace std;
using namespace std::chrono;
class thread_fn {
	public:
		int thread_number; // i am bored oookay yes mhm
	void fn_input(int arr1[], int arr2[], int arr3[],int count) {
		for (int i = 0; i < count; i++)
			arr3[i] = arr2[i] = arr1[i] = rand() % 100;
	}

	void fn_sort(int arr[], int count) {
		sort(arr, arr + count);
	}

	void fn_qsort(int arr[], int count) {
		qsort(arr, count, sizeof(int), compare);
	}

	std::thread fn_input_thread(int arr1[], int arr2[], int arr3[], int count) {
		return std::thread([=] { fn_input(arr1,arr2,arr3,count); });
	}

	std::thread fn_sort_thread(int arr[], int count) {
		return std::thread([=] { fn_sort(arr, count); });
	}

	std::thread fn_qsort_thread(int arr[], int count) {
		return std::thread([=] { fn_qsort(arr, count); });
	}
};

