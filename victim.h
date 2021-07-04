// Rizwan Habib 	I190603
//Talha				I192049
//CS-G
//Submitted to Sir faisal Cheema

int rolling_dice()
{
	srand (time(NULL));
	return rand()%6+1;
}

int x[4][3];
void* hitVictimThread(void * attr)
{
	cout<<"hitVictimTHREAD\n";
	int temp=(*(int*)attr);
	player * tempPlayer;
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
    if(tempPlayer->inGame && !tempPlayer->is_win)
	{
		sem_wait(&sem1);
		for(int i=0;i<tokens;i++){
			if(tempPlayer->tok[i].sym=='&')
			{
				for(int j=0;j<tokens;j++)
				{
					if(tempPlayer->tok[i].x==p3.tok[j].x&&tempPlayer->tok[i].y==p3.tok[j].y && p3.tok[j].open ==1 && p3.tok[j].stop!=1)
					{
						cout<<"p1 ne p3 ko mara 1"<<endl;
						p3.tok[j].value=-1;
						p3.tok[j].open=0;
						p3.tok[j].home=0;
						p3.tok[j].x=8;
						p3.tok[j].y=1;
						tempPlayer->hitRate++;
					}
					if(tempPlayer->tok[i].x==p4.tok[j].x &&tempPlayer->tok[i].y==p4.tok[j].y && p4.tok[j].open==1 &&p4.tok[j].stop!=1)
					{
						cout<<"p1 ne p4 ko mara 1"<<endl;
						p4.tok[j].value=-1;
						p4.tok[j].open=0;
						p4.tok[j].home=0;
						p4.tok[j].x=13;
						tempPlayer->hitRate++;
						p4.tok[j].y=8;
					}
					if(tempPlayer->tok[i].x==p2.tok[j].x && tempPlayer->tok[i].y==p2.tok[j].y && p2.tok[j].open==1 &&p2.tok[j].stop!=1)
					{
						cout<<"p1 ne p2 ko mara 1"<<endl;
						p2.tok[j].home=0;

						p2.tok[j].value=-1;
						p2.tok[j].open=0;
						p2.tok[j].x=6;
						tempPlayer->hitRate++;
						p2.tok[j].y=13;
					}
				}
			}
			else if(tempPlayer->tok[i].sym=='%')
			{
				for(int j=0;j<tokens;j++)
				{
					if(tempPlayer->tok[i].x==p1.tok[j].x && tempPlayer->tok[i].y==p1.tok[j].y&& p1.tok[j].open==1 && p1.tok[j].stop!=1)
					{
						cout<<"p2 ne p1 ko mara 1"<<endl;
						p1.tok[j].value=-1;
						tempPlayer->hitRate++;
						p1.tok[j].home=0;
						p1.tok[j].open=0;
						p1.tok[j].x=1;
						p1.tok[j].y=6;
					}
					if(tempPlayer->tok[i].x==p3.tok[j].x && tempPlayer->tok[i].y==p3.tok[j].y && p3.tok[j].open==1  &&p3.tok[j].stop!=1)
					{
						cout<<"p2 ne p3 ko mara 1"<<endl;
						p3.tok[j].value=-1;
						p3.tok[j].home=0;
						p3.tok[j].open=0;
						tempPlayer->hitRate++;
						p3.tok[j].x=8;
						p3.tok[j].y=1;
					}
					if(tempPlayer->tok[i].x==p4.tok[j].x && tempPlayer->tok[i].y==p4.tok[j].y && p4.tok[j].open==1  &&p4.tok[j].stop!=1)
					{
						cout<<"p2 ne p4 ko mara 1"<<endl;
						p4.tok[j].value=-1;
						p4.tok[j].open=0;
						tempPlayer->hitRate++;
						p4.tok[j].home=0;
						p4.tok[j].x=13;
						p4.tok[j].y=8;
					}
				}
			}
			else if(tempPlayer->tok[i].sym=='#')
			{
				for(int j=0;j<tokens;j++)
				{
					if(tempPlayer->tok[i].x==p4.tok[j].x && tempPlayer->tok[i].y==p4.tok[j].y && p4.tok[j].open==1  &&p4.tok[j].stop!=1)
					{
						cout<<"p3 ne p4 ko mara 1"<<endl;
						p4.tok[j].value=-1;
						p4.tok[j].open=0;
						p4.tok[j].home=0;
						p4.tok[j].x=13;
						tempPlayer->hitRate++;
						p4.tok[j].y=8;
					}
					if(tempPlayer->tok[i].x==p2.tok[j].x && tempPlayer->tok[i].y==p2.tok[j].y && p2.tok[j].open==1  &&p2.tok[j].stop!=1)
					{
						cout<<"p3 ne p2 ko mara 1"<<endl;
						p2.tok[j].value=-1;
						p2.tok[j].open=0;
						tempPlayer->hitRate++;
						p2.tok[j].home=0;
						p2.tok[j].x=6;
						p2.tok[j].y=13;
					}
					if(tempPlayer->tok[i].x==p1.tok[j].x && tempPlayer->tok[i].y==p1.tok[j].y && p1.tok[j].open==1  &&p1.tok[j].stop!=1)
					{
						cout<<"p3 ne p1 ko mara 1"<<endl;
						p1.tok[j].value=-1;
						tempPlayer->hitRate++;
						p1.tok[j].home=0;
						p1.tok[j].open=0;
						p1.tok[j].x=1;
						p1.tok[j].y=6;
					}
				}
			}
			else if(tempPlayer->tok[i].sym=='@')
			{
				for(int j=0;j<tokens;j++)
				{
					if(tempPlayer->tok[i].x==p2.tok[j].x &&tempPlayer->tok[i].y==p2.tok[j].y && p2.tok[j].open==1 && p2.tok[j].stop!=1)
					{
						cout<<"p4 ne p2 ko mara 1"<<endl;
						p2.tok[j].value=-1;
						p2.tok[j].open=0;
						p2.tok[j].x=6;
						tempPlayer->hitRate++;
						p2.tok[j].home=0;
						p2.tok[j].y=13;
					}
					if(tempPlayer->tok[i].x==p1.tok[j].x && tempPlayer->tok[i].y==p1.tok[j].y  && p1.tok[j].open==1 &&p1.tok[j].stop!=1)
					{
						cout<<"p4 ne p1 ko mara 1"<<endl;
						p1.tok[j].value=-1;
						tempPlayer->hitRate++;
						p1.tok[j].home=0;
						p1.tok[j].open=0;
						p1.tok[j].x=1;
						p1.tok[j].y=6;
					}
					if(tempPlayer->tok[i].x==p3.tok[j].x && tempPlayer->tok[i].y==p3.tok[j].y && p3.tok[j].open==1 && p3.tok[j].stop!=1)
					{
						cout<<"p4 ne p3 ko mara 1"<<endl;
						p3.tok[j].value=-1;
						tempPlayer->hitRate++;
						p3.tok[j].open=0;
						p3.tok[j].home=0;
						p3.tok[j].x=8;
						p3.tok[j].y=1;
					}
				}
			}
		}
		sem_post(&sem1);
	}
pthread_exit(NULL);
}
