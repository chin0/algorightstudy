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
        int root = parent[x];
        while(root != parent[x]) 
            root = parent[root];
        parent[x] = root; //path compression!
        return root;
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
        cout << parent[yRoot] << endl;
    }
};

int main(void) {
    UnionFind UF(10);
    cout << UF.Find(1) << endl;
}




        

