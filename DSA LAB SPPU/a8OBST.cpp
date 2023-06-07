#include <iostream>


using namespace std;

int optimalBSTCost(int keys[], int frequencies[], int n)
{
    int cost[n][n];

    for (int i = 0; i < n; i++)
    {
        cost[i][i] = frequencies[i];
    }

    // Fill in the rest of the cost matrix using dynamic programming
    for (int len = 0; len < n-1; len++)
    {
        for (int i = 0; i < n - len - 1; i++)
        {
            int j = i + len + 1;
            cost[i][j] = 999;

            // Calculate the cost for each possible root in the range [i, j]
            int sumFreq = 0;
            for (int k = i; k <= j; k++)
            {
                sumFreq += frequencies[k];
            }

            for (int k = i; k <= j; k++)
            {
                int tempCost = 0;
                if (k > i)
                {
                    tempCost += cost[i][k - 1];
                }
                if (k < j)
                {
                    tempCost += cost[k + 1][j];
                }
                tempCost += sumFreq;
                cost[i][j] = min(cost[i][j], tempCost);
            }
        }
    }

    return cost[0][n - 1];
}

int main()
{
    int n;
    cout << "Enter the number of keys: ";
    cin >> n;

    int keys[n];
    int frequencies[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter key" << i + 1 << " : ";
        cin >> keys[i];
    }

    cout << "Enter the frequencies:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter frequency of " << keys[i] << " : ";
        cin >> frequencies[i];
    }

    int optimalCost = optimalBSTCost(keys, frequencies, n);
    cout << "The optimal cost of the binary search tree is: " << optimalCost << endl;

    return 0;
}