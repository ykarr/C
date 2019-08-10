#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50000//�ִ� �޴� �������� ���� 5�� 

typedef struct node{//����ü  
   int num;//���ڸ� ���������� ���� 
   int loc;//��ġ�� ��Ÿ�� ���� 
}sim; 

int framefind(sim *Frame,int size, int page)//�������� ������ �������� ����� ��ġ�ϴ��� Ȯ���ϴ� �Լ� 
{
   int j;//���� ���� 
   for(j=0; j<size; j++)//�Է¹��� size��ŭ for���� ����. 
      if(Frame[j].num == page) return j;//������ j�� �����Ѵ�. 
   return -1;//�ٸ��� -1�� �����Ѵ�. 
}
int main(int argc, char *argv[]){//���ι� 
int inputsize = atoi(argv[2]);//�Է¹��� argv[2] (�����Ӱ�) 
   //int inputsize=100;
   int access=0, read=0, write=0, hit=0, fault=0;//���� ���� 
   int i=0;//���� ���� 
   int j=0;//���� ���� 
   int max=0;//�������� 
   int loc=0;//���� ���� 
   int count1=0;//���� ���� 
   int snum;//���� �� �� 
   int find;//ã���� ���� ���ϰ��� ���� ���� ���� 
   int page[MAX];//�������� ��� ���� �ִ´�. 
   char txt[8];//read/write�� ���� ����
   
   sim frame[inputsize];//������ 
   FILE *fp;//������ �������� ���� 
   fp=fopen("access.list","r");//access.list�� ����. 
   while(fscanf(fp,"%s",txt)!=-1) //�о�ð� ���������� �д´�. 
      if(!strcmp(txt,"read")) //fscanf�� ���� ���ڿ� read�� �� 
	  	read++;//read�϶� 
      else if(!strcmp(txt,"write")) //fscanf�� ���� ���ڿ� write�� �� 
	  	write++;//write�϶� 
      else
      {
         access++;//access�� ī��Ʈ�� �ø���. 
         page[j] = atoi(txt);//j�� ���� �ִ´�. 
         j++;//j�� ���� �ø���. 
      }
   for(j=0; j<inputsize; j++)//inputsize��ŭ (100,1000)��ŭ ī��Ʈ�� �ø��鼭 �����Ѵ�. 
   {
      frame[j].num = -1;//-1�� num�ʱ�ȭ 
      frame[j].loc = 0;//ī��Ʈ�� 0���� �ʱ�ȭ 
   }
if(!strcmp(argv[1],"belady")) //Belady's algorithm
  {
   for(i = 0 ; i < MAX ; i++)//i�� 0���� �ϰ� maxsize��ŭ for���� ����. 
   {
      for(loc=0;loc<inputsize;loc++)//loc�� 0���� �ϰ� �Է¹��� �����Ӹ�ŭ f���� ����. 
      {
         if(frame[loc].num == page[i])//�����ӿ� �ִ� ���� 5������ ���߿��� ���ٸ� 
         {
            for(snum=i+1;snum < MAX;snum++)//i+1�� snum�� �ǰ� �ϰ� snum�� maxsize�� ������������ for���� ����. 
            {
               if(page[snum]== page[i])//page[snum]�� ����� page[i]�� ������ ������ 
                  break;//for���� ����������. 
            }
            frame[loc].loc = snum - i;//frame[loc].loc�� ���� snum-i������ ���ش�. 
            hit++;//hit�� �ø���. 
            break;//for���� ����������. 
         }
      }   
      if(loc >= inputsize)//loc�� inputsize���� ũ�ų� ������(�� �������� �� á����) 
      {
         if(count1 < inputsize) //ī��Ʈ1�� inputsize���� ������  
         {
            for(snum=i+1;snum < MAX;snum++)//snum�� i+1�� �������ְ� max�� �Ǳ� ������ �����ش�. 
            {
               if(page[snum] == page[i])//page[snum]�̶� page[i]�� ���ٸ� 
                  break;//for���� ����������. 
            }
            frame[count1].loc = snum - i;//frame[count1].loc�� ���� snum-i������ ���ش�. 
            frame[count1].num = page[i];//frame[count1].num�� ���� page[i]�� ������ ���ش�. 
            fault++;//fault�� ������Ų��. 
            count1++;//count1�� ������Ų��.  
         }      
         else if(count1>=inputsize)//count1�� �����Ӻ��� ũ�� 
         {          
            max = 0;       //�߽����� 0���� ���� 
            for(j = 0 ; j < inputsize ; j++)//j�� 0���� �����ϰ� �����Ӹ�ŭ for���� ������. 
               if(frame[j].loc>frame[max].loc) 
			   		max = j;//���� frame[j].loc���� frame[max].loc�� �� ũ�� max�� ���� j�� �ȴ�. 
            for(snum=i+1;snum < MAX;snum++)//snum�� i+1������ ���ְ� max��ŭ ������. 
            {
               if(page[snum]== page[i])//page[snum]���� page[i]���� ���ؼ� ���̶�� 
                  break;//for���� ������. 
            }
            frame[max].loc = snum - i;  //frame[max].loc�� ���� snum-i�� ������ �������ش�.                
            frame[max].num = page[i];      //frame[max].num�� ���� page[i]�� ������ �������ش�. 
            fault++;//fault���� �ø���. 
         }         
      }
      for(j = 0 ; j<inputsize; j++)//for���� ������ ũ�⸸ŭ ������. 
         frame[j].loc--;//frame[j].loc�� ���� -1�� ���ش�. 
   } //for���� ����� ������ �������� �ʴ´ٸ� ���� �ö󰡼� ���� ������ �ݺ��Ѵ�. 
}
   else if(!strcmp(argv[1],"lru")) //LRU algorithm
   {   
    for(;loc<inputsize;i++)//loc�� ���� 0 loc�� �������� ũ�⸦ ���Ѵ�. 
      {
         if((find=framefind(frame,inputsize,page[i]))==-1)//������ 
         {
            frame[loc].num = page[i];//pfraem[loc].num�� ���� page[i]�� 
            for(j=0; j<=loc; j++) 
				frame[j].loc++;//for���� ���鼭 pframep[j].loc�� ���� ++ ���ش�. 
            loc++;//loc���� �÷��ش٤�. (frame.loc�ʹ� �ٸ�����)
			fault++;//fault�� ���� �ø���. 
         }
         else if(find!=-1)//�˻������� �ִٸ� 
         {
            for(j=0; j<=loc; j++) 
				frame[j].loc++;//for���� ���鼭 frame[j].loc�� ���� ++���ش�. 
            frame[find].loc=1;//frame[find].loc�� ���� 1�� ���ش�. 
            hit++;//hit�� �÷��ش�. 
         }
      }
      for(;i<MAX;i++)//i���� max���� ������ ���� 
      {
         if((find=framefind(frame,inputsize,page[i]))==-1)//������ ���� 
         {
            for(j=0; j<inputsize; j++){//inputsize��ŭ ����.
				frame[j].loc++;//������ ũ�⸸ŭ ���鼭 frame[j].loc�� ���� �ø���.  
               if(frame[max].loc<frame[j].loc) 
			   		max=j;//���� frame[max].loc�� frame[j].loc���� ������ max=j���� �ȴ�. 
			}
            frame[max].num=page[i];//frame[max].num���� page[i]�� ���� �ִ´�. 
            frame[max].loc=1;//frame[max].loc�� ���� 1�� ���ش�. 
            fault++;//fault���� �ø���. 
         }
         else if(find!=-1)//���� ������ 
         {
            for(j=0; j<inputsize; j++) 
				frame[j].loc++;//for���� �����Ӹ�ŭ �����鼭 frame[j].loc���� �ø���. 
            frame[find].loc =1;//frame[find].loc�� ���� 1�� �����. 
            hit++;//hit�� �ø���.
         }
      }
   }
	fclose(fp);//������ �ݴ´�.
   printf("Total number of access : %d\n",access);//access�� ��� 
   printf("Total number of read : %d\n",read);//read�� ��� 
   printf("Total number of write : %d\n",write);//write�� ��� 
   printf("Number of page hits : %d\n",hit);//hit�� ��� 
   printf("Number of page faults : %d\n",fault);//fault�� ��� 
   printf("Page fault rate : %d/%d = %f",fault,access,(double)fault/access*100);//fault/access�� �����ְ� ����� ���� rate�� ��� 
   return 0;//���� 
}

