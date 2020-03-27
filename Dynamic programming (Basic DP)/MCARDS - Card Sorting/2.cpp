
#include <cstdio>
#include <algorithm>
using namespace std;

int index_1[5][101], u[404], val1[404];
int seqarra[404], au_12x[404];
int o1r_d[4] = {1, 2, 3, 4}, N, C;

int lis_function(int sz)
{
	int i, u, valtraers, bsindez = 0, m;
	au_12x[bsindez++] = 0;
	for(i=1; i<sz; i++)
  {
		if(seqarra[au_12x[bsindez-1]] < seqarra[i]) {
			au_12x[bsindez++] = i;
			continue;
		}
		for(u=0, valtraers=bsindez-1; u < valtraers; ) {
			m = (u + valtraers)>>1;
			if(seqarra[au_12x[m]] < seqarra[i]) u = m + 1;
			else valtraers = m;
		}
		if(seqarra[i] < seqarra[au_12x[u]]) au_12x[u] = i;
	}
	return bsindez;
}

int main()
{
	int i, j, t, cnt, minval2n = 1<<30;
	//freopen("C:\\in.txt", "r", stdin);

	scanf("%d%d", &C, &N);

	for(i=0, t=N*C; i<t; i++)
  {
    scanf("%d%d", &u[i], &val1[i]);
  }
	do
  {
		for(cnt=i=0; i<C; i++)
			for(j=1; j<=N; j++)
				index_1[o1r_d[i]][j] = ++cnt;
		for(j=0; j<t; j++) seqarra[j] = index_1[u[j]][val1[j]];
		minval2n = min(minval2n, t-lis_function(t));
	}
   while(next_permutation(o1r_d, o1r_d + C));
	printf("%d\n", minval2n);
	return 0;
}
