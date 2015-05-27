#include <stdio.h>
#include <stdlib.h>

typedef struct s_elemento{
    int v;
    struct s_elemento* next;
}elemento;

elemento* aggiungiElementoDiTesta(elemento*);
void StampaLista(elemento*);
void SvuotaLista(elemento*);

int main(int argc, char** argv) {
    elemento* primo=NULL;
    char ctrl[2]="1";
    
    while(strcmp(ctrl,"0")){
        primo=aggiungiElementoDiTesta(primo);
        if(primo==NULL){
            fprintf(stderr,"Errore durante l'aggiunta di un elemento");
            exit(1);
        }
        printf("Vuoi aggiungere altri elementi alla lista? (1/0): ");
        scanf("%s",ctrl);
        printf("\n");
    }
    
    StampaLista(primo);
    
    SvuotaLista(primo);
    

    return (EXIT_SUCCESS);
}

elemento* aggiungiElementoDiTesta(elemento* testa){
   elemento* temp=NULL;
   temp=(elemento*)malloc(sizeof(elemento));
   
   if(temp==NULL){
        fprintf(stderr,"Errore durante l'aggiunta di un elemento");
        return NULL;
   }
   
   printf("Inserisci il valore: ");
   scanf("%d",&(temp->v));   
   temp->next=testa;
   testa=temp;
   
   return testa;
}

void StampaLista(elemento* testa){
    int i=1;
    elemento* temp;
    
    while(testa){
        printf("%d° valore: %d\n",i,testa->v);        
        testa=testa->next;        
        i++;
    }
}

void SvuotaLista(elemento* testa){
    elemento* temp=NULL;
    
    while(testa){
        temp=testa->next;
        free(testa);
        testa=temp;
    }
}