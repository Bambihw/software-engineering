#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct yiqing{//定义结构体来存储文件的内容
	char provinces[32];
	char city[32];
	int number;
}yq;

int main(int argc,char*argv[]){
	FILE *r;
	FILE *w;
	
	int b;//定义一个变量来统计人数
    int c;
	char d[50];
	char inName[50],outName[50],prName[50];//定义数组来存储
	scanf("%s %s %s",inName,outName,prName);//输入文件名字，输出文件名字，省份
	r=fopen(inName,"r");//打开输入文件
	assert(r!=NULL);
	w=fopen(outName,"w");//打开输出文件
	assert(w!=NULL);

	yq a[150];
	int i=0;
	while(fscanf(r,"%s%s%d",a[i].provinces,a[i].city,&a[i].number)!=EOF){
		if(prName!=NULL){					//判断有无输入想要的省份` 
			if(strcmp(prName,a[i].provinces)==0){	//判断输入的省份名字与文件中的省份名字是否一致
				if(i==0){
					b=0;					
					b=a[i].number;				
					printf("%s\n",a[i].provinces);//输出省份
					fprintf(w,"%s\n",a[i].provinces);//将输出的省份打印到文本中
					printf("%s\t %d\t %d\n",a[i].city,a[i].number,b);//输出城市以及确诊人数
					fprintf(w,"%s\t %d\t %d\n",a[i].city,a[i].number,b);//将输出的城市以及确诊人数打印到文本中
					
				}
				else if(strcmp(a[i].provinces,a[i-1].provinces)==0){//输入属于第一个省份的内容
					b=b+a[i].number;
                    if(a[i].number>a[i-1].number){
                        c=a[i].number;
                        a[i].number=a[i-1].number;
                        a[i-1].number=c;
                        printf("%s\t %d\t %d\n",a[i].city,a[i].number,b);
					    fprintf(w,"%s\t %d\t %d\n",a[i].city,a[i].number,b);
                    }
                    else if(a[i].number<a[i-1].number){
                        printf("%s\t %d\t %d\n",a[i].city,a[i].number,b);
					    fprintf(w,"%s\t %d\t %d\n",a[i].city,a[i].number,b);                        
                    }
                    else{
                        if(strcmp(a[i].city,a[i-1].city)>0){
                            c=a[i].number;
                            a[i].number=a[i-1].number;
                            a[i-1].number=c;
                            printf("%s\t %d\t %d\n",a[i].city,a[i].number,b);
					        fprintf(w,"%s\t %d\t %d\n",a[i].city,a[i].number,b);
                        }
                        else{//反之不换
					        printf("%s\t %d\t %d\n",a[i].city,a[i].number,b);
					        fprintf(w,"%s\t %d\t %d\n",a[i].city,a[i].number,b);
                        }                        
                    }

				}
				else if(strcmp(a[i].provinces,a[i-1].provinces)!=0){//输入其他省份的内容
					b=0;
					b=b+a[i].number;
					printf("%s\n",a[i].provinces);
					fprintf(w,"%s\n",a[i].provinces);
					printf("%s\t %d\t %d\n",a[i].city,a[i].number,b);
					fprintf(w,"%s\t %d\t %d\n",a[i].city,a[i].number,b);
				}
			}
		}
		i++;
	}
	fclose(r);//关闭输入文本
	fclose(w);//关闭输出文本

	system("pause");
	return 0;
}
