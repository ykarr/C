#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include"haha.h"
#include<time.h>
#define CLR system("cls")
void lvup(struct status *ch);
int war(struct monster *m3,struct status *ch);
int yes(char a);
int main()
{	
	struct monster m1,m2,m3;
	struct wp wp1,wp2,wp3,wp4; //�� ��  
	wp1.wpcount=0;
	wp2.wpcount=0;
	wp3.wpcount=0;
	wp4.wpcount=0;
	char a,name[10]; 
	int first,i,b;
	printf("�ҷ����� �̱�������,�뷱�� �̱���(�������� �̱���)\n"); 
	printf("1. ����\n");
	printf("2. �ҷ�����\n");
	
	scanf("%d",&first);
	CLR;
	switch(first){
		case 1:
			printf("1. ����\n");
			printf("�̸��� �Է��ϼ���.\n");
			scanf("%s",name);
			printf("�Է��Ͻ� �̸��� %s�Դϴ�.\n",name);
			
			Sleep(2000);
			CLR;
			printf("%s���� ������ �غ����Դϴ�.\n",name);
			printf("��� ��ٷ��ּ���.");
			printf("������ ���۵Ǹ� ���⸦ �����մϴ�.\n ��������.");
			Sleep(3000);
			CLR;
			/*�ʱ� �������ͽ� �ʱ�ȭ*/
			struct status ch={1,0,100,10,5,5,5,3,200,0,1,0}; //����,����ġ,hp,mp,str,dex,in,skill,gold,dmg,only,wdmg 
			
			/*�������*/
			
			while(1){
				int ingame=0;
				CLR;
				printf("�������: %d\n",ch.gold);
				printf("1. ����â\n2. ��ųâ\n3. �κ�\n4. ���\n5. ����\n6. �����\n7. ����\n0*. �޽�(�ƹ�Ű�� ��������.ȿ���̱���.)\n");
				
				scanf("%d",&ingame);
				if(ingame==1){ //����â 
					CLR; 
					/*�ѵ�����*/ //���⿡���� ������, ���ݿ����� ������ �̱��� 
					ch.dmg=(ch.str+ch.dex+ch.in)*ch.wdmg; 
					printf("����â\n");
					printf("%s���� LV�� %d�Դϴ�.\n",name,ch.lv);
					printf("%s���� �ѵ������� %d�Դϴ�.\n",name,ch.dmg);
					printf("%s���� exp�� %d�Դϴ�.\n",name,ch.exp);
					printf("%s���� hp�� %d�Դϴ�.\n",name,ch.hp);
					printf("%s���� mp�� %d�Դϴ�.\n",name,ch.mp);
					printf("%s���� ���� %d�Դϴ�.\n",name,ch.str);
					printf("%s���� ������ %d�Դϴ�.\n",name,ch.in);
					printf("%s���� ������ %d�Դϴ�.\n",name,ch.dex);
					getch(); 
				}
				else if(ingame==2){ //��ųâ 
					CLR;
					printf("��ųâ\n");
				}
				else if(ingame==3){ //�κ�
					CLR;
					printf("�κ�\n");
				}
				else if(ingame==4){ //��� 
					
						int e;
						CLR;
						printf("���\n");
					
						if(wp1.wpcount>=1){
						printf("1. �α��� ��Į %d��\n",wp1.wpcount);
						}
						if(wp2.wpcount>=1){
						printf("2. �氡�� �ֿ� ����� %d��\n",wp2.wpcount);
						}
						getch();
						if(ch.only==1){
							printf("����� �����Ͻðڽ��ϱ�?\n");
							scanf("%d",&e);
							switch(e){
								case 1:
									ch.dex+=wp1.wdex;
									ch.str+=wp1.wstr;
									ch.wdmg+=wp1.wdmg;
									ch.in+=wp1.win;
									wp1.wpcount--;
									ch.only--;
									break;
							}
						}
					
				}
				else if(ingame==5){ //���� 
					while(1){
					CLR;
					printf("����(���� ���� �̱���)\n");
					printf("���԰����� ����\n");
					printf("1. �α��� ��Įlv.1 100gold \n");
					printf("2. �氡�� �ֿ� �����lv.1 100gold \n");
					printf("3.����lv.1 100gold \n");
					printf("4.ŷ�����ʷ� ���䷯ �ҵ� ��� �ҳ����� �����lv.99 1000gold \n");
					printf("���������� \n");
					scanf("%d",&ingame);
					switch(ingame){
						case 1:							
							if(ch.gold>=100){					
								wp1.wdmg=5;
								wp1.wstr=5;
								wp1.win=0;
								wp1.wdex=0;
								ch.gold-=100;
								printf("�����߽��ϴ�.");
								wp1.wpcount++;		
							}
							else
								printf("�������� ���߽��ϴ�.(��峪 ������ Ȯ�����ּ���.)");
							Sleep(2000);
							break;
							case 2:
							if(ch.gold>=100){							
								wp2.wdmg=5;
								wp2.win=5;
								wp2.wdex=0;
								wp2.wstr=0;
								ch.gold-=100;	
								printf("�����߽��ϴ�.");
								wp2.wpcount++;	
								}
							else
								printf("�������� ���߽��ϴ�.(��峪 ������ Ȯ�����ּ���.)");
							Sleep(2000);
							break;
							case 3:	
								if(ch.gold>=100){						
									wp3.wdmg=5;
									wp3.wdex=5;
									wp3.win=0;
									wp3.wstr=0;
									ch.gold-=100;
									printf("�����߽��ϴ�.");
									wp3.wpcount++;		
								}
								else
									printf("�������� ���߽��ϴ�.(��峪 ������ Ȯ�����ּ���.)");
								Sleep(2000);
								break;
							case 4:	
								if(ch.lv>=99&&ch.gold>=1000){						
									wp4.wdmg=99;
									wp4.wstr=99;
									wp4.win=99;
									wp4.wdex=99;
									ch.gold-=1000;
									printf("�����߽��ϴ�.");
									wp4.wpcount++;
								}
								else
									printf("�������� ���߽��ϴ�.(��峪 ������ Ȯ�����ּ���.)");
								Sleep(2000);
								break;
							default:
								break;	
						 }
					 	if(ingame>=5)
					 	 break;
					}
				}
				else if(ingame==6){ //�����
					
					printf("����1�� ��Ÿ����.!!\n");
					printf("�ο�ðڽ��ϱ�? y/n\n"); //��¥�� �ϳ��ۿ� ��� ���ñ� ���� �׳� �ο�� 
					ch.exp+=war(&m3,&ch);
					lvup(&ch);
				}
				else if(ingame==7){ //���� 
					CLR;
					printf("�����մϴ�.\n");
					break; 
				}
				else{ //�޽� 
					CLR;
					printf("��� �޽�()\n");
					Sleep(5000);
					ch.exp++;
					lvup(&ch);
					getch();
					
				}
			}
			break;	
		case 2:
			printf("2. �ҷ�����\n");
	}
	scanf("%c",&a);
	printf("%d",i);
	return 0;
}
int war(struct monster *m3,struct status *ch){
		int i=1;
		int exp;
		m3->hp=1000;
		m3->mp=100;
		m3->dmg=1;
		m3->df=1;
		m3->exp=10;
		while(i){
		
		if(ch->hp>=0){
			CLR;
			
			printf("���� hp: %d\n",m3->hp);
			printf("���� mp: %d\n",m3->mp);
			printf("�� hp: %d\n",ch->hp);
			printf("�� mp: %d\n",ch->mp);
			i=rand()%2+1;
			if(i==1){
				m3->hp-=ch->dmg;
			}
			if(i==2){
				ch->hp-=m3->dmg;
			}
			if(m3->hp<=0){
				exp=m3->exp;
				printf("���� �����ƽ��ϴ�. ����ġ�� �����ϴ�.\n");
				getch();
				break;
			}
			if(ch->hp<=0){
				exp=-m3->exp;
				printf("�÷��̾ ����ϼ̽��ϴ�.\n ������ ����ġ��ŭ ����ġ�� �϶��մϴ�.");
				getch();
				break;
			}
			getch();
		}
		}
	return exp;
}


