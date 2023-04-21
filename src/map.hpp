#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <time.h>

using namespace std;

void readOneMap(vector<vector<int>> mat, int tam, int numMat, int soma);

void imprimindo(vector<vector<int>> mat);

void movimento(vector<vector<int>> mat, int linha, int coluna, int tam, int *vida,
               int *contCasasPercorridas, int *contPerigos, int *maisVida, int *count, int *contZero, int soma, int *itensConsumidos,bool *fin,
               int fim_i, int fim_j);

void configDeCaminho(int *aleatorio, int i, int j, int tam);

void selecionandoCaminho(int aleatorio, int *i, int *j, vector<vector<int>> mat);

void altVida(int *maisVida, int *vida);

void criarMap(vector<vector<int>> mat, int count);

#endif