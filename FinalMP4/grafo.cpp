#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "grafo.h"


      
void menu(){
       system("clear");
       printf(" _____________________________________________________________________________\n");
       printf("|                                                                             |\n"); 
       printf("|                                                                             |\n");             
       printf("|                         |------- M E N U -------|                           |\n");
       printf("|                         |_______________________|                           |\n");
       printf("|                         | 1 - CRIAR PESSOA      |                           |\n");
       printf("|                      ADM| 2 - EDITAR PESSOAS    |                           |\n");
       printf("|                      ADM| 3 - EXIBIR PESSOAS    |                           |\n");
       printf("|                      ADM| 4 - INSERIR AMIZADE   |                           |\n");
       printf("|                      ADM| 5 - EDITAR  AMIZADE   |                           |\n");
       printf("|                      ADM| 6 - EXIBIR AMIZADE    |                           |\n");
       printf("|                      ADM| 7 - BUSCAR AMIZADE    |                           |\n");
       printf("|                         | 8- FINALIZAR          |                           |\n");              
       printf("|                         |_______________________|                           |\n");
       printf("|                                                                             |\n");
       printf("|                                                                             |\n");
       printf("|_____________________________________________________________________________|\n");              
       printf("                             INFORME SUA OPCAO: ");
}

void fim(){
      printf("\n _____________________________________________________________________________");
      printf("\n|                     VOCE OPTOU POR FINALIZAR O PROGRAMA!                    |");
      printf("\n|                      PRESSIONE QUALQUER TECLA PARA SAIR                     |");
      printf("\n|_____________________________________________________________________________|\n");
}

void display_opcao_invalida(){
      printf("\n _____________________________________________________________________________");
      printf("\n|                       OPCAO INVALIDA! TENTE NOVAMENTE                       |");
      printf("\n|                   PRESSIONE QUALQUER TECLA PARA CONTINUAR                   |");
      printf("\n|_____________________________________________________________________________|\n");
}

void display_cria_pessoa(){
      printf(" _____________________________________________________________________________\n");
      printf("|                                CRIAR PESSOA                                 |\n");
      printf("|_____________________________________________________________________________|\n");
}

void display_editar_uma_pessoa1(){
      printf("\n _____________________________________________________________________________");
      printf("\n|                      VOCE ESCOLHEU EDITAR UMA PESSOA!                       |");
      printf("\n|_____________________________________________________________________________|\n\n");
      printf("\n\n\t\t        LISTA DE PESSOAS CADASTRADAS\n");
      printf("\t\t___________________________________________\n");
      printf("\t\t PESSOA\n");
}

void display_impossivel_inserir(){

      printf("\n _____________________________________________________________________________");
      printf("\n|   IMPOSSIVEL INSERIR NOVA PESSOA, A PESSOA INFORMADA NAO ESTA CADASTRADA!   |");
      printf("\n|                   PRESSIONE UMA TECLA E TENTE NOVAMENTE                     |");
      printf("\n|_____________________________________________________________________________|\n");
}