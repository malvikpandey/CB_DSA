/*
Implementation of Single Source Shortest path using BFS in un-weighted Graph.
*/

#include<iostream>
#include<unordered_map>
#include<list>
#include<unordered_set>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>

using namespace std;

template<typename T>
class Graph{
    
    bool isDirected;
    unordered_map<T, list<T>> neighbourMap;

    public:
        Graph(bool isDirected = false){
            this->isDirected = isDirected;
        }

        void addEdge(T u, T v) {
            neighbourMap[u].push_back(v);
            if(!isDirected){
                neighbourMap[v].push_back(u);
            }
        }

        void printGraph() {
            for(pair<T, list<T>> vertex : neighbourMap) {
                T vertexLabel = vertex.first;
                list<T> neighbourList = vertex.second;

                cout<<vertexLabel<<" : ";
                for(T neighbour : neighbourList){
                    cout<<neighbour<<" ";
                }

                cout<<endl;
            }
        }

        void ssspBfs(T s, T d){
            unordered_map<T, int> distanceMap;
            unordered_map<T, T> parentMap;

            distanceMap[s] = 0;
            parentMap[s] = s;

            unordered_set<T> visited;
            visited.insert(s);

            queue<T> q;
            q.push(s);

            while(!q.empty()) {
                T front = q.front();
                q.pop();

                T vertexLabel = front;
                list<T> neighbourList = neighbourMap[front];

                for(T neighbour : neighbourList) {
                    if(visited.find(neighbour) == visited.end()){
                        visited.insert(neighbour);
                        q.push(neighbour);

                        distanceMap[neighbour] = distanceMap[front] + 1;
                        parentMap[neighbour] = front;
                    }
                }


            }

            for(pair<T, int> vertex : distanceMap){
                T vertexLabel = vertex.first;
                int distance = vertex.second;
                cout<<vertexLabel<<" : "<<distance;
                cout<<endl;
            }
            cout<<endl;

            vector<T> shortestPath;

            T temp = d;

            while(parentMap[temp] != temp){
                shortestPath.push_back(temp);
                temp = parentMap[temp];
            }

            shortestPath.push_back(temp);

            reverse(shortestPath.begin(), shortestPath.end());

            for(T vertex : shortestPath){
                cout<<vertex<<" ";
            }

        }
};


int main(){
    Graph<char> g;

    g.addEdge('A', 'B');
    g.addEdge('A', 'C');
    g.addEdge('B', 'D');
    g.addEdge('B', 'E');
    g.addEdge('D', 'G');
    g.addEdge('E', 'G');
    g.addEdge('E', 'H');
    g.addEdge('G', 'I');
    g.addEdge('H', 'I');
    g.addEdge('C', 'E');
    g.addEdge('C', 'F');
    g.addEdge('F', 'H');

    g.printGraph();

    cout<<endl;

    g.ssspBfs('A', 'I');
    return 0;
}