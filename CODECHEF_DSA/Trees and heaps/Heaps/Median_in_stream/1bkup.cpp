#include <iostream>
using namespace std;


class Heap
{
public:

    Heap(int *b, bool (*c)(int, int)) : A(b), comp(c)
    {
        heapSize = -1;
    }


    virtual ~Heap()
    {
        if( A )
        {
            delete[] A;
        }
    }

    // We need only these four interfaces of Heap ADT
    virtual bool Insert(int e) = 0;
    virtual int  GetTop() = 0;
    virtual int  ExtractTop() = 0;
    virtual int  GetCount() = 0;

protected:

    // We are also using location 0 of array
    int left(int i)
    {
        return 2 * i + 1;
    }

    int right(int i)
    {
        return 2 * (i + 1);
    }

    int parent(int i)
    {
        if( i <= 0 )
        {
            return -1;
        }

        return (i - 1)/2;
    }

    // Heap array
    int   *A;
    // Comparator
    bool  (*comp)(int, int);
    // Heap size
    int   heapSize;

    // Returns top element of heap data structure
    int top(void)
    {
        int max = -1;

        if( heapSize >= 0 )
        {
            max = A[0];
        }

        return max;
    }

    // Returns number of elements in heap
    int count()
    {
        return heapSize + 1;
    }

    // Heapification
    // Note that, for the current median tracing problem
    // we need to heapify only towards root, always
    void heapify(int i)
    {
        int p = parent(i);

        // comp - differentiate MaxHeap and MinHeap
        // percolates up
        if( p >= 0 && comp(A[i], A[p]) )
        {
            Exch(A[i], A[p]);
            heapify(p);
        }
    }

    // Deletes root of heap
    int deleteTop()
    {
        int del = -1;

        if( heapSize > -1)
        {
            del = A[0];

            Exch(A[0], A[heapSize]);
            heapSize--;
            heapify(parent(heapSize+1));
        }

        return del;
    }

    // Helper to insert key into Heap
    bool insertHelper(int key)
    {
        bool ret = false;

        if( heapSize < MAX_HEAP_SIZE )
        {
            ret = true;
            heapSize++;
            A[heapSize] = key;
            heapify(heapSize);
        }

        return ret;
    }

};



class MinHeap
{

  // MinHeap();

public:

  MinHeap(int *b, bool (*c)(int, int)) : A(b), comp(c)
  {
      heapSize = -1;
  }


  virtual ~Heap()
  {
      if( A )
      {
          delete[] A;
      }

  }






  int left(int i)
  {
      return 2 * i + 1;
  }

  int right(int i)
  {
      return 2 * (i + 1);
  }

  int parent(int i)
  {
      if( i <= 0 )
      {
          return -1;
      }

      return (i - 1)/2;
  }

  // Heap array
  int   *A;
  // Comparator
  bool  (*comp)(int, int);
  // Heap size
  int   heapSize;



  int top(void)
  {
      int max = -1;

      if( heapSize >= 0 )
      {
          max = A[0];
      }

      return max;
  }

  // Returns number of elements in heap
  int count()
  {
      return heapSize + 1;
  }


  // Heapification

  void heapify(int i)
  {
      int p = parent(i);

      if( p >= 0 && comp(A[i], A[p]) )
      {
          Exch(A[i], A[p]);
          heapify(p);
      }
  }









}
