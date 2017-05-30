#include<bits/stdc++.h>
#define MaxSize 1000001
using namespace std;
/*alguns casos de teste não funcionaram T.T mas toma ai o código*/
struct Link{

    int city1, city2, weight;
};

vector<Link> cities(MaxSize);
vector<int> combine(MaxSize); //T(n) = c
map<string,int> cityMap;

void fill(int size){
    for(int i = 0; i < size; i++){  //T(n) = n
        combine[i] = i;
    }
}

int parent(int son){

    return combine[son] == son ? combine[son] : parent(combine[son]);  //T(n) = nlogn
}

int merge(int city1, int city2){

    int auxcity1 = parent(city1);
    int auxcity2 = parent(city2);
    if(auxcity1 != auxcity2){
        if(auxcity1 < auxcity2)combine[auxcity2] = auxcity1;  //T(n) = nlogn
        else if(auxcity1 > auxcity2) combine[auxcity1] = auxcity2; //T(n) = nlogn => T(n) = 2nlog 
        return 1;
    }
    return 0;
}

bool compare(const Link &a, const Link &b)
{
    return a.weight < b.weight;  //  //T(n) = c
}

int exists(string str){

    if(cityMap.find(str) != cityMap.end()) return cityMap[str];  //T(n) = logn
    else return cityMap[str] = cityMap.size();

}

int main(){

    int testCases;
    cin >> testCases;  //T(n) = c
    while(testCases){  //T(n) = n

        getchar();

        int numberOfCities, numberLinks, counter = 1;
        string cityKey1, cityKey2;
        
        cin >> numberOfCities >> numberLinks;
        
        for(int i = 0; i < numberLinks; i++){  //T(n) = numberLinks

            cin >> cityKey1 >> cityKey2 >> cities[i].weight;

            int aux1 = exists(cityKey1);  //T(n) = logn
            int aux2 = exists(cityKey2); //T(n) = logn => T(n) = 2logn

            cities[i].city1 = aux1;
            cities[i].city2 = aux2;

        }
        
        int sum = 0;
        fill(numberOfCities+1);
        sort(cities.begin(),cities.begin()+numberLinks,compare); //T(n) = log(numberofCities)

        for(int i = 0; i < numberLinks; i++){
          
            if(merge(cities[i].city1,cities[i].city2)) sum += cities[i].weight;  //T(n) = nlogn => T(n) = 2nlog 
        }

        cout << sum << endl;
        
        testCases--;
    }

    return 0;
}

