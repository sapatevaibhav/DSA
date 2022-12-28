/* Problem Statement :
Implementation of graph using dynamic arrays (vector in C++) to represent adjacency lists instead of the linked list.
Include traversing algorithm and path output. 

*/
// -.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.

#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0)

// -.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.

void dfs(vector <int> g[], int curr,bool visit[]) //Depth First search approach
{
    visit[curr]=true;
    cout<<curr<<"  ";

    for(int i=0;i<g[curr].size();i++)
    {

      if(!visit[g[curr][i]])
      {
        dfs(g,g[curr][i],visit);
      }
    }
    
}

// -.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.

void bfs(vector <int> g[], int curr,bool visit[]) //Breadth First search approach
{
    int i;
    visit[curr]=true;
    queue <int> q;
    q.push(curr);
    while(!q.empty())
    {
      curr=q.front();
      i=0;
      while(i<g[curr].size())
      {
        if(!visit[g[curr][i]])
        {
          visit[g[curr][i]]=true;
          q.push(g[curr][i]);
        }
        
        i++;
      }
      i=q.front();
      q.pop();
      cout<<i<<" ";
    } 
    
}

// -.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.

bool path(vector <int> g[], int curr,bool visit[],int b)
{
    visit[curr]=true;
    if(curr==b)
    {
      cout<<curr<<endl;
      return true;
    }
    cout<<curr<<" ---->";
    for(int i=0;i<g[curr].size();i++)
    {
      if(!visit[g[curr][i]])
      {
        return path(g,g[curr][i],visit,b);
      }
    }
    return false;
    
}

// -.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.

void graph() //Creating Graph using vector
{
  int v,e;
  cout<<"Enter the value of vectices in the graph :";
  cin>>v;
  v--;
  cout<<"Enter the value of edges in the graph :";
  cin>>e;
  vector <int> g[v+1];
  int x,y;

  for(int i=0;i<e;i++)
  {
    cout<<"Enter the value of both edges included :\n";
    cin>>x>>y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  cout<<"\nGraph Representation as follows : \n";

  for(int i=0;i<=v;i++)
  {
    cout<<i<<"---> ";
    for(int j=0;j<g[i].size();j++)
    {
      cout<<g[i][j]<<" ";
    }
    cout<<endl;
  }

  cout<<"Depth First Search of the graph :\n";

  //Depth First Search
  bool visit[v+1];
  for(int i=0;i<v+1;i++)
  {
    if(!visit[i])
    {
      dfs(g,i,visit);
      cout<<endl;
    }
  }
  
  cout<<endl;

  memset(visit,false,v+1);

  cout<<"Breadth First Search of the graph :\n";
  //Breadth First Search
  for(int i=0;i<v+1;i++)
  {
    if(!visit[i])
    {
      bfs(g,i,visit);
      cout<<endl;
    }
  }

  memset(visit,false,v+1);

  cout<<"\nChecking whether path exists between two vectices :\n";

  cout<<"Enter vectex 1 :";
  cin>>x;
  cout<<"Enter vectex 2 :";
  cin>>y;

  cout<<"\nPath from "<<x<<" to "<<y<<endl;
  if(path(g,x,visit,y))
  {
    cout<<"Path Exists ";
  }
  else
  {
    cout<<"Path does not Exists ";
  }
  cout<<endl;
}
 
  // -.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.
   
int main()
{
  fast;   //makes cin fast  

  int v,e;
  cout<<"Enter the value of vectices in the graph :";
  cin>>v;
  v--;
  cout<<"Enter the value of edges in the graph :";
  cin>>e;
  vector <int> g[v+1];
  int x,y;

  for(int i=0;i<e;i++)
  {
    cout<<"Enter the value of both edges included :\n";
    cin>>x>>y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  cout<<"\nGraph Representation as follows : \n";

  for(int i=0;i<=v;i++)
  {
    cout<<i<<"---> ";
    for(int j=0;j<g[i].size();j++)
    {
      cout<<g[i][j]<<" ";
    }
    cout<<endl;
  }

  cout<<"Depth First Search of the graph :\n";

  //Depth First Search
  bool visit[v+1];
  for(int i=0;i<v+1;i++)
  {
    if(!visit[i])
    {
      dfs(g,i,visit);
      cout<<endl;
    }
  }
  
  cout<<endl;

  memset(visit,false,v+1);

  cout<<"Breadth First Search of the graph :\n";
  //Breadth First Search
  for(int i=0;i<v+1;i++)
  {
    if(!visit[i])
    {
      bfs(g,i,visit);
      cout<<endl;
    }
  }

  memset(visit,false,v+1);

  cout<<"\nChecking whether path exists between two vectices :\n";

  cout<<"Enter vectex 1 :";
  cin>>x;
  cout<<"Enter vectex 2 :";
  cin>>y;

  cout<<"\nPath from "<<x<<" to "<<y<<endl;
  if(path(g,x,visit,y))
  {
    cout<<"Path Exists ";
  }
  else
  {
    cout<<"Path does not Exists ";
  }
  cout<<endl;
  cout<<endl;
 
  return 0;
}
