#include<stdio.h>
#include<string.h>
#include "student.h"
//��������������������õ����Զ��庯������������

void inputInformation(Student*stus,int N){
    for(int i = 0; i < N; i++){
        printf("ѧ��%d��ѧ�ţ�������ƽʱ�ɼ������Գɼ�(�ո�ָ�):\n",i);
        scanf("%s %s %f %f",stus[i].stu_number,stus[i].stu_name,&stus[i].usual_mark,&stus[i].exam_mark);
        stus[i].overall_mark = stus[i].usual_mark * 0.2 + stus[i].exam_mark * 0.8;
    }
}

void saveInformation(Student*stus,int N,char*filename){
    FILE *fp = fopen(filename,"w");
    if (fp == NULL)
        return;
    for (int i = 0; i < N; i++){
        fprintf(fp,"ѧ��=%s\t����=%s\tƽʱ�ɼ�=%.2lf\t���Գɼ�=%.2lf\t�����ɼ�=%.2lf\n",
                stus[i].stu_number,stus[i].stu_name,stus[i].usual_mark,
                stus[i].exam_mark,stus[i].overall_mark);
    }
    fclose(fp);
}

void outputInformation(char*filename){
    FILE *fp = fopen(filename, "r");
    Student min,max,tp;
    char temp[80];
    int control = 1;
    if (fp == NULL)
        return;
    printf("ȫ��ѧ��:\n");
    while (fgets(temp,80,fp)){
        sscanf(temp,"ѧ��=%s\t����=%s\tƽʱ�ɼ�=%f\t���Գɼ�=%f\t�����ɼ�=%f",
               tp.stu_number,tp.stu_name,&tp.usual_mark,&tp.exam_mark,&tp.overall_mark);
        printf("ѧ��=%s,����=%s,ƽʱ�ɼ�=%.2f,���Գɼ�=%.2f,�����ɼ�=%.2f\n",tp.stu_number,tp.stu_name,tp.usual_mark,tp.exam_mark,tp.overall_mark);
        if (control){
            max = min = tp;
            control = 0;
        }
        if(min.overall_mark > tp.overall_mark)
            min = tp;
        if(max.overall_mark < tp.overall_mark)
            max = tp;
    }
    printf("��ͷ�ѧ��:\n");
    printf("ѧ��=%s,����=%s,ƽʱ�ɼ�=%.2f,���Գɼ�=%.2f,�����ɼ�=%.2f\n",
           min.stu_number,min.stu_name,min.usual_mark,
           min.exam_mark,min.overall_mark);
    printf("��߷�ѧ��:\n");
    printf("ѧ��=%s,����=%s,ƽʱ�ɼ�=%.2f,���Գɼ�=%.2f,�����ɼ�=%.2f\n",
           max.stu_number,max.stu_name,max.usual_mark,
           max.exam_mark,max.overall_mark);
}