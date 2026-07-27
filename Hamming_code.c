//This is the code of Hamming Code.
//Hamming Code can detect error upto two bits
//Hamming Code can fix errror upto one bit

// indexing hoite sabdhan -->



#include<stdio.h>
int main (){
int data[4],h[8];
int p1,p2,p4;

printf("Enter 4 bit data bits: ");

//Scan data bits

for (int i=0;i<4;i++){

scanf("%d",&data[i]);


}

h[3]=data[0];
h[5]=data[1];
h[6]=data[2];
h[7]=data[3];

p1=(h[3]^h[5])^h[7];
p2=(h[3]^h[6])^h[7];
p4=(h[6]^h[5])^h[7];

h[1]=p1;
h[2]=p2;
h[4]=p4;

printf("\n\n Hamming Code : ");

for (int i=1;i<8;i++){
    printf("%d ",h[i]);
}


//syndrome

int s1=h[1]^h[3]^h[5]^h[7];
int s2=h[2]^h[3]^h[6]^h[7];
int s3=h[4]^h[5]^h[6]^h[7];

if (s1==0 && s2 == 0 && s3==0){
    printf("\n\n Walah No Error Fould");
}
else{
    int error= (s1*1)+(s2*2)+(s3*4);

    printf("\n\nAyhay Error Ache %d no bit e ",error);

    printf ( "\n\nNeo Fix kore dilam : ");

    if (h[error]==1){
        h[error]=0;
    }

    else {
        h[error]=1;
    }

    for (int i=1;i<8;i++){
    printf("%d ",h[i]);
}



}

return 0;
}
