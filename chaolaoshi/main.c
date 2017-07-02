#include <stdio.h>
#include <string.h>
int main()
{
    char lat[9];
    char mat[63];
    char date[7];
    char num[70];
    char time[7];
    char longitude[10];
    char high[5];
    char speed[6];
    char snum[3];
    char dir[6];
    int i,math,math1,math2,math3;
    double spe,spe1;
    FILE *fp1,*fp2;
    fp1=fopen("C:\\Users\\lenovo\\Desktop\\chaolaoshi\\GPS170510.txt","r");
    fp2=fopen("C:\\Users\\lenovo\\Desktop\\chaolaoshi\\GPS.CSV","w+");
if(fp1==NULL)
    printf("���ļ�����");
    else
        fprintf(fp2,"���� ,ʱ�� ,ά�� ,���� ,���� ,�ٶ� ,�������� ,����\n");

while(!feof(fp1))
{
    {
        
        fscanf(fp1,"%s%s",mat,num);
        
        for(i=0; i<2; i++)  /*����*/ 
            date[i]=mat[i+55];
            date[2]='\0';
        fprintf(fp2,"20%s��",date);
        
        for(i=0; i<2; i++)
            date[i]=mat[i+51];
            date[2]='\0';
        fprintf(fp2,"%s��",date);
        
        for(i=0; i<2; i++)
            date[i]=mat[i+53];
            date[2]='\0';
        fprintf(fp2,"%s��,",date);
        
        {
            
        for(i=0; i<2; i++)   /*ʱ��*/ 
            time[i]=mat[i+7];
            math1=10*(time[0]-'0');
            math2=1*(time[1]-'0');
            math=math1+math2+8;
        fprintf(fp2,"%dСʱ",math);
        
        for(i=0; i<2; i++)
            time[i]=mat[i+9];
            math1=10*(time[0]-'0');
            math2=1*(time[1]-'0');
            math=math1+math2;
            time[2]='\0';
        fprintf(fp2,"%d��",math);
  
        for(i=0; i<2;i++)
            time[i]=mat[i+11];
            math1=10*(time[0]-'0');
            math2=1*(time[1]-'0');
            math=math1+math2;
            time[2]='\0';
        fprintf(fp2,"%d��,",math);
        }
        
        for(i=0; i<2; i++)    /*γ��*/ 
            lat[i]=mat[i+16];
            lat[2]='\0';
        fprintf(fp2,"N %s.",lat);
        for(i=0; i<6; i++)
            lat[i]=mat[i+18];
            lat[6]='\0';
        fprintf(fp2,"%s��,",lat);
        
        
        for(i=0; i<3; i++)    /*����*/ 
            longitude[i]=mat[i+27];
            longitude[3]='\0';
        fprintf(fp2,"E %s.",longitude);
        for(i=0; i<9; i++)
            longitude[i]=mat[i+30];
            longitude[6]='\0';
        fprintf(fp2,"%s��,",longitude);
        
        
        for(i=0; i<4; i++)    /*����*/ 
            high[i]=num[i+43];
            high[4]='\0';
        fprintf(fp2,"%sm,",high);
        
        
        for(i=0; i<5; i++)    /*�ٶ�*/
            speed[i]=mat[i+39];
            math1=100*(speed[0]-'0');
            math2=10*(speed[1]-'0');
            math3=1*(speed[2]-'0');
            spe1=0.1*(speed[4]-'0');
            spe=(math1+math2+math3+spe1)*1.852;
            speed[5]='\0';
        fprintf(fp2,"%.4fkm/s,",spe);
        
        
        for(i=0; i<2; i++)   /*��������*/ 
            snum[i]=num[i+39];
            math1=10*(snum[0]-'0');
            math2=1*(snum[1]-'0');
            math=math1+math2;
            snum[2]='\0';
        fprintf(fp2,"%d,",math);
        
        
        for(i=0; i<5; i++)    /*����*/ 
            dir[i]=mat[i+45];
            dir[5]='\0';
        fprintf(fp2,"%s��\n",dir);
    }
}
    fclose(fp1);
    fclose(fp2);
    return 0;
}
