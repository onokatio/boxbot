
void drowworld(){
  int key;
  key = getkey();
  if(!(key)) return;
//    printf("non press");
  if(key == 'w'){
    playery_old = playery;
    playerx_old = playerx;
    playery--;
  }else if(key == 's'){
    playery_old = playery;
    playerx_old = playerx;
    playery++;
  }else if(key == 'a'){
    playery_old = playery;
    playerx_old = playerx;
    playerx--;
  }else if(key == 'd'){
    playery_old = playery;
    playerx_old = playerx;
    playerx++;
  }else if(key == 'r'){
    printf("\033[%d;%dH" ,1,1);
    printf("\033[%dB\n" ,VMY);
    printf("reloading...\n");
    waku();
  }else if(key == 'q'){
    roop = 0;
  }
  if(playerx < 2) playerx = 2;
  if(playery < 4) playery = 4;
  if(playerx > WORLDX) playerx = WORLDX;
  if(playery > WORLDY+3) playery = WORLDY+3;
  if(playerx != playerx_old | playery != playery_old){
    printf("\033[39m");
    printf("\033[%d;%dH" ,playery_old,playerx_old);
    printf(" ");
    printf("\033[32m");
    printf("\033[%d;%dH" ,playery,playerx);
    printf("■");
    printf("\033[39m");
    printf("\033[%d;%dH\n" ,1,1);
  }
//  if(world)
}

int waku(){
  int i;
  int j;
  for( i = 0 ; i < WORLDX+2 ; i++){
    printf("-");
  }
  for( i = 0 ; i < WORLDX+2 ; i++){
    printf("-");
  }
  printf("┌");
  for( i = 0 ; i < WORLDX ; i++){
    printf("━");
  }
  printf("┐\n");
  for( i = 0 ; i < WORLDY ; i++){
      printf("│");
      for( j = 0 ; j < WORLDX ; j++){
      if( ( world[i][j] & BIT_FLAG_1 ) != 0 ){
        printf("\033[32m");
        printf("\033[%d;%dH" ,playery,playerx);
        printf("■");
      }else{
        printf("\033[39m");
        printf(" ");
      }
    }
    printf("│\n");
  }
  printf("└");
  for( i = 0 ; i < WORLDX ; i++){
    printf("━");
  }
  printf("┘");
  printf("\033[%d;%dH\n" ,1,1);
  return 0;
}
