#include<bits/stdc++.h>
#define MaxSize 1000001
using namespace std;

struct computerSet{
    int computer1,computer2, weight;
};

vector<computerSet> computers(MaxSize);
vector<int> combine(MaxSize);

int verify(int son){

    return combine[son] == son ? combine[son] : parent(combine[son]); // T(n) = nlogn
}

int merge(int computer1, int computer2){ // tempo C

    int auxComputer1 = verify(computer1);  // T(n) = nlogn
    int auxComputer2 = verify(computer2);   //T(n) = nlogn => T(n) = 2nlog 
    if(auxComputer1 != auxComputer2){
        if(auxComputer1 > auxComputer2)combine[auxComputer2] = auxComputer1;
        else if(auxComputer2 > auxComputer1) combine[auxComputer1] = auxComputer2;  // T(n) = c
        return 1;
    }
    return 0;
}

void fill(int size){
    for(int i = 0; i < size; i++){  // T(n) = n
        combine[i] = i;
    }
}

bool compare(const computerSet &a, const computerSet &b)
{
    return a.weight < b.weight;  // T(n) = c
}

int main(){

    int comuputerSites, counter = 0; //T(n) = c
    while(cin >> comuputerSites){

        if(counter > 0) cout << endl;
        int sum = 0;
        for(int i = 0; i < comuputerSites-1; i++){  //T(n) = c*comuputerSites
            int a,b,c;
            cin >> a >> b >> c;
            sum += c;
        }
        cout << sum << endl;
        
        int K,M;
        cin >> K;
        for(int i = 0; i < K; i++){
            cin >> computers[i].computer1 >> computers[i].computer2 >> computers[i].weight;  //T(n) = c*K
        }
        
        cin >> M;
        int newSetSize = M+K;
        for(int i = K; i < newSetSize; i++){
            cin >> computers[i].computer1 >> computers[i].computer2 >> computers[i].weight; //T(n) = c*K+M
        }
        sum = 0;
        sort(computers.begin(),computers.begin()+newSetSize,compare); //T(n) = K+MLog(K+M)
        fill(newSetSize); //T(n) = K+M

        for(int i = 0; i < newSetSize; i++){
            if(merge(computers[i].computer1, computers[i].computer2)) sum += computers[i].weight;  //T(n) = 2K+MLog(K+M)
        }
        cout << sum << endl;
        counter += 1;

    }
    return 0;
}


//Prova de Corretude
//K+M = m
//T(roads,junctions) = c*computerSites + c+ c*K + c*m + m(Log(m)) + (m)*2(log(m)) + c
/***************T(n,k) = c + c*K + c*m + mlogm + 2mlogm ************/
//T(m,k) = k + m + 3mlogm *(MÁGICA)* T(n) = 3nlogn + m

//Teorema Mestre
//(MÁGICA)
//T(m) = 3T(m/2) + m  a = 3; b = 2; f(n) = n;
//n^log3 na base 2 +-= n^1,58
//cai no caso 3 onde af(n/b) <= cf(n)