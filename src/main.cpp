//#include "Dice.h"
#include "Dice.h"
#include <future>

int main() {
    // -----------------------------------------------
    // 1. SINGLE-THREADED VERSION
    // -----------------------------------------------

    auto start = std::chrono::steady_clock::now();
    auto freq = roll_random_die(60'000'000);
    auto end = std::chrono::steady_clock::now();

    std::cout << "Single-threaded version:\n";
    print(freq, get_time(start, end));


    // -----------------------------------------------
    // 2. MULTI-THREADED with std::launch::async
    // -----------------------------------------------

    // Launch each task immediately in a new thread
    auto cores = std::thread::hardware_concurrency(); // cores
    int work_per_thread = 60'000'000 / cores;     // workload per thread
    auto async_start = std::chrono::steady_clock::now();
    std::vector<std::future<std::vector<int>>> futures;
    std::vector<std::vector<int>> partial_freqs_async;

    for (int i = 0; i < cores; ++i) { // create nCores threads
        futures.push_back(std::async(std::launch::async, roll_random_die, work_per_thread));
    }
    for (auto& f : futures) { // wait for all threads to finish
        partial_freqs_async.push_back(f.get());
    }

    // Combine results from async futures
    auto freq_counter_async = std::vector<int>(7, 0); // initialize frequency counter
    for (const auto& part : partial_freqs_async) {
      for (int i = 1; i < 7; ++i){
        freq_counter_async[i] += part[i];
      }
    }
    auto async_end = std::chrono::steady_clock::now();

    std::cout << "\nMulti-threaded with std::launch::async:\n";
    print(freq_counter_async, get_time(async_start, async_end));


    // -----------------------------------------------
    // 3. MULTI-THREADED with std::launch::deferred
    // -----------------------------------------------
    auto deferred_start = std::chrono::steady_clock::now();
    std::vector<std::future<std::vector<int>>> deferred_futures;
    std::vector<std::vector<int>> partial_freqs_deferred;

    for (int i = 0; i < cores; ++i) { // create nCores threads
        deferred_futures.push_back(std::async(std::launch::deferred, roll_random_die, work_per_thread));
    }
    for (auto& f : deferred_futures) { // wait for all threads to finish
        partial_freqs_deferred.push_back(f.get());
    }

    auto freq_counter_deferred = std::vector<int>(7, 0); // initialize frequency counter
    for (const auto& part : partial_freqs_deferred) {
      for (int i = 1; i < 7; ++i){
        freq_counter_deferred[i] += part[i];
      }
    }
    auto deferred_end = std::chrono::steady_clock::now();

    std::cout << "\nMulti-threaded with std::launch::deferred:\n";
    print(freq_counter_deferred, get_time(deferred_start, deferred_end));
  }

  // -----------------------------------------------
  // Summary (Paste your actual output as comment) in the code:
  // -----------------------------------------------
  /*
Single-threaded version:
10002546 10003205 10002507 9997674 9997141 9996927 : 4.54 seconds

Multi-threaded with std::launch::async:
9997286 9997407 10001552 10003332 10002594 9997829 : 0.889 seconds

Multi-threaded with std::launch::deferred:
9997563 10001394 10005132 9997254 9998136 10000521 : 4.574 seconds
  */