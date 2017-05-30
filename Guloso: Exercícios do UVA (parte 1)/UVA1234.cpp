#include<bits/stdc++.h>
#define MaxSize 1000001
using namespace std;

struct Road{

    int junc1, junc2, weight;
};
vector<Road> road(MaxSize);
vector<int> combine(MaxSize);

void fill(int size){
    for(int i = 0; i < size; i++){  // c*n
        combine[i] = i;
    }
}

int parent(int son){

    return combine[son] == son ? combine[son] : parent(combine[son]); //nlogn
}

bool compare(const Road &a, const Road &b)
{
    return a.weight < b.weight;           // c
}

int merge(int junc1, int junc2){

    int auxjunc1 = parent(junc1); // nlogn
    int auxjunc2 = parent(junc2); // nlogn
    if(auxjunc1 != auxjunc2){
        if(auxjunc1 < auxjunc2)combine[auxjunc2] = auxjunc1;
        else if(auxjunc1 > auxjunc2) combine[auxjunc1] = auxjunc2;
        return 1;
    }
    return 0;
}

int main(){

    int dataSets;
    cin >> dataSets;
    while(dataSets){  // c = dataSets

        int junctions, roads, sum = 0;
        cin >> junctions >> roads;
        for(int i = 0; i < roads; i++){ // c = roads
            cin >> road[i].junc1 >> road[i].junc2 >> road[i].weight;
            sum += road[i].weight;
        }

        fill(junctions+1); // c = junctions
        sort(road.begin(),road.begin()+roads,compare); // nlogn

        for(int i = roads-1; i >= 0; i--){  // c= roads-1 

            if(merge(road[i].junc1,road[i].junc2)){  // 2logn
                sum -= road[i].weight;
            }
        }                            // roads-1 * (2log(roads))
        cout << sum << endl;
        dataSets--;
    }

        int aux;
        cin >> aux;

    return 0;
}

//Prova de Corretude

//T(roads,junctions) = roads + junctions + roadslog(roads) + (roads)*2(log(roads))
/***************T(n,k) = n + k + nlogn + 2nlogn ************/
//T(n,k) = k + n + 3nlogn *(MÁGICA)* T(n) = 3nlogn + n

//Teorema Mestre
//(MÁGICA)
//T(n) = 3T(n/2) + n  a = 3; b = 2; f(n) = n;
//n^log3 na base 4 +-= n^1,58
//cai no caso 3 onde af(n/b) <= cf(n)
