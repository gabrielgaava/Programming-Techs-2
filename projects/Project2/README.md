# Projeto 2 - Uso simples de funções

Escreva um programa que leia um conjunto de N pares de coordenadas de um arquivo de entrada **"input.txt"**,  sendo N o primeiro valor contido neste arquivo, e determine o ponto mais central dos pares de coordenadas lidos. Use uma função para calcular distâncias entre pontos e uma função para determinar o "centro" das coordenadas.

Exemplo de entrada:
```text
3
4.5 6.3
0.0 0.0
2.4 3.7
```

Saída para este caso de teste
```text
Ponto (2.4, 3.7)
```

M = m1 + m2 + m3 = 3

Xcm = 1/M * (4.5) + (0) + (2.4) 
Xcm = 1/3 * (6.9) = 2.3

Ycm = 1/M * (6.3) + (0) + (3.7)
Ycm = 1/3 * (10) = 3.33

Centro = (2.3, 3.33)
Centro do Aleardo = (2.4, 3.7)