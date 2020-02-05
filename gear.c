#include<stdio.h>

typedef struct{
	int z1;
	int z2;
	double sokuhi1;
	double gosa;
}resultData_t;

typedef struct{
	double sokuhi;
	double error;
	int zMin;
	int zMax;
}inputData_t;

int main(){
	resultData_t result = {0,0,0,0};
	inputData_t input = {0,0,0,0};

	printf("input...\n");

	do{
#ifdef DEBUG
		printf("%f",input.sokuhi);
#endif //DEBUG
		printf("速比>>>>");
		scanf("%lf",&input.sokuhi);
	}while(input.sokuhi <= 1.0);

	do{
		printf("許容誤差(%%)>>>>");
		scanf("%lf",&input.error);
		input.error /= 100.0;
#ifdef DEBUG
		printf("%f\n",input.error );
#endif //DEBUG
	}while(input.error < 0  || 1 < input.error);

	do{
		printf("最少歯数>>>>");
		scanf("%d",&input.zMin);
	}while(input.zMin < 6);

	do{
		printf("最大歯数>>>>");
		scanf("%d",&input.zMax);
	}while(input.zMax <= input.zMin);

	printf("----------------------------\n");
	printf("z1\tz2\tz2/z1\t差\n");
	printf("----------------------------\n");

	for(result.z1 = input.zMin; result.z1 < input.zMax / (input.sokuhi - input.sokuhi * input.error) + 1; result.z1++){
#ifdef DEBUG
			printf("%d\t", result.z1);
#endif //DEBUG
		result.z2 = result.z1 * (input.sokuhi - input.sokuhi * input.error) - 1;
		while(result.z2 <= result.z1 * (input.sokuhi + input.sokuhi * input.error)+1){
#ifdef DEBUG
			printf("%d\t", result.z2);
#endif //DEBUG
			result.sokuhi1 = (double)result.z2 / (double)result.z1;
#ifdef DEBUG
			printf("%f\t", result.rate);
			printf("%f\t", input.sokuhi + input.sokuhi * input.error);
			printf("%f\n", input.sokuhi - input.sokuhi * input.error);
#endif //DEBUG
			if(input.sokuhi - input.sokuhi * input.error <= result.sokuhi1 && result.sokuhi1 <= input.sokuhi + input.sokuhi * input.error ){
				result.gosa = result.sokuhi1 - input.sokuhi;
				printf("%d\t%d\t%f\t%f\n",result.z1 ,result.z2 ,result.sokuhi1 ,result.gosa);
			}
			result.z2++;
			if(result.z2 > input.zMax)	break;

		}
	}
	return 0;

}
