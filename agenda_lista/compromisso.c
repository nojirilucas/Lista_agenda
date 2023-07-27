#include "header.h"

int inicializa_compromisso(TCOMPROMISSO* comp, int tipo_compromisso, TDATA data, int duracao, char* nome) {
	strcpy(comp->nome_do_compromisso, nome);
	comp->tipo_compromisso = tipo_compromisso;
	comp->data = data;
	comp->duracao = duracao;
	comp->status = A_SER_CUMPRIDO;
	comp->adiavel = false;
	printf("Sucesso ao salvar compromisso:%d\n",++comp->identificador);
	return 1;
}

void insereCompromisso(TAGENDA* agenda, int tipo_compromisso, TDATA data, int duracao, char* nome) {
	TCOMPROMISSO* aux_compromisso = agenda->eventos;
	int id = 0;
	while (aux_compromisso->prox_TCOMPROMISSO != NULL) {
		id = aux_compromisso->identificador;
		aux_compromisso = aux_compromisso->prox_TCOMPROMISSO;
	}
	if (id == 0) {
		aux_compromisso->identificador = id;
	} else {
		aux_compromisso->identificador = id;
	}
	/*	printf("Digite o identificador da sua agenda:\n");
		int id_agenda;
		scanf("%d",&id_agenda);
		printf("buscando...\n");
		if(buscarAgenda(agenda,id_agenda, aux_compromisso->tipo_compromisso,aux_compromisso->data,aux_compromisso->duracao,agenda->nome_professor)==1){
	 		printf("inicializacao do compromisso.....\n");
	 		inicializa_compromisso(aux_compromisso,aux_compromisso->tipo_compromisso,aux_compromisso->data,aux_compromisso->duracao,nome); 
		}*/
	aux_compromisso->prox_TCOMPROMISSO = malloc(sizeof(TCOMPROMISSO));
	aux_compromisso = aux_compromisso->prox_TCOMPROMISSO;
	aux_compromisso->prox_TCOMPROMISSO = NULL;
}

void altera_prioridade(TCOMPROMISSO* comp) {
	while (1) {
		int novaPri;
		printf("DIGITE UMA OPCAO:\n");
		scanf("%d", &novaPri);
		if (novaPri <= 0 || novaPri >= 5) {
			printf(" Prioridade inexistente ;) \n");
		} else {
			comp->tipo_compromisso = novaPri;
			return;
		}
	}
}

int retorna_prioridade(TCOMPROMISSO* comp) {  // retornando mesma coisa que retornaStatus
	return comp->status;
}
int retornaStatus(TCOMPROMISSO* comp) {	 // retornando mesma coisa que retornaPrioridade
	return comp->status;
}

void atribuiStatus(TCOMPROMISSO* comp, int novoStatus) {
	if (comp->tipo_compromisso == 2 || comp->tipo_compromisso == 4) {
		printf(" Aulas e eventos nao podem ser adiados\n");
		return;
	} else {
		comp->status = novoStatus;
	}
}

/*ordem identificador, tipo, data, hora, duracao, nome de disciplina/aluno/reuniao/evento (ou razao), adiavel, status.*/
void imprimeCompromisso(TCOMPROMISSO* comp) {
	TDATA* dat;
	*dat = comp->data;

	printf(" Identificador do compromisso : %d \n", comp->identificador);
	printf(" Compromisso : %s \n", tipo_de_compromisso_string(comp->tipo_compromisso));
	printf(" Data : %d / %d / %d \n", dat->dia, dat->mes, dat->ano);
	printf(" Hora :  %d:%d\n", dat->hora, dat->minuto);
	printf(" Nome : %s \n", comp->nome_do_compromisso);

	int* Duracao = malloc(sizeof(int) * 3);
	converte_duracao(comp->duracao, Duracao);
	printf(" Duracao de dias : %d , horas : %d , minutos %d :  \n", Duracao[0], Duracao[1], Duracao[2]);

	// bool a= Eadiavel(comp->adiavel);

	printf(" Pode ser adiado? %s:\n", comp->adiavel ? "sim" : "não");
}

void imprimeCompromissosAdiados(TAGENDA* agenda) {
	TCOMPROMISSO* eventos = agenda->eventos;
	while (eventos->prox_TCOMPROMISSO != NULL) {
		if (eventos->status == 1)
			imprimeCompromisso(eventos);
	}
	eventos = eventos->prox_TCOMPROMISSO;
}

void imprimeCompromissosCancelados(TAGENDA* agenda) {
	TCOMPROMISSO* eventos = agenda->eventos;
	while (eventos->prox_TCOMPROMISSO != NULL) {
		if (eventos->status == 2)
			imprimeCompromisso(eventos);
	}
	eventos = eventos->prox_TCOMPROMISSO;
}

void imprimeCompromissosACumprir(TAGENDA* agenda) {
	TCOMPROMISSO* eventos = agenda->eventos;
	while (eventos->prox_TCOMPROMISSO != NULL) {
		if (eventos->status == 0){
			imprimeCompromisso(eventos);
		}
	}
	eventos = eventos->prox_TCOMPROMISSO;
}

int retornaNcompromissos(TAGENDA* agenda) {
	int numero_de_compromissos = 0;
	TCOMPROMISSO* eventos = agenda->eventos;
	while (eventos->prox_TCOMPROMISSO != NULL) {
			imprimeCompromisso(eventos);
			numero_de_compromissos++;
	}
	eventos = eventos->prox_TCOMPROMISSO;
	return numero_de_compromissos;
}

int retornaNadiamentos(TAGENDA* agenda){
	int numero_de_compromissos = 0;
	TCOMPROMISSO* eventos = agenda->eventos;
	while (eventos->prox_TCOMPROMISSO != NULL) {
		if (eventos->status == 1){
			numero_de_compromissos++;
		}
	}
	eventos = eventos->prox_TCOMPROMISSO;
	return numero_de_compromissos;
}

int retornaNcancelamentos(TAGENDA* agenda){
	int numero_de_compromissos = 0;
	TCOMPROMISSO* eventos = agenda->eventos;
	while (eventos->prox_TCOMPROMISSO != NULL) {
		if (eventos->status == 2){
			numero_de_compromissos++;
		}
	}
	eventos = eventos->prox_TCOMPROMISSO;
	return numero_de_compromissos;
}

/*ordem identificador, tipo, data, hora, duracao, nome de disciplina/aluno/reuniao/evento (ou razao), adiavel, status.*/
void converte_duracao(int tempo_total, int* Duracao) {
	Duracao[0] = tempo_total / 1440;
	tempo_total = (tempo_total - (1440 * Duracao[0]));
	Duracao[1] = tempo_total / 60;
	Duracao[2] = tempo_total % 60;
}

bool Eadiavel(TCOMPROMISSO c, bool adiavel) {
	if (c.tipo_compromisso == 2 || c.tipo_compromisso == 4) {  // ser for aula ou evento não podera ser adiado, outros compromisso podem ser adiados.
		printf("NAO E ADIVAVEL\n");
		adiavel = false;
		return adiavel;
	} else {
		printf("ADIVAVEL\n");  //status tem que mudar para true;
		adiavel = true;
		return adiavel;
	}
}

char* tipo_de_compromisso_string(int tipo_compromisso) {
	switch (tipo_compromisso) {
	case 1:
		return "ORIENTACÃO";
	case 2:
		return "AULA";
		// return "COMPROMISSO PARTICULAR";
	case 3:
		return "EVENTO";
	case 4:
		return "REUNIÃO";
	default:
		return "TIPO INVALIDO";
	}
}

//printf("Tipo de compromisso: %s",tipo_de_compromisso_string(t));
int temConflito(TCOMPROMISSO prim, TCOMPROMISSO novo) {
	if (prim.tipo_compromisso != 4 && novo.tipo_compromisso != 4) {
		float novo_duracao;	 //(float)novo.duracao;
		float prim_duracao;	 //(float)prim.duracao;
		if (prim.data.dia == novo.data.dia && prim.data.mes == novo.data.mes) {
			prim_duracao = converte_hora_dia_minuto((float)prim.duracao, prim.tipo_compromisso);
			novo_duracao = converte_hora_dia_minuto((float)novo.duracao, novo.tipo_compromisso);
			if (((prim.data.hora <= novo.data.hora) && (prim.data.hora + prim_duracao >= novo.data.hora) || (novo.data.hora <= prim.data.hora) && (novo.data.hora + novo_duracao) >= prim.data.hora)) {
				return printf("Conflito;\n");
			} else {
				return printf("Sem conflito\n");
			}
		} else {
			printf("Sem conflito\n");
		}
	}
	if (prim.tipo_compromisso == 4 || novo.tipo_compromisso == 4) {
		float dias_duracao;
		if (prim.tipo_compromisso == 4) {
			dias_duracao = converte_hora_dia_minuto(prim.duracao, prim.tipo_compromisso);  // recebe duracao em dias
			if (novo.data.dia >= prim.data.dia && prim.data.dia + dias_duracao >= novo.data.dia && prim.data.mes == novo.data.mes) {
				return printf("Conflito;\n");
			} else {
				printf(" Sem conflito\n");
			}
		} else {
			dias_duracao = converte_hora_dia_minuto(novo.duracao, novo.tipo_compromisso);
			if (prim.data.dia >= novo.data.dia && novo.data.dia + dias_duracao >= prim.data.dia && prim.data.mes == novo.data.mes) {
				return printf("Conflito;\n");
			} else {
				printf(" Sem conflito\n");
			}
		}
	}
}

float converte_hora_dia_minuto(float duracao, int tipo_compromisso) {
	if (tipo_compromisso == 4) {
		float dia, dia_horas = 24.00;
		return duracao / dia_horas;
	} else {
		float hora_minutos = 60.00;
		return duracao / hora_minutos;
	}
}