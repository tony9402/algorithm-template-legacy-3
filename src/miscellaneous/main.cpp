//title: Testcase Basic Main
//prefix: tcmain, ma
//description: Main Template for Testcase
#include<bits/stdc++.h>

using namespace std;

typedef bool i1;
typedef char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef float f4;
typedef double f8;
typedef long double f16;

template<typename T> using Vec = vector<T>;

template<int fp=0> struct fastio { fastio() { ios::sync_with_stdio(false); cin.tie(0); if(fp)cout<<fixed<<' '<<setprecision(fp); } };

template<typename InputType> void in(InputType& x) { cin>>x; }
template<typename InputType, typename... InputTypes> void in(InputType& x, InputTypes& ...y) { cin>>x; in(y...); }
template<typename IterableInputType> void vin(IterableInputType &V) { for(auto &x: V) cin >> x; }

template<const int p=0, typename OutputType> void out(OutputType x) { cout<<x<<' '; }
template<const int p=0, typename OutputType, typename... OutputTypes> void out(OutputType x, OutputTypes ...y) { cout<<fixed<<setprecision(p)<<x<<' '; out<p>(y...); }
template<const int p=0, typename IterableOutputType> void vout(const IterableOutputType &V) { for(auto &x: V) out<p>(x); }

template<i64 modulo=numeric_limits<i64>::max(), typename... T> i64 Sum(T... x) { return (... + x) % modulo; }
template<i64 modulo=numeric_limits<i64>::max(), typename... T> i64 Mul(T... x) { return (... * x) % modulo; }

constexpr int dy[] = {-1,1,0,0,-1,-1,1,1,-2,-1,1,2,2,1,-1,-2};
constexpr int dx[] = {0,0,-1,1,-1,1,-1,1,1,2,2,1,-1,-2,-2,-1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int testcase = $1;$2 cin >> testcase;
    while(~--testcase) {
        $3
    }
}
