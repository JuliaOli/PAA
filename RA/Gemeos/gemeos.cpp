#include <bits/stdc++.h>
#define MAX 1000000;

using namespace std;

typedef vector<int> vi;

int guloso(vi coins, int total_sum){

    int max_sum = 0;
    for(int i = coins.size()-1; i >= 0; --i){

        max_sum += coins[i];
        total_sum -= coins[i];
        if(max_sum > total_sum){
            return  coins.size() - i;
        }
    }
    return coins.size();
}

int main(){

    int num_coins, total_sum = 0;
    cin >> num_coins;

    vi coins(num_coins);

    for(int i = 0; i < num_coins; ++i){
        
        cin >> coins[i];
        total_sum += coins[i];
    }
    sort(coins.begin(),coins.end());

    cout << guloso(coins,total_sum);

    return 0;
}