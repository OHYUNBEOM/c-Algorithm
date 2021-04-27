#include <iostream>
using namespace std;

void floydD(int W[4][4], int D[4][4]);
void floydP(int W[4][4], int P[4][4]);
void print(int d[4][4]);

static int P[4][4] = { 0 };//전역으로 선언해둬야 path 함수에서 P 를 뽑아 쓸 수 있음


void path(int start, int end);

int main()
{
    int W[4][4] = {
       { 0, 10, 4, 6 },
       { 3, 0, 12, 7 },
       { 9, 2, 0, 8 },
       { 11, 999, 4, 0 }
    };

    int D[4][4];


    cout << "----D----\n<Start>" << endl;
    print(W);
    floydD(W, D);

    cout << "\n\n----P----\n<Start>" << endl;
    print(P);
    floydP(W, P);


    cout << "v4에서 v1 까지 최단경로 : \n";
    cout << "v4->";
    path(3, 0);
    cout << "v1";

}

void floydD(int W[4][4], int D[4][4])
{
    int i, j, k;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            D[i][j] = W[i][j];
        }
    }

    for (k = 0; k < 4; k++)
    {
        cout << "< " << k + 1 << " >" << endl;
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                if (D[i][k] + D[k][j] < D[i][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
        print(D);
    }
}

void floydP(int D[4][4], int P[4][4])
{
    int i, j, k;

    for (k = 0; k < 4; k++)
    {
        cout << "< " << k + 1 << " >" << endl;
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                if (D[i][k] + D[k][j] < D[i][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = k + 1;
                }
            }
        }
        print(P);
    }
}


void print(int d[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << d[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "\n";
}

void path(int start, int end)
{
    if (P[start][end] != 0)
    {
        path(start, P[start][end] - 1);//실제 사용자가 보고 , 생각하는 (1,3) 좌표는 배열은 0부터 시작이기에 실제로는 (0,2) 좌표 // 따라서 -1
        cout << "v" << P[start][end] << "->";
        path(P[start][end] - 1, end);
    }
}