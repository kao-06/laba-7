#include <stdio.h>
#include <stdlib.h>
void int_in(int* n){
    char c[100];
    int error = 0;
    do{
    error = 0;
    fgets(c, sizeof(c), stdin);

    if (c[0] < '0' || c[0] > '9') {
      if (c[0] != '-') {
        error = 1;
      }
    }

    for (int i = 1; c[i] != '\n'; i++)
    {
      if (c[i] < '0' || c[i] > '9') {
        error = 1;
        break;
      }
    }

    if(!error)
    {
      if (sscanf(c, "%d", n) == 1)
        {
          return;
        }
      else{printf("Please enter one number\n");}
    }
    else{printf("Please enter a number\n");}
    }while(error);
    return;
}
void delete(char* c, int* n, int k){
  int k1 = 0, i = 0, n1 = *n, mem_i, f = 0, l = 0;
  char* temp;
  temp = (char*) malloc(1 * sizeof(char));
  while(1){
    if(c[i] != ' '){
      if(f == 0){
        /*puts("||||||||||||||||||");
        printf("%d \n", i);
        puts("||||||||||||||||||");*/
        mem_i = i;
        f = 1;
      }
      k1++;
      /*puts("******************");
      printf("%d \n", k1);
      puts("^^^^^^^^^^^^^^^^^^");
      printf("%c \n", c[i]);
      puts("******************");*/
    }
    //printf("%d // %d || %c ;;", k1, i, c[i]);
    if(k1 > k && (c[i] == ' ' || c[i] == '\n')){
      //puts("()()()()()()()()()()");
      temp = (char*) realloc(temp, (n1 - k1 - 1) * sizeof(char));
      for(int j = 0; j < n1;j++){
        if(j < mem_i - 1 || j > mem_i + k1){
          temp[l] = c[j];
          //printf("%d |||", mem_i);
          l++;
        }
        else{
      /*puts("^^^^^^^^^^^^^^^^^^");
      printf("%c \n", c[j]);
      puts("******************");*/
        }
      }
      /*puts("|||");
      for(int j = 0; j < (n1 - k1 -1);j++)
        printf("%c ", temp[j]);
      puts("|||");*/
      c = (char*) realloc(c, (n1 - k1 - 1) * sizeof(char));
      n1 -= (k1 + 1);
      i -= (k1 + 1);
      for(int j = 0;j < n1;j++){
        c[j] = temp[j];
      }
      k1 = 0;
      f = 0;
      l = 0;
    }
    if(k1 <= k && c[i] == ' '){
     //printf("%c |||", c[i - 1]);
      k1 = 0;
      f = 0;
      l = 0;
    }
    i++;
    if(i > n1){
      *n = n1;
      break;
      }
  }
  free(temp);
}
int main(){
  char t;
  int k, n = 1;
  char* c = (char*) malloc(1 * sizeof(char));
  system("clear");
  puts("Please enter string:");
  while(t != '\n'){
    scanf("%c", &t);
    c = (char*) realloc(c, n * sizeof(char));
    c[n - 1] = t;
    n++;
  }
  puts("Your string:");
  for(int i = 0;i < n;i++)
    printf("%c", c[i]);
    k = -1;
    while(k <= 0){
      puts("Plese enter k:");
      int_in(&k);
    }
  delete(c, &n, k);
  for(int i = 0;i < n;i++)
    printf("%c",c[i]);
puts("");
return 0;}