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

    map[3][2][0] = temp[0][0][0];
    map[3][1][0] = temp[0][1][0];
    map[3][0][0] = temp[0][2][0];

    map[1][2][0] = temp[3][2][0];
    map[1][1][0] = temp[3][1][0];
    map[1][0][0] = temp[3][0][0];

    map[2][0][0] = temp[1][2][0];
    map[2][1][0] = temp[1][1][0];
    map[2][2][0] = temp[1][0][0];

    map[0][0][0] = temp[2][0][0];
    map[0][1][0] = temp[2][1][0];
    map[0][2][0] = temp[2][2][0];
}
void RIGHT()
{

    int right[] = {0, 2, 1, 3};

    map[3][2][2] = temp[0][0][2];
    map[3][1][2] = temp[0][1][2];
    map[3][0][2] = temp[0][2][2];

    map[1][2][2] = temp[3][2][2];
    map[1][1][2] = temp[3][1][2];
    map[1][0][2] = temp[3][0][2];

    map[2][0][2] = temp[1][2][2];
    map[2][1][2] = temp[1][1][2];
    map[2][2][2] = temp[1][0][2];

    map[0][0][2] = temp[2][0][2];
    map[0][1][2] = temp[2][1][2];
    map[0][2][2] = temp[2][2][2];
}

void UP()
{

    int right[] = {0, 2, 1, 3};

    map[5][0][2] = temp[2][0][2];
    map[5][0][1] = temp[2][0][1];
    map[5][0][0] = temp[2][0][0];

    map[3][0][0] = temp[5][0][2];
    map[3][0][1] = temp[5][0][1];
    map[3][0][2] = temp[5][0][0];

    map[4][0][2] = temp[3][0][0];
    map[4][0][1] = temp[3][0][1];
    map[4][0][0] = temp[3][0][2];

    map[2][0][2] = temp[4][0][2];
    map[2][0][1] = temp[4][0][1];
    map[2][0][0] = temp[4][0][0];
}

void DOWN()
{

    int right[] = {0, 2, 1, 3};

    map[5][2][2] = temp[2][2][2];
    map[5][2][1] = temp[2][2][1];
    map[5][2][0] = temp[2][2][0];

    map[3][2][0] = temp[5][2][2];
    map[3][2][1] = temp[5][2][1];
    map[3][2][2] = temp[5][2][0];

    map[4][2][2] = temp[3][2][0];
    map[4][2][1] = temp[3][2][1];
    map[4][2][0] = temp[3][2][2];

    map[2][2][2] = temp[4][2][2];
    map[2][2][1] = temp[4][2][1];
    map[2][2][0] = temp[4][2][0];
}

void FRONT()
{

    map[4][0][2] = temp[0][2][2];
    map[4][1][2] = temp[0][2][1];
    map[4][2][2] = temp[0][2][0];

    map[1][2][0] = temp[4][0][2];
    map[1][2][1] = temp[4][1][2];
    map[1][2][2] = temp[4][2][2];

    map[5][2][0] = temp[1][2][0];
    map[5][1][0] = temp[1][2][1];
    map[5][0][0] = temp[1][2][2];

    map[0][2][2] = temp[5][2][0];
    map[0][2][1] = temp[5][1][0];
    map[0][2][0] = temp[5][0][0];
}
void BACK()
{

    map[4][0][0] = temp[0][0][2];
    map[4][1][0] = temp[0][0][1];
    map[4][2][0] = temp[0][0][0];

    map[1][0][0] = temp[4][0][0];
    map[1][0][1] = temp[4][1][0];
    map[1][0][2] = temp[4][2][0];

    map[5][2][2] = temp[1][0][0];
    map[5][1][2] = temp[1][0][1];
    map[5][0][2] = temp[1][0][2];

    map[0][0][2] = temp[5][2][2];
    map[0][0][1] = temp[5][1][2];
    map[0][0][0] = temp[5][0][2];
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
                if (v[i][1] == '-')
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
                if (v[i][1] == '+')
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

            // for (int m = 0; m < 6; m++)
            // {

            //     for (int i = 0; i < 3; i++)
            //     {
            //         for (int j = 0; j < 3; j++)
            //         {
            //             cout << map[m][i][j];
            //         }
            //         cout << '\n';
            //     }
            // }
            // cout <<"pass"<<'\n';
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

    return 0;
}