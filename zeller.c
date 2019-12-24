#include <stdio.h>
#include <math.h>

int zeller(int y, int m, int d, int *dtw);

int main(){
  int year, month, day, dtw, ff;
  printf("input date(yyyy/mm/dd) >>>> ");
  scanf("%d/%d/%d",&year, &month, &day);
  ff = zeller(year, month, day, &dtw);
  if(ff == 0){
    switch (dtw) {
      case 1:
        printf("月曜日");
        break;
      case 2:
        printf("火曜日");
        break;
      case 3:
        printf("水曜日");
        break;
      case 4:
        printf("木曜日");
        break;
      case 5:
        printf("金曜日");
        break;
      case 6:
        printf("土曜日");
        break;
      case 6:
        printf("日曜日");
        break;
    }
  }
  if(ff == 0){

  }
  if(ff == 0){

  }
  if(ff == 0){

  }
}
