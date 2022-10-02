#include<queue>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Divisinc
{

public:
    
    int countOpera(int N,int M)
    {
        vector <int> dist(M+1,-1);
        queue <int> q;
        q.push(N);
        dist[N] = 0;

        while (!q.empty())
        {
            int val = q.front();
            q.pop();

            if (val==M) 
            {
                break;
            }
            vector <int> gri = gEtDivi(val);
            for(int d = 0 ; d <gri.size() ; d++)
            {
                int pathval = val+gri[d];
                if (pathval<= M && dist[pathval]==-1)

                {
                    q.push(pathval);
                    dist[pathval] = dist[val]+1;
                }
                
            }



        }

        return dist[M];
        
    }



    vector <int> gEtDivi(int val)
    {
        vector <int> diVisors;
        for (int i = 2; i <= sqrt(val); i++)
        {
            /* code */
            if (val%i==0)
            {
                diVisors.push_back(i);
                diVisors.push_back(val/i);
            }
        }
        return diVisors;
        
    }


};

int main(int argc, char const *argv[])
{
    int m,n;
    cin>>m>>n;
    Divisinc D12;
    cout<<D12.countOpera(m,n)<<endl;
    return 0;
}
