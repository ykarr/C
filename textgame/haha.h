struct status{
	int lv; //����  
	int exp; //����ġ
	int hp; //hp
	int mp; //����
	int str;// ��
	int dex; //���� 
 	int in; //����
	int skil; //��ų����Ʈ 
	int gold; //�� 
	int dmg; //�ѵ����� 
	int only; //�������� ���ⰳ�� 
	int wdmg;
};
struct wp{
	int wdmg; //���ⵥ���� 
	int wdex; //����� �ö󰡴� ���� 
	int win; //����� �ö󰡴� ���� 
	int wstr; //����� �ö󰡴� �� 
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
	while(ch->exp>=100){ //������ 
		printf("����\n");
		++ch->lv;
		ch->exp=ch->exp-100;
		ch->str=ch->str+5;
		ch->dex=ch->dex+5;
		ch->in=ch->in+5;
	}
}
