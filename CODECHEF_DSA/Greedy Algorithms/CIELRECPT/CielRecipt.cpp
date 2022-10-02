#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(int argc,const char *argv[])
{
int t,p,count = 0 ;
cin>>t;

while(t--)
{
count = 0;
cin>>p;
while(p>0)
	{
		if (p<=2048)
		{
			int po = log2(p);
			po = pow(2,po);	
			p = p-po;
			count++;
		}
		else
		{
			while(p>2048)	
			{
				p-=2048;
				count++;
			}
		}
	}
	cout<<count<<endl;	

}


return 0;
}
