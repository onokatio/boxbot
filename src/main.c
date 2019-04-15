#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include "main.h"
#include "key.c"
#include "drow.c"
#include "timer.c"

void init();

int main(){
  init();//初期化変数(main.c)
  while(roop){
    drowworld();//描画(drow.c)
    fpscounter++;//fpsカウント用変数(main.h)
  }
  ioctl(0, TCSETAF, &tty_backup);//キーボードを戻す
  printf("\033[%d;%dH\n" ,WORLDY+4,1);//カーソルを一番下に
  return 0;
}

void init(){
  system("clear");//最初に画面綺麗にする。
  for( i = 0 ; i <  WORLDY ; i++){
    for( j = 0 ; j < WORLDX ; j++){
      world[i][j] = 0;//ワールドデータ初期化
    }
  }
  waku();//枠組み作成(drow.c)
  timeinit();//タイマ初期設定(timer.c)
  world[0][0] = BIT_FLAG_1;
  return;
}
