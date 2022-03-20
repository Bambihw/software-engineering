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
	char inName[50],outName[50],prName[50],people[50];//定义数组来存储
	scanf("%s %s %s",inName,outName,prName);//输入文件名字，输出文件名字，省份
	r=fopen(inName,"r");//打开输入文件
	assert(r!=NULL);
	w=fopen(outName,"w");//打开输出文件
	assert(w!=NULL);

	yq a[150];
	int i=0;
	while(fscanf(r,"%s%s%d",a[i].provinces,a[i].city,&a[i].number)!=EOF){
		if(prName!=NULL){					//判断有无输入想要的省份
			if(strcmp(prName,a[i].provinces)==0){	//判断输入的省份名字与文件中的省份名字是否一致
				if(i==0){					//输入第一个内容
				printf("%s\n",a[i].provinces);//输出省份
				fprintf(w,"%s\n",a[i].provinces);//将输出的省份打印到文本中
				printf("%s\t %d\n",a[i].city,a[i].number);//输出城市以及确诊人数
				fprintf(w,"%s\t %d\n",a[i].city,a[i].number);//将输出的城市以及确诊人数打印到文本中
				}
				else if(strcmp(a[i].provinces,a[i-1].provinces)==0){//输入属于第一个省份的内容
				printf("%s\t %d\n",a[i].city,a[i].number);
				fprintf(w,"%s\t %d\n",a[i].city,a[i].number);
				}
				else if(strcmp(a[i].provinces,a[i-1].provinces)!=0){//输入其他省份的内容
				printf("%s\n",a[i].provinces);
				fprintf(w,"%s\n",a[i].provinces);
				printf("%s\t %d\n",a[i].city,a[i].number);
				fprintf(w,"%s\t %d\n",a[i].city,a[i].number);
			}
			}
		}
		else{
			if(i==0){						//输入第一个内容
				printf("%s\n",a[i].provinces);//输出省份
				fprintf(w,"%s\n",a[i].provinces);//将输出的省份打印到文本中
				printf("%s\t %d\n",a[i].city,a[i].number);//输出城市以及确诊人数
				fprintf(w,"%s\t %d\n",a[i].city,a[i].number);//将输出的城市以及确诊人数打印到文本中
			}
			else if(strcmp(a[i].provinces,a[i-1].provinces)==0){//输入属于第一个省份的内容
				printf("%s\t %d\n",a[i].city,a[i].number);//输出城市以及确诊人数
				fprintf(w,"%s\t %d\n",a[i].city,a[i].number);//将输出的城市以及确诊人数打印到文本中
			}
			else if(strcmp(a[i].provinces,a[i-1].provinces)!=0){//输入其他省份的内容
				printf("\n");//换行
				fprintf(w,"\n");
				printf("%s\n",a[i].provinces);//输出省份
				fprintf(w,"%s\n",a[i].provinces);//将输出的省份打印到文本中
				printf("%s\t %d\n",a[i].city,a[i].number);//输出城市以及确诊人数
				fprintf(w,"%s\t %d\n",a[i].city,a[i].number);//将输出的城市以及确诊人数打印到文本中
			}
		}
		i++;
	}
	fclose(r);//关闭输入文本
	fclose(w);//关闭输出文本

	system("pause");
	return 0;
}
