// Rizwan Habib 	I190603
//Talha				I192049
//CS-G
//Submitted to Sir faisal Cheema


#include "player.h"
#include "masterThread.h"
#include "drawgrid.h"
#include "victim.h"
#include "playerThread.h"


int main(void)
{ 
	//asking about the number of tokens
    do
	{
		cout<<"Enter the number of tokens for each player between 0 and 5 :";
    	cin>>tokens;
	} while (tokens<1 || tokens>4);
	
	//creating four players
	player temp('&',tokens);
	player temp1('%',tokens);
	player temp2('#',tokens);
	player temp3('@',tokens);
	
	p1=temp;
	p2=temp1;
	p3=temp2;
	p4=temp3;

	//creating an array for random turns
	int arr[4]={1,2,3,4};	
	while(1){
		sem_init(&sem,0,1);	
		random_shuffle(arr,arr+4);//random values for different player selection
		string button;
		cout<<"Press and Enter any key to Continue: " ;
		cin>>button;   
		pthread_t tid[4];
		
       

		//creating 4 threads each for one player
		for(int i=0;i<4;i++){
			pthread_create(&tid[i],NULL,&playerthread,&arr[i]);
			
		}
		//joing 4 threads
		for(int i=0;i<4;i++){
			pthread_join(tid[i],NULL);

		}
		
	}    
    return 0;
}




