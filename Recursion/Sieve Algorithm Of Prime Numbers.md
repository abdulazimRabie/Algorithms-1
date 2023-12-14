# Sieve of Eratosthenes
It is an efficient algorithm to count prime number from L to P.
<br>
In general we use loops to find out prime numbers, so it takes a long time compared to Sieve algorithms.
<br>
So, Sieve algorithms based on 2, 3 and 5 because they and their multiplications means the same.
<br>
<span style="color: red">2</span> : 4, 6, 8, 10, 12, 16, 18
<br>
<span style="color: red">3</span> : 6, 9, 12, 15, 18
<br>
<span style="color: red">5</span> : 10, 15, 20, 25

Algorithms:
- create an array refers to prime number with size of (n+1)
- all array elements is true initially
- start loop from 2
- check if the element you indicate is prime (means : 2, 3, 5)
- loop again to set all multiplication of this prime number is false

```cpp
int n = 20;
vector<bool> isPrime(n + 1, true);

for (int i = 2; i <= n; i++) {
  if (isPrime[i]) {
  cout << i << " ";
  for (int j = 2; i*j <= n; j++)
  	isPrime[i*j] = false;
  }
}
```