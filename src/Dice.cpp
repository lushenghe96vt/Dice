#include "Dice.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <thread>

std::vector<int> roll_random_die(int times) {
    // Step 1: Set up a random number generator (seed, random enginer, uniform distribution etc)
    std::random_device rd; // seed
    std::default_random_engine gen(rd()); // engine
    std::uniform_int_distribution<> dis(1, 6); // uniform distribution

    // Step 2: Initialize frequency vector of size 7 (index 0 unused)
    std::vector<int> freq(7, 0);
    freq[0] = 0; // useless index

    // Step 3: Roll the die 'times' times
    for (int i = 0; i < times; ++i) {
        int roll = dis(gen);
        freq[roll]++;
    }

    // Step 4: Return the frequency vector
    return freq;
}

double get_time(std::chrono::steady_clock::time_point start, std::chrono::steady_clock::time_point end) {
    // Step 1: Calculate the duration between 'end' and 'start' in milliseconds
    // milliseconds gives higher precision since directly computing seconds will truncate fractional
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // Step 2: Convert the duration to seconds (milliseconds to seconds)
    // Step 3: Return the duration in seconds
    return duration.count()/1000.0;
}

void print(std::vector<int> freq, double time){
    // Print the frequency of each die face (1 to 6)
    for (int i = 1; i < freq.size(); ++i) {
        std::cout << freq[i] << " ";
    }
    std::cout << ": " << time << " seconds\n";
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