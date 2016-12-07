#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "grafo.cpp"

int main(){
      int i,j,x,valida[10];
       
      int resp;
      char aux [10];
      char pesquisa [40];
      int opcao, result;
      int cont;
      char vai[40];
      char volta[40];
      char amizade1[10][40];
      char amizade2[10][40];
      int viagem;
      int num[10];
      int edita;
      int quantidade; 
      int invalido;
      char c,sn[1];     
      char nome[10][40],nomedit[40],generoc[2],genero[10][10],escolaridade[10][50],interesse[10][20][200];
      int idade[10],op,pos=1;     
      int interesses,contai;       
            result = 0;
            quantidade = 0;
            viagem = 0;
            resp = 1;
            opcao = 0;
            cont = 0;
     
       
    for (i =1; i<=10; i++){
        fflush(stdin);
        strcpy(nome[i], " - ");
        strcpy(amizade1[i], " - ");
        strcpy(amizade2[i], " - ");
        num[i] = 0;
        valida[i] = i;
    }
       

    inicio:
    while (resp == 1)  { 
        menu();
        scanf("%d",&opcao); 
        invalido = 0;
        for (i=1; i<=10; i++){
            if (opcao != valida[i]){
                invalido++;
            }
            if (invalido == 10){
                display_opcao_invalida();
                c = getchar();
                scanf("%c",&c);                               
            }
        }             
              
        switch (opcao){
            case 1:

                system("clear");
                void display_cria_pessoa();
                printf("\nDigite o nome: ");
                scanf(" %[^\n]s",nome[pos]);
                printf("\nGênero [M ou F]: ");
                scanf("%s", generoc);

                while(generoc[0] != 'm' && generoc[0] != 'f' && generoc[0] != 'M' && generoc[0] != 'F'){
            
                    printf("Caracter incorreto! Digite novamente: ");
                    scanf("%s", generoc);
        
                }
      
                if(generoc[0] == 'm' || generoc[0] == 'M')
                    strcpy(genero[pos],"Masculino");
                if(generoc[0] == 'f' || generoc[0] == 'F')
                    strcpy(genero[pos],"Feminino");
                    printf("\nDigite a idade: ");
                    scanf("%d", &idade[pos]);

                do{

                    printf("\nEscolha o grau de escolaridade:\n");
                    printf("[1] Primeiro grau incompleto\n");
                    printf("[2] Primeiro grau completo\n");
                    printf("[3] Segundo grau incompleto\n");
                    printf("[4] Segundo grau completo\n");
                    printf("[5] Superior incompleto\n");
                    printf("[6] Superior completo\n");
                    printf("[7] Pós-graduação\n");
                    printf("Digite: ");
                    scanf("%d", &op);
                    if(op==1)
                        strcpy(escolaridade[pos],"Primeiro grau incompleto");
                    if(op==2)
                        strcpy(escolaridade[pos],"Primeiro grau completo");
                    if(op==3)
                        strcpy(escolaridade[pos],"Segundo grau incompleto");
                    if(op==4)
                        strcpy(escolaridade[pos],"Segundo grau completo");
                    if(op==5)
                        strcpy(escolaridade[pos],"Superior incompleto");
                    if(op==6)
                        strcpy(escolaridade[pos],"Superior completo");
                    if(op==7)
                        strcpy(escolaridade[pos],"Pós-graduação");
                    if(op<=0 || op>7)
                        printf("Opção incorreta! Digite novamente.");
                }while(op<=0 || op>7);

                sn[0]='s';
                printf("\nDigite no máximo 20 interesses :\n");
                interesses=1;
                contai=20; 

                do{

                    if(sn[0]=='s' && interesses<=20){
                        printf("Digite o interesse %d: ",interesses);
                        scanf(" %[^\n]s",interesse[pos][interesses]);
                        contai--;
                        printf("Inserir outro interesse? [s][n] (%d interesses restantes): ",contai);
                        scanf("%s",sn);
                    if(sn[0]=='s')
                        interesses++;
                    }

                }while(sn[0]=='s' && interesses<=20);


                printf("                  CADASTRO                   \n");
                system("clear");
                printf("Nome:\t\t%s\n",nome[pos]);
                printf("Gênero:\t\t%s\n",genero[pos]);
                printf("Idade:\t\t%d\n",idade[pos]);
                printf("Escolaridade:\t%s\n",escolaridade[pos]);
                printf("Interesses:\t");
                for(x=1;x<=interesses;x++){
                    if (x<interesses && interesses!=x)
                        printf("%s, ",interesse[pos][x]);
                    if (x==interesses)
                        printf("%s\n",interesse[pos][x]);
                }

            printf("\n                   PRESSIONE QUALQUER TECLA PARA CONTINUAR                   ");
            c = getchar();
            scanf("%c",&c);
            pos++;     
             
        break;
                     
        case 2:
                  editar:
                          system("clear");
                         
                    printf("\n _____________________________________________________________________________");
                          printf("\n|                      VOCE ESCOLHEU EDITAR UMA PESSOA!                       |");
                          printf("\n|_____________________________________________________________________________|\n\n");
                          printf("\n\n\t\t        LISTA DE PESSOAS CADASTRADAS\n");
                          printf("\t\t___________________________________________\n");
                          printf("\t\t PESSOA\n");
                    for (i=1; i<=10; i++){
                               printf("\t\t %s\n",nome[i]); 
                          }
                          printf("\n     >> INDIQUE O NOME DA PESSOA QUE DESEJA EDITAR: ");
                          scanf(" %[^\n]s",nomedit);
                  x=0; 
                  for (i=1; i<=10; i++){
                              if(strcmp (nomedit, nome[i])==0)
                              x=i; 
                          }
                        if (x==0){

                                     printf("\n _____________________________________________________________________________");
                                     printf("\n|   IMPOSSIVEL INSERIR NOVA PESSOA, A PESSOA INFORMADA NAO ESTA CADASTRADA!   |");
                                     printf("\n|                   PRESSIONE UMA TECLA E TENTE NOVAMENTE                     |");
                                     printf("\n|_____________________________________________________________________________|\n");
                                                                         c=getchar();
                      scanf("%c",&c);                 
                                               goto editar;

                  }     

                        else{
                          printf("\n     >> VOCE ESCOLHEU EDITAR %s",nome[x]);
                          printf("\n     >> AGORA ENTRE COM O NOVO NOME: ");
                          scanf(" %[^\n]s", nome[x]);
                          
                          printf("\n _____________________________________________________________________________");
                          printf("\n|                     O NOME FOI ALTERADO COM SUCESSO!                      |");
                          printf("\n|                   PRESSIONE QUALQUER TECLA PARA CONTINUAR                   |");
                          printf("\n|_____________________________________________________________________________|\n");
                                                    c=getchar();
                      scanf("%c",&c);}                  
                     break;
                     
                     case 3:
                          system("clear");
                          printf("\n _____________________________________________________________________________");
                          printf("\n|                VOCE ESCOLHEU EXIBIR AS PESSOAS CADASTRADAS                  |");
                          printf("\n|_____________________________________________________________________________|\n");
                          
                          printf("\n\n\t\t        LISTA DE PESSOAS CADASTRADAS\n");
                          printf("\t\t___________________________________________\n");
                          printf("\t\t PESSOA\n");
                  for (i=1; i<=10; i++){
                               printf("\t\t %s\n",nome[i]); 
                          }

                          printf("\n _____________________________________________________________________________");
                          printf("\n|                     VISUALIZACAO EFETUADA COM SUCESSO!                      |");
                          printf("\n|                   PRESSIONE QUALQUER TECLA PARA CONTINUAR                   |");
                          printf("\n|_____________________________________________________________________________|\n");
                          c=getchar();
                      scanf("%c",&c);                  
                     break;                    
                     
                     case 4:
                           if (cont < 2){
                                printf("\n _____________________________________________________________________________");
                                printf("\n| IMPOSSIVEL INSERIR AMIZADE, DEVE HAVER PELO MENOS 2 PESSOAS CADASTRADAS     |");
                                printf("\n|                   PRESSIONE QUALQUER TECLA PARA CONTINUAR                   |");
                                printf("\n|_____________________________________________________________________________|\n");
                                                          c=getchar();
                      scanf("%c",&c);                
                           }
                           else{             
                                invalido:
                                system("clear");
                                printf("\n _____________________________________________________________________________");
                                printf("\n|                   VOCE ESCOLHEU INSERIR UMA AMIZADE                         |");
                                printf("\n|_____________________________________________________________________________|\n\n");
                                printf("\n\n\t\t        LISTA DE PESSOAS CADASTRADAS\n");
                                printf("\t\t___________________________________________\n\n");
                                printf("\t\t PESSOA\n");
                    for (i=1; i<=10; i++){
                               printf("\t\t %s\n",nome[i]); 
                          }
                                printf("\n     >> ENTRE COM A PESSOA A RECEBER A AMIZADE: ");
                                scanf(" %[^\n]s", vai);
                                
                                strcpy(amizade1[viagem] , vai);
                                for (i=1; i<=10; i++){
                                     if (strcmp (vai, nome[i])==0){
                                          i = 10;
                                     }
                                     else{
                                          if (i == 9){
                                               printf("\n _____________________________________________________________________________");
                                               printf("\n|   IMPOSSIVEL INSERIR AMIZADE , A PESSOA INFORMADA NAO ESTA CADASTRADA!      |");
                                               printf("\n|                   PRESSIONE UMA TECLA E TENTE NOVAMENTE                     |");
                                               printf("\n|_____________________________________________________________________________|\n");
                                                                         c=getchar();
                      scanf("%c",&c);                 
                                               goto invalido;
                                          }
                                     }
                                }    
                                                             
                                printf("\n     >> AGORA, ENTRE COM A PESSOA QUE SERA A AMIZADE: ");
                                scanf(" %[^\n]s", volta);
                                
                                strcpy(amizade2[viagem] , volta);
                                for (i=1; i<=10; i++){
                                     if (strcmp (volta, nome[i])==0){
                                          i = 10;
                                     }
                                     else{
                                          if (i == 9){
                                               printf("\n _____________________________________________________________________________");
                                               printf("\n|   IMPOSSIVEL INSERIR AMIZADE, A PESSOA INFORMADA NAO ESTA CADASTRADA!       |");
                                               printf("\n|                   PRESSIONE UMA TECLA E TENTE NOVAMENTE                     |");
                                               printf("\n|_____________________________________________________________________________|\n");
                                                                         c=getchar();
                      scanf("%c",&c);                
                                               goto invalido;
                                          }
                                     }
                                }
                                
                               
                                viagem ++;
                                                          
                           }                                 
                     break;
                     
                     case 5:
                           if (cont < 2){
                                printf("\n _____________________________________________________________________________");
                                printf("\n| IMPOSSIVEL INSERIR AMIZADE , DEVE HAVER PELO MENOS 2 PESSOAS CADASTRADAS    |");
                                printf("\n|                   PRESSIONE QUALQUER TECLA PARA CONTINUAR                   |");
                                printf("\n|_____________________________________________________________________________|\n");
                                                          c=getchar();
                      scanf("%c",&c);                 
                           }
                           else{
                                system("clear");
                                printf("\n _____________________________________________________________________________");
                                printf("\n|                   VOCE ESCOLHEU EDITAR UMA AMIZADE !                        |");
                                printf("\n|_____________________________________________________________________________|\n\n");
                                printf("\n\t\t        LISTA DAS AMIZADES CADASTRADAS\n");
                                printf("\t\t___________________________________________\n");
                                for (i=1; i<=10; i++){
                                     printf("\t\t CONTROLE >> %d\t\t\tAMIZADE >> %d\n\t\t\t\tAMIZADE1  >> %s\n\t\t\t\tAMIZADE2  >> %s\n",1,num[i],amizade1[i],amizade2[i]);
                                     printf("\n\t\t___________________________________________\n");
                                }
                                printf("\n\n     >> INFORME O CONTROLE DA AMIZADE A SER EDITADO: ");  
                                scanf("%d",&edita);
                                printf("\n     >> VOCE ESCOLHEU EDITAR O AMIZADE: %d",num[edita-1]);
                                
                                edite:
                                printf("\n\n     >> ENTRE COM O NOME DA PESSOA QUE RECEBERÁ A AMIZADE: ");
                                scanf(" %[^\n]s", vai);
                                
                                strcpy(amizade1[edita-1] , vai);
                                for (i=1; i<=10; i++){
                                     if (strcmp (vai, nome[i])==0){
                                          i = 10;
                                     }
                                     else{
                                          if (i == 9){
                                               printf("\n _____________________________________________________________________________");
                                               printf("\n|   IMPOSSIVEL INSERIR AMIZADE , A PESSOA INFORMADA NAO ESTA CADASTRADA!   |");
                                               printf("\n|                   PRESSIONE UMA TECLA E TENTE NOVAMENTE                     |");
                                               printf("\n|_____________________________________________________________________________|\n");
                                                                         c=getchar();
                      scanf("%c",&c);                
                                               goto edite;
                                          }
                                     }
                                }    
                                                             
                                printf("\n     >> AGORA, ENTRE COM A NOVA AMIZADE: ");
                                scanf(" %[^\n]s", volta);
                                
                                strcpy(amizade2[edita-1] , volta);
                                for (i=1; i<=10; i++){
                                     if (strcmp (volta, nome[i])==0){
                                          i = 10;
                                     }
                                     else{
                                          if (i == 9){
                                               printf("\n _____________________________________________________________________________");
                                               printf("\n|   IMPOSSIVEL INSERIR AMIZADE , A PESSOA INFORMADA NAO ESTA CADASTRADA!   |");
                                               printf("\n|                   PRESSIONE UMA TECLA E TENTE NOVAMENTE                     |");
                                               printf("\n|_____________________________________________________________________________|\n");
                                                                         c=getchar();
                      scanf("%c",&c);                 
                                               goto edite;
                                          }
                                     }
                                }
                                
                                printf("\n     >> POR FIM, INFORME O NOVO NUMERO DA AMIZADE: ");                     
                                scanf("%d",&num[edita-1]);
                                printf("\n _____________________________________________________________________________");
                                printf("\n|                       AMIZADE  EDITADA COM SUCESSO!                      |");
                                printf("\n|                   PRESSIONE QUALQUER TECLA PARA CONTINUAR                   |");
                                printf("\n|_____________________________________________________________________________|\n");
                                                          c=getchar();
                      scanf("%c",&c);               
                         
                         }                        
                         
                     break;
                     
                     case 6:
                           system("clear");
                           printf("\n _____________________________________________________________________________");
                           printf("\n|                  VOCE ESCOLHEU VISUALIZAR AS AMIZADES !                  |");
                           printf("\n|_____________________________________________________________________________|\n\n");
                           printf("\n\t\t        LISTA DAS AMIZADES CADASTRADAS\n");
                           printf("\t\t___________________________________________\n\n");
                           for (i=1; i<=10; i++){
                                printf("\t\t CONTROLE >> %d\t\t\tAMIZADE >> %d\n\t\t\t\tAMIZADE1  >> %s\n\t\t\t\tAMIZADE2  >> %s\n",1,num[i],amizade1[i],amizade2[i]);
                                printf("\n\t\t___________________________________________\n\n");
                           }
                           printf("\n _____________________________________________________________________________");
                           printf("\n|                   AS AMIZADE FORAM VISUALIZADAS COM SUCESSO!                   |");
                           printf("\n|                   PRESSIONE QUALQUER TECLA PARA CONTINUAR                   |");
                           printf("\n|_____________________________________________________________________________|\n");
                                                     c=getchar();
                      scanf("%c",&c);               
                     break;
                     
                    case 7:
                          result = 0;
                          if (cont < 2){
                                printf("\n _____________________________________________________________________________");
                                printf("\n|  IMPOSSIVEL BUSCAR AMIZADE , DEVE HAVER PELO MENOS 2 PESSOAS CADASTRADAS    |");
                                printf("\n|                   PRESSIONE QUALQUER TECLA PARA CONTINUAR                   |");
                                printf("\n|_____________________________________________________________________________|\n");
                                                          c=getchar();
                      scanf("%c",&c);                 
                          }
                          else{
                               system("clear");
                               printf("\n _____________________________________________________________________________");
                               printf("\n|                VOCE ESCOLHEU BUSCAR UMA AMIZADE POR NOME                 |");
                               printf("\n|_____________________________________________________________________________|\n\n");
                               printf("\n\n\t\t        LISTA DAS AMIZADES CADASTRADAS\n");
                               printf("\t\t___________________________________________\n\n");
                               for (i=1; i<=10; i++){
                                    printf("\t\t NUMERO >> %d\t\t\tNOME >> %s\n",1,nome[i]);
                                    printf("\n\t\t___________________________________________\n\n");  
                               }
                             printf("\n     >> AGORA, ENTRE COM O NUMERO DA NOME A SER BUSCADA NAS AMIZADES: ");                           
                               scanf(" %[^\n]s", pesquisa);
                                
                               printf("\n\n\t\t LISTA DAS AMIZADES CADASTRADAS PARA A PESSOA\n");
                               printf("\t\t___________________________________________\n");                         
                               for (i=1; i<=10; i++){                            
                                   if (strcmp (pesquisa, amizade1[i])==0){                                   
                                        printf("\t\t CONTROLE >> %d\t\t\tAMIZADE >> %d\n\t\t\t\tAMIZADE1  >> %s\n\t\t\t\tAMIZADE2  >> %s\n",1,num[i],amizade1[i],amizade2[i]);
                                        printf("\n\t\t___________________________________________\n\n");                              
                                        quantidade++;
                                        result = 1;
                                   }                                  
                                   if (strcmp (pesquisa, amizade2[i])==0){                                  
                                        printf("\t\t CONTROLE >> %d\t\t\tAMIZADE >> %d\n\t\t\t\tAMIZADE1  >> %s\n\t\t\t\tAMIZADE2  >> %s\n",1,num[i],amizade1[i],amizade2[i]);
                                        printf("\n\t\t___________________________________________\n\n");                              
                                        quantidade++;
                                        result = 1;                                  
                                   } 
                                   if ((i == 9)&&(result!= 1)){
                                        printf("\n\t\t                -  ZERO  -                 \n"); 
                                        printf("\n\t\t NAO HA REGISTROS CADASTRADOS PARA ESSE NOME\n\n\n");
                                   }           
                               } 
                                           
                               printf("\n _____________________________________________________________________________");
                               printf("\n|    BUSCAS REALIZADAS COM SUCESSO!                                           |");
                               printf("\n|                   PRESSIONE QUALQUER TECLA PARA CONTINUAR                   |");
                               printf("\n|_____________________________________________________________________________|\n");
                                                         c=getchar();
                      scanf("%c",&c);               
                          }
                     break;
                     
                     case 8:
                          fim();
                          resp = 2;
                                                    c=getchar();
                      scanf("%c",&c);               
                     break;
                           
                     
                     
                    
                     
                     
                     
                     
                }  
                 
       }
       return 0;     
}
