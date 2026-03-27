#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SEP ';'

int lerop() {
    char buffer[100];
    int op;

    printf("Escolha a opcao: ");
    if (!fgets(buffer, sizeof(buffer), stdin))
    return -1;

    if (sscanf(buffer, "%d", &op)!=1)
    return -1;
    return op;
}

//função para adicionar nome
char* addNOME(char *lista) {
    char nome[100];
    printf("Digite o nome: ");
    scanf(" %[^\n]", nome);
     int tamA=lista ? strlen(lista):0;
     int tamN=strlen(nome);

     //tamanho atual + nome + separador +\0
     char *novalista=realloc(lista, tamA+tamN+2);
     if (!novalista) {
        printf("Erro de memoria.\n");
        free(lista);
        return NULL;
     }
     //separador para nomes que não são os primeiros
     if (tamA>0) {
        novalista[tamA]=SEP;
        strcpy(novalista+tamA+1, nome);
     } else {
        strcpy(novalista, nome);
     }
     return novalista;
     }
     //função para listar os nomes
     void listarnomes(char *lista) {
        if (!lista||strlen(lista)==0) {
            printf("Lista vazia.\n");
            return;
        }
        char *copia=strdup(lista);
        char *token=strtok(copia, ";");

        printf("Nomes:\n");
        while (token) {
            printf("- %s\n", token);
            token=strtok(NULL, ";");
        }
        free(copia);
     }
     //função para remover nomes da lista
     char* remover(char *lista) {
        if (!lista||strlen(lista)==0) {
            printf("Lista vazia.\n");
            return lista;
        }
        char nome[100];
        printf("Digite o nome a ser removido: ");
        scanf(" %[^\n]", nome);

        char *novalista=malloc(1);
        novalista[0]='\0';

        char *copia=strdup(lista);
        char *token=strtok(copia, ";");

        int primeiro=1;
        while (token) {
            if (strcmp(token, nome)!=0) {
                int tamA=strlen(novalista);
                int tamN=strlen(token);

                novalista=realloc(novalista, tamA+tamN+2);

                if (!primeiro) {
                    novalista[tamA]=SEP;
                    strcpy(novalista+tamA+1, token);
                } else {
                    strcpy(novalista, token);
                    primeiro=0;
                }
                }
                token=strtok(NULL, ";");
            }
            free(copia);
            free(lista);

            return novalista;
        }
        //main (menu)

        int main() {
            char *lista=NULL;
            int op;

            do {
                printf("\n---MENU---\n");
                printf("1) Adicionar nome\n");
                printf("2) Remover nome\n");
                printf("3) Exibir lista\n");
                printf("4) Sair\n");
                printf("Escolha a opcao: ");
                op=lerop();

                switch(op) {
                    case 1:
                        lista=addNOME(lista);
                        break;
                    case 2:
                        lista=remover(lista);
                        break;
                    case 3:
                        listarnomes(lista);
                        break;
                    case 4:
                        printf("Tchau!!\n");
                        break;
                    default:
                        printf("Opcao invalida.\n");
                }
            } while (op!=4);
            free(lista);
            system("pause");
            return 0;
        }