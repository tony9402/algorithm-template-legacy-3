//title: a^b with modulo
//prefix: power
//description: a^b % mod
template<typename T> T power(T a, T b, T mod=numeric_limits<T>::max()) {
    if(b == 0) return 1;
    if(b & 1) return a * power(a, b - 1, mod) % mod;
    return power(a * a % mod, b >> 1, mod);
}