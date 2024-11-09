#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <assert.h>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <numeric>
#include <stack>
#define el '\n'
#define br  cout << "-------------------------------" << el;
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
const ll mod = 1e9 + 7;

#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
#endif
void runtime(){
    #ifndef ONLINE_JUDGE
        fprintf(stderr, ">> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
}
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

// --------------------------------------------------------------------------- //

void run_case(){

    
 
}

signed main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    run_case();
    runtime();
    return 0;
}