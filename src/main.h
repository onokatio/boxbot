int BIT_FLAG_1   = 0x0001; // 2進数 : (0000 0000 0000 0001)
int BIT_FLAG_2   = 0x0002; // 2進数 : (0000 0000 0000 0010)
int BIT_FLAG_4   = 0x0004; // 2進数 : (0000 0000 0000 0100)
int BIT_FLAG_8   = 0x0008; // 2進数 : (0000 0000 0000 1000)
int BIT_FLAG_16  = 0x0010; // 2進数 : (0000 0000 0001 0000)
int BIT_FLAG_32  = 0x0020; // 2進数 : (0000 0000 0010 0000)
int BIT_FLAG_64  = 0x0040; // 2進数 : (0000 0000 0100 0000)
int BIT_FLAG_128 = 0x0080; // 2進数 : (0000 0000 1000 0000)
//↑どこかのサイトで見つけた。ビットを扱うための変数。

#define VMX 62
#define VMY 18
#define WORLDX VMX-2
#define WORLDY VMY-4

short vm[VMX][VMY];//画面の配列
short world[WORLDX][WORLDY];//ワールドの配列

char read_byte = 0, in_char = 0;//キーボード入力用
int playerx=2,playery=4;//最初のプレイヤー座標
int playerx_old=3,playery_old=5;//最初のプレイヤー元座標
int fpscounter = 0;//fpsをカウントする奴
int roop = 1;//これが0になると終了する。
char *configname = "boxbot.cfg";//設定ファイルの名前
FILE *configfp;//設定ファイル入出力用のファイルポインタ
char config[100];//設定ファイル用のメモリ
int i,j;
