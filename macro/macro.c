#include <windows.h>
#include <stdio.h>
 
void home();
int main(void)
{
    POINT pt; // 마우스 포인터
    int x[50000]; // 매크로 x좌표
    int y[50000]; // 매크로 y좌표
    int sub_x[50000], sub_y[50000]; // 보조 xy
    int sub_x2[50000], sub_y2[50000]; // 보조 xy
    int check_mouse = 2; // 마우스 관련 변수
    int check_mouse2 = 2; // 마우스 관련 변수
    int i = 0; // 매크로 녹화시 이용
    //int n = 0; // 메크로 진행시 이용
    system("mode con: cols=30 lines=13"); // 화면 고정
    home(); //home이라는 이름을 가진 함수 
   while(1) //무한반복 break문이나 return문으로 나가야됨. 
   { 
        if(GetKeyState(VK_F10) < 0) // F10키 누르면
        {
           printf("프로그램을 종료합니다.\n"); 
            return 0; // 프로그램 종료
        }

        else if(GetKeyState(VK_F3) < 0 ) // 마우스 녹화 
         {
            printf("마우스 입력중입니다.\n");
            
            for(i = 0 ; i <= 50000 ; i ++) //초기화 
            {
               x[i] =0; y[i] = 0; // 초기화 과정 다 0으로 초기화해줌 
                sub_x[i] =0; sub_y[i] = 0;
                sub_x2[i] =0; sub_y2[i] = 0;
            }
            i = 0;     
            while(1)//무한반복. 
            {
              GetCursorPos(&pt); // 마우스 좌표값들 받아옴
               x[i] = pt.x; // x좌표값 저장
               y[i] = pt.y; // y좌표값 저장
               sub_x[i] = 0, sub_y[i] = 0; // 왼쪽버튼 누르고 떼는 모습 저장하는 곳
               i++; // i는 프레임을 의미
               Sleep(10); //  0.01초 마다 1프레임 찍힘
               if(GetKeyState(VK_LBUTTON) < 0 && check_mouse >= 1||GetKeyState(VK_RBUTTON) < 0 && check_mouse2 >= 1)  // 왼쪽버튼,오른쪽 버튼  눌렀을 때
               { 
                   if(GetKeyState(VK_LBUTTON) < 0 && check_mouse >= 1){//왼쪽만 
                
                      sub_x[i] = x[i-1];
                      sub_y[i] = y[i-1];
                      x[i] = 5000;
                      y[i] = 5000; 
                      check_mouse = 0; 
                      }
                   else if(GetKeyState(VK_RBUTTON) < 0 && check_mouse2 >= 1){ //오른쪽만 
                      sub_x2[i] = x[i-1];
                      sub_y2[i] = y[i-1];
                      x[i] = 7000;
                      y[i] = 7000; 
                      check_mouse2 = 0; 
                      }
                i++;        
               }
               else if(GetKeyState(VK_LBUTTON) >= 0 && check_mouse == 0||GetKeyState(VK_RBUTTON) >= 0 && check_mouse2 == 0) // 왼쪽버튼 뗄 때
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
                  printf("녹화를 멈춥니다.\n");
                   break;
               }
 
               if(GetKeyState(VK_F10) < 0 )
               {
                  printf("프로그램을 종료합니다.\n"); 
                   return 0;
               }
 
            }
    
       }
 
         else if(GetKeyState(VK_F8) < 0 ) // 매크로 재생
         {
            printf("재생중입니다. \n");
             i = 0; // 프레임 처음으로 돌아가서 재생하기 위한 n
             
             while(1)
             {
                 if(x[i] == 7000) // 왼쪽버튼 눌러지는 것을 5000이라고 가정
                {
                    mouse_event(MOUSEEVENTF_RIGHTDOWN, sub_x2[i], sub_y2[i], 0, 0); // 좌표에 맞게 왼쪽버튼 누르기
                    Sleep(1);
                }
                else if(x[i] == 8000) // 왼쪽버튼 떼지는 것을 6000이라고 가정
                {
                    mouse_event(MOUSEEVENTF_RIGHTUP, sub_x2[i], sub_y2[i], 0, 0);  // 좌표에 맞게 왼쪽버튼 떼기
                    Sleep(1);
                }
                if(x[i] == 5000) // 왼쪽버튼 눌러지는 것을 5000이라고 가정
                {
                    mouse_event(MOUSEEVENTF_LEFTDOWN, sub_x[i], sub_y[i], 0, 0); // 좌표에 맞게 왼쪽버튼 누르기
                    Sleep(1);
                }
                else if(x[i] == 6000) // 왼쪽버튼 떼지는 것을 6000이라고 가정
                {
                    mouse_event(MOUSEEVENTF_LEFTUP, sub_x[i], sub_y[i], 0, 0);  // 좌표에 맞게 왼쪽버튼 떼기
                    Sleep(1);
                }
            
                if(x[i] == 0) //NULL을 만나면 작동 
                {
                        i = 0; // 즉, 매크로의 끝부분으로 가면 다시 n = 0 으로 하여 다시 처음부터 시작
                }
             
                SetCursorPos(x[i],y[i]); // 0.01초마다 지정한 곳의 좌표로 마우스 이동
                Sleep(10);//0.01초마다 한번씩 쉬고 
 
                i++;
                
                if(GetKeyState(VK_F7) < 0 )//0.01초마다 조건문 확인 
                 {
                    printf("재생을 멈춥니다.\n");
                    break;
                 }
                if(GetKeyState(VK_F10) < 0 )
                {
                   printf("프로그램을 종료합니다.\n"); 
                    return 0;
                }
 
             }  
         }
    Sleep(10); //Sleep(1000)은 1초임. 즉, 0.01초를 기다린후 위로 올라가 반복문을 다시 실행 
   }
return 0;//메인문을 나감. 
}
void home(){
   //홈화면 
    puts("    ----------------------"); // puts함수는 자동으로 줄바꿈 처리를 한다.
     puts("    |　　　　　　　  　　|");
     puts("    |     Mouse Macro　  |");
     puts("    |　　　　　　　　　  |");
     puts("    |　F3 : 매크로 녹화　|");
     puts("    |  F7 : 매크로 정지  |");
     puts("    |　F8 : 매크로 시작　|");
     puts("    |  F10 : 종료하기 　 |");
     puts("    |　　　　　　　　　　|");
     puts("    ----------------------");
 
}

