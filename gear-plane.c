#include<stdio.h>
#include<math.h>

int main(){
//input variable
	int z1;
	int z2;
	double rate;
	double dif;
//result variable
	double sokuhi;
	double error;
	int zMin;
	int zMax;

	printf("input...\n");
//input speed rate
	do{
		printf("%f",sokuhi);
		printf("速比>>>>");
		scanf("%lf",&sokuhi);
	}while(sokuhi <= 1.0);
//inpout allow error
	do{
		printf("許容誤差(%)>>>>");
		scanf("%lf",&error);
		error /= 100.0;
	}while(error < 0  || 1 < error);
//input minimamu no. of teeth
	do{
		printf("最少歯数>>>>");
		scanf("%d",&zMin);
	}while(zMin < 6);
//input mazimamu no. of teeth
	do{
		printf("最大歯数>>>>");
		scanf("%d",&zMax);
	}while(zMax <= zMin);

	printf("----------------------------\n");
	printf("z1\tz2\tz2/z1\t差\n");
	printf("----------------------------\n");

	for(z1 = zMin; z1 < zMax; z1++){
		int flag = 0;
		z2 = 0;
		while(1){
			rate = (double)z2 / (double)z1;
			if(sokuhi - sokuhi * error <= rate && rate <= sokuhi + sokuhi * error ){
				flag = 1;
				dif = rate - sokuhi;
				printf("%d\t%d\t%f\t%8.6f\n",z1 ,z2 ,rate ,dif);
			}else if(flag){
				break;
			}
			z2++;
			if(z2 >= zMax)	break;
		}
	}
	return 0;
}
