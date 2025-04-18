typedef int item;

// struct item {
//     int suf, pref, val;
// };


template<class T>
struct ST
{
#define lc (at << 1)
#define rc ((at << 1) | 1)
    int n;
    std::vector<T>values;

    ST(int _n) {
        values.resize(4 * _n, 0);

        n = _n;
    }



    item marge(T a, T b)
    {
        return a + b;
    }

    void build(vector<int>&arr, int at, int b, int e)
    {

        if (b == e)
        {
            values[at] = arr[b];
            return;
        }
        int mid = (b + e) >> 1;
        build(arr, lc, b, mid);
        build(arr, rc, mid + 1, e);
        values[at] = marge(values[lc], values[rc]);
    }
    void Build(vector<int>&arr) {build(arr, 1, 1, n);} //change here
    void upd(int at , int b, int e, int i, int val)
    {

        if (i < b or e < i)
            return;
        if (b == i and e == i)
        {
            values[at] = val;
            return;
        }
        int mid = (b + e) >> 1;
        upd(lc, b, mid, i, val);
        upd(rc, mid + 1, e, i, val);

        values[at] = marge(values[lc], values[rc]);
    }
    void Upd(int b, int val) {upd(1, 1, n, b, val);} //change here
    T query(int at, int b, int e, int i, int j)
    {


        if (j < b or e < i)
            return 0; // change here

        if (b >= i and e <= j)
        {
            return values[at];
        }

        int mid = (b + e) >> 1;

        return marge(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
    }
    T Query(int l, int r) {return query(1, 1, n, l, r);} //change here
};
