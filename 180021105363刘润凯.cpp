#include <iostream> 
using namespace std; 
 
const int L = 7;
 
int MatrixChain(int n,int **m,int **s,int *p); 
void Traceback(int i,int j,int **s);
 
int main()
{
	int p[L]={10,20,30,40,50,60,70};
 
    int **s = new int *[L];
	int **m = new int *[L];
	for(int i=0;i<L;i++)  
    {  
		s[i] = new int[L];
		m[i] = new int[L];
    } 
 
	cout<<"矩阵的最少计算次数为："<<MatrixChain(6,m,s,p)<<endl;
	cout<<"矩阵最优计算次序为："<<endl;
	Traceback(1,6,s);
	return 0;
}
 
int MatrixChain(int n,int **m,int **s,int *p)
{
	for(int i=1; i<=n; i++)
	{
		m[i][i] = 0;
	}
	for(int r=2; r<=n; r++) 
	{
		for(int i=1; i<=n-r+1; i++)
		{
			int j = i+r-1;
			m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j]; 
			s[i][j] = i;
			for(int k=i+1; k<j; k++)
			{  
				int t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if(t<m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
	return m[1][L-1];
}
 
void Traceback(int i,int j,int **s)
{
	if(i==j) 
	return;
	Traceback(i,s[i][j],s);
	Traceback(s[i][j]+1,j,s);
	cout<<"Multiply A"<<i<<","<<s[i][j];
	cout<<" and A"<<(s[i][j]+1)<<","<<j<<endl;
}

