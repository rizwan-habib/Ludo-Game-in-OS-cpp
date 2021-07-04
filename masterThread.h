// Rizwan Habib 	I190603
//Talha				I192049
//CS-G
//Submitted to Sir faisal Cheema


sem_t sem;
sem_t sem1;
sem_t sem2;
pthread_t gtid2;
pthread_t tid3;
int tokens=4;

player p1;
player p2;
player p3;
player p4;
void* MasterThread(void * attr)
{
	
	cout<<"MASTER THREAD\n";
	int temp=(*(int*)attr);
	player * tempPlayer;
	//checking player
	if(temp==1){
		tempPlayer=&p1;
	}
	else if(temp==2){
		tempPlayer=&p2;
	}
	else if(temp==3){
		tempPlayer=&p3;
	}
	else if(temp==4){
		tempPlayer=&p4;
	} 
	sem_wait(&sem2);
	for (int i = 0; i < tokens; i++)
	{		
			//checing home path condition and hit rate
			if(tempPlayer->hitRate>0&&tempPlayer->tok[i].value>=50)
			{
				tempPlayer->tok[i].home=1;
			}
			else{
				tempPlayer->tok[i].home=0;
			
			}
			
	}
	//checking without sixes ( i.e if a player plays 20 turns without sixes he will be removed from game )
	if(tempPlayer->withoutsixturns>=20)
	{
		tempPlayer->inGame=0;
	}
	bool winflag=0;
	for (int i = 0; i < tokens; i++)
	{
		if(!tempPlayer->tok[i].win){
			winflag=1;
		}
	}
	
	if (!winflag)
	{
		tempPlayer->is_win=1;
	}
	
	
	sem_post(&sem2);
	
	pthread_exit(NULL);
}