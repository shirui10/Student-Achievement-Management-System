#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//头文件

#define N 100

typedef struct StuLink{
    long int xh;
    char xm[20];
    float cj;
    char dj;
    int mc;
    struct StuLink *next;
} stu;
//设定链表里的元素，与建立链表操作的缩写

stu *head=NULL;
stu *tail=NULL;
stu *piliang(stu *head, int i);
void ReadFromFile(long int number, char name[20], float score);
int SaveToFile(stu *head);
stu *Insert_Node(stu *head);
stu *Edit_Node(stu *head);
stu *Rank_Link(stu *head);
stu *Delete_Node(stu *head);
void Query_Node(stu *head);
void Analysis_Link(stu *head);
void Sort_Link(stu *head,int n);
void Output_Link(stu *head,int n);
void cj_jiangxu(stu *head);
void xh_shengxu(stu *head);
void Display(stu *head);
//所需函数声明


int main(){
    int n;
    int j=0;
    FILE *fp = NULL;
    stu *newhead=NULL;
    
    if((fp=fopen("student.dat", "rb"))==NULL){
        printf("File cannot open!");
        exit(0);
    }
    printf("读取信息中...\n\n");
    
    stu stu;
    
    while (!feof(fp)) {
        if((int)fread(&stu, sizeof(stu), 1, fp)==0) break;
        ReadFromFile(stu.xh, stu.xm, stu.cj);
        j++;
    }
    Rank_Link(head);
    if ((fclose(fp))){
        printf("Cannot close the file!\n");
        exit(0);
    }
    
    printf("共读取到%d个学生的数据。\n\n", j);
    
    
    while(1){
        system("cls");
        printf("       主菜单—学生成绩管理      \n");
        printf(" =============================\n");
        printf("|  1-批量添加      2-链表维护    |\n");
        printf("|  3-计算排序      4-统计分析    |\n");
        printf("|  5-报表输出      0-退出       |\n");
        printf(" =============================\n");
        printf("     请输入菜单编号(0-5):");
        scanf("%d",&n);
        
        while(!(n==1 || n==2 || n==3 || n==4 || n==5 || n == 0 ) ){
            printf("输入错误，请重新输入...");
            scanf("%d",&n);
        }
        
        if(n==0){
            printf("欢迎继续使用学生管理系统！\n");
            break;
        }
            
        switch(n){
                
            case 1:
                newhead=piliang(tail,j);
                tail->next=newhead;
                printf("\n批量添加后的结果如下：\n");
                Display(head);
                fflush(stdin);
                printf("\n按回车键继续...\n");
                getchar();
                break;
                
            case 2:
                while(1){
                    system("cls");
                    printf("   二级菜单—链表维护管理\n");
                    printf(" ======================\n");
                    printf("|   1-添加一个学生信息    |\n");
                    printf("|   2-修改一个学生信息    |\n");
                    printf("|   3-删除一个学生信息    |\n");
                    printf("|   4-查询一个学生信息    |\n");
                    printf("|   0-退回上级菜单       |\n");
                    printf(" ======================\n");
                    printf("  请输入菜单编号(0-4):");
                    scanf("%d",&n);
                    
                    while(!(n==1 || n==2 || n==3 || n==4 || n==5 || n == 0 )){
                        printf("输入错误，请重新输入...");
                        scanf("%d",&n);
                    }
                    
                    if(n==0)break;
                    else
                        switch(n){
                            case 1:
                                head=Insert_Node(head);
                                head=Rank_Link(head);
                                printf("\n添加信息后的名单如下：\n");
                                Display(head);
                                break;
                                
                            case 2:
                                head=Edit_Node(head);
                                head=Rank_Link(head);
                                printf(" \n修改信息后的名单如下：\n");
                                Display(head);
                                break;
                            
                            case 3:
                                head=Delete_Node(head);
                                head=Rank_Link(head);
                                printf("\n删除信息后的名单如下：\n");
                                Display(head);
                                break;
                                
                            case 4:
                                Query_Node(head);break;
                        }
                    
                    fflush(stdin);
                    printf("请按回车键继续...");
                    getchar();
                    }
                break;
                
            case 3:
                while(1){
                    system("cls");
                    printf("          二级菜单—计算排序管理\n");
                    printf(" ======================================\n");
                    printf("|   1-计算学生名次     2-按学号升序排序    |\n");
                    printf("|   3-按成绩降序排序   0-返回上级菜单      |\n");
                    printf(" ======================================\n");
                    printf("         输入菜单编号(0-3): ");
                    scanf("%d",&n);
                       
                    while(!(n==1 || n==2 || n==3 || n == 0 ) ){
                            printf("输入错误，请重新输入...");
                            scanf("%d",&n);
                    }
                        
                    if(n==0)break;
                    else
                        switch(n){
                               
                            case 1:
                                printf("计算名次后的学生信息表如下：\n");
                                printf("学号\t\t\t\t\t姓名\t\t成绩\t\t等级\t\t名次\n");
                                head=Rank_Link(head);
                                xh_shengxu(head);
                                break;
                               
                            case 2:
                                printf("按学号升序排序后的学生信息表如下：\n");
                                printf("学号\t\t\t\t\t姓名\t\t成绩\t\t等级\t\t名次\n");
                                Sort_Link(head,2);
                                break;
                               
                            case 3:
                                printf("按成绩降序排序后的学生信息表如下：\n");
                                printf("学号\t\t\t\t\t姓名\t\t成绩\t\t等级\t\t名次\n");
                                Sort_Link(head,3);
                                break;
                            }
                    fflush(stdin);
                    printf("请按回车键继续...");
                    getchar();
                }
                break;
                
            case 4:
                Analysis_Link(head);
                fflush(stdin);
                printf("请按回车键继续...");
                getchar();
                break;
                
            case 5:
                while(1){
                    system("cls");
                    printf("          二级菜单—报表输出管理\n");
                    printf(" ========================================\n");
                    printf("|  1-学号升序   2-成绩降序   0-返回上级菜单   |\n");
                    printf(" ========================================\n");
                    printf("           输入菜单编号(0-2): ");
                    scanf("%d",&n);
                       
                    while(!(n==1 || n==2 || n==3 || n == 0  ) ){
                        printf("输入错误，请重新输入");
                        scanf("%d",&n);
                    }
                    
                    if(n==0)break;
                    else
                        switch(n){
                                
                            case 1:
                                printf("\n学生信息表如下：\n");
                                Output_Link(head,1);
                                break;
                                
                            case 2:
                                printf("\n学生信息表如下：\n");
                                Output_Link(head,2);
                                break;
                        }
                        
                    fflush(stdin);
                    printf("请按回车键继续...");
                    getchar();
                }
        }
    }
    
    printf("\n正在保存信息中...\n");
    printf("\n共保存%d个学生信息。\n",SaveToFile(head));
    return 0;
}
//主函数


stu *piliang(stu *head, int i){
    int j=0;
    stu *p1,*p2=NULL;
    if((p1=(stu*) malloc(sizeof(stu)))==NULL){
        printf("动态内存分配失败。\n");
        exit(0);
    }
    printf("姓名、成绩---（成绩为-1时，输入停止）\n");
    scanf("%s%f",p1->xm,&p1->cj);
    
    while(p1->cj!=-1){
        j++;
        p1->xh=j+i;
        if(p1->cj>=90) p1->dj='A';
        else if(p1->cj>=80 && p1->cj<90) p1->dj='B';
        else if(p1->cj>=70 && p1->cj<80) p1->dj='C';
        else if(p1->cj>=60 && p1->cj<70) p1->dj='D';
        else p1->dj='E';
        if(j==1){
            head=p1;
        }
        else{
            p2->next=p1;
        }
            p2=p1;
            if((p1=(stu*) malloc(sizeof(stu)))==NULL){
                printf("动态内存分配失败。\n");
                exit(0);
            }
            scanf("%s%f",p1->xm,&p1->cj);
    }
    p2->next=NULL;
   
    return head;
}


void ReadFromFile(long int number, char name[20], float score){
    stu *p;
    if ((p=(stu*)malloc(sizeof(stu)))==NULL){
        printf("Failed!\n");
        exit(0);
    }
    
    p->next=NULL;
    
    p->xh=number;
    strcpy(p->xm, name);
    p->cj=score;
    if(score>=90) p->dj='A';
    else if(score>=80 && score<90) p->dj='B';
    else if(score>=70 && score<80) p->dj='C';
    else if(score>=60 && score<70) p->dj='D';
    else p->dj='E';
    
    if (head==NULL)head=p;
    else tail->next=p;
    tail=p;
}


int SaveToFile(stu *head){
    stu *p=NULL;
    Sort_Link(head, 2);
    
    FILE *fp;
    stu stu;
    
    if ((fp=fopen("student.dat","wb"))==NULL) {
        printf("File open error!\n ");
        exit(0);
    }
    
    int j=0;
    for (p=head; p!=NULL; p=p->next) {
        stu.xh=p->xh;
        strcpy(stu.xm, p->xm);
        stu.cj=p->cj;
        
        fwrite(&stu, sizeof(stu), 1, fp);
        j++;
    }
    
    if (fclose(fp)) {
        printf("Cannot open file!\n");
        exit(0);
    }
    
    return(j);
}


stu *Insert_Node(stu *head){
    stu *p1=head, *p0=NULL, *p2=NULL;
    char name[20];
    float score;
    
    printf("请输入姓名和成绩：\n");
    scanf("%s%f",name,&score);
    while(!(score>=0 && score<=100) ){
        printf("输入成绩错误，请重新输入");
        scanf("%s%f",name,&score);
    }
    //输入数据
    
    if((p0=(struct StuLink *)malloc(sizeof(struct StuLink)))==NULL){
        printf("error");
        exit(0);
    }
    //动态分配空间
    
    strcpy(p0->xm,name);
    p0->cj=score;
    //赋值
    
    if(score>=90) p0->dj='A';
    else if(score>=80 && score<90) p0->dj='B';
    else if(score>=70 && score<80) p0->dj='C';
    else if(score>=60 && score<70) p0->dj='D';
    else p0->dj='E';
    //分级
    
    p0->next=NULL;      //设定尾节点
    
    if(p1==NULL){
        p0->xh=1;            //若链表为空，学号为1
        head=p0;
        head->next=NULL;
    }
    
    else{
        while(p1!=NULL){
                p2=p1;
                p1=p1->next;
        }
        p0->xh=p2->xh+1;        //新学号,加上1
        p2->next=p0;
    }
    
    return head;
}


stu *Edit_Node(stu *head){
    stu *p=head;
    int num;
    
    printf("请输入要修改学生的学号：");
    scanf("%d",&num);
    
    while( p->xh != num && p->next!=NULL){
        p=p->next;
    }
    
    if(p->xh==num){
        int score;
        char name[20];
        printf("学号=%ld，姓名=%s，成绩=%.1f，等级=%c，名次=%d\n",p->xh,p->xm,p->cj,p->dj,p->mc);
        printf("请输入姓名和成绩：\n");
        scanf("%s%d",name,&score);
        
        while(!(score>=0 && score<=100) ){
            printf("输入成绩错误，请重新输入");
            scanf("%s%d",name,&score);
        }
        //输入需要的姓名成绩
        
        strcpy(p->xm,name);
        p->cj=score;
        //修改
           
        if(score>=90) p->dj='A';
        else if(score>=80 && score<90) p->dj='B';
        else if(score>=70 && score<80) p->dj='C';
        else if(score>=60 && score<70) p->dj='D';
        else p->dj='E';
    }
    //重新分级
    
    else printf("没有该学生\n");
    
    return head;
}


stu *Rank_Link(stu *head){
    int i=0;                      //设定计数器，初始化为0
    stu *p1=NULL,*p2=NULL;
    
    for(p1=head;p1!=NULL;p1=p1->next){
        
        for(p2=head;p2!=NULL;p2=p2->next){
            if(p1->cj < p2->cj)
                i++;
        }
        
        p1->mc=i+1;
        i=0;
    }
        
    return head;
}


stu *Delete_Node(stu *head){
    stu *p1 = (stu*)malloc(sizeof(stu));
    stu *p2 = (stu*)malloc(sizeof(stu));
   
    p1=head;
    p2=head;
    
    int num,i;
    
    printf("请输入删除的学生学号: ");
    scanf("%d",&num);
    
    while( num != p1->xh &&  p1->next!=NULL){
        p1=p1->next;
    }
    if(p1->xh == num){
        printf("学号=%ld, 姓名=%s, 成绩=%.1f, 等级=%c 名次=%d \n",p1->xh,p1->xm,p1->cj,p1->dj,p1->mc);
    }
   
    p1=head;
    p2=head;
    
    printf("是否确认删除？1:是  2:否\n");
    scanf("%d", &i);
    
    if(i==2){
        return head;
    }
    
    while(p1!=NULL){
        if(p1->xh == num){
            if(p1 == head){
                head = p1->next;
            }
            else{
                p2->next = p1->next;
                p1 = p1->next;
            }
        }
        else{
            p2 = p1;
            p1 = p1->next;
        }
    }
    
    return head;
}


void Query_Node(stu *head){
    stu *p1=head;
    int num;
    
    printf("请输入要查询的学生学号: ");
    scanf("%d",&num);
    
    while( num != p1->xh &&  p1->next!=NULL){
        p1=p1->next;
    }
    //遍历
    printf("\n");
    if(p1->xh == num){
        printf("学号=%ld, 姓名=%s, 成绩=%.1f, 等级=%c 名次=%d \n\n",p1->xh,p1->xm,p1->cj,p1->dj,p1->mc);
    }
    
    else printf("查无学号为%d的学生\n",num);
}


void Analysis_Link(stu *head){
    int a[5]={0,0,0,0,0};      //设定计数器
    stu *p1=head;
    
    while(p1 !=  NULL){
        if(p1->dj == 'A') a[0]++;
        else if(p1->dj == 'B') a[1]++;
        else if(p1->dj == 'C') a[2]++;
        else if(p1->dj == 'D') a[3]++;
        else if(p1->dj == 'E') a[4]++;
        p1=p1->next;
    }
    //分级，计数
    
    printf("A:90分及以上  B:80分及以上  C:70分及以上  D:60分及以上 E：60分以下\n");
    printf("A级人数=%d\n",a[0]);
    printf("B级人数=%d\n",a[1]);
    printf("C级人数=%d\n",a[2]);
    printf("D级人数=%d\n",a[3]);
    printf("E级人数=%d\n",a[4]);
    //输出各级人数
}


void Sort_Link(stu *head,int n){
    if(n==2) xh_shengxu(head);
    else cj_jiangxu(head);
}


void Output_Link(stu *head,int n){
    if(n==1) xh_shengxu(head);
    else cj_jiangxu(head);
}


void xh_shengxu(stu *head){
    stu *pfirst=(stu*)malloc(sizeof(stu));
    stu *ptail=NULL;
    stu *pminBefore = NULL;
    stu *pmin=NULL;
    stu *p=NULL;
   
    pfirst = NULL;
    while (head != NULL){
        for (p = head, pmin = head; p->next != NULL; p = p->next){
            if (p->next->xh < pmin->xh){
                pminBefore = p;
                pmin       = p->next;
            }
        }
      
        if (pfirst == NULL){
            pfirst = pmin;
            ptail  = pmin;
        }
        else{
            ptail->next = pmin;
            ptail = pmin;
        }
  
        if (pmin == head){
            head = head->next;
        }
        else{
            pminBefore->next = pmin->next;
        }
    }
  
    if (pfirst != NULL){
        ptail->next = NULL;
    }
    
    head = pfirst;
    stu *q = head;
    while(q != NULL){
        printf("%-20ld%-8s%-9.1f%-8c%d\n",q->xh,q->xm,q->cj,q->dj,q->mc);
        q = q->next;
    }
}


void cj_jiangxu(stu *head){
    stu *pfirst=(stu*)malloc(sizeof(stu));
    stu *ptail=NULL;
    stu *pminBefore = NULL;
    stu *pmin=NULL;
    stu *p=NULL;
     
    pfirst = NULL;
    while (head != NULL){
        for (p = head, pmin = head; p->next != NULL; p = p->next){
            if (p->next->cj >= pmin->cj){
                pminBefore = p;
                pmin       = p->next;
            }
        }
        
        if (pfirst == NULL){
            pfirst = pmin;
            ptail  = pmin;
        }
        else{
            ptail->next = pmin;
            ptail = pmin;
        }
    
        if (pmin == head){
            head = head->next;
        }
        else{
            pminBefore->next = pmin->next;
        }
    }
    
    if (pfirst != NULL){
        ptail->next = NULL;
    }
      
    head = pfirst;
    stu *q = head;
    while(q != NULL){
        printf("%-20ld%-8s%-9.1f%-8c%d\n",q->xh,q->xm,q->cj,q->dj,q->mc);
        q = q->next;
    }
}

void Display(stu *head){
    stu *p1=NULL;
    printf("学号\t\t\t\t\t姓名\t\t成绩\t\t等级\t\t名次\n");
    p1=Rank_Link(head);
    while(p1!=NULL){
            printf("%-20ld%-8s%-9.1f%-8c%d\n",p1->xh,p1->xm,p1->cj,p1->dj,p1->mc);
            p1=p1->next;
    }
}
