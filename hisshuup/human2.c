// human1.c�i���̃v���O�����̖��O�j
#include<stdio.h>      // �W�����o�̓w�b�_�̃C���N���[�h
#include"ppmlib2.h"    // ��ʕ\�������J�b�g���� ppmlib.h
#include"makefname.c"  // �A�ԃt�@�C�����̍쐬


//�֐��̃v���g�^�C�v�錾�imakefname.c���̊֐��j
void make_filename( char head[], int keta, int num, char fname[] );

// main�֐��̎n�܂�
int main(void)
{
    int i;              // i:���̓t�@�C���ԍ�
    char fname[256];    // �t�@�C�����p�z��i���o�͌��p�j
    int x,y,col,t1=20,t2=18;        // ����ϐ�
    int limitup =30;
    int limitdown =-30;

    load_color_image( 1,"back.ppm" );
    load_color_image( 2,"back.ppm" );
    for(i=1;i<=200;i+=20){
        // �A�Ԃ̃t�@�C�����𐶐��iorg00001.ppm�`org00200.ppm�j
        make_filename( "org", 5, i, fname );   // 5:�����̌���
        // �摜��No.0�ɓǂݍ���
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
    printf("���ʉ摜�� human.ppm �ŏo�͂��܂���\n");
    return 0;  // �v���O�����̐���I��
}

