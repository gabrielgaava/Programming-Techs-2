# Aula 2 - 06/10/2020

## **1. Arquivos**
Arquivos são estruturas para armazenamento de dados de forma não volátil, em dispositivos secundarios.  

Necessario criar estruturas para manipulart arquivos trazidos para a memoria  

**Operações sobre o arquivo:** Leitura, Escrita e Adição.  

Abertura de um arquivo envolve várias ações do Sistema Operacional.  

**Abrir um arquivo** = Trazer para memoria  
**Fechar um arquivo** = destroi registro na memoria

## **2. Arquivos em C**
Existe um marcador (ponteiro) chamado FILE para representação de arquivos em C.

```c
// Declaração de Ponteiro para arquivos
FILE * file1, file2;  
```

Um ponteiro representa uma posição na memoria. Mas aqui, neste caso, representa a cabeçã de leitura/escrita do arquivo. 

### **2.1. Abertura de arquivos**
```c
file1 = fopen("arquivo.txt", "r");   // Leitura  
file2 = fopen("arquivo.txt", "w");   // Escrita  
file3 = fopen("arquivo.txt", "a");   // Anexo ao Final  
file3 = fopen("arquivo.txt", "r+");  // Leitura e Escrita  
file4 = fopen("arquivo.txt", "rb");  // Leitura Binária
```

### **2.2. Escrita em arquivos**
```c
fprintf(file1, "String de texto", vars);  
fputs(file1, "String de texto");
```

### **2.2. Leitura em arquivos**
```c
fsacnf(file1, "%d", &var);
```


### **2.4. Funções adicionais**
```c
// retorna 1 se chegou ao final do arquivo
feof(file1) 

 // Acesso não sequencial de conteudo
fseek(file1, count, org)

// Retorna a posição atual do ponteiro
ftell(file1) 
```


