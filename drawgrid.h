// Rizwan Habib 	I190603
//Talha				I192049
//CS-G
//Submitted to Sir faisal Cheema

///
// function for the motion of the tokens
///
void path1(int distance,token *t)
{
	int attr;

    //checking players tokens
	if (t->sym=='&')
	{
		attr=1;
	}
	else if (t->sym=='%')
	{
		attr=2;
	} 
	else if (t->sym=='#')
	{
		attr=3;
	} 
	else if (t->sym=='@')
	{
		attr=4;
	} 
	
	for (int i = 0; i < distance; i++)
	{
		sem_init(&sem2,0,1);
        //ceating master thread
		pthread_create(&tid3,NULL,&MasterThread,&attr);
		pthread_join(tid3,NULL);
		t->value++;
        //checking if not home and then assingning respective positions to tokens
		if(!t->home)
		{			
			if(t->y>9&&t->x==6){
				t->y--;
			}
			else if(t->y==9&&t->x==6){
				t->y=8;
				t->x=5;
			}
			else if(t->y==8&&t->x>0&&t->x<=5){	
				t->x--;
			}
			else if (t->x==0&&t->y>6)
			{
				t->y--;
			}
			else if(t->y==6&&t->x<5){
				t->x++;
			}
			else if(t->x==5&&t->y==6){
				t->y=5;
				t->x=6;
			}
			else if(t->y>0&&t->x==6){
				t->y--;
			}
			else if(t->y==0&&t->x<8){
				t->x++;
			}
			else if(t->y<5&&t->x==8){
				t->y++;
			}
			else if(t->x==8&&t->y==5){
				t->y=6;
				t->x=9;
			}
			else if(t->x<14&&t->y==6){
				t->x++;
			}
			else if(t->x==14&&t->y<8){
				t->y++;
			}
			else if(t->x>9&&t->y==8){
				t->x--;
			}
			else if(t->x==9 && t->y==8)
			{
				t->y=9;
				t->x=8;
			}
			else if(t->x==8&&t->y<14 ){
				t->y++;
			}
			else if(t->x>6&&t->y==14 ){
				t->x--;
			}
			if(t->value>51){
				t->value=(t->value%52);
			}
		}
		else
		{
			if (t->sym=='&')
			{
					t->x++;
			}
			else if (t->sym=='#')
			{
					t->y++;
			}
			else if (t->sym=='%')
			{
					t->y--;
			}
			else if (t->sym=='@')
			{
					t->x--;
			}
				
		}
	}
}

///
// draw the whole game scenarion or grid as well as tokens
///

void draw_frame(){
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
                
            // grid for four tokens     
			if(tokens==4)
			{
				if(i==4&&j==1&&!p1.tok[0].open)
				cout<<"  &  ";
            else if(i==4&&j==4&&!p1.tok[1].open)
				cout<<"  &  ";
            else if(i==1&&j==4&&!p1.tok[2].open)
				cout<<"  &  ";
            else if(i==1&&j==1&&!p1.tok[3].open)
				cout<<"  &  ";
			else if(i==10&&j==1&&!p2.tok[0].open)
				cout<<"  %  ";
            else if(i==10&&j==4&&!p2.tok[1].open)
				cout<<"  %  ";
            else if(i==13&&j==1&&!p2.tok[2].open)
				cout<<"  %  ";
            else if(i==13&&j==4&&!p2.tok[3].open)
				cout<<"  %  ";
			else if(i==1&&j==10&&!p3.tok[0].open)
				cout<<"  #  ";
            else if(i==1&&j==13&&!p3.tok[1].open)
				cout<<"  #  ";
            else if(i==4&&j==10&&!p3.tok[2].open)
				cout<<"  #  ";
            else if(i==4&&j==13&&!p3.tok[3].open)
				cout<<"  #  ";
			else if(i==10&&j==10&&!p4.tok[0].open)
				cout<<"  @  ";
            else if(i==10&&j==13&&!p4.tok[1].open)
				cout<<"  @  ";
            else if(i==13&&j==10&&!p4.tok[2].open)
				cout<<"  @  ";
            else if(i==13&&j==13&&!p4.tok[3].open)
				cout<<"  @  ";	
            else if(i==p1.tok[0].y&&j==p1.tok[0].x&&p1.tok[0].open)
                cout<<"  &  ";
            else if(i==p1.tok[1].y&&j==p1.tok[1].x&&p1.tok[1].open)
                cout<<"  &  ";
            else if(i==p1.tok[2].y&&j==p1.tok[2].x&&p1.tok[2].open)
                cout<<"  &  ";
            else if(i==p1.tok[3].y&&j==p1.tok[3].x&&p1.tok[3].open)
                cout<<"  &  ";
			else if(i==p2.tok[0].y&&j==p2.tok[0].x&&p2.tok[0].open)
                cout<<"  %  ";
            else if(i==p2.tok[1].y&&j==p2.tok[1].x&&p2.tok[1].open)
                cout<<"  %  ";
            else if(i==p2.tok[2].y&&j==p2.tok[2].x&&p2.tok[2].open)
                cout<<"  %  ";
            else if(i==p2.tok[3].y&&j==p2.tok[3].x&&p2.tok[3].open)
                cout<<"  %  ";
            else if(i==p3.tok[0].y&&j==p3.tok[0].x&&p3.tok[0].open)
                cout<<"  #  ";
            else if(i==p3.tok[1].y&&j==p3.tok[1].x&&p3.tok[1].open)
                cout<<"  #  ";
            else if(i==p3.tok[2].y&&j==p3.tok[2].x&&p3.tok[2].open)
                cout<<"  #  ";
            else if(i==p3.tok[3].y&&j==p3.tok[3].x&&p3.tok[3].open)
                cout<<"  #  ";
			else if(i==p4.tok[0].y&&j==p4.tok[0].x&&p4.tok[0].open)
                cout<<"  @  ";
            else if(i==p4.tok[1].y&&j==p4.tok[1].x&&p4.tok[1].open)
                cout<<"  @  ";
            else if(i==p4.tok[2].y&&j==p4.tok[2].x&&p4.tok[2].open)
                cout<<"  @  ";
            else if(i==p4.tok[3].y&&j==p4.tok[3].x&&p4.tok[3].open)
                cout<<"  @  ";



				else if(j<5&&i<5)
                cout<<"     ";
			else if(j<6&&i==5)
				cout<<" --- ";
			else if(j==5&&i<6)
				cout<<"    |";
            else if(j<5&&i>9)
                cout<<"     ";
			else if(j<6&&i==9)
                cout<<" --- ";
			else if(j==5&&i>8)
                cout<<"    |";
            else if(j>9&&i<5)
                cout<<"     ";
			else if(j>8&&i==5)
                cout<<" --- ";
			else if(j==9&&i<6)
                cout<<"|     ";
            else if(j>9&&i>9)
                cout<<"     ";
            else if(j>8&&i==9)
                cout<<" --- ";
            else if(j==9&&i>8)
                cout<<"|    ";
            else if(j==1&&i==6)
                cout<<"  A  ";
            else if(j==2&&i==8)
                cout<<"  A  ";
            else if(i==7&&j>0&&j<6)
                cout<<"  A  ";
            else if(j==6&&i==2)
                cout<<"  C  ";
            else if(j==8&&i==1)
                cout<<"  C  ";
            else if(j==7&&i>0&&i<6)
                cout<<"  C  ";
            else if(j==6&&i==13)
                cout<<"  B  ";
            else if(j==8&&i==12)
                cout<<"  B  ";
            else if(j==7&&i>8&&i<14)
                cout<<"  B  ";
            else if(j==13&&i==8)
                cout<<"  D  ";
            else if(j==12&&i==6)
                cout<<"  D  ";
            else if(i==7&&j>8&&j<14)
                cout<<"  D  ";
            else if(i>5&&j>5&&j<9&&i<9)
                cout<<"  H  ";
            
            else
                cout<<"  -  ";  	

			}
			else if(tokens==3)//grid for 3 tokens
			{
				if(i==4&&j==1&&!p1.tok[0].open)
				cout<<"  &  ";
            else if(i==4&&j==4&&!p1.tok[1].open)
				cout<<"  &  ";
            else if(i==1&&j==4&&!p1.tok[2].open)
				cout<<"  &  ";
			else if(i==10&&j==1&&!p2.tok[0].open)
				cout<<"  %  ";
            else if(i==10&&j==4&&!p2.tok[1].open)
				cout<<"  %  ";
            else if(i==13&&j==1&&!p2.tok[2].open)
				cout<<"  %  ";
        
			else if(i==1&&j==10&&!p3.tok[0].open)
				cout<<"  #  ";
            else if(i==1&&j==13&&!p3.tok[1].open)
				cout<<"  #  ";
            else if(i==4&&j==10&&!p3.tok[2].open)
				cout<<"  #  ";
           
			else if(i==10&&j==10&&!p4.tok[0].open)
				cout<<"  @  ";
            else if(i==10&&j==13&&!p4.tok[1].open)
				cout<<"  @  ";
            else if(i==13&&j==10&&!p4.tok[2].open)
				cout<<"  @  ";
        
            else if(i==p1.tok[0].y&&j==p1.tok[0].x&&p1.tok[0].open)
                cout<<"  &  ";
            else if(i==p1.tok[1].y&&j==p1.tok[1].x&&p1.tok[1].open)
                cout<<"  &  ";
            else if(i==p1.tok[2].y&&j==p1.tok[2].x&&p1.tok[2].open)
                cout<<"  &  ";
            
			else if(i==p2.tok[0].y&&j==p2.tok[0].x&&p2.tok[0].open)
                cout<<"  %  ";
            else if(i==p2.tok[1].y&&j==p2.tok[1].x&&p2.tok[1].open)
                cout<<"  %  ";
            else if(i==p2.tok[2].y&&j==p2.tok[2].x&&p2.tok[2].open)
                cout<<"  %  ";
            
            else if(i==p3.tok[0].y&&j==p3.tok[0].x&&p3.tok[0].open)
                cout<<"  #  ";
            else if(i==p3.tok[1].y&&j==p3.tok[1].x&&p3.tok[1].open)
                cout<<"  #  ";
            else if(i==p3.tok[2].y&&j==p3.tok[2].x&&p3.tok[2].open)
                cout<<"  #  ";
            
			else if(i==p4.tok[0].y&&j==p4.tok[0].x&&p4.tok[0].open)
                cout<<"  @  ";
            else if(i==p4.tok[1].y&&j==p4.tok[1].x&&p4.tok[1].open)
                cout<<"  @  ";
            else if(i==p4.tok[2].y&&j==p4.tok[2].x&&p4.tok[2].open)
                cout<<"  @  ";


				else if(j<5&&i<5)
                cout<<"     ";
			else if(j<6&&i==5)
				cout<<" --- ";
			else if(j==5&&i<6)
				cout<<"    |";
            else if(j<5&&i>9)
                cout<<"     ";
			else if(j<6&&i==9)
                cout<<" --- ";
			else if(j==5&&i>8)
                cout<<"    |";
            else if(j>9&&i<5)
                cout<<"     ";
			else if(j>8&&i==5)
                cout<<" --- ";
			else if(j==9&&i<6)
                cout<<"|     ";
            else if(j>9&&i>9)
                cout<<"     ";
            else if(j>8&&i==9)
                cout<<" --- ";
            else if(j==9&&i>8)
                cout<<"|    ";
            else if(j==1&&i==6)
                cout<<"  A  ";
            else if(j==2&&i==8)
                cout<<"  A  ";
            else if(i==7&&j>0&&j<6)
                cout<<"  A  ";
            else if(j==6&&i==2)
                cout<<"  C  ";
            else if(j==8&&i==1)
                cout<<"  C  ";
            else if(j==7&&i>0&&i<6)
                cout<<"  C  ";
            else if(j==6&&i==13)
                cout<<"  B  ";
            else if(j==8&&i==12)
                cout<<"  B  ";
            else if(j==7&&i>8&&i<14)
                cout<<"  B  ";
            else if(j==13&&i==8)
                cout<<"  D  ";
            else if(j==12&&i==6)
                cout<<"  D  ";
            else if(i==7&&j>8&&j<14)
                cout<<"  D  ";
            else if(i>5&&j>5&&j<9&&i<9)
                cout<<"  H  ";
            
            else
                cout<<"  -  ";  
			}
			else if(tokens==2)//grid for 2 tokens
			{
				if(i==4&&j==1&&!p1.tok[0].open)
				cout<<"  &  ";
            else if(i==4&&j==4&&!p1.tok[1].open)
				cout<<"  &  ";
            
			else if(i==10&&j==1&&!p2.tok[0].open)
				cout<<"  %  ";
            else if(i==10&&j==4&&!p2.tok[1].open)
				cout<<"  %  ";
            
			else if(i==1&&j==10&&!p3.tok[0].open)
				cout<<"  #  ";
            else if(i==1&&j==13&&!p3.tok[1].open)
				cout<<"  #  ";
            
			else if(i==10&&j==10&&!p4.tok[0].open)
				cout<<"  @  ";
            else if(i==10&&j==13&&!p4.tok[1].open)
				cout<<"  @  ";
           
            else if(i==p1.tok[0].y&&j==p1.tok[0].x&&p1.tok[0].open)
                cout<<"  &  ";
            else if(i==p1.tok[1].y&&j==p1.tok[1].x&&p1.tok[1].open)
                cout<<"  &  ";
            
			else if(i==p2.tok[0].y&&j==p2.tok[0].x&&p2.tok[0].open)
                cout<<"  %  ";
            else if(i==p2.tok[1].y&&j==p2.tok[1].x&&p2.tok[1].open)
                cout<<"  %  ";
            
            else if(i==p3.tok[0].y&&j==p3.tok[0].x&&p3.tok[0].open)
                cout<<"  #  ";
            else if(i==p3.tok[1].y&&j==p3.tok[1].x&&p3.tok[1].open)
                cout<<"  #  ";
            
			else if(i==p4.tok[0].y&&j==p4.tok[0].x&&p4.tok[0].open)
                cout<<"  @  ";
            else if(i==p4.tok[1].y&&j==p4.tok[1].x&&p4.tok[1].open)
                cout<<"  @  ";

				else if(j<5&&i<5)
                cout<<"     ";
			else if(j<6&&i==5)
				cout<<" --- ";
			else if(j==5&&i<6)
				cout<<"    |";
            else if(j<5&&i>9)
                cout<<"     ";
			else if(j<6&&i==9)
                cout<<" --- ";
			else if(j==5&&i>8)
                cout<<"    |";
            else if(j>9&&i<5)
                cout<<"     ";
			else if(j>8&&i==5)
                cout<<" --- ";
			else if(j==9&&i<6)
                cout<<"|     ";
            else if(j>9&&i>9)
                cout<<"     ";
            else if(j>8&&i==9)
                cout<<" --- ";
            else if(j==9&&i>8)
                cout<<"|    ";
            else if(j==1&&i==6)
                cout<<"  A  ";
            else if(j==2&&i==8)
                cout<<"  A  ";
            else if(i==7&&j>0&&j<6)
                cout<<"  A  ";
            else if(j==6&&i==2)
                cout<<"  C  ";
            else if(j==8&&i==1)
                cout<<"  C  ";
            else if(j==7&&i>0&&i<6)
                cout<<"  C  ";
            else if(j==6&&i==13)
                cout<<"  B  ";
            else if(j==8&&i==12)
                cout<<"  B  ";
            else if(j==7&&i>8&&i<14)
                cout<<"  B  ";
            else if(j==13&&i==8)
                cout<<"  D  ";
            else if(j==12&&i==6)
                cout<<"  D  ";
            else if(i==7&&j>8&&j<14)
                cout<<"  D  ";
            else if(i>5&&j>5&&j<9&&i<9)
                cout<<"  H  ";
            
            else
                cout<<"  -  ";  
			}
			else if(tokens==1)// grid for 1 token
			{
				if(i==4&&j==1&&!p1.tok[0].open)
				cout<<"  &  ";
			else if(i==10&&j==1&&!p2.tok[0].open)
				cout<<"  %  ";
            
			else if(i==1&&j==10&&!p3.tok[0].open)
				cout<<"  #  ";
            
			else if(i==10&&j==10&&!p4.tok[0].open)
				cout<<"  @  ";
            
            else if(i==p1.tok[0].y&&j==p1.tok[0].x&&p1.tok[0].open)
                cout<<"  &  ";
           
			else if(i==p2.tok[0].y&&j==p2.tok[0].x&&p2.tok[0].open)
                cout<<"  %  ";
           
            else if(i==p3.tok[0].y&&j==p3.tok[0].x&&p3.tok[0].open)
                cout<<"  #  ";
            
			else if(i==p4.tok[0].y&&j==p4.tok[0].x&&p4.tok[0].open)
                cout<<"  @  ";

				else if(j<5&&i<5)
                cout<<"     ";
			else if(j<6&&i==5)
				cout<<" --- ";
			else if(j==5&&i<6)
				cout<<"    |";
            else if(j<5&&i>9)
                cout<<"     ";
			else if(j<6&&i==9)
                cout<<" --- ";
			else if(j==5&&i>8)
                cout<<"    |";
            else if(j>9&&i<5)
                cout<<"     ";
			else if(j>8&&i==5)
                cout<<" --- ";
			else if(j==9&&i<6)
                cout<<"|     ";
            else if(j>9&&i>9)
                cout<<"     ";
            else if(j>8&&i==9)
                cout<<" --- ";
            else if(j==9&&i>8)
                cout<<"|    ";
            else if(j==1&&i==6)
                cout<<"  A  ";
            else if(j==2&&i==8)
                cout<<"  A  ";
            else if(i==7&&j>0&&j<6)
                cout<<"  A  ";
            else if(j==6&&i==2)
                cout<<"  C  ";
            else if(j==8&&i==1)
                cout<<"  C  ";
            else if(j==7&&i>0&&i<6)
                cout<<"  C  ";
            else if(j==6&&i==13)
                cout<<"  B  ";
            else if(j==8&&i==12)
                cout<<"  B  ";
            else if(j==7&&i>8&&i<14)
                cout<<"  B  ";
            else if(j==13&&i==8)
                cout<<"  D  ";
            else if(j==12&&i==6)
                cout<<"  D  ";
            else if(i==7&&j>8&&j<14)
                cout<<"  D  ";
            else if(i>5&&j>5&&j<9&&i<9)
                cout<<"  H  ";
            
            else
                cout<<"  -  ";  
    
			}	
			
				
            
			
        }
        cout<<endl<<endl;
    }
 
}
