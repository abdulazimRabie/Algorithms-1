#include <iostream>
#include <vector>
using namespace std;

// 1 - First problem : printing triangle Descending
void fun1(int levels) {
    for (int i = levels; i > 0; i--) {
        for (int j = 0; j < i; j++)
            cout << "*";

        cout << "\n";
    }
}

void fun1_recursive(int levels) {
    if (levels == 0) return;
    for (int i = 0; i < levels; i++)
        cout << "*";
    cout << "\n";
    fun1_recursive(levels - 1);
}

// 2 - Second problem : printing triangle Ascending
void fun2(int levels) {
    for (int i = 0; i < levels; i++) {
        for (int j = 0; j <= i; j++)
            cout << "*";
        cout << "\n";
    }
}

void fun2_recursive(int levels) {
    if (levels == 0) return;

    fun2_recursive(levels - 1);

    for (int i = 0; i < levels; i++)
        cout << "*";

    cout << "\n";
}

// 3 - Third problem : 3n + 1 problem
/*
* 3n+1 goes as following
* start from number n
*   n -> even -> (n/2)
*   n -> odd -> (3n+1)
*   n -> 1 -> end the sequence
*/

void fun3(int n) {
    if (n == 1) {
        cout << 1;
        return;
    };

    if (n % 2 == 0) {
        cout << n << " ";
        fun3(n / 2);
    }
    else {
        cout << n << " ";
        fun3((3*n) + 1);
    }
}

// ========================
// ====== Homework 1 ======
// ========================


// (1) - Printing length of 3n+1 function
int length_3n_plus_1(int n) {
    if (n == 1) return 1;
    if (n % 2 == 0) { 
        return 1 + length_3n_plus_1(n / 2);
    }
    else {
        return 1 + length_3n_plus_1((3 * n) + 1);
    }
}

// (2) - Power recursivly
int power_recursive(int n, int p) {
    if (p == 0) return 1;
    return n * power_recursive(n, p-1);
}

// (3) - Array maximum
// {1, 8, 2, 10, 3}
int max_arr(int arr[], int len) {
    if (len == 1) return arr[0];
    return max(max_arr(arr, len - 1), arr[len - 1]);
}

// (4) - Array sum
// {1, 8, 2, 10, 3}
int sum_arr(int arr[], int len) {
    if (len == 1) return arr[0];

    return sum_arr(arr, len - 1) + arr[len - 1];
}

// (5) - Array average
double average_arr(int arr[], int len) {
    if (len == 1) return arr[0];
    double sub_sum = average_arr(arr, len - 1) * (len - 1);
    return (sub_sum + arr[len - 1]) / len;
}

// (6) - Array increment
// {1, 8, 2, 10, 3}
//  1 => len = 1 => arr[len-1] += len-1;
//  8 => len = 2 => arr[len-1] += len-1 => 8 += 1 => 9
void array_increment(int arr[], int len) {
    if (len == 1) return;
    arr[len - 1] += len - 1;
    array_increment(arr, len - 1);
}

// (7) - Array accumulation
// {1, 8, 2, 10, 3}
void array_accumulation(int arr[], int len) {
    if (len == 1) return;
    array_accumulation(arr, len - 1);
    arr[len - 1] += arr[len - 2];
}
// (8) - Left max
// (9) - Right max

// (10) - Suffix sum
// function that sums only the last N elements in an array
// {1, 8, 2, 10, 3} | N = 3 | (2 + 10 +3) = 15

int suffix_sum(int arr[], int len, int n) {
    if (n == 1) return arr[len - 1];
    return arr[len - 1] + suffix_sum(arr, len - 1, n - 1);
}

// (11) - Prefix sum
// same concept of suffix sum but from the array begining

int prefix_sum(int arr[], int len, int n) {
    if (n == 1) return arr[0];
    return arr[n - 1] + prefix_sum(arr, len, n - 1);
}

// (12) - Palindrome
bool palindrome(int arr[], int s, int e) {
    if (s == e || s > e) return true;
    if (arr[s] == arr[e]) return palindrome(arr, s+1, e-1);
    else return false;
}

// (13) - Is prefix
// "abcdefg" "abcd"
bool is_prefix(string mainStr, string prefix, int pos) {
    if (prefix.length() == 1) return mainStr[pos] == prefix[0];

    if (mainStr[pos] == prefix[0]) {
        prefix = prefix.substr(1);
        return is_prefix(mainStr, prefix, pos + 1);
    }
    else return false;
}

// (14) - Trace
// [1] trace the code without running
// [2] what will be the output if we swapped (cout) with (do_something)
void do_something(int n) {
    if (n) {
        cout << n % 10;
        do_something(n / 10);
    }
}
// Answers
// [1] - 654321
// [2] - 123456

// (15) - Count Primes
// Learned Topics : Sievof Of Eratosthenes
// 10 - 20 [11, 13, 17, 19]

// (16) - Grid Sum

// (17) - Fibonacci
// 0 1 2 3 4 5 6  7  8  9
// 0 1 1 2 3 5 8 13 21 35
// fib(n) = fib(n-1) + fib(n-2) 

long fib(int n) {
    if (n == 0 || n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}


int main()
{

    int n = 20;
    vector<bool> isPrime(n + 1, true);
  

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            cout << i << " ";
            for (int j = 2; i*j <= n; j++)
                isPrime[i*j] = false;
        }
    }
    
    cout << endl;

    cout << fib(41);
}
