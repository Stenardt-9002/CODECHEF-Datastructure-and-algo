#include <iostream>
typedef long long int lli;

using namespace std;


lli max(lli a, lli b){lli ans = a>b ? a: b;return ans;}


lli min(lli a, lli b){lli ans = a<b ? a: b;return ans;}

int main(int argc, char const *argv[])
{

  int t,n;
    int maxtempleft[10001],mintempleft[10001];

    int maxtempright[10001],mintempright[10001];
    int arr1[10001];
std::cin >> t;
cout<<endl<<t;
  while (t--)
  {
    cin>>n;
    

    cout<<"n"<<endl<<n;
    //for (int i = 0; i < n; i++)

    
    lli ans = 0;
    for (int i = 0; i < n; i++)
    {
      cin>>arr1[i];
    }
	cout<<"Reachedfhere"<<endl;
      for (int j = 0; j < n; ++j)
      {
          cout<<arr1[j];
      }
    maxtempleft[0] = arr1[0];
    mintempleft[0] = arr1[0];


    for (int i = 1; i < n; i++)
    {
	maxtempleft[i] = max(maxtempleft[i-1],0) + arr1[i];
	
	mintempleft[i] = min(mintempleft[i-1],0) + arr1[i];
    }



    maxtempright[n-1] = arr1[n-1];
    mintempright[n-1] = arr1[n-1];




    for (int i = n-2; i >0; i++)
    {
	maxtempright[i] = max(maxtempright[i+1],0) + arr1[i];
	
	mintempright[i] = min(mintempright[i+1],0) + arr1[i];
    }


    // #functionality


    for (int i =0; i <n-1; i++)
    {
	ans  = max(abs(maxtempleft[i]-mintempright[i+1]),ans);
	
	ans  = max(abs(mintempleft[i]-maxtempright[i+1]),ans);
    }
	

printf("%lld\n",ans);



  }



  return 0;
}
