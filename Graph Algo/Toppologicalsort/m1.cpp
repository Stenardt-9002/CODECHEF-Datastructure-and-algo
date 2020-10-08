#include<iostream>
#include<stack>
#include<list>

using namespace std;
class Graph1{

    int vertex;

    list<int> *other_edges;

    Graph1(int vertex2)
    {
        this->vertex = vertex2;
        other_edges = new list<int>[vertex2];

    }



    void add_Edge(int v,int w)
    {
        other_edges[v].push_back(w);
    }





}









int main(int argc, char const *argv[])
{
    
    return 0;
}







