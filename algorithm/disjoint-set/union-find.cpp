#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
    vector <int> parent,rank;
    UnionFind(int n) {
        for(int i = 0; i < n; i++) {
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    int Find(int x) {
        if(parent[x] != x) 
            Find(parent[x]);
        return x;
    }

    void Union(int x, int y) {
        int xRoot = Find(x);
        int yRoot = Find(y);

        //x와 y는 이미 같은 집합에 있음.
        if(xRoot == yRoot) 
            return;

        if(rank[xRoot] < rank[yRoot]) 
            parent[xRoot] = yRoot;
        else if(rank[xRoot] > rank[yRoot])
            parent[yRoot] = xRoot;
        else{
            parent[yRoot] = xRoot;
            rank[xRoot] += 1;
        }
    }
};

int main(void) {
    UnionFind UF(10);
    UF.Union(1,3);
    UF.Union(2,3);
    cout << UF.Find(3) << endl;
}




        

