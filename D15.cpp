#include <bits/stdc++.h>

using namespace std;

struct vertex
{
    bool seen = 0;
    vector < int > connections ;

    int pre = 0;
    int low = 0;

    int parent = -1 ;

};

set < int > k ;
int tim = 0;

void dfs(int u, vector < vertex > &v )
{
    v[u].seen = true;
    v[u].low = v[u].pre = (++tim);

    int child = 0;

        for(int i=0 ; i<v[u].connections.size() ;i++)
        {
            int x = v[u].connections[i];

            if(v[x].seen == false)
            {
                child++;
                v[x].parent = u;
                dfs(x, v);

                v[u].low = min(v[u].low , v[x].low);

                if( (v[u].parent!= -1) && ( v[x].low >= v[u].pre ) ) k.insert(u) ;
                if( (v[u].parent == -1) && (child>1)) k.insert(u) ;
            }
            else if( x!=v[u].parent ) v[u].low = min(v[u].low, v[x].pre);
        }
}

int main()
{
    int z;
    cin >> z;

    while(z--)
    {
        int n,m;
        cin >> n >> m ;

        vector < vertex > v(n+1) ;

        for(int i=0; i<m; i++)
        {
            int a,b;
            cin >> a >> b;

            v[a].connections.push_back(b);
            v[b].connections.push_back(a);
        }

        dfs(1, v) ;

        cout << k.size() ;

        for(auto i : k)
        {
            cout << " " << i ;
        }

        cout << endl;

        tim = 0;
        k.clear() ;


    }

    return 0;
}
