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
  printf("----------------------------------------WELCOME TO Address Book-------------------------\n");
  // Varaile define
  int c, y, addcon, a = 1;
  int choice, v, pos;
  char b[50];

  // Insert a static data for perform program
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

  // loop for contiunes run program
  while (a) {
    // display the option
    printf("\n1--->DISPLAY CONTACTS\n2--->DELETING CONTACTS\n3--->ADDING CONTACTS\n4--->EDIT CONTACTS\n5--->FINDING CONTACTS\n6--->EXIT CONTACTS");
    // take value from user to select option
    printf("\nENTER YOUR CHOICE: ");
    scanf("%d", & choice);

    // display the horizantal line
    for (int j = 0; j < 140; j++) {
      printf("_");
    }

    // switch case for perform the differnt function
    switch (choice) {
        // case 1 is for display all the Contact
      case 1:
        display();
        break;
        // case 2 is for delete the Contact 
      case 2:
        delete();
        break;
        // case 3 is for add the Contact
      case 3:
        add();
        break;
        // case 4 is for edit the particular Contact by it's reg id
      case 4:
        edit();
        break;
        // case 5 is for find the Contact by it's reg id
      case 5:
        find();
        break;
        // case 6 is for exit the loop program
      case 6:
        a = 0;
        break;
        // print the default message which is invalid choose option
      default:
        printf("\nINVALID CHOICE OPTION\n\n");
        break;
    }
  }
}

/*
* add function 
* add the contact on no of persons
-----------------------------------
* steps for add function block
* 1) take the user input for ask how many persons you have to add
* 2) on number of person loop will execute for eg:- number of person is 2 therefore 2 time loop will execute
* 3) after the add the all contact list will print
*/
void add(){
    // varaiable define
    int addcon, v, j, n;

    // take input from user foe enter the number of persons entered
    printf("\nADDING CONTACT");
    printf("\nENTER THE NO OF PERSONS TO BE ADDED:");
    scanf("%d", & addcon);

    // loop perform a add data in a structure dict
    for (v = i; v < i + addcon; ++v) {
      printf("\nEnter Name: ");
      scanf("%s", sp[v].name);
      printf("\nEnter Number: ");
      scanf("%s", sp[v].num);
      printf("\nEnter Mail: ");
      scanf("%s", sp[v].mail);
    }

    // display the horizantal line 
    printf("\n");
    for (int j = 0; j < 140; j++) {
      printf("_");
    }
    i = v;

    // display the whole list in contact
    printf("\nAFTER CHANGING\n");
    printf("REG NO\tNAME\t\tNUMBER\t\t\tEMAIL");
    for (int n = 1; n < i; n++) {
      printf("\n%d\t%s\t\t%s\t\t%s", n, sp[n].name, sp[n].num, sp[n].mail);
    }
    
    // display the horizantal line
    printf("\n");
    for (int j = 0; j < 140; j++) {
      printf("_");
    }
    printf('\n');
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