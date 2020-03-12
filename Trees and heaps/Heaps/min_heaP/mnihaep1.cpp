#include<iostream>
#include<climits>
#include <math.h>
using namespace std;

// Prototype of a utility function to swap two integers
void swap(int *x, int *y);


class Min_Hae1p1
{
  int *harr;
  int cpacitya;
  int haeps_ize;



// private:
  /* data */

public:
  Min_Hae1p1 (int cpacitya)
  {
    haeps_ize = 0;
    this->cpacitya = cpacitya;
    harr = new int[cpacitya];
  }

  void MinHeapify(int );
  int parent(int i) { return (i-1)/2;}
  int left(int i) {return (2*i+1);}
  int right(int i) {return (2*i+2);}
  int extractMin();
  void descreaseKey(int i,int new_val);
  int getMin() {return harr[0];}
  void deleteKey(int i);

  void insertKey(int k);
  void printshiz();


  // virtual ~Min_Hae1p1 ();
};


void Min_Hae1p1::insertKey(int k)
{
  if (haeps_ize==cpacitya)
  {
    return;
    // overlow
    /* code */
  }

  haeps_ize++;
  int i = haeps_ize-1;
  harr[i] = k;

  while (i!=0&&harr[parent(i)]>harr[i])
  {
    swap(&harr[i],&harr[parent(i)]);
    i = parent(i);


  }


}
void Min_Hae1p1::printshiz()
{
  int i = 0 ;//mark
  std::cout << endl << '\n';
  int count = 0;
  int stop;
  while (i<haeps_ize)
  {
    stop = pow(2,count);
    count++;
    for (int j = i; j <i+stop ; j++)
    {
      if (j==haeps_ize)
      {
        break;
      }
      std::cout << harr[j]<<" ";

    }
    i = i+stop;
      std::cout  << '\n';
  }
}

void Min_Hae1p1::descreaseKey(int i,int new_val)
{
  harr[i] = new_val;
  while (i!=0&&harr[parent(i)]>harr[i])
  {
    swap(&harr[i],&harr[parent(i)]);
    i = parent(i);


  }


}

int Min_Hae1p1::extractMin()
{
  if (haeps_ize<=0)
  {
    return INT_MAX;
  }

  if (haeps_ize==1)
  {
    haeps_ize--;
    return harr[0];
  }

  int root = harr[0];
  harr[0] = harr[--haeps_ize];
  MinHeapify(0);
  return root;


}

void Min_Hae1p1::deleteKey(int i)
{
  descreaseKey(i,INT_MIN);
  extractMin();

}

void Min_Hae1p1::MinHeapify(int i)
{
  int l = left(i);
  int r = right(i);
  int smalles_t = i;
  if (l<haeps_ize && harr[l]<harr[i])
  {
    smalles_t = l;
  }
  if (r<haeps_ize&& harr[r]<harr[smalles_t])
  {
    smalles_t = r;

  }

  if (smalles_t!=i)
  {
    swap(&harr[i],&harr[smalles_t]);
    MinHeapify(smalles_t);
  }


}
//
// void Min_Hae1p1::buildheaiinlinear(int *arra1,int length)
// {
//
// }


void swap(int *x,int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}



int main(int argc, char const *argv[])
{
  Min_Hae1p1 h1(11);
  h1.insertKey(3);
  h1.insertKey(2);
  // h1.deleteKey(1);
  h1.insertKey(15);

  h1.insertKey(5);

  h1.insertKey(4);

  h1.insertKey(45);
  // cout << h1.extractMin() << " ";
  cout << h1.getMin() << " ";
  // h1.descreaseKey(2,1);
  // h1.decreaseKey(2, 1);
  // cout << h1.getMin();

  h1.printshiz();

  return 0;
}
