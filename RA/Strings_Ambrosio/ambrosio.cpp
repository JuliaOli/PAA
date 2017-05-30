#include <bits/stdc++.h>

using namespace std;

bool div_conq(string a, string b){

    if(a.size()%2 == 1 && b.size()%2 == 1){
        if(!a.compare(b)){
            return true;
        }
        return false;
    }

    int a_size = a.size()/2;
    int b_size = b.size()/2;
    int a_rest = a.size() - a_size;
    int b_rest = b.size() - b_size;

    char a1[a_size+1],a2[b_rest+1], b1[b_size+1], b2[b_rest+1];

    a.copy(a1, a_size, 0);
    a1[a_size] = '\0';
    a.copy(a2, a_rest, a_size);
    a2[a_rest] = '\0';
    b.copy(b1, b_size, 0);
    b1[b_size] = '\0';
    b.copy(b2, b_rest, b_size);
    b2[b_rest] = '\0';

    //cout << a1 << " " << a2 << " " << b1 << " " << b2 << endl;

    if(div_conq((string)a1, (string)b1) && div_conq((string)a2, (string)b2) || div_conq((string)a1, (string)b2) 
    && div_conq((string)a2, (string)b1)){
        return true;
    }
    return false;
}


int main(){

    string a, b;
    cin >> a >> b;

    if(div_conq(a,b)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}