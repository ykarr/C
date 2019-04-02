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
	struct wp wp1,wp2,wp3,wp4; //무 기  
	wp1.wpcount=0;
	wp2.wpcount=0;
	wp3.wpcount=0;
	wp4.wpcount=0;
	char a,name[10]; 
	int first,i,b;
	printf("불러오기 미구현버전,밸런스 미구현(여러가지 미구현)\n"); 
	printf("1. 시작\n");
	printf("2. 불러오기\n");
	
	scanf("%d",&first);
	CLR;
	switch(first){
		case 1:
			printf("1. 시작\n");
			printf("이름을 입력하세요.\n");
			scanf("%s",name);
			printf("입력하신 이름은 %s입니다.\n",name);
			
			Sleep(2000);
			CLR;
			printf("%s님의 모험이 준비중입니다.\n",name);
			printf("잠시 기다려주세요.");
			printf("모험이 시작되면 무기를 얻어야합니다.\n 상점참고.");
			Sleep(3000);
			CLR;
			/*초기 스테이터스 초기화*/
			struct status ch={1,0,100,10,5,5,5,3,200,0,1,0}; //레벨,경험치,hp,mp,str,dex,in,skill,gold,dmg,only,wdmg 
			
			/*여기까지*/
			
			while(1){
				int ingame=0;
				CLR;
				printf("소지골드: %d\n",ch.gold);
				printf("1. 상태창\n2. 스킬창\n3. 인벤\n4. 장비\n5. 상점\n6. 사냥터\n7. 종료\n0*. 휴식(아무키나 누르세요.효과미구현.)\n");
				
				scanf("%d",&ingame);
				if(ingame==1){ //스텟창 
					CLR; 
					/*총데미지*/ //무기에따른 데미지, 스텟에따른 데미지 미구현 
					ch.dmg=(ch.str+ch.dex+ch.in)*ch.wdmg; 
					printf("상태창\n");
					printf("%s님의 LV은 %d입니다.\n",name,ch.lv);
					printf("%s님의 총데미지는 %d입니다.\n",name,ch.dmg);
					printf("%s님의 exp는 %d입니다.\n",name,ch.exp);
					printf("%s님의 hp은 %d입니다.\n",name,ch.hp);
					printf("%s님의 mp은 %d입니다.\n",name,ch.mp);
					printf("%s님의 힘은 %d입니다.\n",name,ch.str);
					printf("%s님의 지력은 %d입니다.\n",name,ch.in);
					printf("%s님의 명중은 %d입니다.\n",name,ch.dex);
					getch(); 
				}
				else if(ingame==2){ //스킬창 
					CLR;
					printf("스킬창\n");
				}
				else if(ingame==3){ //인벤
					CLR;
					printf("인벤\n");
				}
				else if(ingame==4){ //장비 
					
						int e;
						CLR;
						printf("장비\n");
					
						if(wp1.wpcount>=1){
						printf("1. 싸구려 식칼 %d개\n",wp1.wpcount);
						}
						if(wp2.wpcount>=1){
						printf("2. 길가다 주운 막대기 %d개\n",wp2.wpcount);
						}
						getch();
						if(ch.only==1){
							printf("어떤것을 장착하시겠습니까?\n");
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
				else if(ingame==5){ //상점 
					while(1){
					CLR;
					printf("상점(아직 물약 미구현)\n");
					printf("구입가능한 무기\n");
					printf("1. 싸구려 식칼lv.1 100gold \n");
					printf("2. 길가다 주운 막대기lv.1 100gold \n");
					printf("3.새총lv.1 100gold \n");
					printf("4.킹갓제너럴 엠페러 소드 겸용 불나오는 막대기lv.99 1000gold \n");
					printf("상점나가기 \n");
					scanf("%d",&ingame);
					switch(ingame){
						case 1:							
							if(ch.gold>=100){					
								wp1.wdmg=5;
								wp1.wstr=5;
								wp1.win=0;
								wp1.wdex=0;
								ch.gold-=100;
								printf("구매했습니다.");
								wp1.wpcount++;		
							}
							else
								printf("구매하지 못했습니다.(골드나 레벨을 확인해주세요.)");
							Sleep(2000);
							break;
							case 2:
							if(ch.gold>=100){							
								wp2.wdmg=5;
								wp2.win=5;
								wp2.wdex=0;
								wp2.wstr=0;
								ch.gold-=100;	
								printf("구매했습니다.");
								wp2.wpcount++;	
								}
							else
								printf("구매하지 못했습니다.(골드나 레벨을 확인해주세요.)");
							Sleep(2000);
							break;
							case 3:	
								if(ch.gold>=100){						
									wp3.wdmg=5;
									wp3.wdex=5;
									wp3.win=0;
									wp3.wstr=0;
									ch.gold-=100;
									printf("구매했습니다.");
									wp3.wpcount++;		
								}
								else
									printf("구매하지 못했습니다.(골드나 레벨을 확인해주세요.)");
								Sleep(2000);
								break;
							case 4:	
								if(ch.lv>=99&&ch.gold>=1000){						
									wp4.wdmg=99;
									wp4.wstr=99;
									wp4.win=99;
									wp4.wdex=99;
									ch.gold-=1000;
									printf("구매했습니다.");
									wp4.wpcount++;
								}
								else
									printf("구매하지 못했습니다.(골드나 레벨을 확인해주세요.)");
								Sleep(2000);
								break;
							default:
								break;	
						 }
					 	if(ingame>=5)
					 	 break;
					}
				}
				else if(ingame==6){ //사냥터
					
					printf("몬스터1이 나타났다.!!\n");
					printf("싸우시겠습니까? y/n\n"); //어짜피 하나밖에 없어서 선택권 없음 그냥 싸우셈 
					ch.exp+=war(&m3,&ch);
					lvup(&ch);
				}
				else if(ingame==7){ //종료 
					CLR;
					printf("종료합니다.\n");
					break; 
				}
				else{ //휴식 
					CLR;
					printf("잠시 휴식()\n");
					Sleep(5000);
					ch.exp++;
					lvup(&ch);
					getch();
					
				}
			}
			break;	
		case 2:
			printf("2. 불러오기\n");
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
			
			printf("몬스터 hp: %d\n",m3->hp);
			printf("몬스터 mp: %d\n",m3->mp);
			printf("내 hp: %d\n",ch->hp);
			printf("내 mp: %d\n",ch->mp);
			i=rand()%2+1;
			if(i==1){
				m3->hp-=ch->dmg;
			}
			if(i==2){
				ch->hp-=m3->dmg;
			}
			if(m3->hp<=0){
				exp=m3->exp;
				printf("적을 물리쳤습니다. 경험치가 오릅니다.\n");
				getch();
				break;
			}
			if(ch->hp<=0){
				exp=-m3->exp;
				printf("플레이어가 사망하셨습니다.\n 몬스터의 경험치만큼 경험치가 하락합니다.");
				getch();
				break;
			}
			getch();
		}
		}
	return exp;
}


