#include <windows.h>
#include <stdio.h>
 
void home();
int main(void)
{
    POINT pt; // ���콺 ������
    int x[50000]; // ��ũ�� x��ǥ
    int y[50000]; // ��ũ�� y��ǥ
    int sub_x[50000], sub_y[50000]; // ���� xy
    int sub_x2[50000], sub_y2[50000]; // ���� xy
    int check_mouse = 2; // ���콺 ���� ����
    int check_mouse2 = 2; // ���콺 ���� ����
    int i = 0; // ��ũ�� ��ȭ�� �̿�
    //int n = 0; // ��ũ�� ����� �̿�
    system("mode con: cols=30 lines=13"); // ȭ�� ����
    home(); //home�̶�� �̸��� ���� �Լ� 
   while(1) //���ѹݺ� break���̳� return������ �����ߵ�. 
   { 
        if(GetKeyState(VK_F10) < 0) // F10Ű ������
        {
           printf("���α׷��� �����մϴ�.\n"); 
            return 0; // ���α׷� ����
        }

        else if(GetKeyState(VK_F3) < 0 ) // ���콺 ��ȭ 
         {
            printf("���콺 �Է����Դϴ�.\n");
            
            for(i = 0 ; i <= 50000 ; i ++) //�ʱ�ȭ 
            {
               x[i] =0; y[i] = 0; // �ʱ�ȭ ���� �� 0���� �ʱ�ȭ���� 
                sub_x[i] =0; sub_y[i] = 0;
                sub_x2[i] =0; sub_y2[i] = 0;
            }
            i = 0;     
            while(1)//���ѹݺ�. 
            {
              GetCursorPos(&pt); // ���콺 ��ǥ���� �޾ƿ�
               x[i] = pt.x; // x��ǥ�� ����
               y[i] = pt.y; // y��ǥ�� ����
               sub_x[i] = 0, sub_y[i] = 0; // ���ʹ�ư ������ ���� ��� �����ϴ� ��
               i++; // i�� �������� �ǹ�
               Sleep(10); //  0.01�� ���� 1������ ����
               if(GetKeyState(VK_LBUTTON) < 0 && check_mouse >= 1||GetKeyState(VK_RBUTTON) < 0 && check_mouse2 >= 1)  // ���ʹ�ư,������ ��ư  ������ ��
               { 
                   if(GetKeyState(VK_LBUTTON) < 0 && check_mouse >= 1){//���ʸ� 
                
                      sub_x[i] = x[i-1];
                      sub_y[i] = y[i-1];
                      x[i] = 5000;
                      y[i] = 5000; 
                      check_mouse = 0; 
                      }
                   else if(GetKeyState(VK_RBUTTON) < 0 && check_mouse2 >= 1){ //�����ʸ� 
                      sub_x2[i] = x[i-1];
                      sub_y2[i] = y[i-1];
                      x[i] = 7000;
                      y[i] = 7000; 
                      check_mouse2 = 0; 
                      }
                i++;        
               }
               else if(GetKeyState(VK_LBUTTON) >= 0 && check_mouse == 0||GetKeyState(VK_RBUTTON) >= 0 && check_mouse2 == 0) // ���ʹ�ư �� ��
               {
                  if(GetKeyState(VK_LBUTTON) >= 0 && check_mouse == 0){
                
                      sub_x[i] = x[i-1];
                      sub_y[i] = y[i-1];
                      x[i] = 6000;
                      y[i] = 6000;            
                      check_mouse = 1;
                   }
                   else if(GetKeyState(VK_RBUTTON) >= 0 && check_mouse2 == 0){
                
                      sub_x2[i] = x[i-1];
                      sub_y2[i] = y[i-1];
                      x[i] = 8000;
                      y[i] = 8000;            
                      check_mouse2 = 1;
                   }
                i++;        
               }
               if(GetKeyState(VK_F7) < 0 )
               {
                  printf("��ȭ�� ����ϴ�.\n");
                   break;
               }
 
               if(GetKeyState(VK_F10) < 0 )
               {
                  printf("���α׷��� �����մϴ�.\n"); 
                   return 0;
               }
 
            }
    
       }
 
         else if(GetKeyState(VK_F8) < 0 ) // ��ũ�� ���
         {
            printf("������Դϴ�. \n");
             i = 0; // ������ ó������ ���ư��� ����ϱ� ���� n
             
             while(1)
             {
                 if(x[i] == 7000) // ���ʹ�ư �������� ���� 5000�̶�� ����
                {
                    mouse_event(MOUSEEVENTF_RIGHTDOWN, sub_x2[i], sub_y2[i], 0, 0); // ��ǥ�� �°� ���ʹ�ư ������
                    Sleep(1);
                }
                else if(x[i] == 8000) // ���ʹ�ư ������ ���� 6000�̶�� ����
                {
                    mouse_event(MOUSEEVENTF_RIGHTUP, sub_x2[i], sub_y2[i], 0, 0);  // ��ǥ�� �°� ���ʹ�ư ����
                    Sleep(1);
                }
                if(x[i] == 5000) // ���ʹ�ư �������� ���� 5000�̶�� ����
                {
                    mouse_event(MOUSEEVENTF_LEFTDOWN, sub_x[i], sub_y[i], 0, 0); // ��ǥ�� �°� ���ʹ�ư ������
                    Sleep(1);
                }
                else if(x[i] == 6000) // ���ʹ�ư ������ ���� 6000�̶�� ����
                {
                    mouse_event(MOUSEEVENTF_LEFTUP, sub_x[i], sub_y[i], 0, 0);  // ��ǥ�� �°� ���ʹ�ư ����
                    Sleep(1);
                }
            
                if(x[i] == 0) //NULL�� ������ �۵� 
                {
                        i = 0; // ��, ��ũ���� ���κ����� ���� �ٽ� n = 0 ���� �Ͽ� �ٽ� ó������ ����
                }
             
                SetCursorPos(x[i],y[i]); // 0.01�ʸ��� ������ ���� ��ǥ�� ���콺 �̵�
                Sleep(10);//0.01�ʸ��� �ѹ��� ���� 
 
                i++;
                
                if(GetKeyState(VK_F7) < 0 )//0.01�ʸ��� ���ǹ� Ȯ�� 
                 {
                    printf("����� ����ϴ�.\n");
                    break;
                 }
                if(GetKeyState(VK_F10) < 0 )
                {
                   printf("���α׷��� �����մϴ�.\n"); 
                    return 0;
                }
 
             }  
         }
    Sleep(10); //Sleep(1000)�� 1����. ��, 0.01�ʸ� ��ٸ��� ���� �ö� �ݺ����� �ٽ� ���� 
   }
return 0;//���ι��� ����. 
}
void home(){
   //Ȩȭ�� 
    puts("    ----------------------"); // puts�Լ��� �ڵ����� �ٹٲ� ó���� �Ѵ�.
     puts("    |��������������  ����|");
     puts("    |     Mouse Macro��  |");
     puts("    |������������������  |");
     puts("    |��F3 : ��ũ�� ��ȭ��|");
     puts("    |  F7 : ��ũ�� ����  |");
     puts("    |��F8 : ��ũ�� ���ۡ�|");
     puts("    |  F10 : �����ϱ� �� |");
     puts("    |��������������������|");
     puts("    ----------------------");
 
}

