/* Bu projeyi yaparken veri yap�lar� olarak ba�l� listeleri kulland�m. Olu�turdu�um ba�l� listeyi hem �ift y�nl� hemde dairesel �ekilde tasarlad�m.
	Bu sayede �ark�lar �zerinde dola�abilecek bir �ark�dan di�er �ark�ya ge�i� yapabilecek ve istendi�i zaman bi �nceki �nceki �ark�lara geriye giderek
	ula��labilecek. Olu�turulan �ark� listesine �ark� ekleme i�lemlerini  list * insertSong fonksiyonunda yap�yorum. Bu fonksiyon geriye list * tipinde 
	de�er d�nd�r�yor. Bu sayede her ekleme i�leminde �ark� isteme �ark� ekleyebiliyorum. �ark� silme i�lemlerimi list *removeSong fonksiyonunda yap�yorum.
	Bu fonksiyonda geriye list * tipinde de�er d�nd�r�yor. Bu sayede �ark� listesindeki istenen �ark�y� silip yeni �ark� listesini �nceki �ark� listesine at�yorum.
	�ark� yerlerini de�i�tirme i�lemimi list *moveSong fonksiyonunda yap�yorum. Bu fonksiyonun i�inde silme fonksiyonu olan removeSong u da kulland�m.
	�ark�lar �zerinde ileri geri dola�ma ve hangi �ark�n�n �ald���n� belirleme i�lemimi list *playSong fonksiyonunda yap�yorum. �ark� listesindeki �ark�lar� g�r�nt�leme,
	bast�rma i�lemini void printPlayList fonksiyonunda yap�yorum. Son olarak �ark� listesini ters �evirme i�lemini list *reversePlayList fonksiyonunda yap�yorum.
	Bizden istenen her �eyi istenen formatta yapm�� bulunmaktay�m. Dosya okuma i�lemini main fonksiyonunda yap�yorum. Dosyaya yazd�rma i�lemlerinide gerekti�i fonksiyon 
	ve yerlerde yapmaktay�m.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


 struct n{

	
	char songName[50];
	struct n * next;
	struct n * prev;



};
typedef struct n list;

	static int i=0;
	static char play[50];
		
	char first[50];
	char second[50];
	char third[50];
	char fourth[50];

list * insertSong(list *playList,char *second,char *third){
	
	if(playList==NULL){
			
	list *playList=(list *)malloc(sizeof(list))	;
	playList ->prev=playList;
	playList->next=playList;


  	strcpy(playList->songName,third);
	  
		
	return playList;
	}
		list *temp=playList;
		list *iter=playList;
	    if(strcmp(second,"H") == 0){
	    	 temp=(list *)malloc(sizeof(list));
	    strcpy(temp->songName,third);
	    temp->next=playList;
	    playList->prev=temp;
	    
	    while(iter->next!=playList){
	    	iter=iter->next;
		}
		iter->next=temp;
	    temp->prev=iter;

	  
	    return temp;
	    
    }
    else if(strcmp(second,"T") == 0){
    	 temp=(list *)malloc(sizeof(list));
    	 strcpy(temp->songName,third);
    	 while(iter->next!=playList){
	    	iter=iter->next;
		}
	 iter->next=temp;
	 temp->prev=iter;
	 temp->next=playList;
	 playList->prev=temp;
	 return playList;
    }
    	
    	
    	
    
   		
	}




 list *removeSong(list *playList,char *name){
 
 	if(playList==playList->next){
 			
 		return NULL;
	 }
		list *iter=playList;
		list *temp;
		if(strcmp(playList->songName,name) == 0){
		
	
	
		playList=playList->next;
		iter=iter->next;
	
		while(iter->next->next!=playList){
			
			iter=iter->next;
			
		}
		iter->next=playList;
		playList->prev=iter;
		
		return playList;
		
		}
		
		
		while(iter->next!=playList && strcmp(iter->next->songName,name) != 0){
			
		iter=iter->next;
		
		}
	
		iter->next=iter->next->next;
			
		iter->next->prev=iter;

		
	
		return playList;
		
		
		}
		
list *moveSong(list *playList,char *second,char *third,char *fourth){

	list *iter=playList;
	list *temp;

	
	
	
	
	if(strcmp(second,"B") == 0){
	
			if(strcmp(playList->songName,third)==0 && strcmp(playList->next->songName,fourth)==0 ){
				
				return playList;
			}
			
			if(strcmp(playList->songName,fourth)==0){
					 	 temp=(list *)malloc(sizeof(list));
	 	 strcpy(temp->songName,third);
	 	 
	 
		   	while(iter->next!=iter && strcmp(iter->next->songName,fourth) != 0){
    	 
	    	iter=iter->next;
	   
		}
		
			playList=removeSong(playList,third);
	
	
		
			
					temp->next=iter->next;
				 iter->next=temp;
				 temp->prev=iter;
				 temp->next->prev=temp;
				 		
				 
	 	 
		 return temp;
	
	
				
				
			}
			
			
	 	 temp=(list *)malloc(sizeof(list));
	 	 strcpy(temp->songName,third);
	 	 
	 
		   	while(iter->next!=iter && strcmp(iter->next->songName,fourth) != 0){
    	 
	    	iter=iter->next;
	   
		}
		
			playList=removeSong(playList,third);
	
	
		

		temp->next=iter->next;
	 iter->next=temp;
	 temp->prev=iter;
	 temp->next->prev=temp;
	 		
	 
	 	 
	 return playList;
	
	
	
	}	
	else if(strcmp(second,"A") == 0){
		
	
	
	 	 temp=(list *)malloc(sizeof(list));
	 	 strcpy(temp->songName,third);
	 	 
	 	 
	 	
   
    while(iter->next!=iter && strcmp(iter->songName,fourth) != 0){
	    	iter=iter->next;
	    	
		}
			playList=removeSong(playList,third);
		temp->next=iter->next;
	 iter->next=temp;
	 temp->prev=iter;
	 temp->next->prev=temp;
	 
	 return playList;
	
	
	
	}	

}
		
		
		

list *playSong(list *playList,char *second){
	FILE *fk;
	fk = fopen("output.txt","a");

	list *iter=playList;
		
	
	if(iter!=NULL){
		
		if(i==0){
			
			if(strcmp(second,"N") == 0){
				strcpy(play,iter->songName);
				fprintf(fk,"Playing\t%s\n*****\n",iter->songName);
		
				i=1;
				fclose(fk);
				return iter;
			}
			else if(strcmp(second,"P") == 0){
			
			strcpy(play,iter->prev->songName);
			fprintf(fk,"Playing\t%s\n*****\n",iter->prev->songName);
					
				i=1;
				fclose(fk);
				return iter->prev;
		}
	}
		
		if(strcmp(second,"N") == 0){
			while(strcmp(iter->songName,play) != 0){
				
				iter=iter->next;
				
			}
			iter=iter->next;
			strcpy(play,iter->songName);
			fprintf(fk,"Playing\t%s\n*****\n",iter->songName);
		
			fclose(fk);
			return iter;
			
		}
		else if(strcmp(second,"P") == 0){
				while(strcmp(iter->songName,play) != 0){
				
				iter=iter->next;
				
			}
			
			iter=iter->prev;
			strcpy(play,iter->songName);
			fprintf(fk,"Playing\t%s\n*****\n",iter->songName);
		
				fclose(fk);
			return iter;
			
		}
		
		
			
			
		

	
}
	else {
		fprintf(fk,"No Songs To Play\n*****\n");

		fclose(fk);
		return iter;
	}

}
		
void printPlayList(list *playList,char *second){
	FILE *fk;
	
	fk = fopen("output.txt","a");
	if(playList!=NULL){
	
	
	list *iter=playList;
	
	
	if(strcmp(second,"F") == 0){
	
		fprintf(fk,"%s\n",iter->songName);
		iter=iter->next;
    	while(iter!=playList){
    		fprintf(fk,"%s\n",iter->songName);
    	
    		
		iter=iter->next;
		
		}
    	

	
	}
	else if(strcmp(second,"R") == 0){
	
	
		iter=iter->prev;
    	while(iter!=playList){
    		fprintf(fk,"%s\n",iter->songName);
   	
		iter=iter->prev;
		
		}
	
		fprintf(fk,"%s\n",iter->songName);
	
}

	fprintf(fk,"*****\n");

}

else {
	fprintf(fk,"No Songs To Print\n*****\n");

}
fclose(fk);
}

 list *reversePlayList(list *playList){
 
 	if(playList!=NULL){
 	list *reverse=playList;

 list *iter=playList;
 list *tutucu=playList;

 
 
 
 while(strcmp(tutucu->prev->songName,playList->songName) != 0 ){
 	
 	reverse=insertSong(reverse,"H",iter->songName);
 	iter=removeSong(iter,iter->songName);
 	tutucu=tutucu->prev;
 	
 }
 playList=reverse;
 
 return playList;;
	 }
	 else {
	 	
	 	return NULL;
	 }
	 
 
}

int main(int argc, char *argv[]) {

	
	list *sago;
	sago=NULL;
	list *playing=NULL;


	 FILE *fp;
	 
	 if((fp = fopen("input.txt","r")) == NULL)
        printf("***Error***");
        else {
			fscanf(fp,"%s",first);
	while(!feof(fp)) {
     
    	
      
	
		 	 
		if(strcmp(first,"InsertSong")==0){
			fscanf(fp,"\t%s\t%s",second,third);
			sago=insertSong(sago,second,third);
        	playing=sago;
		 	 
		 
		 }
		
		else if(strcmp(first,"MoveSong") == 0){
			fscanf(fp,"\t%s\t%s\t%s",second,third,fourth);
	
        	sago=moveSong(sago,second,third,fourth);
        	playing=sago;
		}
		else if(strcmp(first,"RemoveSong") == 0){
        	fscanf(fp,"\t%s",second);
        	FILE *fk;
	
			fk = fopen("output.txt","a");
        	 if(strcmp(second,play)==0){
 	
 		fprintf(fk,"Cannot Remove The Playing Song\n*****\n");
 			fclose(fk);
 		
	 }
        	else{
        		sago=removeSong(sago,second);
        		playing=sago;
			}
        	
        
        
		}
		else if(strcmp(first,"PlaySong") == 0){
       		 fscanf(fp,"\t%s",second);
        	playing=playSong(playing,second);
        
		}
		else if(strcmp(first,"PrintPlaylist") == 0){
        	fscanf(fp,"\t%s",second);
        	printPlayList(sago,second);
        	
		}
		else if(strcmp(first,"ReversePlaylist") == 0){
        
        	sago=reversePlayList(sago);
        	playing=sago;
      
       
		}
		
     	fscanf(fp,"%s",first);
    }
    
   fclose(fp);
   
}


	return 0;
}
