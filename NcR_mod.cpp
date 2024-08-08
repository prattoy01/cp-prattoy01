const int MOD = 998244353;
const int MAX = 3e5 + 5;
long long inv(long long a, long long b = MOD) {
    return 1 < a ? b - inv(b % a, a) * b / a : 1;
}
int fct[MAX], iv[MAX];
void pre()
{
    fct[0] = 1;
    for (int i = 1; i <= MAX - 1; i++)
    {
        fct[i] = (fct[i - 1] * i) % MOD;
    }
    iv[MAX - 1] = inv(fct[MAX - 1]);
    for (int i = MAX - 2; i >= 0; i--)
    {
        iv[i] = (iv[i + 1] * (i + 1)) % MOD;
    }
}
int ncr(int n, int r)
{
    if (r > n)
        return 0;
    return (((fct[n] * iv[r]) % MOD) * iv[n - r]) % MOD;
}