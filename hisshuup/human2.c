// human1.c（このプログラムの名前）
#include<stdio.h>      // 標準入出力ヘッダのインクルード
#include"ppmlib2.h"    // 画面表示部をカットした ppmlib.h
#include"makefname.c"  // 連番ファイル名の作成


//関数のプロトタイプ宣言（makefname.c中の関数）
void make_filename( char head[], int keta, int num, char fname[] );

// main関数の始まり
int main(void)
{
    int i;              // i:入力ファイル番号
    char fname[256];    // ファイル名用配列（入出力兼用）
    int x,y,col,t1=20,t2=18;        // 制御変数
    int limitup =30;
    int limitdown =-30;

    load_color_image( 1,"back.ppm" );
    load_color_image( 2,"back.ppm" );
    for(i=1;i<=200;i+=20){
        // 連番のファイル名を生成（org00001.ppm～org00200.ppm）
        make_filename( "org", 5, i, fname );   // 5:数字の桁数
        // 画像をNo.0に読み込む
        load_color_image( 0, fname );


        for(y=0;y<height[0];y=y+1){
            for(x=0;x<width[0];x=x+1){
                image[0][x][y][0]=(image[0][x][y][0]*t1+image[1][x][y][0]*t2)/(t1+t2);
		image[0][x][y][1]=(image[0][x][y][1]*t1+image[1][x][y][1]*t2)/(t1+t2);
		image[0][x][y][2]=(image[0][x][y][2]*t1+image[1][x][y][2]*t2)/(t1+t2);
            }
        }
	
	t2-=2;        
        for(y=0;y<height[0];y++){
            for(x=0;x<width[0];x++){
                    if(((image[0][x][y][0]-image[1][x][y][0]>=limitup)||(image[0][x][y][0]-image[1][x][y][0]<=limitdown))||((image[0][x][y][1]-image[1][x][y][1]>=limitup)||(image[0][x][y][1]-image[1][x][y][1]<=limitdown))||((image[0][x][y][2]-image[1][x][y][2]>=limitup)||(image[0][x][y][2]-image[1][x][y][2]<=limitdown))){image[2][x][y][0]=image[0][x][y][0];image[2][x][y][1]=image[0][x][y][1];image[2][x][y][2]=image[0][x][y][2];}
            }
        }
    }
    save_color_image( 2, "human.ppm" );
    printf("結果画像を human.ppm で出力しました\n");
    return 0;  // プログラムの正常終了
}

