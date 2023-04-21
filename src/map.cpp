#include "map.hpp"

void readOneMap(vector<vector<int>> mat, int tam, int numMat, int soma)
{
    string arq, loc;
    string num, line;
    vector<int> n;
    bool fin=false,aux=true;
    int vida = 10, contCasasPercorridas = 0, contPerigos = 0, maisVida = 0, count = 0, i, j, contZero = 0, itensConsumidos = 0;
    int fim_i,fim_j;
    cout << "Bem vindo ao game LABIRINTO RECORRENTE!!!" << endl;
    cout << "Teste sua sorte digitando a posicao que ira comecar!" << endl;
    cin >> i;
    cin >> j;
    while (count < numMat)
    {
        cout << "Mapa atual: " << count << endl;
        arq = "input" + to_string(count) + ".data";
        loc = "dataset/" + arq;
        ifstream input_file(loc, ios::in);

        while (!input_file.eof())
        {
            while (getline(input_file, line, '\n'))
            {
                istringstream ln(line);

                if (line.size() > 1)
                {
                    while (ln >> num)
                    {
                        n.push_back(atoi(num.c_str()));
                    }
                    mat.push_back(n);
                    line.clear();
                    n.clear();
                }
                else
                {
                    cout << endl;
                    
                    while (mat[i][j] == -1)
                    {
                        i = rand() % tam;
                        j = rand() % tam;
                    }
                    if (mat[i][j]!= -1 && aux==true)
                    {
                        fim_i=i;
                        fim_j=j;
                        aux=false;
                    }
                    imprimindo(mat);
                    movimento(mat, i, j, tam, &vida, &contCasasPercorridas, &contPerigos, &maisVida, &count, &contZero, soma, &itensConsumidos,&fin,fim_i,fim_j);
                    cout<<fin<<endl;
                    count++;
                    
                    if (count == numMat && vida != 0)
                    {
                        cout<<"Voltando ao mapa 0! Nivel de dificuldade aumentado! "<<endl;
                        count = 0;
                    }
                                        
                    cout << endl;

                    mat.clear();
                }
            }
        }
        input_file.close();
        if (fin==true)
        {
            break;
        }
        
    }

    cout<<"Casas percorridos pelo labirinto: "<<contCasasPercorridas<<endl;
    cout<<"Soma dos itens consumidos pelo caminho: "<<itensConsumidos<<endl;
    cout<<"Perigos enfrentados pelo caminho: "<<contPerigos<<endl;
}

void criarMap(vector<vector<int>> mat, int count)
{

    string arq = "input" + to_string(count) + ".data";
    string loc = "dataset/" + arq;
    ofstream f(loc);

    for (int i = 0; i < (int)mat.size(); i++)
    {
        for (int j = 0; j < (int)mat[i].size(); j++)
        {
            f << mat[i][j] << " ";
        }
        f << endl;
    }
    f << ".";//ponto para que seja possivel salvar a ultima linha da matriz
}

void imprimindo(vector<vector<int>> mat)
{

    for (int i = 0; i < (int)mat.size(); i++)
    {
        for (int j = 0; j < (int)mat[i].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void movimento(vector<vector<int>> mat, int linha, int coluna, int tam, int *vida,
               int *contCasasPercorridas, int *contPerigos, int *maisVida, int *count, int *contZero, int soma, int *itensConsumidos,bool *fin,
               int fim_i, int fim_j)
{

    int aleatorio, i, j;
    i = linha;
    j = coluna;
    
    cout << "CAMINHO PERCORRIDO" << endl;
    while (*vida != 0)
    {
        *contCasasPercorridas = *contCasasPercorridas + 1;
        if (*contZero>=soma && *count==0 && i==fim_i && j==fim_j)
        {
            cout<<"Posicao atual:"<<i<<" "<<j<<" || Posicao inicial:"<<fim_i<<" "<<fim_j<<endl;
            cout << "Vida: " << *vida << endl;
            *fin=true;
            return;
        }
        configDeCaminho(&aleatorio, i, j, tam);
        if (*vida == 0)
        {
            break;
        }

        cout << i << " " << j << " Valor: " << mat[i][j] << "." << endl;
        if (mat[i][j] > 0)
        {
            *maisVida = *maisVida + 1;
            altVida(maisVida, vida);
            mat[i][j] = mat[i][j] - 1;
            *contZero = 0;
            *itensConsumidos = *itensConsumidos + 1;
        }
        else if (mat[i][j] <= -2)
        {
            *vida = *vida - 1;
            mat[i][j] = mat[i][j] - 1;
            *contPerigos = *contPerigos + 1;
        }
        else if (mat[i][j] == 0)
        {
            *contZero = *contZero + 1;
        }
        cout << "Vida: " << *vida << endl;
        cout << "Mais Vida: " << *maisVida << endl;
        if (aleatorio == 10)
        {
            criarMap(mat, *count);
            return;
        }
        selecionandoCaminho(aleatorio, &i, &j, mat);
    }
    cout << endl;
    cout << "Vida atual: " << *vida << endl;

}

void selecionandoCaminho(int aleatorio, int *i, int *j, vector<vector<int>> mat)
{
    switch (aleatorio)
    {
    case 0: // diagonal esquerda

        if (mat[*i - 1][*j - 1] != -1)
        {
            *i = *i - 1;
            *j = *j - 1;
        }

        break;
    case 1: // cima
        if (mat[*i - 1][*j] != -1)
        {
            *i = *i - 1;
        }

        break;
    case 2: // diagonal direita
        if (mat[*i - 1][*j + 1] != -1)
        {
            *i = *i - 1;
            *j = *j + 1;
        }

        break;
    case 3: // direita
        if (mat[*i][*j + 1] != -1)
        {
            *j = *j + 1;
        }

        break;
    case 4: // diagonal direita baixo
        if (mat[*i + 1][*j + 1] != -1)
        {
            *i = *i + 1;
            *j = *j + 1;
        }

        break;
    case 5: // baixo
        if (mat[*i + 1][*j] != -1)
        {
            *i = *i + 1;
        }

        break;
    case 6: // diagonal esquerda baixo
        if (mat[*i + 1][*j - 1] != -1)
        {
            *i = *i + 1;
            *j = *j - 1;
        }
        break;
    case 7: // esquerda
        if (mat[*i][*j - 1] != -1)
        {
            *j = *j - 1;
        }

        break;
    default:
        break;
    }
}

void configDeCaminho(int *aleatorio, int i, int j, int tam)
{

    if (i == 0 && j == 0)
    {
        do
        {
            (*aleatorio) = rand() % 7;
        } while ((*aleatorio) < 3 || (*aleatorio) > 5);
    }
    else if (i == tam - 1 && j == 0)
    {

        do
        {
            (*aleatorio) = 1 + rand() % 7;
        } while ((*aleatorio) > 3);
    }
    else if (j == tam - 1)
    {

        (*aleatorio) = 10;
        return;
    }
    else if (i == tam - 1)
    {

        do
        {
            (*aleatorio) = rand() % 7;
        } while ((*aleatorio) > 3 && (*aleatorio) < 7);
    }
    else if (j == 0)
    {
        do
        {
            (*aleatorio) = 1 + rand() % 7;
        } while ((*aleatorio) > 5);
    }
    else if (i == 0)
    {
        do
        {
            (*aleatorio) = rand() % 7;
        } while ((*aleatorio) < 3);
    }
    else
    {
        (*aleatorio) = rand() % 7;
    }
}

void altVida(int *maisVida, int *vida)
{
    if (*maisVida == 3 && *vida < 10)
    {
        *vida = *vida + 1;
        *maisVida = 0;
    }
    else if (*vida == 10 && *maisVida == 3)
    {
        *maisVida = 0;
    }
}
