/*

Detection of a cycle in a graph.

*/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<map>
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

        bool dfsHelper(T source, unordered_set<T>& visited, T parent) {
            visited.insert(source);
            list<T> neighborList = neighbourMap[source];
            for(T neighbor : neighborList){
                if(visited.find(neighbor) == visited.end()){
                        if(dfsHelper(neighbor, visited, source)){
                            return true;
                        }
                } else {
                        if(neighbor != parent){
                            return true;
                        }
                }
            }

            return false;
        }

        bool isCyclePresent(){
            bool flag = false;
            unordered_set<T> visited;

            for(pair<T, list<T>> vertex : neighbourMap){
                T vertexLabel = vertex.first;
                if(visited.find(vertexLabel) == visited.end()){
                    if(dfsHelper(vertexLabel, visited, vertexLabel)){
                        flag = true;
                        break;
                    }
                }
            }
            return flag;
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

    g.isCyclePresent() ? cout<<"Cycle Found!" : cout<<"Cycle Not Found!" ;

    return 0;
}