#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void menu();
void opcaoM();
void aquivoTexto();
void lendoArquivo();
void menuVerificacao();
void criptografando(char sera_criptografada[100]);
void descriptografando(char sera_criptografada[100]);
void texto_descriptografado();
void novo_arquivo_texto(char novo_arquivo_texto[10000]);

int main(void)
{
    menu();

    system("pause");
    return 0;
}

void menu(){
    system("cls");

    printf("\t\t\t\t\tMENU\n\n\n");
    printf("\t\t\t\t 1- Adicionar texto\n\t\t\t\t 2- Verificar texto adicionado\n\t\t\t\t 3- Sair\n\n");
    opcaoM();
}
void opcaoM(){

    int opcaoMenu;
    printf("\tDigite o numero da Opcao: ");
    scanf("%d", &opcaoMenu);
    setbuf(stdin,NULL);

    switch(opcaoMenu){
    case 1:
        aquivoTexto();
        break;
    case 2:
        system("cls");
        lendoArquivo();
        break;
    case 3:
        system("cls");
        printf("Saindo...\n\n");
        break;
    default:
        menu();
        break;
    }
}

void aquivoTexto(){
    system("cls");
    setlocale(LC_ALL,"");
    char texto[1000];
    printf("\n\n\n\t\t");
    printf("Descricao da obra: ");
    gets(texto);

    FILE *file;
    file = fopen("Texto_Obra.txt", "w");

    if(file == NULL){
        printf("O arquivo não pode ser aberto");
        getchar();
        exit(1);
    }

    fprintf(file, "\t%s\n\n", texto);

    fclose(file);
    system("pause");

    system("cls");
    printf("\n\tFoi criado um arquivo em texto chamado \"Texto_Obra.txt\", nesse mesmo diretorio\n\n\n");
    system("pause");
    menu();
}

void menuVerificacao(){
    system("cls");

    int senha;

    do{
        printf("\n\n\tDigite a senha para acessar a mensagem criptografada: ");
        scanf("%d", &senha);
    }
    while(senha != 123);
    texto_descriptografado();

}

void lendoArquivo(){

    FILE *file;
    file = fopen("Texto_Obra.txt", "r");

    char textoLido[10000];

    printf("\n\n\n\t\tTexto criptografado: ");
    while(fgets(textoLido, 10000, file) != NULL){
        criptografando(textoLido);
        printf("%s", textoLido);
    }
    fclose(file);
    printf("\n\n");
    system("pause");

    menuVerificacao();
}

void texto_descriptografado(){

    FILE *file;
    file = fopen("Texto_Obra.txt", "r");

    char textoLido[10000];

    printf("\n\n\n\t O texto descriptografada: ");
    while(fgets(textoLido, 10000, file) != NULL){
        printf("%s \n\n", textoLido);
    }

    fclose(file);
    system("pause");

    printf("\nFoi criado um novo arquivo texto chamado \"Novo_Arquivo_texto.txt\" neste mesmo diretorio\n\n");

    system("cls");
    menu();
}

void criptografando(char sera_criptografada[100]){

    for(int i=0; i<=sera_criptografada[i]; i++){
        sera_criptografada[i] = sera_criptografada[i] - 3;
    }
}
// '()÷∟÷÷∟N‗a
void descriptografando(char sera_criptografada[100]){

    for(int i=0; i<=sera_criptografada[i]; i++){
        sera_criptografada[i] = sera_criptografada[i] + 3;
    }
}
