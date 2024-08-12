// typedef int item;

struct item {
    int suf, pref, val;
};


template<class T>
struct ST
{
#define lc (at << 1)
#define rc ((at << 1) | 1)
    int n;
    std::vector<T>values;
    std::vector<int>lazy;
    ST(int _n) {
        values.resize(4 * _n);
        lazy.resize(4 * _n, 0);
        n = _n;
    }

    void push(int at, int b, int e)
    {
        if (lazy[at] == 0) // change here
            return;
        values[at].suf ^= lazy[at]; // change here
        values[at].pref ^= lazy[at]; // change here
        if (b != e)
        {
            lazy[lc] ^= lazy[at]; // change here
            lazy[rc] ^= lazy[at]; // change here
        }
        lazy[at] = 0; // change here
    }

    // void pull(item at)
    // {
    //   return (values[lc]^values[rc])
    // }

    item marge(item a, item b)
    {
        if (a.suf == -1)return b;
        if (b.suf == -1)return a;
        item node;
        node.pref = a.pref;
        node.suf = b.suf;
        if (a.val == 0 or b.val == 0)
        {
            /* code */
            node.val = 0;
            return node;
        }
        if (a.suf != b.pref) {
            node.val = 1;
            return node;
        }
        else {
            node.val = 0;
            return node;
        }
    }

    void build(vector<int>&arr, int at, int b, int e)
    {
        lazy[at] = 0; // change here
        if (b == e)
        {
            values[at] = {arr[b], arr[b], 1};
            return;
        }
        int mid = (b + e) >> 1;
        build(arr, lc, b, mid);
        build(arr, rc, mid + 1, e);
        values[at] = marge(values[lc], values[rc]);
    }
    void Build(vector<int>&arr) {build(arr, 1, 1, n);} //change here
    void upd(int at , int b, int e, int i, int j, int val)
    {
        push(at, b, e);
        if (j < b or e < i)
            return;
        if (b >= i and e <= j)
        {
            lazy[at] = val;
            push(at, b, e);
            return;
        }
        int mid = (b + e) >> 1;
        upd(lc, b, mid, i, j, val);
        upd(rc, mid + 1, e, i, j, val);

        values[at] = marge(values[lc], values[rc]);
    }
    void Upd(int b, int e, int val) {upd(1, 1, n, b, e, val);} //change here
    T query(int at, int b, int e, int i, int j)
    {

        push(at, b, e);
        if (j < b or e < i)
            return { -1, -1, -1}; // change here

        if (b >= i and e <= j)
        {
            return values[at];
        }

        int mid = (b + e) >> 1;

        return marge(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
    }
    T Query(int l, int r) {return query(1, 1, n, l, r);} //change here
};
