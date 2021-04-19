#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int row_cnt = 3;
int col_cnt = 3;
int arr[200][200];

void count(int fix, int col)
{

    if (col)
    {
        for (int j = 0; j < col_cnt; j++)
        {
            vector<int> temp;
            vector<pair<int, int> > result;
            for (int i = 0; i < row_cnt; i++)
            {

                if (arr[i][j] == 0)
                    continue;
                temp.push_back(arr[i][j]);
            }

            sort(temp.begin(), temp.end());
            int index;

            for (int k = 0; k < temp.size(); k += index)
            {
                int num = temp[k];
                index = upper_bound(temp.begin(), temp.end(), num) - lower_bound(temp.begin(), temp.end(), num);

                result.push_back(make_pair(index, num));
            }

            sort(result.begin(), result.end());

            for (int i = 0; i < 105; i++)
            {

                arr[i][j] = 0;
            }

            row_cnt = max(row_cnt, (int)result.size() * 2);

            for (int i = 0; i < result.size(); i++)
            {

                arr[i * 2][j] = result[i].second;
                arr[i * 2 + 1][j] = result[i].first;
            }
        }
    }
    if (!col)
    {

        for (int i = 0; i < row_cnt; i++)
        {
            vector<int> temp;
            vector<pair<int, int> > result;
            for (int j = 0; j < col_cnt; j++)
            {

                if (arr[i][j] == 0)
                    continue;

                temp.push_back(arr[i][j]);
            }

            sort(temp.begin(), temp.end());
            int index;

            for (int k = 0; k < temp.size(); k += index)
            {
                int num = temp[k];
                index = upper_bound(temp.begin(), temp.end(), num) - lower_bound(temp.begin(), temp.end(), num);
                result.push_back(make_pair(index, num));
            }

            sort(result.begin(), result.end());
            col_cnt = max(col_cnt, (int)result.size() * 2);

            for (int j = 0; j < 105; j++)
            {

                arr[i][j] = 0;
            }

            for (int j = 0; j < result.size(); j++)
            {
                arr[i][j * 2] = result[j].second;
                arr[i][j * 2 + 1] = result[j].first;
            }
        }
    }
}

int main()
{

    int r, c, k;
    cin >> r >> c >> k;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    int cnt = 101;

    int time_ = 0;

    bool check = false;

    while (cnt--)
    {

        if (arr[r - 1][c - 1] == k)
        {
            check = true;
            break;
        }

        if (row_cnt >= col_cnt)
        {

            count(row_cnt, 0);
        }
        else
        {

            count(col_cnt, 1);
        }

        time_ += 1;
    }

    if (check)
    {
        cout << time_ << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }

    return 0;
}