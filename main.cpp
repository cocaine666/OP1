#include <iostream>
#include <thread>
#include <windows.h>
#include <intrin.h>
#include <chrono>
#include "fn.hpp"
#include "threading_fn.hpp"

#define N1 1000
#define N2 500000


using namespace std::chrono;

int main()
{
	//aesthetics
    std::cout << "Multithread sorting\n\n";
    int cores = get_core_count();
	std::string processor_name = get_cpu_name();
	std::cout << "Processor: " << processor_name << "\n";
    std::cout << "Cores: " << cores << "\n\n";
	char repeat;

	// creating thread_fn objects
	thread_fn* num_1 = new thread_fn();
	thread_fn* num_2 = new thread_fn();
	thread_fn* num_3 = new thread_fn();
	thread_fn* num_4 = new thread_fn();
	thread_fn* num_5 = new thread_fn();
	thread_fn* num_6 = new thread_fn();
	thread_fn* num_7 = new thread_fn();
	thread_fn* num_8 = new thread_fn();

	// arrays for testing
	int* array_1 = new int[N1];
	int* array_1_d = new int[N1];
	int* array_1_d2 = new int[N1];
	int* array_2 = new int[N2];
	int* array_2_d = new int[N2];
	int* array_2_d2 = new int[N2];

	//seed
	srand(time(NULL));

benchmark:

	// program execution time (fucking nigger)
	auto start_exec_time = high_resolution_clock::now();

	//how many cores = how many threads we will run 
	switch(cores) {
	case 1:
	{
		num_1->thread_number = 1;
		auto start_input = high_resolution_clock::now();
		std::thread one = num_1->fn_input_thread(array_1, array_1_d, array_1_d2, N1);
		auto end_input = high_resolution_clock::now();
		auto start_sort = high_resolution_clock::now();
		one = num_1->fn_sort_thread(array_1_d, N1);
		auto end_sort = high_resolution_clock::now();
		auto start_qsort = high_resolution_clock::now();
		one = num_1->fn_qsort_thread(array_1_d2, N1);
		auto end_qsort = high_resolution_clock::now();
		auto start_input2 = high_resolution_clock::now();
		one = num_1->fn_input_thread(array_2, array_2_d, array_2_d2, 100000);
		auto end_input2 = high_resolution_clock::now();
		auto start_sort2 = high_resolution_clock::now();
		one = num_1->fn_sort_thread(array_2_d, 100000);
		auto end_sort2 = high_resolution_clock::now();
		auto start_qsort2 = high_resolution_clock::now();
		one = num_1->fn_qsort_thread(array_2_d2, 100000);
		auto end_qsort2 = high_resolution_clock::now();
		auto duration_input = duration_cast<microseconds>(end_input - start_input);
		auto duration_sort = duration_cast<microseconds>(end_sort - start_sort);
		auto duration_qsort = duration_cast<microseconds>(end_qsort - start_qsort);
		auto duration_input2 = duration_cast<microseconds>(end_input2 - start_input2);
		auto duration_sort2 = duration_cast<microseconds>(end_sort2 - start_sort2);
		auto duration_qsort2 = duration_cast<microseconds>(end_qsort2 - start_qsort2);
		std::cout << "Thread#" << num_1->thread_number;
		std::cout << " -> Execution time for input with " << cores << " cores is " << duration_input.count() << " microseconds.\n";
		std::cout << "Thread#" << num_1->thread_number;
		std::cout << " -> Execution time for sort with " << cores << " cores is " << duration_sort.count() << " microseconds.\n";
		std::cout << "Thread#" << num_1->thread_number;
		std::cout << " -> Execution time for qsort with " << cores << " cores is " << duration_qsort.count() << " microseconds.\n";
		std::cout << "Thread#" << num_1->thread_number;
		std::cout << " -> Execution time for input #2 with " << cores << " cores is " << duration_input2.count() << " microseconds.\n";
		std::cout << "Thread#" << num_1->thread_number;
		std::cout << " -> Execution time for sort #2 with " << cores << " cores is " << duration_sort2.count() << " microseconds.\n";
		std::cout << "Thread#" << num_1->thread_number;
		std::cout << " -> Execution time for qsort #2 with " << cores << " cores is " << duration_qsort2.count() << " microseconds.\n";
		one.join();
		num_1->thread_number = 0;
		break;
	}
	case 2:
	{
		{
			num_1->thread_number = 1;
			auto start_input = high_resolution_clock::now();
			std::thread one_dual = num_1->fn_input_thread(array_1, array_1_d, array_1_d2, N1);
			auto end_input = high_resolution_clock::now();
			auto start_input2 = high_resolution_clock::now();
			one_dual = num_1->fn_input_thread(array_2, array_2_d, array_2_d2, N2);
			auto end_input2 = high_resolution_clock::now();
			auto duration_input = duration_cast<microseconds>(end_input - start_input);
			auto duration_input2 = duration_cast<microseconds>(end_input2 - start_input2);
			std::cout << "Thread#" << num_1->thread_number;
			std::cout << " -> Execution time for input with " << cores << " cores is " << duration_input.count() << " microseconds.\n";
			std::cout << "Thread#" << num_1->thread_number;
			std::cout << " -> Execution time for input #2 with " << cores << " cores is " << duration_input2.count() << " microseconds.\n";
			one_dual.join();
			num_1->thread_number = 0;
		}
		{
			num_2->thread_number = 2;
			auto start_sort = high_resolution_clock::now();
			std::thread two_dual = num_2->fn_sort_thread(array_1_d, N1);
			auto end_sort = high_resolution_clock::now();
			auto start_qsort = high_resolution_clock::now();
			two_dual = num_2->fn_qsort_thread(array_1_d2, N1);
			auto end_qsort = high_resolution_clock::now();
			auto start_sort2 = high_resolution_clock::now();
			two_dual = num_2->fn_sort_thread(array_2_d, N2);
			auto end_sort2 = high_resolution_clock::now();
			auto start_qsort2 = high_resolution_clock::now();
			two_dual = num_2->fn_qsort_thread(array_2_d2, N2);
			auto end_qsort2 = high_resolution_clock::now();
			auto duration_sort = duration_cast<microseconds>(end_sort - start_sort);
			auto duration_qsort = duration_cast<microseconds>(end_qsort - start_qsort);
			auto duration_sort2 = duration_cast<microseconds>(end_sort2 - start_sort2);
			auto duration_qsort2 = duration_cast<microseconds>(end_qsort2 - start_qsort2);
			std::cout << "Thread#" << num_2->thread_number;
			std::cout << " -> Execution time for sort with " << cores << " cores is " << duration_sort.count() << " microseconds.\n";
			std::cout << "Thread#" << num_2->thread_number;
			std::cout << " -> Execution time for qsort with " << cores << " cores is " << duration_qsort.count() << " microseconds.\n";
			std::cout << "Thread#" << num_2->thread_number;
			std::cout << " -> Execution time for sort #2 with " << cores << " cores is " << duration_sort2.count() << " microseconds.\n";
			std::cout << "Thread#" << num_2->thread_number;
			std::cout << " -> Execution time for qsort #2 with " << cores << " cores is " << duration_qsort2.count() << " microseconds.\n";
			two_dual.join();
			num_2->thread_number = 0;
		}
		break;
	}
	case 4: // do it yourself if you have quadcore
	{
		break;
	}
	case 6: // do it yourself if you have a 6 core cpu (c+p the 8 core code it's ran on 6 cores)
	{
		break;
	}
	case 8:
	{
		{
			auto start_input = high_resolution_clock::now();
			num_1->thread_number = 1;
			std::thread one_octa = num_1->fn_input_thread(array_1, array_1_d, array_1_d2, N1);
			auto end_input = high_resolution_clock::now();
			auto duration_input = duration_cast<microseconds>(end_input - start_input);
			std::cout << "Thread#" << num_1->thread_number;
			std::cout << " -> Execution time for input with " << cores << " cores is " << duration_input.count() << " microseconds.\n";
			one_octa.join();
			num_1->thread_number = 0;
		}
		{
			auto start_input = high_resolution_clock::now();
			num_6->thread_number = 6;
			std::thread six_octa = num_6->fn_input_thread(array_2, array_2_d, array_2_d2, N2);
			auto end_input = high_resolution_clock::now();
			auto duration_input = duration_cast<microseconds>(end_input - start_input);
			std::cout << "Thread#" << num_6->thread_number;
			std::cout << " -> Execution time for input #2 with " << cores << " cores is " << duration_input.count() << " microseconds.\n";
			six_octa.join();
			num_6->thread_number = 0;
		}
		{
			auto start_sort = high_resolution_clock::now();
			num_2->thread_number = 2;
			std::thread two_octa = num_2->fn_sort_thread(array_1_d, N1);
			auto end_sort = high_resolution_clock::now();
			auto duration_sort = duration_cast<microseconds>(end_sort - start_sort);
			std::cout << "Thread#" << num_2->thread_number;
			std::cout << " -> Execution time for sort with " << cores << " cores is " << duration_sort.count() << " microseconds.\n";
			two_octa.join();
			num_2->thread_number = 0;
		}
		{
			auto start_qsort = high_resolution_clock::now();
			num_3->thread_number = 3;
			std::thread three_octa = num_3->fn_qsort_thread(array_1_d2, N1);
			auto end_qsort = high_resolution_clock::now();
			auto duration_qsort = duration_cast<microseconds>(end_qsort - start_qsort);
			std::cout << "Thread#" << num_3->thread_number;
			std::cout << " -> Execution time for qsort with " << cores << " cores is " << duration_qsort.count() << " microseconds.\n";
			three_octa.join();
			num_3->thread_number = 0;
		}
		{
			auto start_sort = high_resolution_clock::now();
			num_4->thread_number = 4;
			std::thread four_octa = num_4->fn_sort_thread(array_2_d, N2);
			auto end_sort = high_resolution_clock::now();
			auto duration_sort = duration_cast<microseconds>(end_sort - start_sort);
			std::cout << "Thread#" << num_4->thread_number;
			std::cout << " -> Execution time for sort #2 with " << cores << " cores is " << duration_sort.count() << " microseconds.\n";
			four_octa.join();
			num_4->thread_number = 0;
		}
		{
			auto start_qsort = high_resolution_clock::now();
			num_5->thread_number = 5;
			std::thread five_octa = num_5->fn_qsort_thread(array_2_d2, N2);
			auto end_qsort = high_resolution_clock::now();
			auto duration_qsort = duration_cast<microseconds>(end_qsort - start_qsort);
			std::cout << "Thread#" << num_5->thread_number;
			std::cout << " -> Execution time for qsort #2 with " << cores << " cores is " << duration_qsort.count() << " microseconds.\n";
			five_octa.join();
			num_5->thread_number = 0;
		}
		break;
	}
	}
	auto end_exec_time = high_resolution_clock::now();

	// print it out 
	auto duration = duration_cast<microseconds>(end_exec_time - start_exec_time);
	std::cout << "Execution time of all tasks with " << cores << " cores is " << duration.count() << " microseconds. (thread PROGRAM_THREAD)\n\n";
	std::cout << "Repeat the benchmark? (Y/N)? ";
	std::cin >> repeat;
	if (repeat == 'Y')
	{
		start_exec_time = {};
		end_exec_time = {};

		// HAHAHAHAHAHAHAHAHHAHAHAHHAHAHAHAHAHHAHAHHAAHHAHAHAHHAHAHH
		goto benchmark;
	}

    return 0;
}

