# LabirintoRecorrente: Implementação em C++

<div style="display: inline-block;">
<img align="center" height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/> 
<img align="center" height="20px" width="80px" src="https://img.shields.io/badge/Made%20for-VSCode-1f425f.svg"/> 
</a> 
</div>

# Problema Proposto
<p align="justify">
  Utilizando o processo de caminhamento aleatorio, nesse projeto o objetivo é caminhar por matrizes NxN, passadas como entrada, iniciando pela posição digitada pelo usuario. O caminho passado será o que for gerado aleatoriamente, sendo possivel caminhar a direita, a esquerda, baixo, cima, diagonais para esquerda e direita para baixo e para cima, apresentando tambem a possibilidade de andar entre as matrizes. <br>
  Através dessas regras, o objetivo do programa apresentado e consumir o maximo de itens possiveis ate chegar a zerar as possibilidades ou morrer tentando.
</p>

# Lógica

Para o caso em que o arquivo de entrada tivesse apenas um '\n' ao final, a leitura do arquivo considerava essa última linha já como o final do arquivo, o que interrompia o loop de leitura e não permitia que a última matriz fosse percorrida(não entrava no else). Para resolver este problema, foi criado um booleano `decisao` que é responsável por tomar a decisão se a última matriz salva já foi percorrida ou não. Este booleano é iniciado com false, e recebe falso toda vez que uma linha é tokenizada. O true só é atribuído à variável no else, que é onde as matrizes são percorridas.<br>
Então, por meio de um if após o loop de leitura, no caso onde o input do programa tivesse dois '\n', a variável booleana iria impedir a matriz de ser caminhada duas vezes, e no caso de apenas um '/n', ela seria percorrida dentro do if, finalizando o percorrimento de todas as matrizes corretamente.<br>

 # Resultados 
   Considerando a lógica e a descrição do problema acima, os resultados esperados durante a leitura do arquivo com 4 matrizes 6x6:<br><br>
   <div align="center"><img width="300px" src="imgs/teste1.jpeg" /> <br></div>
   
 > OBS: O resultado apresentado é de apenas uma matriz 6x6.
   Todas as matrizes apresentaram o mesmo padrão de resultado, ao finalizar os processos, irá retornar as casas percorridas, a soma dos itens consumidos, a soma da quantidade de perigos enfrentados e as casas inexploradas.<br>
   
 # Conclusao
 
 # Bibliotecas 
<p>Para o funcionamento do programa, é necessário incluir as seguintes bibliotecas: 
<ul>
    <li><code>#include 'iostream'</code></li>
    <li><code>#include 'fstream'</code></li>
    <li><code>#include 'vector'</code></li>
    <li><code>#include 'string'</code></li>
    <li><code>#include 'sstream'</code></li>
    <li><code>#include 'iterator'</code></li>
    <li><code>#include 'algorithm'</code></li>
    <li><code>#include 'time.h'</code></li>
</ul>

# Compilação e Execução

Esse pequeno exemplo possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o g++, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |


# Contatos

<div style="display: inline-block;">
<a href="https://t.me/felipewom">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
</a>

<a href="https://www.linkedin.com/in/felipe-werneck-93520a209">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white"/>
</a>

</div>

<p> </p>
