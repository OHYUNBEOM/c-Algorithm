#include <iostream>
using namespace std;

void floydD(int W[6][6], int D[6][6]);
void floydP(int W[6][6], int P[6][6]);
void print(int d[6][6]);

static int P[6][6] = { 0 };//전역으로 선언해둬야 path 함수에서 P 를 뽑아 쓸 수 있음


void path(int start, int end);

int main()
{
    int W[6][6] = {
       { 0, 7, 999, 11, 999, 999 },
       { 3, 0, 999, 999, 17, 999 },
       { 999, 6, 0, 999, 999, 999 },
       { 999, 999, 999, 0, 9, 999 },
       { 999, 5, 15, 16, 0, 2 },
       { 999, 999, 11, 999, 8, 0 }
    };

    int D[6][6];


    cout << "----D----\n<Start>" << endl;
    print(W);
    floydD(W, D);

    cout << "\n\n----P----\n<Start>" << endl;
    print(P);
    floydP(W, P);


    cout << "v1에서 v3 까지 최단경로 : \n";
    cout << "v1->";
    path(0, 2);
    cout << "v3";

}

void floydD(int W[6][6], int D[6][6])
{
    int i, j, k;

    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++)
        {
            D[i][j] = W[i][j];
        }
    }

    for (k = 0; k < 6; k++)
    {
        cout << "< " << k + 1 << " >" << endl;
        for (i = 0; i < 6; i++)
        {
            for (j = 0; j < 6; j++)
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

void floydP(int D[6][6], int P[6][6])
{
    int i, j, k;

    for (k = 0; k < 6; k++)
    {
        cout << "< " << k + 1 << " >" << endl;
        for (i = 0; i < 6; i++)
        {
            for (j = 0; j < 6; j++)
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


void print(int d[6][6])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
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
        path(start, P[start][end]-1);//실제 사용자가 보고 , 생각하는 (1,3) 좌표는 배열은 0부터 시작이기에 실제로는 (0,2) 좌표 // 따라서 -1
        cout << "v" << P[start][end] << "->";
        path(P[start][end]-1, end);
    }
}