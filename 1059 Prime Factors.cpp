#include <bits/stdc++.h>
using namespace std;

const long int N = 50000;
bool not_prime[N + 1];
vector<int> primes; 

void build_prime_table() {
    for (int i = 2; i < N; ++i) {
        if (!not_prime[i]) {
            primes.push_back(i);
        }
        for (auto j: primes) {
            if (i * j > N) {
                break;
            }
            not_prime[i * j] = true;
            if (i % j == 0) {
                break;
            }
        }
    }
}

void print(int x, int y){
    if (y == 1) {
        printf("%d", x);
    } else {
        printf("%d^%d", x, y);
    }
}

int main() {
    build_prime_table();
    long int n;
    scanf("%ld", &n);
    if (n == 1) {
        printf("1=1");
        return 0;
    }
    int cnt = 0, first = true;;
    printf("%ld=", n);
    for (int i = 0; i <= primes.size() && n > 1; ++i){
        cnt = 0;
        while (n % primes[i] == 0) {
            n /= primes[i];
            cnt++;
        }
        if (cnt > 0) {
            if (first) {
                first = false;
            } else {
                printf("*");
            }
            print(primes[i], cnt);
        }
    }
}