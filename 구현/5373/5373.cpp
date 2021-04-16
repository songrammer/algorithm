#include <iostream>
#include <vector>
using namespace std;
char map[6][3][3];

char temp[6][3][3];
void copy()
{

    for (int m = 0; m < 6; m++)
    {

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                temp[m][i][j] = map[m][i][j];
            }
        }
    }
}

void LEFT()
{

    int right[] = {0, 2, 1, 3};

    for (int i = 0; i < 3; i++)
    {
        int from = right[i];
        int to = right[i + 1];
        for (int j = 0; j < 3; j++)
        {

            map[to][j][0] = temp[from][j][0];
        }
    }

    for (int j = 0; j < 3; j++)
    {
        map[right[0]][j][0] = temp[right[3]][j][0];
    }
}

void RIGHT()
{

    int left[] = {0, 2, 1, 3};

    for (int i = 0; i < 3; i++)
    {
        int from = left[i];
        int to = left[i + 1];
        for (int j = 0; j < 3; j++)
        {
            // cout <<"index:"<<j <<'\n';
            //   cout <<"char_b :"<< map[to][j][3]<<" value :"<<temp[from][j][3]<<'\n';

            map[to][j][2] = temp[from][j][2];
        }
    }

    for (int j = 0; j < 3; j++)
    {
        map[left[0]][j][2] = temp[left[3]][j][2];
    }
}

void UP()
{

    int left[] = {2, 5, 3, 4};

    for (int i = 0; i < 3; i++)
    {
        int from = left[i];
        int to = left[i + 1];
        for (int j = 0; j < 3; j++)
        {

            map[to][0][j] = temp[from][0][j];
        }
    }

    for (int j = 0; j < 3; j++)
    {
        map[left[0]][0][j] = temp[left[3]][0][j];
    }
}

void DOWN()
{

    int right[] = {2, 5, 3, 4};

    for (int i = 0; i < 3; i++)
    {
        int from = right[i];
        int to = right[i + 1];
        for (int j = 0; j < 3; j++)
        {

            map[to][2][j] = temp[from][2][j];
        }
    }

    for (int j = 0; j < 3; j++)
    {
        map[right[0]][2][j] = temp[right[3]][2][j];
    }
}

void FRONT()
{

    int left[] = {0, 4, 1, 5};

    for (int i = 0; i < 3; i++)
    {
        int from = left[i];
        int to = left[i + 1];
        for (int j = 0; j < 3; j++)
        {

            if (i % 2 == 0)
            {
                if (i == 0)
                {
                    map[to][j][2] = temp[from][2][j];
                }
                else
                {
                    map[to][j][0] = temp[from][2][j];
                }
            }
            else
            {
                map[to][2][j] = temp[from][j][2];
            }
        }
    }

    for (int j = 0; j < 3; j++)
    {

        map[left[0]][2][j] = temp[left[3]][j][0];
    }
}

void BACK()
{

    int right[] = {0, 4, 1, 5};

    for (int i = 0; i < 3; i++)
    {
        int from = right[i];
        int to = right[i + 1];
        for (int j = 0; j < 3; j++)
        {

            if (i % 2 == 0)
            {
                if (i == 0)
                {
                    map[to][j][0] = temp[from][0][j];
                }
                else
                {
                    map[to][j][2] = temp[from][0][j];
                }
            }
            else
            {
                map[to][0][j] = temp[from][j][0];
            }
        }
    }

    for (int j = 0; j < 3; j++)
    {

        map[right[0]][0][j] = temp[right[3]][j][2];
    }
}

int main()
{

    int n;
    cin >> n;

    for (int m = 0; m < 6; m++)
    {

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {

                char init;
                if (m == 0)
                {
                    init = 'w';
                }
                else if (m == 1)
                {
                    init = 'y';
                }
                else if (m == 2)
                {

                    init = 'r';
                }
                else if (m == 3)
                {

                    init = 'o';
                }
                else if (m == 4)
                {

                    init = 'g';
                }
                else
                {
                    init = 'b';
                }
                map[m][i][j] = init;
            }
        }

        // cout <<'\n';
    }

    while (n--)
    {

        vector<string> v;
        int k;
        cin >> k;
        int index = 0;

        for (int i = 0; i < k; i++)
        {
            string s;
            cin >> s;
            v.push_back(s);
        }

        for (int i = 0; i < v.size(); i++)
        {

            if (v[i][0] == 'L')
            {
                copy();
                if (v[i][1] == '+')
                {

                    LEFT();
                }
                else
                {
                    LEFT();
                    copy();
                    LEFT();
                    copy();
                    LEFT();
                }
            }

            if (v[i][0] == 'R')
            {
                copy();
                if (v[i][1] == '-')
                {

                    RIGHT();
                }
                else
                {
                    RIGHT();
                    copy();
                    RIGHT();
                    copy();
                    RIGHT();
                }
            }

            if (v[i][0] == 'U')
            {
                copy();
                if (v[i][1] == '-')
                {

                    UP();
                }
                else
                {
                    UP();
                    copy();
                    UP();
                    copy();
                    UP();
                }
            }

            if (v[i][0] == 'D')
            {
                copy();
                if (v[i][1] == '+')
                {

                    DOWN();
                }
                else
                {
                    DOWN();
                    copy();
                    DOWN();
                    copy();
                    DOWN();
                }
            }

            if (v[i][0] == 'F')
            {
                copy();
                if (v[i][1] == '-')
                {

                    FRONT();
                }
                else
                {
                    FRONT();
                    copy();
                    FRONT();
                    copy();
                    FRONT();
                }
            }
            if (v[i][0] == 'B')
            {

                copy();
                if (v[i][1] == '+')
                {

                    BACK();
                }
                else
                {
                    BACK();
                    copy();
                    BACK();
                    copy();
                    BACK();
                }
            }

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cout << map[0][i][j];
                }
                cout << '\n';
            }
        }
    }

    return 0;
}