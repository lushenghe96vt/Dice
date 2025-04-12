// set up skeleton for a dice class with classic c++ structure
#ifndef DICE_H
#define DICE_H

#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <thread>

// Function to simulate rolling a six-sided die 'times' times.
// Returns a vector<int> where index i represents the frequency of die face i.
// Note: frequency[0] will be unused for convenience (so face 1 maps to index 1).
std::vector<int> roll_random_die(int times);


// Function to calculate elapsed time in seconds between two-time points
// Parameters:
//   - start: the starting time point
//   - end: the ending time point
// Returns:
//   - the duration in seconds as a double
double get_time(std::chrono::steady_clock::time_point start, std::chrono::steady_clock::time_point end);

// Function to print the frequency of die rolls and the time taken to compute them
// Parameters:
//   - freq: a vector containing the frequency of each die face (index 1 to 6)
//   - time: the time duration in seconds (as a double) it took to perform the simulation
void print(std::vector<int> freq, double time);
// Sample output:
// Each number corresponds to the frequency of die faces 1 to 6
// Time is shown after the colon
/*
10003111 10005348 10000549 10001391 9994485 9995116 : 2.034 seconds 
9999281 10000895 9999485 9999850 9998419 10002070 : 0.171 seconds 
*/

#endif // DICE_H