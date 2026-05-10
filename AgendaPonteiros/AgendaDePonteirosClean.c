// Nome: Gabriela de Carvalho Bruno
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_TOTAL 5000

//offsets fixos
#define OFFSET_QTD_PESSOAS 0
#define OFFSET_OPCAO sizeof(int)
#define OFFSET_I (sizeof(int)*2)
#define OFFSET_LIVRE (sizeof(int)*3)
#define OFFSET_CAMINHO (sizeof(int)*4)

#define TAM_SCANF 100

//buffer auxiliar
#define OFFSET_SCANF (OFFSET_CAMINHO + sizeof(int))

#define OFFSET_DADOS (OFFSET_SCANF + TAM_SCANF)

//main
int main() {

    void *pBuffer = malloc(BUFFER_TOTAL);

    *(int*)((char*)pBuffer + OFFSET_QTD_PESSOAS) = 0;
    *(int*)((char*)pBuffer + OFFSET_LIVRE) = OFFSET_DADOS;

    while(1) {

        printf("\n_____________________________________");
        printf("\n1. Adicionar");
        printf("\n2. Remover");
        printf("\n3. Buscar");
        printf("\n4. Listar");
        printf("\n5. Sair");
        printf("\nSelecione uma opcao: ");

        scanf("%d", (int*)((char*)pBuffer + OFFSET_OPCAO));

        //adicionar
        if (*(int*)((char*)pBuffer + OFFSET_OPCAO) == 1) {
            //nome
            printf("Nome: ");
            scanf(" %99[^\n]", (char*)pBuffer + OFFSET_SCANF);

            memcpy(
                (char*)pBuffer + *(int*)((char*)pBuffer + OFFSET_LIVRE),
                (char*)pBuffer + OFFSET_SCANF,
                strlen((char*)pBuffer + OFFSET_SCANF) + 1);

            *(int*)((char*)pBuffer + OFFSET_LIVRE) += strlen((char*)pBuffer + OFFSET_SCANF) + 1;

            //idade
            printf("Idade: ");
            while (scanf("%d",(int*)((char*)pBuffer + *(int*)((char*)pBuffer + OFFSET_LIVRE))) != 1) {
                printf("Idade invalida. Digite novamente: ");
                scanf("%*[^\n]");
                scanf("%*c");
            }
            *(int*)((char*)pBuffer + OFFSET_LIVRE) += sizeof(int);

            //email
            printf("Email: ");
            scanf(" %99[^\n]", (char*)pBuffer + OFFSET_SCANF);

            memcpy(
                (char*)pBuffer + *(int*)((char*)pBuffer + OFFSET_LIVRE),
                (char*)pBuffer + OFFSET_SCANF,
                strlen((char*)pBuffer + OFFSET_SCANF) + 1);

            *(int*)((char*)pBuffer + OFFSET_LIVRE) += strlen((char*)pBuffer + OFFSET_SCANF) + 1;

            // incrementa quantidade
            (*(int*)((char*)pBuffer + OFFSET_QTD_PESSOAS))++;

            printf("\nPessoa adicionada.\n");
        }

        //remove
        else if (*(int*)((char*)pBuffer + OFFSET_OPCAO) == 2) {
            printf("Nome para remover: ");
            scanf(" %99[^\n]", (char*)pBuffer + OFFSET_SCANF);

            //i = 0
            *(int*)((char*)pBuffer + OFFSET_I) = 0;

            //começa do início dos dados
            *(int*)((char*)pBuffer + OFFSET_CAMINHO) = OFFSET_DADOS;

            while (*(int*)((char*)pBuffer + OFFSET_I) < *(int*)((char*)pBuffer + OFFSET_QTD_PESSOAS)) {
                //compara o nome digitado com o nome salvo
                if (strcmp((char*)pBuffer + OFFSET_SCANF,(char*)pBuffer + *(int*)((char*)pBuffer + OFFSET_CAMINHO)) == 0) {

                    // tamanho do nome
                    *(int*)((char*)pBuffer + OFFSET_OPCAO) = strlen((char*)pBuffer + *(int*)((char*)pBuffer + OFFSET_CAMINHO)) + 1;

                    // soma idade
                    *(int*)((char*)pBuffer + OFFSET_OPCAO) += sizeof(int);

                    // soma email
                    *(int*)((char*)pBuffer + OFFSET_OPCAO) +=strlen((char*)pBuffer + *(int*)((char*)pBuffer + OFFSET_CAMINHO) + strlen((char*)pBuffer + *(int*)((char*)pBuffer + OFFSET_CAMINHO)) + 1 + sizeof(int)) + 1;

                    //move memoria pra fechar o gap
                    memmove((char*)pBuffer + *(int*)((char*)pBuffer + OFFSET_CAMINHO),
                    (char*)pBuffer + *(int*)((char*)pBuffer + OFFSET_CAMINHO) + *(int*)((char*)pBuffer + OFFSET_OPCAO),
                    *(int*)((char*)pBuffer + OFFSET_LIVRE) - (*(int*)((char*)pBuffer + OFFSET_CAMINHO) + *(int*)((char*)pBuffer + OFFSET_OPCAO)));

                    //atualiza posição livre
                    *(int*)((char*)pBuffer + OFFSET_LIVRE) -= *(int*)((char*)pBuffer + OFFSET_OPCAO);

                    //decrementa quantidade
                    (*(int*)((char*)pBuffer + OFFSET_QTD_PESSOAS))--;
                    printf("\nPessoa removida.\n");
                    break;
                }

                //skipa nome
                *(int*)((char*)pBuffer + OFFSET_CAMINHO) += strlen((char*)pBuffer + *(int*)((char*)pBuffer + OFFSET_CAMINHO)) + 1;

                //skipa idade
                *(int*)((char*)pBuffer + OFFSET_CAMINHO) += sizeof(int);

                //skipa email
                *(int*)((char*)pBuffer + OFFSET_CAMINHO) += strlen((char*)pBuffer + *(int*)((char*)pBuffer + OFFSET_CAMINHO)) + 1;

                //i++
                (*(int*)((char*)pBuffer + OFFSET_I))++;
            }
        }

        //buscar
        else if (*(int*)((char*)pBuffer + OFFSET_OPCAO) == 3) {
            printf("Nome para buscar: ");
            scanf(" %99[^\n]", (char*)pBuffer + OFFSET_SCANF);

            //i = 0
            *(int*)((char*)pBuffer + OFFSET_I) = 0;

            //começa do início dos dados
            *(int*)((char*)pBuffer + OFFSET_CAMINHO) = OFFSET_DADOS;

            while (*(int*)((char*)pBuffer + OFFSET_I) < *(int*)((char*)pBuffer + OFFSET_QTD_PESSOAS)) {
                if (
                    strcmp((char*)pBuffer + OFFSET_SCANF,(char*)pBuffer +*(int*)((char*)pBuffer + OFFSET_CAMINHO)) == 0) {
                        printf("\nPessoa encontrada:");

                    //nome
                    printf("\nNome: %s", (char*)pBuffer + *(int*)((char*)pBuffer + OFFSET_CAMINHO));

                    //skipa nome
                    *(int*)((char*)pBuffer + OFFSET_CAMINHO) += strlen((char*)pBuffer + *(int*)((char*)pBuffer + OFFSET_CAMINHO)) + 1;

                    //idade
                    printf("\nIdade: %d", *(int*)((char*)pBuffer + *(int*)((char*)pBuffer + OFFSET_CAMINHO)));

                    //skipa idade
                    *(int*)((char*)pBuffer + OFFSET_CAMINHO) += sizeof(int);

                    //email
                    printf("\nEmail: %s\n", (char*)pBuffer + *(int*)((char*)pBuffer + OFFSET_CAMINHO));
                    break;
                }

                //skipa nome
                *(int*)((char*)pBuffer + OFFSET_CAMINHO) += strlen((char*)pBuffer + *(int*)((char*)pBuffer + OFFSET_CAMINHO)) + 1;

                //skipa idade
                *(int*)((char*)pBuffer + OFFSET_CAMINHO) += sizeof(int);

                //skipa email
                *(int*)((char*)pBuffer + OFFSET_CAMINHO) += strlen((char*)pBuffer + *(int*)((char*)pBuffer + OFFSET_CAMINHO)) + 1;

                //i++
                (*(int*)((char*)pBuffer + OFFSET_I))++;
            }
        }

        //listar
        else if (*(int*)((char*)pBuffer + OFFSET_OPCAO) == 4) {

            //i=0
            *(int*)((char*)pBuffer + OFFSET_I) = 0;

            //começa do inicio dos dados
            *(int*)((char*)pBuffer + OFFSET_CAMINHO) = OFFSET_DADOS;

            while (*(int*)((char*)pBuffer + OFFSET_I) < *(int*)((char*)pBuffer + OFFSET_QTD_PESSOAS)) {
                printf("\n_________________________________");

                //nome
                printf("\nNome: %s", (char*)pBuffer + *(int*)((char*)pBuffer + OFFSET_CAMINHO));

                //skipa nome
                *(int*)((char*)pBuffer + OFFSET_CAMINHO) += strlen((char*)pBuffer + *(int*)((char*)pBuffer + OFFSET_CAMINHO)) + 1;

                //idade
                printf("\nIdade: %d", *(int*)((char*)pBuffer + *(int*)((char*)pBuffer + OFFSET_CAMINHO)));

                //skipa idade
                *(int*)((char*)pBuffer + OFFSET_CAMINHO) += sizeof(int);

                //email
                printf("\nEmail: %s\n", (char*)pBuffer + *(int*)((char*)pBuffer + OFFSET_CAMINHO));

                //skipa email
                *(int*)((char*)pBuffer + OFFSET_CAMINHO) += strlen((char*)pBuffer + *(int*)((char*)pBuffer + OFFSET_CAMINHO)) + 1;

                //i++
                (*(int*)((char*)pBuffer + OFFSET_I))++;
            }
        }

        //sair
        else if (*(int*)((char*)pBuffer + OFFSET_OPCAO) == 5) {
            free(pBuffer);
            return 0;
        }
    }
}