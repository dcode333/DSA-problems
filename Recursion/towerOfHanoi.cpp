
#include <bits/stdc++.h>
using namespace std;

void towerOfHonai(int n,char src,char helper,char dest){
    
    if(n==0)
    return;
    towerOfHonai(n-1,src,dest,helper);
    cout<<src<<" to "<<dest<<endl;
    towerOfHonai(n-1,helper,src,dest);
    
}

int main()
{

    towerOfHonai(3,'A','B','C');

    return 0;
}
