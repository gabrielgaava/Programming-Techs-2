# Projeto 1 - Manipulação de Arquivos
### Gabriel Henrique da Silva Gava  
  
//////////////////////////////////////////////////////////////////////////

## **1. Sobre o projeto:**
O enunciado deste projeto consta em ```Statement.md```

Todos os arquivos se encontram dentro da pasta ```Files```. O resultado final gerado pelo programa é salvo no arquivo ```senocosseno.txt```. Uma copia do resultado obtido por min, na ultima execução, está salvo em ```resultados.txt```

A aproximação de graus e do cosseno são feitos sempre em relação ao grau inferior. Por exemplo, se eu sei que o seno de leitura atual está no intervalo entre 25 graus e 26 graus, farei a regra de três utilizando 25 graus.

## **2. Compilação:**
Para compilar o programa basta exucutar o seguinte comando no terminal nesta pasta:

```
gcc main.c -o main -lm
```

E para executar
```
./main
```

## **3. Estrutura do resultado:**
O resultado obtido pelo programa é retornado da seguinte forma:
```
Graus - Radianos - Seno - Cosseno  
grau1 - rad1 - sin1 - cos1
grau2 - rad2 - sin2 - cos2

.
.
.

```
