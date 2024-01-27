/*

Implementation of Breadth First Search to traverse over graph

*/

#include<iostream>
#include<unordered_map>
#include<queue>
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

        void bfs(T s){

            cout<<"bfs("<<s<<") : ";

            unordered_set<T> visited; //to keep track of of visited vertices
            queue<T> q; // to keep track of visited and un-visited vertices

            visited.insert(s);
            q.push(s);

            while(!q.empty()){
                T front = q.front();
                q.pop();

                //explore front
                cout<<front<<" ";

                list<T> ngh = neighbourMap[front];
                for(T ng : ngh){
                    if(visited.find(ng) == visited.end()){
                        visited.insert(ng);
                        q.push(ng);
                    }
                }
            }

            
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

    g.bfs('A');
    return 0;
}