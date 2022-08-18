#include <bits/stdc++.h>
using namespace std;

//UNION FIND 
class Edge{
public:
    int source;
    int destination;
    int weight;
    Edge() {}
    Edge(int x, int y, int z){
        source = x;
        destination = y;
        weight = z;
    }
};

bool comapre(Edge e1, Edge e2){
    return e1.weight < e2.weight;
}
int main() {
    int v, e;
    cin >> v >> e;
    Edge* arr = new Edge[e];
    cout << "size " << e << endl;
    for(int i=0;i<e;i++){
        int x, y, z;
        cin >> x >> y >> z;
        arr[i].source = x;
        arr[i].destination = y;
        arr[i].weight = z;
    }
    sort(arr, arr+e , comapre);
    int count = 0;
    vector<int> parent;
    vector<Edge*> answer;

    for(int i=0;i<v;i++) {
        parent.push_back(i);
    }

    int i = 0;
    while(count < v - 1){
        Edge smallest = arr[i++];
        int src = smallest.source;
        int dest = smallest.destination;
        int tempSrc = src;
        int tempDest = dest;

        while(parent[src] != src){
            src = parent[src];
        }
        while(parent[dest] != dest){
            dest = parent[dest];
        }
        int srcParent = src;
        int destParent = dest;

        if(srcParent == destParent) continue;

        parent[srcParent] = destParent;
        Edge* obj = new Edge(tempSrc, tempDest, smallest.weight);
        answer.push_back(obj);
        count++;

    }

    for(int i=0;i<v-1;i++){
        if(answer[i]->source < answer[i]->destination){
            cout << answer[i]->source << " " << answer[i]->destination << " " << answer[i]->weight;
        }else{
            cout << answer[i]->destination << " " << answer[i]->source << " " << answer[i]->weight;
        }
        cout << endl;
    }
    return 0 ;
}




