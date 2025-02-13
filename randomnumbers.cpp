#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    


    //random_device rd;
    mt19937 gen(time(NULL)); 
    uniform_int_distribution<> dis(1, 6);

    for (int i=0; i<25; i++) {
        
        cout << dis(gen) << " ";
    }
    

    
    

    return 0;
}