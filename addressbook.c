#include <stdio.h>
#include<string.h>

void display();
void delete();
void add();
void edit();
void find();

struct dict {
  char name[50];
  char num[11];
  char mail[35];

}sp[25];
int h, i = 1;

int main() {
  printf("----------------------------------------WELCOME TO E PHONE BOOK-------------------------\n");
  int c, y, addcon, a = 1;
  int choice, v, pos;
  char b[50];
  strcpy(sp[1].name, "Tejas");
  strcpy(sp[1].num, "8511708570");
  strcpy(sp[1].mail, "htejas@gmail.com");
  i++;
  strcpy(sp[2].name, "Bhakti");
  strcpy(sp[2].num, "7600230062");
  strcpy(sp[2].mail, "gbhakti@gmail.com");
  i++;
  strcpy(sp[3].name, "Richa");
  strcpy(sp[3].num, "8160235256");
  strcpy(sp[3].mail, "pricha@gmail.com");
  i++;
  while (a) {
    printf("1--->DISPLAY CONTACTS\n2--->DELETING CONTACTS\n3--->ADDING CONTACTS\n4--->EDIT CONTACTS\n5--->FINDING CONTACTS\n6--->EXIT CONTACTS");
    printf("\nENTER YOUR CHOICE:");
    scanf("%d", & choice);

    for (int j = 0; j < 140; j++) {
      printf("_");
    }
    switch (choice) {
      case 1:
        display();
        break;
        
      case 2:
        delete();
        break;
      case 3:
        add();
        break;
      
      case 4:
        edit();
        break;
        
      case 5:
        find();
        break;
        
      case 6:
        a = 0;
        break;
        
      default:
        printf("\nINVALID CHOICE\n\n");
        break;
    }
  }
}

void add(){
    int addcon, v, j, n;
    printf("\nADDING CONTACT");
    printf("\nENTER THE NO OF PERSONS TO BE ADDED:");
    scanf("%d", & addcon);
    for (v = i; v < i + addcon; ++v) {
      printf("\nEnter Name: ");
      scanf("%s", sp[v].name);
      printf("\nEnter Number: ");
      scanf("%s", sp[v].num);
      printf("\nEnter Mail: ");
      scanf("%s", sp[v].mail);
    }
    printf("\n");
    for (int j = 0; j < 140; j++) {
      printf("_");
    }
    i = v;
    printf("\nAFTER CHANGING\n");
    printf("REG NO\tNAME\t\tNUMBER\t\t\tEMAIL");
    for (int n = 1; n < i; n++) {
      printf("\n%d\t%s\t\t%s\t\t%s", n, sp[n].name, sp[n].num, sp[n].mail);
    }
    printf("\n");
    for (int j = 0; j < 140; j++) {
      printf("_");
    }
}

void edit(){
    struct dict newdict;
    int c, n, j;
    printf("\nENTER THE REG NO OF CONTACT TO UPDATE:");
    scanf("%d", & h);
    if (h >= i) {
        printf("INVALID REG NO");
    } else {
        printf("\n%d\n%s\n%s\n%s\n\n", h, sp[h].name, sp[h].num, sp[h].mail);
        
      printf("\nEnter Name to Edit: ");
      scanf("%s", newdict.name);
      printf("\nEnter the Number to Edit: ");
      scanf("%s", newdict.num);
      printf("\nEnter the Mail id to Edit: ");
      scanf("%s", newdict.mail);
      
      strcpy(sp[h].name,newdict.name);
      strcpy(sp[h].num,newdict.num);
      strcpy(sp[h].mail,newdict.mail);
        
        printf("Update CONTACT");
        printf("\nReg:- %d\nName:- %s\nMobile:- %s\nEmail:- %s\n\n", h, sp[h].name, sp[h].num, sp[h].mail);
    }
}

void display() {
  printf("\nREG NO\tNAME\t\tNUMBER\t\t\tEMAIL");
  for (int n = 1; n < i; n++) {
    printf("\n%d\t%s\t\t%s\t\t%s", n, sp[n].name, sp[n].num, sp[n].mail);
  }
  printf("\n");
  for (int j = 0; j < 140; j++) {
    printf("_");
  }
}

void delete() {
  int c, n, j;
  printf("\nENTER THE REG NO OF CONTACT TO REMOVE:");
  scanf("%d", & h);
  if (h >= i) {
    printf("INVALID REG NO");
  } else {
    for (c = h; c <= i; c++) {
      strcpy(sp[c].name, sp[c + 1].name);
      strcpy(sp[c].num, sp[c + 1].num);
      strcpy(sp[c].mail, sp[c + 1].mail);
    }
    i--;
    for (int n = 1; n < i; n++) {
      printf("\n%d\t%s\t\t%s\t%s", n, sp[n].name, sp[n].num, sp[n].mail);
    }
  }
  printf("\n");
  for (int j = 0; j < 140; j++) {
    printf("_");
  }
}

void find(){
    int pos,j, y;
    printf("\nENTER THE REG NO OF THE PERSON:");
    scanf("%d", & pos);
    if (pos >= i) {
      printf("INVALID REG NO");
    } else {
      for (int y = pos - 1; y < pos; y++) {
        printf("NAME:%s\n", sp[pos].name);
        printf("PHONE NUMBER:%s\n", sp[pos].num);
        printf("MAIL ID:%s\n", sp[pos].mail);
      }
    }
    printf("\n");
    for (int j = 0; j < 140; j++) {
      printf("_");
    }
}