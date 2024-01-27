/*

Implementation of Depth First Search to traverse over graph

*/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<list>

using namespace std;

template <typename T>
class Graph {

    bool isDirected; // to indicate if graph is directed or not
    unordered_map<T,list<T>> neighbourMap;  // to store the graph representation
    //map<T,list<T>> neighbourMap;  // to store the graph representation in sorted manner

    public:
        Graph(bool isDirected = false) {
            this->isDirected = isDirected;
        }

        void addEdge(T u, T v){
            // adds edge b/w vertex u and v

            neighbourMap[u].push_back(v); 
            if(!isDirected){
                neighbourMap[v].push_back(u);
            }
        }

        void print() {
            // prints the adjacency list of graph
            for(pair<T, list<T>> p : neighbourMap){
                T vertex = p.first;
                list<T> neighList = p.second;

                cout<<vertex<<" : ";
                for(T ngb : neighList) {
                    cout<<ngb<<" ";
                }
                cout<<endl;
            }
        }

        void dfsHelper(T s, unordered_set<T>& visited) {
            //mark 's' as visited
            visited.insert(s);
            cout<<s<<" ";

            //Visited un-visited vertices reachable from 's'
            list<T> neighbours = neighbourMap[s];
            for(T ngh : neighbours) {
                if(visited.find(ngh) == visited.end()){
                    dfsHelper(ngh, visited);
                }
            } 
        }

        void dfs(T s) {
            unordered_set<T> visited;
            cout<<"dfs("<<s<<") : ";
            dfsHelper(s, visited);
        }
};

int main(){
    Graph<char> g;

    g.addEdge('A','B');
    g.addEdge('A','C');
    g.addEdge('B','D');
    g.addEdge('D','C');
    g.addEdge('D','E');
    g.addEdge('E','C');

    g.print();
    cout<<endl;

    g.dfs('A');
    return 0;
}