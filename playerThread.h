// Rizwan Habib 	I190603
//Talha				I192049
//CS-G
//Submitted to Sir faisal Cheema

void* playerthread(void* attr)
{

	int temp=(*(int*)attr);

	//checking players
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
	sem_wait(&sem);
	//initializing dice value for all the players to 0
	for (int  i = 0; i < 3; i++)
	{
		x[temp-1][i]=0;
	}
	bool threesix=true;
	int tempdice=0;
	for(int i=0;i<3;i++){
		x[temp-1][i]=rolling_dice();// assiging dice value
		cout<<"dice value of player: "<<temp<<" is: "<<x[temp-1][i]<<endl;//priinting dice value
		sleep(1);
		//checking without six turns condition and incrementing value of variable withoutsixturns
        if (x[temp-1][i]!=6)
	    {
		tempPlayer->withoutsixturns++;
	    }
	    else
	    {
		tempPlayer->withoutsixturns=0;
	    }

		if(x[temp-1][i]!=6){
			threesix=false;
			break;
		}

	}
	if(threesix){//checking 3 consective sixes condition
		for (int  i = 0; i < 3; i++)
		{
			x[temp-1][i]=0;//assigning zero on 3 consective sixes 
		}
	}
	
	for(int j=0;j<3 && x[temp-1][j]>0 ; j++){
		int n=1;
		bool flag=false;
		for(int i=0;i<tokens;i++){
			if(tempPlayer->tok[i].open==1){
				flag=true;
			}
		}
		if(flag||x[temp-1][j]==6){
			cout<<"Enter which token you want to move for player: "<<temp<<" :";
			cin>>n;
			
			while(n>tokens||n<1){
				cout<<"Enter value between 0 to "<<tokens+1<<"::";
				cin>>n;
			}
			while(((!tempPlayer->tok[n-1].open) && x[temp-1][j]!=6) || (tempPlayer->tok[n-1].win)){
				cout<<"Please Enter value of opened tokens::";
				cin>>n;
			}
			bool winflag=0;
			bool notmoveflag=0;
			while (tempPlayer->tok[n-1].value+x[temp-1][j]>56)
			{
				cout<<"movement of this token is not posssible"<<endl;

				for (int k = 0; k < tokens; k++)
				{
					if(k!=n-1)
					{
						if (!tempPlayer->tok[k].win && tempPlayer->tok[k].open)
						{
							winflag=1;
						}
						if(x[temp-1][j]==6 && !tempPlayer->tok[k].open)
						{
							winflag=1;
						}
					}
				}
				if(winflag){
					cout<<"enter another token"<<endl;
					cin>>n;
				}
				else
				{
					notmoveflag=1;
					break;
				}
			}

			
			if(tempPlayer->tok[n-1].open && !notmoveflag){
				path1(x[temp-1][j],&tempPlayer->tok[n-1]);
			}
			else if(x[temp-1][j]==6){
				
				tempPlayer->tok[n-1].value=0;
				tempPlayer->tok[n-1].open=1;
				if(tempPlayer->tok[n-1].sym=='&')
				{
					tempPlayer->tok[n-1].x=1;
					tempPlayer->tok[n-1].y=6;
				}
				else if(tempPlayer->tok[n-1].sym=='%')
				{
					tempPlayer->tok[n-1].x=6;
					tempPlayer->tok[n-1].y=13;
				}
				else if(tempPlayer->tok[n-1].sym=='#')
				{
					tempPlayer->tok[n-1].x=8;
					tempPlayer->tok[n-1].y=1;
				}
				else if(tempPlayer->tok[n-1].sym=='@')
				{
					tempPlayer->tok[n-1].x=13;
					tempPlayer->tok[n-1].y=8;
				}
				
			}
			//safe points conditions
			if(tempPlayer->tok[n-1].value==0||tempPlayer->tok[n-1].value==8||tempPlayer->tok[n-1].value==13||tempPlayer->tok[n-1].value==21||tempPlayer->tok[n-1].value==26||tempPlayer->tok[n-1].value==34||tempPlayer->tok[n-1].value==39||tempPlayer->tok[n-1].value==47)
			{
				tempPlayer->tok[n-1].stop=1;
			}
			else
			{
				tempPlayer->tok[n-1].stop=0;
			}
		}

		for(int i=0;i<tokens;i++)
			cout<<"position value of token: "<< i+1<< " of player: "<<temp<<" is : "<<tempPlayer->tok[i].value<<endl;
		cout<<endl;
		
		sem_init(&sem1,0,1);
		pthread_create(&gtid2,NULL,&hitVictimThread,&temp);
		pthread_join(gtid2,NULL);

		draw_frame();
	}
	sem_post(&sem);
	pthread_exit(NULL);
}
