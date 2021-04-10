#include<stdio.h>
#include<string.h>
#include "student.h"
//请在下面给出程序中所用到的自定义函数的完整定义

void inputInformation(Student*stus,int N){
    for(int i = 0; i < N; i++){
        printf("学生%d的学号，姓名，平时成绩，考试成绩(空格分隔):\n",i);
        scanf("%s %s %f %f",stus[i].stu_number,stus[i].stu_name,&stus[i].usual_mark,&stus[i].exam_mark);
        stus[i].overall_mark = stus[i].usual_mark * 0.2 + stus[i].exam_mark * 0.8;
    }
}

void saveInformation(Student*stus,int N,char*filename){
    FILE *fp = fopen(filename,"w");
    if (fp == NULL)
        return;
    for (int i = 0; i < N; i++){
        fprintf(fp,"学号=%s\t姓名=%s\t平时成绩=%.2lf\t考试成绩=%.2lf\t总评成绩=%.2lf\n",
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
    printf("全部学生:\n");
    while (fgets(temp,80,fp)){
        sscanf(temp,"学号=%s\t姓名=%s\t平时成绩=%f\t考试成绩=%f\t总评成绩=%f",
               tp.stu_number,tp.stu_name,&tp.usual_mark,&tp.exam_mark,&tp.overall_mark);
        printf("学号=%s,姓名=%s,平时成绩=%.2f,考试成绩=%.2f,总评成绩=%.2f\n",tp.stu_number,tp.stu_name,tp.usual_mark,tp.exam_mark,tp.overall_mark);
        if (control){
            max = min = tp;
            control = 0;
        }
        if(min.overall_mark > tp.overall_mark)
            min = tp;
        if(max.overall_mark < tp.overall_mark)
            max = tp;
    }
    printf("最低分学生:\n");
    printf("学号=%s,姓名=%s,平时成绩=%.2f,考试成绩=%.2f,总评成绩=%.2f\n",
           min.stu_number,min.stu_name,min.usual_mark,
           min.exam_mark,min.overall_mark);
    printf("最高分学生:\n");
    printf("学号=%s,姓名=%s,平时成绩=%.2f,考试成绩=%.2f,总评成绩=%.2f\n",
           max.stu_number,max.stu_name,max.usual_mark,
           max.exam_mark,max.overall_mark);
}