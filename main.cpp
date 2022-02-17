#include <iostream>
#include <string>
#include<cstdlib>
#include <cmath>
#include <sstream>
using namespace std;
int exponentMod(int A, int B, int C)
{
    if (A == 0)
        return 0;
    if (B == 0)
        return 1;

    long y;
    if (B % 2 == 0) {
        y = exponentMod(A, B / 2, C);
        y = (y * y) % C;
    }
    else {
        y = A % C;
        y = (y * exponentMod(A, B - 1, C) % C) % C;
    }

    return (int)((y + C) % C);
}

int InverseMod(int a, int b)
{
	int b0 = b, t, q;
	int x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}
int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);}

int main() {
    int j,z,e,n,Q,r,w;
    string alphabet="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";
    int premierp[]={7,11};
    int premierq[]={19,17};
    cout<<"Entrer votre text :"<<endl;
	string x;
	getline(cin,x);
    cout<<"Entrer '1' pour chiffrer ce texte , '2' pour dechiffrer ce texte :"<<endl;
    int choice ;
    cin>>choice;
    if (choice==1){
    int q=rand()%2;
    int p=rand()%2;
    n=premierp[p]*premierq[q];
    Q=(premierp[p]-1)*(premierq[q]-1);
    e=2;
    while(gcd(e,Q)!=1){e++;}
    int i=0;
    for(i;i<x.size();i++){
    j=0;
    while(x[i]!=alphabet[j]){j++;}
    z = pow(j,e) ;
    z = z % n;
    if (i!=x.size()-1){
    cout<<z<<";";}
    else{cout<<z;}
    }
    cout<<""<<endl;
	cout<<"d:"<<InverseMod(e,Q)<<", n:"<<n<<endl;
    }
	if (choice==2){
	cout<<"Entrer la cle d :"<<endl;
	int k;
	cin>>k;
	cout<<"Entrer la cle n :"<<endl;
	int l;
	cin>>l;
	string c="0";
	int i=0;
	for(i;i<x.size();i++){
    if (x[i]!=';'){
    c=c+x[i];}
    if (x[i]==';' || i==x.size()-1){
    stringstream degree(c);
    int r=0;
    degree >> r ;
    int w = exponentMod(r,k,l);
    w=w%63;
    cout<<alphabet[w];
    c="0";
    }
	}
	}
	return 0;
}
