#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50000//최대 받는 데이터의 수는 5만 

typedef struct node{//구조체  
   int num;//숫자를 가지고있을 변수 
   int loc;//위치를 나타낼 변수 
}sim; 

int framefind(sim *Frame,int size, int page)//프레임의 내용이 페이지의 내용과 일치하는지 확인하는 함수 
{
   int j;//변수 선언 
   for(j=0; j<size; j++)//입력받은 size만큼 for문을 돈다. 
      if(Frame[j].num == page) return j;//같으면 j를 리턴한다. 
   return -1;//다르면 -1을 리턴한다. 
}
int main(int argc, char *argv[]){//메인문 
int inputsize = atoi(argv[2]);//입력받은 argv[2] (프레임값) 
   //int inputsize=100;
   int access=0, read=0, write=0, hit=0, fault=0;//변수 선언 
   int i=0;//변수 선언 
   int j=0;//변수 선언 
   int max=0;//변수선언 
   int loc=0;//변수 선언 
   int count1=0;//변수 선언 
   int snum;//변수 선 언 
   int find;//찾고나서 받은 리턴값을 받을 변수 선언 
   int page[MAX];//페이지에 모든 값을 넣는다. 
   char txt[8];//read/write를 받을 변수
   
   sim frame[inputsize];//프레임 
   FILE *fp;//파일을 열기위해 선언 
   fp=fopen("access.list","r");//access.list를 연다. 
   while(fscanf(fp,"%s",txt)!=-1) //읽어올게 없을때까지 읽는다. 
      if(!strcmp(txt,"read")) //fscanf로 받은 문자와 read와 비교 
	  	read++;//read일때 
      else if(!strcmp(txt,"write")) //fscanf로 받은 문자와 write를 비교 
	  	write++;//write일때 
      else
      {
         access++;//access의 카운트를 올린다. 
         page[j] = atoi(txt);//j에 값을 넣는다. 
         j++;//j의 값을 올린다. 
      }
   for(j=0; j<inputsize; j++)//inputsize만큼 (100,1000)만큼 카운트를 올리면서 실행한다. 
   {
      frame[j].num = -1;//-1로 num초기화 
      frame[j].loc = 0;//카운트를 0으로 초기화 
   }
if(!strcmp(argv[1],"belady")) //Belady's algorithm
  {
   for(i = 0 ; i < MAX ; i++)//i를 0으로 하고 maxsize만큼 for문을 돈다. 
   {
      for(loc=0;loc<inputsize;loc++)//loc를 0으로 하고 입력받은 프레임만큼 f문을 돈다. 
      {
         if(frame[loc].num == page[i])//프레임에 있는 값과 5만개의 값중에서 같다면 
         {
            for(snum=i+1;snum < MAX;snum++)//i+1을 snum이 되게 하고 snum이 maxsize와 같아질때까지 for문을 돈다. 
            {
               if(page[snum]== page[i])//page[snum]의 내용과 page[i]의 내용이 같으면 
                  break;//for문을 빠져나간다. 
            }
            frame[loc].loc = snum - i;//frame[loc].loc의 값을 snum-i값으로 해준다. 
            hit++;//hit를 올린다. 
            break;//for문을 빠져나간다. 
         }
      }   
      if(loc >= inputsize)//loc이 inputsize보다 크거나 같을때(즉 프레임이 꽉 찼을때) 
      {
         if(count1 < inputsize) //카운트1이 inputsize보다 작을때  
         {
            for(snum=i+1;snum < MAX;snum++)//snum을 i+1로 설정해주고 max가 되기 전까지 돌려준다. 
            {
               if(page[snum] == page[i])//page[snum]이랑 page[i]가 같다면 
                  break;//for문을 빠져나간다. 
            }
            frame[count1].loc = snum - i;//frame[count1].loc의 값을 snum-i값으로 해준다. 
            frame[count1].num = page[i];//frame[count1].num의 값을 page[i]의 값으로 해준다. 
            fault++;//fault를 증가시킨다. 
            count1++;//count1을 증가시킨다.  
         }      
         else if(count1>=inputsize)//count1이 프레임보다 크면 
         {          
            max = 0;       //멕스값을 0으로 설정 
            for(j = 0 ; j < inputsize ; j++)//j를 0으로 설정하고 프레임만큼 for문을 돌린다. 
               if(frame[j].loc>frame[max].loc) 
			   		max = j;//만약 frame[j].loc보다 frame[max].loc가 더 크면 max의 값은 j가 된다. 
            for(snum=i+1;snum < MAX;snum++)//snum을 i+1값으로 해주고 max만큼 돌린다. 
            {
               if(page[snum]== page[i])//page[snum]값과 page[i]값을 비교해서 참이라면 
                  break;//for문을 나간다. 
            }
            frame[max].loc = snum - i;  //frame[max].loc의 값을 snum-i의 값으로 설정해준다.                
            frame[max].num = page[i];      //frame[max].num의 값을 page[i]의 값으로 설정해준다. 
            fault++;//fault값을 올린다. 
         }         
      }
      for(j = 0 ; j<inputsize; j++)//for문을 프레임 크기만큼 돌린다. 
         frame[j].loc--;//frame[j].loc의 값을 -1씩 해준다. 
   } //for문을 벗어나는 조건을 만족하지 않는다면 위로 올라가서 위의 과정을 반복한다. 
}
   else if(!strcmp(argv[1],"lru")) //LRU algorithm
   {   
    for(;loc<inputsize;i++)//loc은 현재 0 loc과 프레임의 크기를 비교한다. 
      {
         if((find=framefind(frame,inputsize,page[i]))==-1)//없을때 
         {
            frame[loc].num = page[i];//pfraem[loc].num의 값은 page[i]로 
            for(j=0; j<=loc; j++) 
				frame[j].loc++;//for문을 돌면서 pframep[j].loc의 값을 ++ 해준다. 
            loc++;//loc값을 올려준다ㅏ. (frame.loc와는 다른값임)
			fault++;//fault의 값을 올린다. 
         }
         else if(find!=-1)//검색했을때 있다면 
         {
            for(j=0; j<=loc; j++) 
				frame[j].loc++;//for문을 돌면서 frame[j].loc의 값을 ++해준다. 
            frame[find].loc=1;//frame[find].loc의 값을 1로 해준다. 
            hit++;//hit를 올려준다. 
         }
      }
      for(;i<MAX;i++)//i값이 max보다 작을때 실행 
      {
         if((find=framefind(frame,inputsize,page[i]))==-1)//없으면 실행 
         {
            for(j=0; j<inputsize; j++){//inputsize만큼 돈다.
				frame[j].loc++;//프레임 크기만큼 돌면서 frame[j].loc의 값을 올린다.  
               if(frame[max].loc<frame[j].loc) 
			   		max=j;//만약 frame[max].loc이 frame[j].loc보다 작으면 max=j값이 된다. 
			}
            frame[max].num=page[i];//frame[max].num값에 page[i]의 값을 넣는다. 
            frame[max].loc=1;//frame[max].loc의 값을 1로 해준다. 
            fault++;//fault값을 올린다. 
         }
         else if(find!=-1)//값이 있을때 
         {
            for(j=0; j<inputsize; j++) 
				frame[j].loc++;//for문을 프레임만큼 돌리면서 frame[j].loc값을 올린다. 
            frame[find].loc =1;//frame[find].loc의 값을 1로 만든다. 
            hit++;//hit를 올린다.
         }
      }
   }
	fclose(fp);//파일을 닫는다.
   printf("Total number of access : %d\n",access);//access를 출력 
   printf("Total number of read : %d\n",read);//read를 출력 
   printf("Total number of write : %d\n",write);//write를 출력 
   printf("Number of page hits : %d\n",hit);//hit를 출력 
   printf("Number of page faults : %d\n",fault);//fault를 출력 
   printf("Page fault rate : %d/%d = %f",fault,access,(double)fault/access*100);//fault/access를 보여주고 계산한 값인 rate를 출력 
   return 0;//리턴 
}

