#include <iostream>

 using namespace std;
 
 long int p,q,n,m,y,e,d,c,i,j,flag;
 char Mssg1[100]; //original mssg
 char Mssg2[100]; //encryp mssg
 char Mssg3[100]; //decryp mssg
 
 bool isPrime=true;
 
 bool prime(long int num){
     for(int i=2;i<=(num/2);i++){
         if(num%i==0){
             return false;
         }
     }
    return true; 
 }
 
 long int Decryp(long int e){
     long int k=1;
     while(1){
         k+=y;
         if(k%e==0){
             return (k/e);
         }
     }
 }
 
 void Encryp(){
     for(int j=2;j<y;j++){
         if(y%j==0){
             continue;
         }
         isPrime=prime(j);
         if(isPrime && j!=p && j!=q){
             e=j;
             flag=Decryp(e);
             if(flag>0){
                 d=flag;
                 break;
             }
         }
     }
 }
 
int main(){
    int cho;
    do{
        cout<<"\n-----MENU-----\n";
        cout<<"1. Enter Your Message\n";
        cout<<"2. Encryption \n";
        cout<<"3. Decryption \n";
        cout<<"4. Detailed Info\n";
        cout<<"5. Exit\n";
        cout<<"Enter Your Choice Here :";
        cin>>cho;
        switch(cho){
            case 1:
            cout<<"Enter Your Mssg: ";
            cin>>Mssg1;
            break;
            
            case 2:
             do {
                    cout<<"Enter p: ";
                    cin>>p;
                    isPrime=prime(p);
                    if(!isPrime){
                        cout<<"p is not Prime, Try Again\n";
                    }
                } while (!isPrime);
            do {
                    cout<<"Enter q: ";
                    cin>>q;
                    isPrime=prime(q);
                    if(!isPrime){
                        cout<<"q is not Prime, Try Again\n";
                    }
                } while (!isPrime);
            n=p*q;
            y=(p-1)*(q-1);
            Encryp();
            int a;
            for(a=0;Mssg1[a]!='\0';a++){
        
            //RSA Encryption Algorithm
            m=Mssg1[a]; //convert char to ASCII code
            long int k=1;
            for(int i=0;i<e;i++){
            k*=m;
            k=k%n;}
            c=k;
            Mssg2[a]=c; //convert int to char
                }
            Mssg2[a]=-1;
            cout<<"Encryption Done Successfully";
            cout<<"\nEncrypted Mssg: ";
            for(int i=0;Mssg2[i]!=-1;i++){
            cout<<Mssg2[i]; }
            cout<<"\n";
            
            break;
            
            case 3:
            
            for(a=0;Mssg1[a]!='\0';a++){
            //RSA Decryption Algorithm
            m=Mssg1[a]; //convert char to ASCII code
            c = Mssg2[a];
            long int k=1;
            for(int i=0;i<d;i++){
            k*=c;
            k%=n;}
            m=k;
            Mssg3[a]=m; //convert int to char
            }
            Mssg3[a]=-1;
            cout<<"Decryption Done Successfully";
            cout<<"\nDecrypted Mssg: ";
            for(int i=0;Mssg3[i]!=-1;i++){
            cout<<Mssg3[i]; }
            cout<<"\n";
            break;
            
            case 4:
            cout<<"p = "<<p<<endl;
            cout<<"q = "<<q<<endl;
            cout<<"n = "<<n<<endl;
            cout<<"y = "<<y<<endl;
            cout<<"m = "<<Mssg1<<endl;
            cout<<"e = "<<e<<endl;
            cout<<"d = "<<d<<endl;
            Mssg2[a]=-1;
            Mssg3[a]=-1;
            cout<<"Encrypted Mssg: ";
            for(int i=0;Mssg2[i]!=-1;i++){
            cout<<Mssg2[i]; }
            cout<<"\nDecrypted Mssg: ";
            for(int i=0;Mssg3[i]!=-1;i++){
            cout<<Mssg3[i]; }
            break;
            
            case 5:
            cout<<"\n****Thanks For Visiting****\n";
            break;

            default:
            cout<<"\nWrong Choice_Plzz Enter Again\n";
            break;
        }
    }while(cho!=5);
    return 0;
}
