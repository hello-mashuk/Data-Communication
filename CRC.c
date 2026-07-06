//this is the c programme of Cyclic Redundancy Check (CRC)
// Data com Lab 

// fix error
#include<stdio.h>
#include<string.h>

int main(){

char data[50],generator[20],temp[50],remainder[20];
int datalen,genlen,i,j;

printf("Enter Data bits : ");
scanf("%s",data);

printf("Enter Generator bits : ");
scanf("%s",generator);


datalen=strlen(data);
genlen=strlen(generator);

strcpy(temp,data);

//Append Zeros

for(i=0;i<genlen-1;i++){
    temp[datalen+i]='0';
}

temp[datalen+genlen-1]='\0';

char dividend[50];
strcpy(dividend,temp);

//CRC division
for (i=0;i<datalen;i++){

    if (dividend[i]=='1'){
        for(j=1;j<genlen;i++){
            dividend[i+j]=(dividend[i+j]==generator[j] ) ? '0':'1'; // that old ternary operator

        }
    }
}

//Extract Remider
for(int i=0;i<genlen-1;i++){
    remainder[i]=dividend[datalen+i];
}

remainder[genlen-1]='\0';
printf("\n\n NRC Reminder : %s\n  ",remainder);


//generate codeword
strcpy(temp,data);
strcat(temp,remainder);

printf("\n Transmitted codeword : %s\n ",temp);


// Reciever Side

printf("Reciever Checking . . . . . . . \n");

strcpy(dividend,temp); // copy codeword to divedend


for (i=0;i<datalen;i++){

    if (dividend[i]=='1'){
        for(j=1;j<genlen;i++){
            dividend[i+j]=(dividend[i+j]==generator[j]) ? '0':'1'; // that old ternary operator

        }
    }
}


int error=0;

for(i=datalen;i<datalen+genlen-1;i++){
       if(dividend[i] !=0){
            error=0;
            break;
       }

}


if(error){
    printf("Oh No !! Errorrrr Found ");
}
else
    printf("Yay its Error freeeeee");

    return 0;
}
