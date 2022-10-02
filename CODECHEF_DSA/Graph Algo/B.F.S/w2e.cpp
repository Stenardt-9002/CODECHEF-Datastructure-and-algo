
// Time Complexity: O(V+E) where V is number of vertices in the graph and E is number of edges in the grap
#include <iostream>
#include <list>

using namespace std;


class Graph
{
private:
  int V;list<int> *adjvertice;




public:
  Graph (int V)
  {
    this->V = V;
    this->adjvertice = new list<int>[V];
  }


  void aDDedge(int v1,int w1)
  {
    this->adjvertice[v1].push_back(w1);



  }


  void BFSalfo(int start1)
  {

    bool *discovere1d = new bool[this->V];
    for (int i = 0; i < this->V; i++)
    {
      discovere1d[i] = false;

    }

    list <int> que1;
    discovere1d[start1] = true;
    que1.push_back(start1);
    // std::cout << "start = "<<start1 << '\n';

    while (!que1.empty())
    {
      start1 = que1.front();
      // std::cout << "start = "<<start1 << '\n';

      // print it
      printf("%d ,",start1 );
      que1.pop_front();

      if(this->adjvertice[start1].size()>0 && this->adjvertice[start1].size()<32000)
      {
        // std::cout << this->adjvertice[start1].size() << '\n';
        for (list<int>::iterator i = this->adjvertice[start1].begin(); i !=this->adjvertice[start1].end(); i++)
      {
        // std::cout << *i << '\n';
        if (discovere1d[*i]==false)
        {
          discovere1d[*i] = true;
          que1.push_back(*i);


        }



      }
    }


    }





  }









};



int main(int argc, char const *argv[])
{

  Graph g1(6) ;
  g1.aDDedge(1,2);
  g1.aDDedge(1,3);
  g1.aDDedge(2,1);
  g1.aDDedge(2,4);
  g1.aDDedge(2,5);
  g1.aDDedge(3,1);
  g1.aDDedge(3,5);
  g1.aDDedge(4,2);
  g1.aDDedge(4,5);
  g1.aDDedge(4,6);
  g1.aDDedge(5,3);
  g1.aDDedge(5,4);
  g1.aDDedge(5,2);
  g1.aDDedge(5,6);


  std::cout << "TEST thi code" << '\n';
  g1.BFSalfo(1);

  return 0;
}
