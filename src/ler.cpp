#include "ler.hpp"

void read()
{
    vector<vector<int>> mat;
    string filename("dataset/input.data");
    ifstream input_file(filename, ios::in);
    string line;
    vector<int> n;
    int tam;
    bool decisao = false;
    int count = 0, soma;
    srand(time(NULL));
    int vida = 10, mochila = 0, contCasasPercorridas = 0, contPerigos = 0, contCasasInexploradas = 0, maisVida = 0, numMat;

    if (!input_file.is_open())
    {
        cout << "Nao foi possivel abrir o arquivo"
             << filename << " " << endl;
    }

    string num;
    int cont = 0;
    while (!input_file.eof())
    {
        while (getline(input_file, line, '\n'))
        {
            istringstream ln(line);

            if (cont == 0)
            {

                cont++;
                while (ln >> num)
                {
                    n.push_back(atoi(num.c_str()));
                }
                tam = n[0];
                numMat = n[2];
                n.clear();
                continue;
            }
            else if (line.size() > 1)
            {
                decisao = false;
                while (ln >> num)
                {
                    if (num == "#")
                    {
                        num = "-1";
                    }
                    else if (num == "*")
                    {
                        num = "-2";
                    }

                    n.push_back(atoi(num.c_str()));
                }
                mat.push_back(n);
                line.clear();
                n.clear();
            }
            else
            {
                decisao = true;
                cout << endl;
                criarMap(mat, count);
                imprimindo(mat);
                count++;
                cout << endl;
                mat.clear();
            }
        }
    }
    if (!(decisao))
    {
        criarMap(mat, count);
        imprimindo(mat);
        mat.clear();
    }
    input_file.close();
    soma = tam * tam * numMat;
    cout << soma << endl;
    readOneMap(mat, tam, numMat, soma);
    casasInexploradas();
}

void casasInexploradas()
{

    vector<vector<int>> mat;
    vector<vector<int>> mat2;
    string filename("dataset/input.data");
    ifstream input_file(filename, ios::in);
    string line, arq, loc;
    vector<int> n;
    bool decisao = false;
    int count = 0, casasInexploradas = 0;

    if (!input_file.is_open())
    {
        cout << "Nao foi possivel abrir o arquivo"
             << filename << " " << endl;
    }

    string num;
    int cont = 0;
    while (!input_file.eof())
    {

        while (getline(input_file, line, '\n'))
        {
            istringstream ln(line);
            if (cont == 0)
            {
                cont++;
                continue;
            }
            else if (line.size() > 1)
            {
                decisao = false;
                while (ln >> num)
                {
                    if (num == "#")
                    {
                        num = "-1";
                    }
                    else if (num == "*")
                    {
                        num = "-2";
                    }

                    n.push_back(atoi(num.c_str()));
                }
                mat.push_back(n);
                line.clear();
                n.clear();
            }
            else
            {
                lerComparacao(mat, &casasInexploradas,count);
                count++;
                mat.clear();
            }
        }
    }
    if (!(decisao))
    {
        lerComparacao(mat, &casasInexploradas,count);
    }
    input_file.close();

    cout << "Casas inexploradas: " << casasInexploradas<<endl;
}

void lerComparacao(vector<vector<int>> mat, int *casasInexploradas, int count)
{
    string arq, loc, line, num;
    vector<int> n;
    vector<vector<int>> mat2;

    arq = "input" + to_string(count) + ".data";
    loc = "dataset/" + arq;
    ifstream f(loc, ios::in);
    if (!f.is_open())
    {
        cout << "Nao foi possivel abrir o arquivo"
             << loc << " " << endl;
    }

    while (!f.eof())
    {
        while (getline(f, line, '\n'))
        {
            istringstream ln(line);

            if (line.size() > 1)
            {
                while (ln >> num)
                {
                    n.push_back(atoi(num.c_str()));
                }
                mat2.push_back(n);
                line.clear();
                n.clear();
            }
            else
            {
                for (int i = 0; i < (int)mat.size(); i++)
                {
                    for (int j = 0; j < (int)mat[i].size(); j++)
                    {
                        if (mat[i][j] == mat2[i][j] && mat[i][j] != -1)
                        {
                            *casasInexploradas = *casasInexploradas + 1;
                        }
                    }
                }
                mat2.clear();
            }
        }
    }
    f.close();
}