#include <bits/stdc++.h>
using namespace std;
int rnd(int a, int b){
    return a + rand() % (b - a + 1);
}
int main(int argc, char* argv[]){
    int seed = atoi(argv[1]);
    srand(seed);
    int n = rnd(1, 100);
    cout<<n<<" "<<rnd(0,20)<<'\n';
    for(int i=0;i<n;i++){
        int x = rnd(1,100);
        cout<<x<<" ";
    }
   
}
