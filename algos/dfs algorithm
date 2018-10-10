/**                             print by dfs by Sahaj Jain                        **/

#include <iostream>
using namespace std;

bool printpathDFS(int** edges,int n, int sv, int ev,int* visited)
{
  
  if(sv==ev)
  {
    return true;
  }
  
  visited[sv]=1;
  
  for(int i=0 ;i<n ;i++)
    if(visited[i]!=1 && edges[sv][i]==1)
    { bool k=printpathDFS(edges,n,i,ev,visited);
      if(k==1)
      {
        cout<<i<<" ";
        return true;
      }
    }
     
  return false;
}

int main()
{
  int n, v, a , b;
   cin >> n >> v;   // vertices and edges
  int** edges = new int*[n];
  
  for(int i=0; i<n; i++)
  {
    edges[i]=new int[n];
    for(int j=0; j<n ;j++)
      edges[i][j]=0;
  }

  for(int i=0; i<v ; i++ )
  {
    int f,s;
    cin>>f>>s;
    edges[f][s]=1;
    edges[s][f]=1;
  }
  
     cin>>a>>b;

  int* visited=new int[n];
  
  bool ans=printpathDFS(edges,n,a,b,visited);
  if(ans)
    cout<<a;
  
  return 0;
}
