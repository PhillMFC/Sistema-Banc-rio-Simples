#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int resposta=0,resposta2=0,totalDeClientes=0, totalDeContas=0;
 int codigoGlobal=0, CPFGlobal=0;
typedef struct clientes{
  char nome[100];
  long int codigo;
  long int cpf;
  char endereco[150];
  int preenchido;
  struct clientes *proximoCliente;
}clientes;

typedef struct contas{
  long int ag;
  long int conta;
  long double saldo;
  long int cpf;
  char nome[100];
  int preenchido;
  struct contas *proximaConta;
} contas;


int menu1(){
  printf("--------Sistema Bancário--------\n\n");

  printf("1 - Opções para clientes.\n");
  printf("2 - Opções para contas bancárias.\n");
  printf("3 - Encerrar programa.\n");
  scanf("%i%*c",&resposta);
  printf("\n");

  while(resposta!=1 && resposta!=2 && resposta!=3){
  printf("Resposta inválida. Tente novamente\n");
  scanf("%i%*c",&resposta);
  printf("\n");
  }

  return resposta;
}

int menu2(){
  printf("1 - Cadastrar novo cliente.\n");
  printf("2 - Buscar cliente.\n");
  printf("3 - Listar clientes.\n");
  printf("4 - Atualizar dados de cliente.\n");
  printf("5 - Excluir cliente.\n");
  printf("6 - Voltar.\n");
  scanf("%i%*c",&resposta2);
  printf("\n");

  while(resposta2!=1 &&resposta2!=2 && resposta2!=3 && resposta2!=4 && resposta2!=5 && resposta2!=6){
  printf("Resposta inválida. Tente novamente.\n");
  scanf("%i%*c",&resposta2);
  printf("\n");
}
  return resposta2;
  
}

int menu3(){
  printf("1 - Cadastrar nova conta.\n");
  printf("2 - Buscar Conta.\n");
  printf("3 - Listar Contas.\n");
  printf("4 - Excluir conta.\n");
  printf("5 - Realizar Saque, transferência ou depósito.\n");
  printf("6 - Voltar.\n");
  scanf("%i%*c",&resposta2);
  printf("\n");
  
  while(resposta2!=1 &&resposta2!=2 && resposta2!=3 && resposta2!=4 && resposta2!=5 && resposta2!=6){
  printf("Resposta inválida. Tente novamente.\n");
  scanf("%i%*c",&resposta2);
  printf("\n");
}
  return resposta2;
}

void ValidaCodigo(long int codigo, clientes *primeiro, clientes *proximoCliente){
  
  proximoCliente = primeiro;
  while(proximoCliente->preenchido==1){
    if(proximoCliente->codigo==codigo){
      printf("Código já cadastrado. Digite outro codigo.\n");
      scanf("%ld",&codigo);
      ValidaCodigo(codigo, primeiro, proximoCliente);
      break;
    }
    else{
      proximoCliente = proximoCliente->proximoCliente;
    }
  }
  proximoCliente->codigo=codigo;
}

void ValidaCodigo2(long int codigo, clientes *primeiro, clientes *proximoCliente,clientes *referencia){
  
  proximoCliente = primeiro;
  while(proximoCliente->preenchido==1){

    if(proximoCliente->codigo==codigo && proximoCliente!=referencia){
      printf("Código já cadastrado. Digite outro codigo\n");
      scanf("%ld",&codigo);
      ValidaCodigo2(codigo, primeiro, proximoCliente,referencia);
      break;
    }
    else{
      proximoCliente = proximoCliente->proximoCliente;
    }
  }
  referencia->codigo=codigo;
}

void ValidaCPF(long int cpf, clientes *primeiro, clientes *proximoCliente){
  
  proximoCliente = primeiro;
  while(proximoCliente->preenchido==1){
    if(proximoCliente->cpf==cpf){
      printf("CPF já cadastrado. Digite outro CPF\n");
      scanf("%ld",&cpf);
      ValidaCPF(cpf, primeiro, proximoCliente);
      break;
    }
    else{
      proximoCliente = proximoCliente->proximoCliente;
    }
  }
  proximoCliente->cpf=cpf;
}

void ValidaCPF2(long int CPF, clientes *primeiro, clientes *proximoCliente,clientes *referencia){
  
  proximoCliente = primeiro;
  while(proximoCliente->preenchido==1){

    if(proximoCliente->cpf==CPF && proximoCliente!=referencia){
      printf("CPF já cadastrado. Digite outro CPF\n");
      scanf("%ld",&CPF);
      ValidaCodigo2(CPF, primeiro, proximoCliente,referencia);
      break;
    }
    else{
      proximoCliente = proximoCliente->proximoCliente;
    }
  }
  referencia->cpf=CPF;
}

int ValidaConta(long int conta, contas *primeira){
  contas *proximaConta=primeira;

  while(proximaConta->preenchido==1){
    if(proximaConta->conta==conta){
      printf("Número da conta já cadastrado. Digite outra conta:\n");
      scanf("%ld",&conta);
      printf("\n");
      ValidaConta(conta, primeira);
      break;
    }
    else{
      proximaConta=proximaConta->proximaConta;
    }
  }
  return conta;
}

void CadastroCliente(clientes *primeiro, clientes *proximoCliente){
  
  proximoCliente=primeiro;
  while(proximoCliente->preenchido==1){
    proximoCliente=proximoCliente->proximoCliente;
  }
  
  long int codigo;
  long int cpf;
  printf("Digite o nome do cliente a ser cadastrado\n");
  scanf(" %[^\n]s%*c ",proximoCliente->nome);
  printf("Digite um código de segurança\n");
  scanf(" %ld",&codigo);
  proximoCliente->codigo = codigoGlobal;
  codigoGlobal++;
  ValidaCodigo(codigo, primeiro, proximoCliente);
  printf("Digite o CPF do titular\n");
  scanf(" %ld",&cpf);
  ValidaCPF(cpf, primeiro, proximoCliente);
  printf("Digite o endereço\n");
  scanf(" %[^\n]s%*c",proximoCliente->endereco);
  proximoCliente->preenchido=1;
  totalDeClientes++;
  proximoCliente->proximoCliente = (clientes*) malloc(sizeof(clientes));
  proximoCliente = proximoCliente->proximoCliente;
}

void listarClientes(clientes *primeiro, clientes *proximoCliente){
  proximoCliente = primeiro;
  do{
    printf("%s\n",proximoCliente->nome);
    if(proximoCliente->preenchido==1)
    proximoCliente = proximoCliente->proximoCliente;
  }
  while(proximoCliente->preenchido==1);
  printf("\n");
}

void buscaCliente(clientes *primeiro, clientes *proximoCliente){
  long int code;
  printf("Digite o código do cliente pelo qual deseja buscar\n");
  scanf("%ld",&code);
  proximoCliente = primeiro;
  while(proximoCliente->preenchido==1){
    if(proximoCliente->codigo==code){
      printf("Cliente encontrado:\n");
      printf("Nome: %s\n", proximoCliente->nome);
      printf("CPF: %ld\n", proximoCliente->cpf);
      printf("Código: %ld\n", proximoCliente->codigo);
      printf("Endereço: %s\n\n",proximoCliente->endereco);
      return;
    }
    else
    proximoCliente = proximoCliente->proximoCliente;
  }
  printf("Cliente não encontrado\n");
}

void AtualizaCliente(clientes *primeiro, clientes *proximoCliente){
  int codigo;
  proximoCliente=primeiro;
  printf("Digite o código do cliente que deseja buscar\n");
  scanf("%d",&codigo);
  while(proximoCliente->preenchido==1){
    if(proximoCliente->codigo==codigo){
      int resposta=0;
      printf("1 - Alterar nome\n");
      printf("2 - Alterar codigo\n");
      printf("3 - Alterar cpf\n");
      printf("4 - Alterar endereço\n");
      scanf("%d",&resposta);
      if(resposta==1){
        printf("Digite o nome atualizado do cliente\n");
        scanf(" %[^\n]s%*c",proximoCliente->nome);
        printf("Dado atualizado\n");
        return;
      }
      if(resposta==2){
        long int codigo;
        clientes *referencia = proximoCliente;
        printf("Digite o novo código\n");
        scanf("%ld",&codigo);
         ValidaCodigo2(codigo,primeiro,proximoCliente,referencia);
        referencia->codigo=codigo;
        return;
      }
      if(resposta==3){
        long int CPF;
        clientes *referencia = proximoCliente;
        printf("Digite o CPF atualizado do cliente\n");
        scanf("%ld",&CPF);
        ValidaCPF2(CPF,primeiro,proximoCliente,referencia);
        referencia->cpf=CPF;
        return;
      }
      if(resposta==4){
        printf("Digite o novo endereço\n");
        scanf("%[^\n]s%*c",proximoCliente->endereco);
        printf("Dado atualizado\n");
        return;
      }
    }
    else{
      proximoCliente=proximoCliente->proximoCliente;
    }
  }
  printf("Cliente não encontrado\n");
}

int ExcluirCliente(clientes *primeiro,clientes *proximoCliente){
  int contador=0;
  long int codigo;
  proximoCliente=primeiro;

  printf("digite o código do cliente que deseja excluir\n");
  scanf("%ld",&codigo);

  while(proximoCliente->preenchido==1){
    if(proximoCliente->codigo==codigo && contador==0){
      printf("Cliente %s excluído\n", proximoCliente->nome);
      return 1;
    }
    else if(proximoCliente->proximoCliente->codigo==codigo && contador<totalDeClientes){
      printf("Cliente %s excluído\n", proximoCliente->nome);
      proximoCliente->proximoCliente=proximoCliente->proximoCliente->proximoCliente;
      return 2;
    }
    else if(proximoCliente->proximoCliente->codigo==codigo && proximoCliente->proximoCliente->preenchido==0)
    {
      printf("Cliente %s excluído\n", proximoCliente->proximoCliente->nome);
      proximoCliente=(clientes*) malloc(sizeof(clientes));
      return 3;
    } 
    else{
      proximoCliente=proximoCliente->proximoCliente;
      printf("aqui2\n");
    }
    contador++;
  }
  return 4;
}

void CadastrarConta(clientes *primeiro, clientes *proximoCliente, contas *primeira, contas *proximaConta){
  long int CPF;
  long int conta;
  int ag=0;
  printf("Digite seu cpf:\n");
  scanf("%ld",&CPF);
  printf("\n");

  proximoCliente=primeiro;
  proximaConta=primeira;

  while(proximaConta->preenchido==1){
    proximaConta=proximaConta->proximaConta;
  }

  while(proximoCliente->preenchido==1){
    if(proximoCliente->cpf==CPF){
      printf("Cliente encontrado:\n");
      printf("Nome: %s\n", proximoCliente->nome);
      printf("CPF: %ld\n", proximoCliente->cpf);
      printf("Código: %ld\n\n", proximoCliente->codigo);
      
      printf("Escolha uma das agências a seguir:\n");
      printf("1 - 1701\n");
      printf("2 - 2702\n");
      printf("3 - 3709\n");
      printf("4 - 4704\n\n");
      scanf("%d",&ag);
      printf("\n");
      while(ag!=1 && ag!=2 && ag!=3 && ag!=4){      
        printf("Escolha inválida, tente novamente.\n");
        scanf("%d",&ag);
        printf("\n");
      }
      if(ag==1){
        proximaConta->ag=1701;
        proximaConta->preenchido=1;
        proximaConta->saldo=0;
        totalDeContas++;
        strcpy(proximaConta->nome,proximoCliente->nome);
        proximaConta->cpf=proximoCliente->cpf;
        proximaConta->proximaConta= (contas*) malloc(sizeof(contas));
      }
      if(ag==2){
        proximaConta->ag=2702;
        proximaConta->preenchido=1;
        proximaConta->saldo=0;
        totalDeContas++;
        strcpy(proximaConta->nome,proximoCliente->nome);
        proximaConta->cpf=proximoCliente->cpf;
        proximaConta->proximaConta= (contas*) malloc(sizeof(contas));
      }
      if(ag==3){
        proximaConta->ag=3709;
        proximaConta->preenchido=1;
        proximaConta->saldo=0;
        totalDeContas++;
        strcpy(proximaConta->nome,proximoCliente->nome);
        proximaConta->cpf=proximoCliente->cpf;
        proximaConta->proximaConta= (contas*) malloc(sizeof(contas));
      }
      if(ag==4){
        proximaConta->ag=4704;
        proximaConta->preenchido=1;
        proximaConta->saldo=0;
        totalDeContas++;
        strcpy(proximaConta->nome,proximoCliente->nome);
        proximaConta->cpf=proximoCliente->cpf;
        proximaConta->proximaConta= (contas*) malloc(sizeof(contas));
      }
      printf("Digite o número da sua conta\n");
      scanf("%ld",&conta);
      proximaConta->conta=ValidaConta(conta, primeira);
      printf("\n");
      printf("Conta criada com sucesso!!\n\n");
      return;
    }
    else{
      proximoCliente = proximoCliente->proximoCliente;
    }
  }
  printf("Cliente não encontrado. Realize o cadastro antes de abrir uma conta\n\n");
}

void BuscarConta(contas *primeira, contas *proximaConta){
  long int cpf;
  printf("Digite o cpf do cliente pelo qual deseja buscar\n");
  scanf("%ld",&cpf);
  printf("\n");
  proximaConta = primeira;
  while(proximaConta->preenchido==1){
    if(proximaConta->cpf==cpf){
      printf("Conta encontrada:\n");
      printf("Nome: %s\n", proximaConta->nome);
      printf("CPF: %ld\n", proximaConta->cpf);
      printf("Agência: %ld\n", proximaConta->ag);
      printf("Conta: %ld\n", proximaConta->conta);
      printf("Saldo: R$%.2Lf\n\n",proximaConta->saldo);
      proximaConta=proximaConta->proximaConta;
    }
    else if(proximaConta->cpf!=cpf && proximaConta->preenchido!=0){
      proximaConta = proximaConta->proximaConta; 
    }
    else{
      printf("Cliente não encontrado\n");
    }
  }
}

void ListarContas(contas *primeira, contas *proximaConta){
  proximaConta=primeira;

  while(proximaConta->preenchido==1){
    printf("Cliente: %s\nAgência: %ld\nNúmero da conta: %ld\n\n",proximaConta->nome,proximaConta->ag,proximaConta->conta);
    proximaConta=proximaConta->proximaConta;
  }
}

int ExcluirConta(contas *primeira){
  contas *proximaConta = primeira;
  long int conta;
  int contador=0;
  printf("Digite o número da conta que deseja excluir\n");
  scanf("%ld",&conta);

  while(proximaConta->preenchido==1){
    if(proximaConta->conta==conta && contador==0){
      printf("Conta %ld excluída\n",proximaConta->conta);
      return 1;
    }
    else if(proximaConta->proximaConta->conta==conta && contador<totalDeContas){
      printf("Conta %ld excluída\n", proximaConta->proximaConta->conta);
      proximaConta->proximaConta=proximaConta->proximaConta->proximaConta;
      return 2;
    }
    else if(proximaConta->proximaConta->conta==conta && proximaConta->proximaConta->preenchido==0)
    {
      printf("Conta %ld excluída\n", proximaConta->proximaConta->conta);
      proximaConta=(contas*) malloc(sizeof(contas));
      return 3;
    } 
    else{
      proximaConta=proximaConta->proximaConta;
    }
    contador++;
  }
  printf("Conta não encontrada\n");
  return 0;
}

void Transferencia(contas *primeira, contas *proximaConta){
  contas *referencia = proximaConta;
  proximaConta=primeira;
  long double valor;
  long int ag2,conta2;

  printf("Digite a agencia da conta destino:\n");
  scanf("%ld",&ag2);
  printf("Digite o número da conta destino:\n");
  scanf("%ld",&conta2);

  while(proximaConta->preenchido==1){
    if(proximaConta->ag==ag2 && proximaConta->conta==conta2 && proximaConta!=referencia){
      printf("Digite o valor que deseja tranferir:\n");
      scanf("%Lf",&valor);

      while(valor>referencia->saldo){
        printf("Valor inválido. Tente novamente.\nSaldo R$%.2Lf\n",referencia->saldo);
        scanf("%Lf",&valor);
      }

      referencia->saldo-=valor;
      proximaConta->saldo+=valor;
      printf("Transferência realizada.\n");
      return;
    }
    else{
      proximaConta=proximaConta->proximaConta;
    }
  }
  printf("Conta não encontrada ou a ação que deseja fazer não é possível.\n");
}

void Transacao(contas *primeira){
  contas *proximaConta = primeira;
  int resposta;
  long double valor;
  long int conta,ag,conta2,ag2;
  
  printf("1 - Realizar Saque\n");
  printf("2 - Realizar Transferência\n");
  printf("3 - Realizar Depósito\n");
  scanf("%d",&resposta);

  printf("Digite o número da agência:\n");
  scanf("%ld",&ag);
  printf("Digite o número da conta:\n");
  scanf("%ld",&conta);
  
  while(proximaConta->preenchido==1){
    if(proximaConta->ag==ag && proximaConta->conta==conta){
      if(resposta==1){
        if(proximaConta->saldo==0){
          printf("Não é possível realizar essa ação.\nSaldo: R$%.2Lf\n",proximaConta->saldo);
        }
        else{
          printf("Digite o valor para saque:\n");
          scanf("%Lf",&valor);
          while(valor>proximaConta->saldo){
            printf("Saldo insuficiente.\n Tente novamente.\nSaldo: R$%.2Lf\n",proximaConta->saldo);
            scanf("%Lf",&valor);
          }
          proximaConta->saldo -= valor;
          printf("Saque realizado com sucesso.\nSaldo: R$%.2Lf\n\n",proximaConta->saldo);
        }
        return;
      }
      if(resposta==2){
        Transferencia(primeira,proximaConta);
        return;
      }
      if(resposta==3){
        printf("Digite o valor que deseja depositar:\n");
        scanf("%Lf",&valor);
        while(valor<0){
          printf("Valor inválido.\nTente novamente.\n");
          scanf("%Lf",&valor);
        }
        proximaConta->saldo+=valor;
        printf("Depósito realizado com sucesso.\nSaldo: R$%.2Lf\n\n",proximaConta->saldo);
        return;
      }
    }
    else{
      proximaConta=proximaConta->proximaConta;
    }
    printf("Conta não encontrada.\n");
  }
}


int main(){
  clientes *primeiro = (clientes*) malloc(sizeof(clientes));
  clientes *proximoCliente = primeiro;
  primeiro->preenchido=0;

  contas *primeira = (contas*) malloc(sizeof(contas));
  contas *proximaConta = primeira;
  primeira->preenchido=0;
  
  menu1();
  while(resposta != 3){
    if(resposta==1){
      menu2();
      if(resposta2 ==1){
        CadastroCliente(primeiro,proximoCliente);
      }
      else if(resposta2==2){
        buscaCliente(primeiro,proximoCliente);
      }
      else if(resposta2==3){
        listarClientes(primeiro, proximoCliente);
      }
      else if(resposta2==4){
        AtualizaCliente(primeiro,proximoCliente);
      }
      else if(resposta2==5){
       int a= ExcluirCliente(primeiro,proximoCliente);
        if(a==1){
          primeiro=proximoCliente->proximoCliente;
        }
      }
      else if(resposta2==6){
        menu1();
      }
    }
    if(resposta==2){
      menu3();
      if(resposta2==1){
          CadastrarConta(primeiro, proximoCliente, primeira, proximaConta);
        }
      else if(resposta2==2){
        BuscarConta(primeira, proximaConta);
      }
      else if(resposta2==3){
        ListarContas(primeira, proximaConta);
      }
      else if(resposta2==4){
        int a = ExcluirConta(primeira);
        if(a==1){
          primeira=proximaConta->proximaConta;
        }
      }
      else if(resposta2==5){
        Transacao(primeira);
      }
      else if(resposta2==6){
        menu1();
      }
    }
  }

  printf("Programa encerrado.\n");
 
  return 0;
}