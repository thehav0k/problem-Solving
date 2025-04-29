#include <iostream>
#include <cstdlib>
using namespace std;
typedef long long ll;

// Function to perform modular exponentiation
ll power(ll a, ll d, ll n) {
    ll result = 1;
    a = a % n;
    while (d > 0) {
        if (d&1) //bitwise AND --> check if d is odd
            result = (result * a) % n;
        a = (a * a) % n;
        d >>= 1;// bitwise right shift --> divide by 2
    }
    return result;
}

// Miller-Rabin primality test
bool miller_rabin(ll n,int k = 5) { 
    //k = number of rounds--> probability of error is 4^(-k) and almost 100% accurate
    // The more rounds, the more accurate the result
    // The default value of k is 5, which is usually sufficient for n < 2^64 or n=10^19
    if (n < 2)//edge case --> 0 and 1 are not prime
        return false;
    if (n == 2 || n == 3)//edge case --> 2 and 3 are prime
        return true;
    if (n % 2 == 0)//All even numbers greater than 2 are composite
        return false;
    
    // Write n-1 as d * 2^r
    ll d = n - 1;
    while (d % 2 == 0)//If d is even, divide it by 2 until it becomes odd
        d /= 2;
    
    // Witness loop
    for (int i = 0; i < k; i++) {
        ll a = 2 + rand() % (n - 3); // random integer in [2, n-2] --> 2 is the smallest prime
        ll x = power(a, d, n);// this is called modular exponentiation--> a^d % n
        
        if (x == 1 || x == n-1)//Generally, if x is 1 or n-1, we can continue to the next iteration
            continue;
        
        bool continue_outer_loop = false;
        ll temp = d;
        while (temp != n-1) {
            x = (x * x) % n;
            temp *= 2;
            if (x == 1)
                return false;
            if (x == n-1) {
                continue_outer_loop = true;
                break;
            }
        }
        
        if (continue_outer_loop)
            continue;
        
        return false; // composite
    }
    
    return true; // probably prime
}

int main() {
    ll n;
    cin>>n;
    
    if (miller_rabin(n))
        cout << n<< " is (probably) prime"<<endl;
    else
        cout<< n<< " is composite"<<endl;
    
    return 0;
}


// YouTube Video to understand this theorem : https://youtu.be/8i0UnX7Snkc?si=RH0HOec5yXZY7Q8L
