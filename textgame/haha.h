struct status{
	int lv; //레벨  
	int exp; //경험치
	int hp; //hp
	int mp; //마나
	int str;// 힘
	int dex; //명중 
 	int in; //지력
	int skil; //스킬포인트 
	int gold; //돈 
	int dmg; //총데미지 
	int only; //장착가능 무기개수 
	int wdmg;
};
struct wp{
	int wdmg; //무기데미지 
	int wdex; //무기로 올라가는 명중 
	int win; //무기로 올라가는 지력 
	int wstr; //무기로 올라가는 힘 
	int wpcount; 
	
};
struct monster{
	int hp;
	int mp;
	int dmg;
	int df;
	int exp;
};
int yes(char a)
{
	int i;
	
	if(a=='y'||a=='Y'||a=='n'||a=='N')
	{
		switch(a){
			case 'y':
				i=1;
				break;	
			case 'Y':
				i=1;
				break;
			case '0':
				i=1;
				break;
			case 'N':
				i=0;
				break;
		}
	}
	return i;
}
void lvup(struct status *ch)
{
	while(ch->exp>=100){ //레벨업 
		printf("축하\n");
		++ch->lv;
		ch->exp=ch->exp-100;
		ch->str=ch->str+5;
		ch->dex=ch->dex+5;
		ch->in=ch->in+5;
	}
}
