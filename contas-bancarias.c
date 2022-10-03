#include <stdio.h>
#define x 10000

int cria(float m[3][x], int *id) {
  if (m[2][*id] == 0 && *id <= x) {
		printf("CPF: ");
		scanf("%f", &m[2][*id]);

		printf("Saldo: ");
		scanf("%f", &m[3][*id]);
		return 1;
	} else {
		return 0;
	}
}

int atualiza(float m[3][x], int ident) {
	if (m[2][ident] > 0) {
		printf("CPF: ");
		scanf("%f", &m[2][ident]);

		printf("Saldo: ");
		scanf("%f", &m[3][ident]);
		return 1;
	} else {
		return 0;
	}
}

int exibe(float m[3][x], int ident) {
	if (m[2][ident] > 0) {
		printf("CPF: %.2f \n", m[2][ident]);
		printf("Saldo: %.2f \n", m[3][ident]);
		return 1;
	} else {
		return 0;
	}
}

int deposito(float m[3][x], int ident, float quant) {
	if (m[2][ident] > 0) {
		m[3][ident] = m[3][ident] + quant;
		return 1;
	} else {
		return 0;
	}
}

int saque(float m[3][x], int ident, float quant) {
	if (m[2][ident] > 0) {
		m[3][ident] = m[3][ident] - quant;
		return 1;
	} else {
		return 0;
	}
}

int exclui(float m[3][x], int *id2) {
	if (m[2][*id2] > 0) {
		m[2][*id2] = -1;
		m[3][*id2] = -1;
		m[1][*id2] = -1;
		return 1;
	} else {
		return 0;
	}
}

int ultimaex(float m[3][x], int ultima) {
	if (ultima > 0) {
		printf("\nUltima conta excluida foi a conta de id: %d\n", ultima);
		return 1;
	} else {
		return 0;
	}
}

int main() {
	float m[3][x], quant;
  int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < x; j++) {
			m[i][j] = 0;
		}
	}

  i = 0;
	float cont = 1.00;
	while (i <= x) {
		m[0][i] = cont;
		cont = cont + 1.00;
    i++;
	}

	int cod = 0; // vai receber o ultimo cadastro
  	int cod2 = 0; // vai receber a ultima exclusão
	int ident, acao = 10, retorno;

	while (acao > 0) {
    printf("\n----------------------------------------------------------------");
		printf("\n\nEscolha uma das opçoes a seguir digitando o numero "
			   "correspondente:\n");
		printf("\n0 para sair/parar\n");
		printf("\n1 para criar contas");
		printf("\n2 para atualizar uma conta");
		printf("\n3 para vizualizar uma conta\n");
		printf("\n4 para fazer deposito em uma conta");
		printf("\n5 para fazer saque em uma conta\n");
		printf("\n6 para excluir uma conta");
		printf("\n7 para ver a ultima conta excluida\n");
		printf("\nSua escolha: ");
		scanf("%d", &acao);

		if (acao == 1) {
      printf("\nDigite um Id para colocar a conta: ");
			scanf("%d", &cod);
			retorno = cria(m, &cod);

      if (retorno == 1) {
				printf("\n\nConta criada com sucesso!\n");
			} else {
				printf("\n\nConta em uso ou excluida!\n");
			}
		}

		else if (acao == 2) {
			printf("\nId da conta para atualizar: ");
			scanf("%d", &ident);
			retorno = atualiza(m, ident);

			if (retorno == 1) {
				printf("\n\nConta atualizada com sucesso!\n");
			} else {
				printf("\n\nConta nao cadastrada ainda ou foi excluida!\n");
			}
		}

		else if (acao == 3) {
			printf("\nId da conta para vizualizar: ");
			scanf("%d", &ident);
			retorno = exibe(m, ident);

			if (retorno == 1) {
				printf("Aqui esta a conta!\n\n");
			} else {
				printf("\n\nConta sem cadastro ou excluida!\n");
			}
		}

		else if (acao == 4) {
			printf("\nId da conta para deposito: ");
			scanf("%d", &ident);
			printf("valor deposito: ");
			scanf("%f", &quant);
			retorno = deposito(m, ident, quant);

			if (retorno == 1) {
				printf("\n\nDeposito realizado com sucesso!\n");
			} else {
				printf("\n\nConta sem cadastro ou excluida!\n");
			}
		}

		else if (acao == 5) {
			printf("\nId da conta para saque: ");
			scanf("%d", &ident);
			printf("valor saque: ");
			scanf("%f", &quant);
			retorno = saque(m, ident, quant);

			if (retorno == 1) {
				printf("\n\nSaque realizado com sucesso!\n");
			} else {
				printf("\n\nConta sem cadastro ou excluida!\n");
			}
		}

		else if (acao == 6) {
			printf("\nId da conta para excluir: ");
			scanf("%d", &cod2);
			retorno = exclui(m, &cod2);

			if (retorno == 1) {
				printf("\n\nConsta excluida com sucesso!\n");
			} else {
				printf("\n\nConta nao cadastrada ou ja foi excluida!\n");
			}
		}

		else if (acao == 7) {
			retorno = ultimaex(m, cod2);

			if (retorno == 0) {
				printf("\n\nNenhuma conta excluida ainda!\n");
			}
		}

    		else if (acao == 0) {
      			//serve para nao aparecer o print abaixo quando for digitado 0;
		}

		else {
			printf("\n\nOpçao invalida!\n");
		}
	}
  return 1;
}
