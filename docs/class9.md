# Aula 9 - 19/11/2020

## **1. Strings e Busca**
O que fazer para armazenar dad

## **2. Knuth-Morris-Pratt (KMOP)**
rocura a ocorrência de uma "palavra" W dentro de um "texto" S empregando a simples técnica de que quando aparece uma diferença, a palavra tem em si a informação necessária para determinar onde começar a próxima comparação.

Exemplo:
S = "abcdabd"
0 - sempre começa com 0
00 - na substring "ab" não há prefixo e sufixo próprios iguais
000 - idem para "abc"
0000 - idem para "abcd"
00001 - na substring "abcda", o prefixo próprio "a", que inicia a substring, é igual ao sufixo próprio "a", que termina a substring
000012 - na substring "abcdab", o prefixo próprio "ab", que inicia a substring, é igual ao sufixo próprio "ab", que termina a substring
0000120 - na substring "abcdabd" não há prefixo e sufixo próprios iguais


## **2. Boyer-Moore (BM)**
O algoritmo pré-processa a string sendo procurada (o padrão), mas não a string em que é feito a busca (o texto). É ainda bem aproveitado para aplicações em que o padrão é muito menor do que o texto ou onde persiste por multiplas buscas. O algoritmo BM (Boyer-Moore) usa informação reunida durante o passo de pré-processamento para pular seções do texto, resultando em um constante fator baixo do que muitos outros algoritmos. Em geral, o algoritmo roda mais rápido de acordo com o tamanho do padrão aumenta. As características chaves do algoritmo são combinar na cauda do padrão ao invés da cabeça, e pular pelo texto em deslocamentos de multiplos caracteres ao invés de procurar cada caractere no texto.

