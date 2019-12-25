#include <stdio.h>
#include <stdint.h>

int zeller(int y, int m, int d, int *dtw);

int main(){
  int year, month, day, dtw, ff;
  char dow[7][4] = {"日\0", "月\0", "火\0", "水\0", "木\0", "金\0", "土\0"};
  printf("input date(yyyy/mm/dd) >>>> ");
  scanf("%d/%d/%d",&year, &month, &day);
  ff = zeller(year, month, day, &dtw);

  if(ff == 0){
    printf("%s曜日\n",dow[dtw] );

  }else{
    printf("計算できません\t%d\n",ff );
  }

}

int zeller(int year, int month, int day, int *dtw){
  int h=0;
  int r=0;
  int k = 0;//0:グレコリオ暦  1:ユリウス暦
  int c=0;
  int y = 0;
  if(year == 4 && month < 3)  return 1;
  if(year == 4 && month == 3 && day == 1) return 1;
  if(year < 4)  return 1;

  if(month > 12) return 2;

  if(year == 1582 && month == 10 && (5 <= day && day <= 14)) return 3;

 if(year == 1582 && month == 10 && day <= 4) k = 1;

  if(month == 1 || month == 2){
    year -= 1;
    month += 12;
  }

  c = year / 100;
  y = year % 100;

  if(k){
    r = 5 + 6*c;
  }else{
    r = (c / 4.0) + (5 * c);
  }

  h = (int)(day + (26 * (month + 1) / 10) + y + (y / 4) + r) % 7;

  *dtw = (h + 6) % 7;
  return 0;
}
