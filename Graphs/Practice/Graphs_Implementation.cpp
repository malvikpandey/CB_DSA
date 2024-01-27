/*

Implementation of Graph Class

*/

#include<iostream>
#include<list>

using namespace std;

class Graph {
    int v; // to store number of vertices in the graph
    bool isDirected; // to indicate if graph is directed or not
    list<int>* arr;  // pointer to the array of list

    public:
        Graph(int v, bool isDirected = false) {
            this->v = v;
            this->isDirected = isDirected;
            arr = new list<int>[v];
        }

        void addEdge(int u, int v){
            // adds edge b/w vertex u and v

            arr[u].push_back(v);
            if(!isDirected){
                arr[v].push_back(u);
            }
        }

        void print() {
            // prints the adjacency list of graph

            for(int i=0; i<v; i++){
                cout<<i<<" : ";
                list<int> neighbourMap = arr[i];
                for(int neighbour : neighbourMap) {
                    cout<<neighbour<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
};

int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,2);

    g.print();
    return 0;
}