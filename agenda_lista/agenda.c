#include "header.h"

int showmenu() {
  int op;
  while (op < 1 || op > 13) {
    printf(" ---Bem Vindo a agenda, digite o numero da acao a ser tomada---\n \n");
    printf("  1-Criar Agenda\n");
    printf("  2-Inserir Compromisso\n");
    printf("  3-Recuperar Agenda\n");
    printf("  4-Inicializa compromisso\n");
    printf("  5-Remover Compromisso\n");
    printf("  6-Numero de adiados\n");
    printf("  7-Numero de cancelados\n");
    printf("  8-Total de compromissos\n");
    printf("  9-Visualizar cancelados\n");
    printf("  10-Visualizar adiados\n");
    printf("  11-Visualizar a cumprir\n");
    printf("  12-Imprimir Agenda\n");
    printf("  13-Sair\n");
    scanf("%d", &op);
    if (op < 1 || op > 13) {
      printf("Opçao Incorreta!!");
    }
  }
  return op;
}

void criaAgenda(TAGENDA* agenda, int idProf, char* nome, int ano) {
  agenda = malloc(sizeof(TAGENDA));
  agenda->prox_TAGENDA = NULL;
  agenda->eventos = malloc(sizeof(TCOMPROMISSO));
  agenda->eventos->prox_TCOMPROMISSO = NULL;
  agenda->id_agenda = idProf;
  strcpy(agenda->nome_professor, nome);
  agenda->ano = ano;
  printf("Seu ID:%d\n",agenda->id_agenda);
}

void imprimeAgenda(TAGENDA* agenda) {
  TCOMPROMISSO* eventos = agenda->eventos;
      int i, j, min,k;
          TCOMPROMISSO comp;
          for (i = 0;eventos!=NULL; i++) {
              min = i;
              for (j = i + 1;eventos!=NULL; j++) {
                if( agenda->eventos[j].data.mes == agenda->eventos[min].data.mes){
                  if( agenda->eventos[j].data.dia < agenda->eventos[min].data.dia){
                    comp = agenda->eventos[min];
                    agenda->eventos[min] = agenda->eventos[j];
                    agenda->eventos[j] = comp;
                    min = j;
                  }
                  if( agenda->eventos[j].data.dia == agenda->eventos[min].data.dia ){
                    if (agenda->eventos[j].tipo_compromisso == agenda->eventos[min].tipo_compromisso) {
                      if(agenda->eventos[j].tipo_compromisso < agenda->eventos[min].tipo_compromisso){
                        comp = agenda->eventos[min];
                        agenda->eventos[min] = agenda->eventos[j];
                        agenda->eventos[j] = comp;
                        min = j;
                      }
                    }
                  }
                }
              }
          }
  while (eventos->prox_TCOMPROMISSO != NULL) {
    imprimeCompromisso(eventos);
}
  eventos = eventos->prox_TCOMPROMISSO;
}

int recuperaAgenda(TAGENDA *agenda, TDATA data) {
  int numero_de_compromissos = 0;
  for (int i = 0;agenda->eventos != NULL;i++){
      if (agenda->eventos[i].data.mes <= 12 && agenda->eventos[i].data.mes >= 1) {
        if (data.mes == agenda->eventos[i].data.mes) {
          if (data.dia < agenda->eventos[i].data.dia) {
            numero_de_compromissos++;
          }
        }
        if (data.mes < agenda->eventos[i].data.mes) {
          numero_de_compromissos++;
        }
      } 
      else {
         printf("SEM COMRPOMISSOS APOS %d/%d \n", data.dia, data.mes);
         break;
    }
  }
  printf("\nProfessor:%s\nAno:%d\nNumero de compromissos apos a data:%d\n",
       agenda->nome_professor, agenda->ano,numero_de_compromissos);
}

int buscarAgenda(TAGENDA* Agenda,int id_agenda,int tipo_compromisso,TDATA data,int duracao,char* nome){
  TAGENDA* aux_agenda=Agenda->prox_TAGENDA;
    while (aux_agenda!=NULL){
      printf("Comparando IDs...\n");
        if(id_agenda == aux_agenda->id_agenda){
            printf("ID Encotrado!\n");
            return 1;
        }
    }
     printf("ID INVALIDO\n");
}