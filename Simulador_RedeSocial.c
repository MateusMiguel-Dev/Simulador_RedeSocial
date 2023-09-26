#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
int usuarios = 0;
//----- FUNCAO 1 [INICIALIZAR GRAFO] -----//
void inicializaGrafo(int mat_temp[MAX-1][MAX-1]){
	int i, j;
	for(i = 0; i < MAX; i++){
		for(j = 0; j < MAX; j++){
			mat_temp[i][j] = 0;
		}
	}
}

//----- FUNCAO 2 [INSERIR USUARIO] -----//
void insereUsuario(char mat[MAX-1][MAX]){
	system("cls");
	int i, cont = 0;
	char nome[MAX];
	printf("\nInsira o nome do novo usuario: ");
	fflush(stdin);
	gets(nome);
	for(i = 0; i < usuarios; i++){
		if(strcmp(mat[i], nome) == 0){
				cont++;
		}
	}
	if(cont == 0){
		usuarios++;
		strcpy(mat[usuarios], nome);
	}else{
		printf("\nUsuario já esta cadastrado!");
		printf("\nRetornando ao menu principal...\n");
	}
}

//----- FUNCAO 3 [INSERIR RELACAO ENTRE SEGUIDORES] -----//
void insereRelacaoSeguidor(char mat[MAX-1][MAX], int mat_temp[MAX-1][MAX-1]){
	int i, cont = 0, aux = 0, source_i, source_j, option = 0, tempo = 0;
	char str1[MAX], str2[MAX];
	printf("\n---- Usuarios Cadastrados ----");
	for(i = 0; i < usuarios+1; i++){
		printf("\n %s ", mat[i]);
	}
	printf("\nInsira o 1o Usuario desejado [1/2]: ");
	fflush(stdin);
	gets(str1);
	
	printf("\nInsira o 2o Usuario desejado [2/2]: ");
	fflush(stdin);
	gets(str2);
	
	for(i = 0; i < usuarios; i++){
		if(strcmp(str1, mat[i])){
			cont++;
			source_i = i;
		}
		if(strcmp(str2, mat[i])){
			aux++;
			source_j = i;
		}
	}
	if(cont == 0){
		printf("\nUsuario '%s' nao cadastrado!", str1);
		printf("\nRetornando ao menu principal...\n");
	}else if(aux == 0){
		printf("\nUsuario '%s' nao cadastrado!", str2);
		printf("\nRetornando ao menu principal...\n");
	}else if(cont == 0 && aux == 0){
		printf("\nUsuarios '%s' e '%s' nao cadastrados!", str1, str2);
		printf("\nRetornando ao menu principal...\n");
	}else{
		if(mat_temp[source_i][source_j] != 0){
			printf("\nA relacao entre os usuarios ja existe!");
			printf("\nDeseja atualizar a relacao entre eles? [Digite 1 para SIM - Digite 0 para NAO]:");
			scanf("%d", &option);
			if(option == 1){
				printf("\nInsira a relacao de tempo entre os usuarios: ");
				scanf("%d", &tempo);
				mat_temp[source_i][source_j] = tempo;
				printf("\nRelacao Atualizada!");
				printf("\nPressione <ENTER> para voltar ao menu principal...");
			}else{
				printf("\nPressione <ENTER> para voltar ao menu principal...");
			}
		}else{
			printf("\nInsira a relacao de tempo entre os usuarios: ");
			scanf("%d", &tempo);
			mat_temp[source_i][source_j] = tempo;
			printf("\nRelacao Atualizada!");
			printf("\nPressione <ENTER> para voltar ao menu principal...");
		}
	}
}

//----- FUNCAO 4 [LISTA TODOS OS USUARIOS QUE O USUARIO SEGUE] -----//
void segueQuem(int mat_temp[MAX-1][MAX-1], char mat[MAX-1][MAX]){
	char str1[100];
	int i, cont = 0, source_i;
	printf("\nInsira o nome do usuario:");
	fflush(stdin);
	gets(str1);
	for(i = 0; i < usuarios; i++){
		if(strcmp(str1, mat[i])){
			cont++;
			source_i = i;
		}
	}
	if(cont == 0){
		printf("\nUsuario '%s' nao cadastrado!", str1);
		printf("\nRetornando ao menu principal...\n");	
	}else{
		for(i = 0; i < usuarios; i++){
			if(mat_temp[source_i][i] != 0){
				printf("\n Usuario: [%s] - Tempo de [%d]", mat[i], mat_temp[i]);
				if(i%2 == 0){
					printf("\n");
				}
			}			
		}
	}
}	

//----- FUNCAO 5 [LISTA TODOS OS USUARIOS QUE SEGUEM O USUARIO] -----//
void quemMeSegue(int mat_temp[MAX-1][MAX-1], char mat[MAX-1][MAX]){
	int i, j, cont = 0, source_j;
	char str1[MAX];
	printf("\nInsira o nome do usuario:");
	fflush(stdin);
	gets(str1);
	for(i = 0; i < usuarios; i++){
		if(strcmp(str1, mat[i])){
			cont++;
			source_j = i;
		}
	}
	if(cont == 0){
		printf("\nUsuario '%s' nao cadastrado!", str1);
		printf("\nRetornando ao menu principal...\n");	
	}else{
		for(i = 0; i < usuarios; i++){
			for(j < 0; j < usuarios; j++){
				if(mat_temp[i][j] != 0 && i != source_j){
					printf("\n Usuario: [%s] - Tempo de [%d]", mat[i], mat_temp[i][j]);
					if(i%2 == 0){
						printf("\n");
					}
				}			
			}
		}
	}
}
 
//----- FUNCAO 6 [ATUALIZA O TEMPO DE RELACAO ENTRE OS USUARIOS] -----//
void atualizaRelacao(int mat_temp[MAX-1][MAX-1], char mat[MAX-1][MAX]){
	int i, source_i = 0, source_j = 0, cont = 0, aux = 0, option_i = 0, op = 0, option = 0, tempo = 0;
	char str1[MAX], str2[MAX];
	
	printf("\nInsira o 1o Usuario desejado [1/2]: ");
	fflush(stdin);
	gets(str1);
	
	printf("\nInsira o 2o Usuario desejado [2/2]: ");
	fflush(stdin);
	gets(str2);
		
	for(i = 0; i < usuarios; i++){
		if(strcmp(str1, mat[i])){
			cont++;
			source_i = i;
		}
		if(strcmp(str2, mat[i])){
			aux++;
			source_j = i;
		}
	}
	if(cont == 0 && aux != 0){
		printf("\nUsuario '%s' nao cadastrado!", str1);
		printf("\nDeseja cadastrar usuario? [Digite 1 para SIM - Digite 0 para NAO]: ");
		scanf("%d", &option_i);
		if(option_i == 1){
			insereUsuario(mat);
			printf("\nInsira o tipo de relacao de tempo entre os usuarios [Digite 1 para SEGUIDOR - Digite 0 para SEGUIDO POR]: ");
			scanf("%d", &op);
			printf("\nInsira o tempo de relacao de tempo entre os usuarios: ");
			scanf("%d", &tempo);
			if(op == 1){
				mat_temp[source_i][source_j] = tempo;
			}else{
				mat_temp[source_j][source_i] = tempo;
			}
			printf("\nRelacao de tempo foi cadastrada entre os usuarios!");
			printf("\nPressione <ENTER> para voltar ao menu principal...");
		}else{
			printf("\nUsuario nao cadastrado...");
			printf("\nRetornando ao menu principal...\n");
		}
	}else if(aux == 0 && cont != 0){
		printf("\nUsuario '%s' nao cadastrado!", str2);
		printf("\nDeseja cadastrar usuario? [Digite 1 para SIM - Digite 0 para NAO]: ");
		scanf("%d", &option_i);
		if(option_i == 1){
			insereUsuario(mat);
			printf("\nInsira o tipo de relacao de tempo entre os usuarios [Digite 1 para SEGUIDOR - Digite 0 para SEGUIDO POR]: ");
			scanf("%d", &op);
			printf("\nInsira o tempo de relacao de tempo entre os usuarios: ");
			scanf("%d", &tempo);
			if(op == 1){
				mat_temp[source_i][source_j] = tempo;
			}else{
				mat_temp[source_j][source_i] = tempo;
			}
			printf("\nRelacao de tempo foi cadastrada entre os usuarios!");
			printf("\nPressione <ENTER> para voltar ao menu principal...");
		}else{
			printf("\nUsuario nao cadastrado...");
			printf("\nRetornando ao menu principal...\n");
		}
	}else if(cont == 0 && aux == 0){
		printf("\nUsuarios '%s' e '%s' nao cadastrados!", str1, str2);
		printf("\nDeseja cadastrar usuarios? [Digite 1 para SIM - Digite 0 para NAO]: ");
		scanf("%d", &option_i);
		if(option_i == 1){
			insereUsuario(mat);
			insereUsuario(mat);
			printf("\nUsuarios Cadastrados!");
			printf("\nInsira o tipo de relacao de tempo entre os usuarios [Digite 1 para SEGUIDOR - Digite 0 para SEGUIDO POR]: ");
			scanf("%d", &op);
			printf("\nInsira o tempo de relacao de tempo entre os usuarios: ");
			scanf("%d", &tempo);
			if(op == 1){
				mat_temp[source_i][source_j] = tempo;
			}else{
				mat_temp[source_j][source_i] = tempo;
			}
			printf("\nRelacao de tempo foi cadastrada entre os usuarios!");
			printf("\nPressione <ENTER> para voltar ao menu principal...");
		}else{
			printf("\nUsuario nao cadastrado...");
			printf("\nRetornando ao menu principal...\n");
		}
	}else{
		if(mat_temp[source_i][source_j] != 0 || mat_temp[source_j][source_i] != 0){
			printf("\nA relacao entre os usuarios ja existe!");
			printf("\nDeseja atualizar a relacao entre eles? [Digite 1 para SIM - Digite 0 para NAO]:");
			scanf("%d", &option);
			if(option == 1){
				printf("\nInsira o tipo de relacao de tempo entre os usuarios [Digite 1 para SEGUIDOR - Digite 0 para SEGUIDO POR]: ");
				scanf("%d", &op);
				printf("\nInsira o tempo de relacao de tempo entre os usuarios: ");
				scanf("%d", &tempo);
				if(op == 1){
					mat_temp[source_i][source_j] = tempo;
				}else{
					mat_temp[source_j][source_i] = tempo;
				}
			}else{
				printf("\nPressione <ENTER> para voltar ao menu principal...");
			}
		}else{
			printf("\nInsira o tipo de relacao de tempo entre os usuarios [Digite 1 para SEGUIDOR - Digite 0 para SEGUIDO POR]: ");
			scanf("%d", &op);
			printf("\nInsira o tempo de relacao de tempo entre os usuarios: ");
			scanf("%d", &tempo);
			if(op == 1){
				mat_temp[source_i][source_j] = tempo;
			}else{
				mat_temp[source_j][source_i] = tempo;
			}
			printf("\nRelacao de tempo foi cadastrada entre os usuarios!");
			printf("\nPressione <ENTER> para voltar ao menu principal...");
		}
	}
}

//----- FUNCAO 7 [REMOVE RELACAO ENTRE OS USUARIOS] -----//
void removeRelacao(int mat_temp[MAX-1][MAX-1], char mat[MAX-1][MAX]){
	int i, source_i = 0, source_j = 0, cont = 0, aux = 0, op, tempo = 0;
	char str1[MAX], str2[MAX];
	printf("\nInsira o nome do usuario: ");
	fflush(stdin);
	gets(str1);
	for(i = 0; i < usuarios; i++){
		if(strcmp(str1, mat[i])){
			cont++;
			source_i = i;	
		}
	}
	if(cont == 0){
		printf("\nUsuario nao cadastrado!");
		printf("\nPressione <ENTER> para voltar ao menu principal...");
	}else{
		printf("\nInsira o nome do outro usuario: ");
		fflush(stdin);
		gets(str2);
		for(i = 0; i < usuarios; i++){
			if(strcmp(str2, mat[i])){
				aux++;
				source_j = i;	
			}
		}
		if(aux == 0){
			printf("\nUsuario nao cadastrado!");
			printf("\nPressione <ENTER> para voltar ao menu principal...");
		}else{
			printf("\nInsira o tipo de relacao de tempo entre os usuarios [Digite 1 para SEGUIDOR - Digite 0 para SEGUIDO POR]: ");
			scanf("%d", &op);
			printf("\nInsira o tempo de relacao de tempo entre os usuarios: ");
			scanf("%d", &tempo);
			if(op == 1){
				mat_temp[source_i][source_j] = tempo;
				usuarios--;
			}else{
				mat_temp[source_j][source_i] = tempo;
				usuarios--;
			}
			printf("\nRelacao removida com sucesso!");
			printf("\nPressione <ENTER> para voltar ao menu principal...");
		}
	}
}

//----- FUNCAO 8 [CALCULA OS SEGUIDORES DO USUARIO] -----//
void calculaSeguidoresTotal(int mat_temp[MAX-1][MAX-1], char mat[MAX-1][MAX]){
	int i, cont = 0, source_i = 0, calc = 0;
	char str1[MAX];
	
	printf("\nInsira o nome do Usuario desejado: ");
	fflush(stdin);
	gets(str1);
	for(i = 0; i < usuarios; i++){
		if(strcmp(str1, mat[i])){
			cont++;
			source_i = i;	
		}
	}
	if(cont == 0){
		printf("\nUsuario nao cadastrado!");
		printf("\nPressione <ENTER> para voltar ao menu principal...");
	}else{
		for(i = 0; i < usuarios; i++){
			if(mat_temp[source_i][i] != 0){
				calc++;
			}
		}
		printf("\nTotal de Seguidores: %d", calc);
		printf("\nPressione <ENTER> para voltar ao menu principal...");
	}
	
}
int mat[MAX-1][MAX-1];
char matStr[MAX-1][MAX];
int op = 0;
int main(){
	
	inicializaGrafo(mat);
	do{
		system("cls");
		printf("\n=-------= GERENCIADOR DE SEGUIDORES =-------=\n");
		printf("\nSelecione a opcao desejada: ");
		printf("\n1 - Inserir Usuario");
		printf("\n2 - Inserir Relacao de Seguidor");
		printf("\n3 - Visualizar Seguidores");
		printf("\n4 - Visualizar Quem Eu Sigo");
		printf("\n5 - Atualizar Relacao Seguir/Seguidor");
		printf("\n6 - Remover Relacao Seguir/Seguidor");
		printf("\n7 - Calcular Total de Seguidores");
		printf("\n0 - Sair do Programa");
		printf("\nOpcao: ");
		scanf("%d", &op);
		switch(op){
			case 1:
				system("cls");
				insereUsuario(matStr);
				system("pause");
				break;
				
			case 2:
				system("cls");
				insereRelacaoSeguidor(matStr, mat);
				system("pause");
				break;
			
			case 3:
				system("cls");
				segueQuem(mat, matStr);
				system("pause");
				break;
	
			case 4:
				
				system("cls");
				quemMeSegue(mat, matStr);
				system("pause");
				break;
			
			case 5:
				
				system("cls");
				atualizaRelacao(mat, matStr);
				system("pause");
				break;
				
			case 6:
				
				system("cls");
				removeRelacao(mat, matStr);
				system("pause");
				break;
			
			case 7:
				
				system("cls");
				calculaSeguidoresTotal(mat, matStr);
				system("pause");
				break;
			
			case 0:
				printf("\nSaindo do Programa...\n");
				
				break;
			
			default:
				printf("\nSaindo do Programa...\n");
				break;
		}
	}while(op!=0);
}
