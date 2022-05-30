#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Input the number of nodes: ";
    cin >> n;
    int m;
    // cout<<"Input the number of edges: ";
    // cin>>m;

    int adjacency[n + 1][n + 1];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Input for " << i << " " << j << " index: ";
            cin >> adjacency[i][j];
        }
    }

    /* for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            cout<<adjacency[i][j]<<" ";
        }
        cout<<endl;
    }

*/
    int inDegree = 0, outDegree = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adjacency[i][j] == 1)
            {
                inDegree++;
            }
            if (adjacency[j][i] == 1)
            {
                outDegree++;
            }
        }
    }

    cout << "Indegree: " << inDegree << " OutDegree: " << outDegree << endl;

    cout << "Sum of in degree and out degree: " << inDegree + outDegree << endl;
    return 0;
}