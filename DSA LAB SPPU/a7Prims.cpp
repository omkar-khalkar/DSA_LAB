/*
You have a business with several offices; you want to lease phone lines to connect them
up with each other; and the phone company charges different amounts of money to
connect different pairs of cities. You want a set of lines that connects all your offices with
a minimum total cost. Solve the problem by suggesting appropriate data structures. 
*/



#include <iostream>
using namespace std;

int main()
{
    int i, j, n, e , p , w, min, minCostOfGraph, row, col,l,m,cost;
    char ch;
    cout << "Enter no of vertices: ";
    cin >> n;
    cout << "\nEnter no of Edegs: ";
    cin >> e;

    int visit[n];
    int costMat[n][n];


    for (i=0; i<n;i++)
    {
        visit[i]=0;
        for(j=0;j<n;j++)
        {
            costMat[i][j] = 999;  //...........made cost of each edge equal to 999
        }
    }


    for (i=0; i<e;i++)
    {
        cout<<"\nEDGES: ";
        cin>>l>>m;
        cout<<"Enter Cost Of : "<<l<<"->"<<m<<": ";
        cin>>p;
        costMat[l][m]=p;
    }


    cost=0;
    visit[0]=1;
    for (int k=0;k<n-1;k++)
    {
        min = 999;
        for (i = 0;i<n;i++)
        {
            for (j =0;j<n;j++)
            {
                if (visit[i]==1 && visit[j]==0)
                {
                    if (costMat[i][j] != 999 && costMat[i][j] < min)
                    {
                        min = costMat[i][j];
                        row = i;
                        col = j;
                    }
                }
            }
        }
        minCostOfGraph = min;
        visit[col] = 1;

        cout << "\n Edge Of MST : " << row  << "---->" << col << " : "<<min<<endl;
        
        cost += min;
    }
    cout<<"\nThe Mininum Cost Of Graph :"<<cost;
}