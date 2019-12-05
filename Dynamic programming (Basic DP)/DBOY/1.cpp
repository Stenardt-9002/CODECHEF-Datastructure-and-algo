#include<stdio.h>
#include<string.h>
int main()
{
int answer=0;
int maxdistance;
int dynaaray[1001],record[501],ditance[501],fuel[501],t,n,m=-1,i,j,k,sizefuel;
scanf("%d",&t);
while(t--)
{
  maxdistance=-1;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&ditance[i]);
    if(ditance[i]>maxdistance)
      {maxdistance=ditance[i];}
  }
  memset(dynaaray,29999,sizeof(dynaaray));
  memset(record,0,sizeof(record));
  sizefuel=0;
  for(i=0;i<n;i++)
  {
  scanf("%d",&k);
  if(record[k]==0)/*used to remove duplicates*/
    {
    fuel[sizefuel++]=k;
    record[k]=1;
    }
  }
  dynaaray[0]=0;
  for(i=0;i<sizefuel;i++)
    {

      for(j=0;j<=2*maxdistance-fuel[i];j++)
      {
      if(dynaaray[j]+1<dynaaray[j+fuel[i]])
        {
          dynaaray[j+fuel[i]]=dynaaray[j]+1;
        }

      }
    }
  answer=0;
  for(i=0;i<n;i++)
      {
        answer+= dynaaray[2*ditance[i]];
      }
  printf("%d\n",answer);


  }
  return 0;
}
