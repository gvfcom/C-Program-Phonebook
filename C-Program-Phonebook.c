#include <stdio.h>
#include <string.h>

#define contatoMax 1001
#define nomeMax 102
#define telMax 22
#define emailMax 52

struct contato {
	char nome[nomeMax];
	char telefone[telMax];
	char email[emailMax];
	char sexo;
	int idade;
	float peso;
	float altura;
} pessoa[contatoMax];

void menu() {
	printf("****MENU AGENDA ELETRONICA****\n1: Adicionar contato\n2: Excluir contato\n3: Pesquisar contato\n4: Visualizar todos os contatos\n0: Sair!\n");
}

void error404() {
	printf("****Nome nao encontrado!****\n");
}

//ORDEM ALFABÉTICA:
void sort(struct contato pessoa[]) {
	int h, i;
	struct contato aux;

	for(h=0; h<contatoMax; h++) {
		for(i=0; i<contatoMax && pessoa[i+1].nome[1] != '\0'; i++) {		
			if(pessoa[i].nome[0] > pessoa[i+1].nome[0]) {
				aux = pessoa[i];
				pessoa[i] = pessoa[i+1];
				pessoa[i+1] = aux;
			}
		}
	}
}

//OPÇÃO 1:
void addContact(struct contato pessoa[], int *y) {
	int x = *y;

	printf("****ADICIONAR CONTATO****\n");

	printf("Digite o nome:\n");
	getchar();
	fgets(pessoa[x].nome,nomeMax,stdin);
	pessoa[x].nome[strlen(pessoa[x].nome)-1] = '\0'; //var[strlen(var)-1] = '\0';

	printf("Digite o telefone (formato: (XX) XXXX-XXXX):\n");
	fgets(pessoa[x].telefone,telMax,stdin);
	pessoa[x].telefone[strlen(pessoa[x].telefone)-1] = '\0';

	printf("Digite e-mail:\n");
	fgets(pessoa[x].email,emailMax,stdin);
	pessoa[x].email[strlen(pessoa[x].email)-1] = '\0';

	printf("Digite o sexo:\n");
	scanf("%c", &pessoa[x].sexo);

	printf("Digite a idade:\n");
	scanf("%d", &pessoa[x].idade);

	printf("Digite o peso:\n");
	scanf("%f", &pessoa[x].peso);

	printf("Digite a altura:\n");
	scanf("%f", &pessoa[x].altura);

	*y += 1;
}

//OPÇÃO 2:
void deleteContact(struct contato pessoa[]) {
	char queryName[nomeMax];
	int i, found=0;
	
	printf("****EXCLUIR CONTATO****\n");
	
	printf("Digite o nome da exclusao:\n");
	getchar();
	fgets(queryName,nomeMax,stdin);
	queryName[strlen(queryName)-1] = '\0'; //var[strlen(var)-1] = '\0';

	for(i=0; i<contatoMax; i++) {
		if(strcmp(queryName, pessoa[i].nome) == 0) {
			found = 1;
			pessoa[i].nome[1] = '\0';
			break;
		}
	}
	if(found == 0)
		error404();
}

//OPÇÃO 3:
void findContact(struct contato pessoa[]) {
	char queryName[nomeMax];
	int i;
	
	printf("****PESQUISAR CONTATO****\n");
	
	printf("Digite o nome da busca:\n");
	getchar();
	fgets(queryName,nomeMax,stdin);
	queryName[strlen(queryName)-1] = '\0'; //var[strlen(var)-1] = '\0';
	
	for(i=0; i<contatoMax; i++) {
		if(strcmp(queryName, pessoa[i].nome) == 0) {
			puts(pessoa[i].nome);
			puts(pessoa[i].telefone);
			puts(pessoa[i].email);
			printf("%c\n%d\n%.2f\n%.2f\n", pessoa[i].sexo, pessoa[i].idade, pessoa[i].peso, pessoa[i].altura);
			break;
		}
	}

	if(strcmp(queryName, pessoa[i].nome) != 0)
		error404();
}

//OPÇÃO 4:
void viewAll(struct contato pessoa[]) {
	int i, found=0;

	printf("****VISUALIZAR TODOS OS CONTATOS****\n");

	for(i=0; i<contatoMax; i++) {
		if(pessoa[i].nome[1] != '\0') {
			found=1;
			puts(pessoa[i].nome);
			puts(pessoa[i].telefone);			
			puts(pessoa[i].email);
			printf("%c\n%d\n%.2f\n%.2f\n", pessoa[i].sexo, pessoa[i].idade, pessoa[i].peso, pessoa[i].altura);
		}
	}

	if(found == 0)
		printf("****Agenda Vazia!****\n");
}

int main() {
	int x=0, i=0;
	short option=-1;

	//Zerar lista:
	for(i=0; i<contatoMax; i++)
		pessoa[i].nome[1] = '\0';

	while(option != 0) {
		menu();
		scanf("%hu", &option);
		switch(option) {
			case 0:
				break;

			case 1:
				addContact(pessoa, &x);
				break;

			case 2:
				deleteContact(pessoa);
				break;
			
			case 3:
				findContact(pessoa);
				break;

			case 4:
				sort(pessoa);
				viewAll(pessoa); 
				break;
			
			default:
				printf("****Opcao Invalida, tentar novamente****\n");
				break;
		}
	}
	
	return 0;
}

