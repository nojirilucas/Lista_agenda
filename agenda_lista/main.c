#include "header.h"

void main() {
  TAGENDA* Agenda = malloc(sizeof(TAGENDA));
  Agenda->eventos = malloc(sizeof(TCOMPROMISSO));
  Agenda->prox_TAGENDA = NULL;
  Agenda->eventos->prox_TCOMPROMISSO = NULL;  //inicializacao de agenda e evento
  TDATA data;
  int tipo_compromisso, duracao, ano;
  char nome[50];
  int op = -1;

  while (1) {
    op = showmenu();
    switch (op) {
      case 1: 
        printf("Nome do professor:\n");
        getchar();
        gets(aux_agenda->nome_professor);
        printf("Ano:\n");
        scanf("%d",&aux_agenda->ano);
        criaAgenda(Agenda,id_unico,Agenda->nome_professor,Agenda->ano);
        id_unico++;
        break;

      case 2:
        printf("Digite o tipo de compromisso:\n");
        fflush(stdin);
        scanf("%d", &tipo_compromisso);
        printf("Digite a data dia/mes:\n");
        fflush(stdin);
        scanf("%d%d", &data.dia, &data.mes);
        printf("Digite a hora marcada:\n");
        fflush(stdin);
        scanf("%d%d", &data.hora, &data.minuto);
        printf("Digite a duracao:\n");
        fflush(stdin);
        scanf("%d", &duracao);
        printf("Digite o nome do compromisso:\n");
        getchar();
        gets(nome);

        insereCompromisso(Agenda, tipo_compromisso, data, duracao, nome);
          break;

      case 3:
        printf("Digite uma data...Dia e Mes\n");
        scanf("%d%d",&data.dia,&data.mes);
        recuperaAgenda(Agenda,data);
          break;

      case 4:
        printf("Digite o identificador da sua agenda:\n");
        scanf("%d",&aux_agenda->id_agenda);
        printf("buscando...\n");
          if(buscarAgenda(Agenda,aux_agenda->id_agenda, tipo_compromisso, data, duracao,Agenda->nome_professor)==1){
            printf("inicializacao do compromisso.....\n");
            inicializa_compromisso(Agenda->eventos,Agenda->eventos->tipo_compromisso,Agenda->eventos->data,Agenda->eventos->duracao,Agenda->eventos->nome_do_compromisso);
          }
            break;

      case 5:
        removeCompromisso(Agenda,Agenda->id_agenda);
        break;

      case 6:
        printf("Numero:%d\n",retornaNadiamentos(Agenda));
        break;
          
      case 7:
        printf("Numero:%d\n",retornaNcancelamentos(Agenda));
        break;
          
      case 8:
        printf("Numero:%d\n",retornaNcompromissos(Agenda));
        break;
          
      case 9:
        imprimeCompromissosCancelados(Agenda);;
        break;
          
      case 10:
        imprimeCompromissosAdiados(Agenda);
        break;
          
      case 11:
        imprimeCompromissosACumprir(Agenda);
        break;
          
      case 12:
        imprimeAgenda(Agenda);
        break;
          
      case 13:
        return 0;
    }
  }
}