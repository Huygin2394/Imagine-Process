#include<stdio.h>      // �W�����o�̓w�b�_�̃C���N���[�h
#include"ppmlib2.h"    // ��ʕ\�������J�b�g���� ppmlib.h
#include"makefname.c"  // �A�ԃt�@�C�����̍쐬


void make_filename( char head[], int keta, int num, char fname[] );

int main(void)
{
    int i;              
    char fname[400];    
    int x,y,col;        

    for(i=35;i<=75;i++){
        
        make_filename( "oyoumondai/frameppm/video", 3, i*5, fname );
        
        load_color_image( 0, fname );

	make_filename( "oyoumondai/finish/video", 3, i, fname );

	save_color_image( 0, fname );
        
    }
    return 0;
}

