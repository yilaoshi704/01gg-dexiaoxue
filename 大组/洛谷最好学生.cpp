#include <stdio.h>
struct stu{
    char name[9];
	int yw;
	int sx;
	int yy;	
};
int best(struct stu a[],int n){
	int i,x=0;
	int sum=a[0].yw+a[0].sx+a[0].yy;
	for (i=1;i<n;i++){
		if (sum<a[i].yw+a[i].sx+a[i].yy){
			sum=a[i].yw+a[i].sx+a[i].yy;
			x=i;
		}
	}
	return x;
}
int main(){
	int i,n,p;
	scanf("%d",&n);
	struct stu student[n];
	for (i=0;i<n;i++){
		scanf("%s",&student[i].name);
		scanf("%d %d %d",&student[i].yw,&student[i].sx,&student[i].yy);
	}
	p=best(student,n);
	printf("%s %d %d %d",student[p].name,student[p].yw,student[p].sx,student[p].yy);
	return 0;
} 
