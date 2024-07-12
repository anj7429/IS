#include <iostream>
#include <ctime>
using namespace std;
class ErrorCorrection
{
public:
    int **mat, size;
    void input();
    void parity_check();
    void generate();
};
void ErrorCorrection::input()
{
    cout << "Enter the size of the data : ";
    cin >> size;
    mat = new int *[size];
    cout << "Enter the data :";
    for (int i = 0; i < size; i++)
    {
        mat[i] = new int[size];
        for (int j = 0; j < size; j++)
        {
            cin >> mat[i][j];
        }
    }

    cout << "Data is :\n";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
void ErrorCorrection::parity_check()
{

    int c;
    int par[size];
    // row-wise
    for (int i = 0; i < size; i++)
    {
        c = 0;
        for (int j = 0; j < size; j++)
        {
            if (mat[i][j] == 1)
            {
                c += 1;
            }
            else
                continue;
        }
        if (c % 2 == 0)
        {
            par[i] = 0;
        }
        else
        {
            par[i] = 1;
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << par[i] << " ";
    }
    // column-wise
    int co, pari[size];
    for (int i = 0; i < size; i++)
    {
        co = 0;
        for (int j = 0; j < size; j++)
        {
            if (mat[j][i] == 1)
            {
                co += 1;
            }
            else
                continue;
        }
        if (co % 2 == 0)
        {
            pari[i] = 0;
        }
        else
        {
            pari[i] = 1;
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << pari[i] << " ";
    }
    cout << endl;
    int newarr[2 * size];
    for (int i = 0; i < size; i++)
    {
        newarr[i] = par[i];
    }
    for (int i = 0; i < size; i++)
    {
        newarr[size + i] = pari[i];
    }
    cout << "Parity array : ";
    for (int i = 0; i < (2 * size); i++)
    {
        cout << newarr[i] << " ";
    }
    int c1 = 2 * size;
    int r_index = rand() % c1;
    int rec_arr[2 * size];
    for (int i = 0; i < 2 * size; i++)
    {
        rec_arr[i] = newarr[i];
    }
    rec_arr[r_index] = rand() % 2;
    for (int i = 0; i < (2 * size); i++)
    {
        cout << rec_arr[i] << " ";
    }
    bool equal = true;
    for (int i = 0; i < 2 * size; i++)
    {
        if (newarr[i] == rec_arr[i])
            equal;
        else
        {
            equal = false;
        }
    }
    if (equal)
    {
        cout << "Message sent successfully !!" << endl;
    }
    else
    {
        cout << "Message not sent successfully !!" << endl;
    }
}
int main()
{
    ErrorCorrection obj;
    obj.input();
    cout << " ----------------Sender Side ------------------ " << endl;
    obj.parity_check();
    cout << " -----------------Receiver Side----------------- " << endl;

    return 0;
}