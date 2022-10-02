#include <iostream>
// #include <stdio.h>

#include <climits>


using namespace std;

class Minheap12
{
  int *ar1;//array
  int cap; //max siez
  int heap_size; //current size



public:
  Minheap12(int capacity)  //Constructor
  {
    heap_size = 0;
    cap = capacity;
    ar1 = new int[capacity];
  }

  void ShowArray()
  {
    cout<<endl<<" The heap size "<<heap_size<<endl;

    for (int i = 0; i < heap_size; i++)
    {
      cout<<" "<<ar1[i]<<" ";
    }
  }

  int parent1(int i)
  {
    return (i-1)/2;
  }

  int leftchid(int i)
  {
    return (2*i)+1;
  }

  int rightchild(int i)
  {
    return (2*i)+2;
  }

  void swap(int *x,int *y)
  {
    int tmp = *x;
    *x = *y;
    *y = tmp;
  }
  //insert ele
  void insertkey(int ele)
  {
      if (heap_size == cap)
      {
        cout<<endl<<"capacity reached";
        return ;
      }

      heap_size++;
      int i = heap_size-1;
      ar1[i] = ele;

      while((ar1[parent1(i)]>ar1[i])&&i!=0 )
      {
          swap(&ar1[i],&ar1[parent1(i)]);
          i = parent1(i);

      }

  }

  void deletekey(int key)
  {
    // decreasekey(key,-6969);
    ar1[key] = -6969;
    while ((ar1[parent1(key)]>ar1[key])&& key!=0)
    {
      swap(&ar1[key],&ar1[parent1(key)]);
      key = parent1(key);
    }

    removeMin();
  }

  int removeMin()
  {
      if (heap_size==0)
      {
          return -6969;
      }
      if (heap_size==1)
      {
          heap_size--;
          return ar1[0];
      }

      int min1 = ar1[0];
      ar1[0] = ar1[heap_size-1];
      heap_size--;
      MinHeapify(0);
      return min1;


  }

  void MinHeapify(int i)
  {
  	int l = leftchid(i);
  	int r = rightchild(i);
  	int smallest = i;
  	if (l < heap_size && ar1[l] < ar1[i])
      {
      smallest = l;
      }
  	if (r < heap_size && ar1[r] < ar1[smallest])
  		{
        smallest = r;
      }
  	if (smallest != i)
  	{
  		swap(&ar1[i], &ar1[smallest]);
  		MinHeapify(smallest);
  	}
  }

};

int main()
{
  Minheap12 M(6);
  M.insertkey(1);
  M.ShowArray();
  M.insertkey(3);
  M.ShowArray();
  M.deletekey(0);
  M.ShowArray();
  M.insertkey(1);
  M.ShowArray();
  M.insertkey(6);
  M.ShowArray();
  M.insertkey(5);
  M.ShowArray();
  M.insertkey(9);
  M.ShowArray();
  M.insertkey(8);
  M.ShowArray();
  return 0;
}
