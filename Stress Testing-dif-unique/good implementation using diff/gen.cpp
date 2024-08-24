#include <bits/stdc++.h>

using namespace std;

int rnd(int a, int b)
{
    return a + rand() % (b - a + 1);
}

string gen(int len)
{

    string letters = "abcdefghijklmnopqrstuvwxyz";
    string random_s;
    int sz = letters.size();
    for (int i = 0; i < len; i++)
    {
        random_s += (letters[rand() % sz]);
    }
    return random_s;
}
int main(int argc, char *argv[])
{
    srand(atoi(argv[1]));
    int n = rnd(1, 50);
    cout<<n<<"\n";
    for(int i=0;i<n;i++){
        cout<<rnd(1,50)<<" ";
    }
    cout<<'\n';
    for(int i=0;i<n;i++){
        cout<<rnd(1,50)<<" ";
    }
    cout<<'\n';
    int m=rnd(1,50);
    cout<<m<<'\n';
    for(int i=0;i<m;i++)cout<<rnd(1,50)<<" ";

   

    // cout << gen(n) << '\n';
}