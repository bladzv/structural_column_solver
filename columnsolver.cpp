#include<iostream.h>
#include<conio.h>
#include<math.h>


int main(){

menu:
	int option;
	cout<<"<----------MENU---------->"<<endl;
	cout<<"Welcome to Column Solver"<<endl;
	cout<<"1 - Straight column\n2 - Crooked column\n3 - Eccentric column\n\n";
   cout<<"Select from the following: ";
	cin>>option;
	switch(option){
		case 1:
			cout<<"You have selected straight column."<<endl;
			goto straight;
		case 2:
			cout<<"You have selected crooked column."<<endl;
			goto crooked;
		case 3:
			cout<<"You have selected eccentric column."<<endl;
			goto eccentric;
	}

back:
	char returner;
	cout<<"\nBack to main menu?(y/n) ";
	cin>>returner;
	if((returner == 'y')||(returner == 'Y')){
		clrscr();
		goto menu;
	}
	else{
		cout<<"\n\nThank you for using the system"<<endl;
		getch();
		goto exit;
	}

straight:
	cout<<"\nPlease type if its 1-circular cross section, 2-rectangular cross section: ";
	cin>>option;
	switch(option){
		case 1:
      	/*
      	r = radius of gyration
         rr = rectangle slenderness ratio
         b = base
         h = height
         d = diameter
         sr = slenderness ratio
         k = end fixity
         l = actual column length
         cc = column constant
         s = yield strength
         e = modulus of elasticity
         a = area
         p = Euler critical load
         ppp = johnson critical load
         */
			float r,rr,b,h,d,sr,k,l,cc,s,e,a,p,ppp;
			cout<<"Enter the Diameter(D): ";
			cin>>d;
			cout<<"Enter the constant end fixity(K): ";
			cin>>k;
			cout<<"Enter the actual length(L): ";
			cin>>l;
			cout<<"Enter the yield strength of material(S): ";
			cin>>s;
			cout<<"Enter the modulus of elasticity of material(E): ";
			cin>>e;
			cout<<"\n------RESULT------"<<endl;
         r=d/4;
			cout<<"Radius of gyration: "<<r<<endl;
			a=(M_PI*d*d)/4;
			cout<<"Area: "<<a<<endl;
			sr=(k*l)/r;
			cout<<"Slenderness ratio: "<<sr<<endl;
			cc=sqrt((2*M_PI*M_PI*e)/s);
			cout<<"Column constants: "<<cc<<endl;
			if(sr>cc){
				cout<<"The column is long, so use Euler's formula."<<endl;
				p=(M_PI*M_PI*e*a)/(sr*sr);
				cout<<"Critical Load: "<<p<<endl;
			}
			else if(sr<cc){
				cout<<"the column is short-we use Johnson's formula."<<endl;
				ppp=(a*s)*(1-(s*sr*sr)/(4*M_PI*M_PI*e));
				cout<<"Critical Load: "<<ppp<<endl;
			}
			goto back;
		case 2:
			cout<<"Enter the base(B): ";
			cin>>b;
			cout<<"Enter the height(H): ";
			cin>>h;
			cout<<"Enter the length(L): ";
			cin>>l;
			cout<<"Enter the constant end fixity(K): ";
			cin>>k;
			cout<<"Enter the yield strength of material(S): ";
			cin>>s;
			cout<<"Enter the modulus elasticity of material(E): ";
			cin>>e;
         cout<<"\n------RESULT------"<<endl;
			rr=b/sqrt(12);
			cout<<"Radius of gyration: "<<rr<<endl;
			a=b*h;
			cout<<"Area: "<<a<<endl;
			sr=(k*l)/rr;
			cout<<"Slender ratio: "<<sr<<endl;
			cc=sqrt((2*M_PI*M_PI*e)/s);
			cout<<"Column constants: "<<cc<<endl;
			if(sr>cc){
				cout<<"The column is long, so use Euler's formula."<<endl;
				p=(M_PI*M_PI*e*a)/(sr*sr);
				cout<<"Critical Load: "<<p<<endl;
			}
			else if(sr<cc){
				cout<<"The column is short, so use Johnson's formula."<<endl;
				ppp=(a*s)*(1-(s*sr*sr)/(4*M_PI*M_PI*e));
				cout<<"Critical Load: "<<ppp<<endl;
			}
			goto back;
	}

crooked:
	cout<<"\nPlease type if its 1-circular cross section, 2-rectangular cross section"<<endl;
	cin>>option;
	switch(option){
		case 1:
      	/*
         r = radius of gyration
         rr = rectangle slenderness ratio
         b = base
         h = height
         d = diameter
         sr = slenderness ratio
         k = end fixity
         l = actual column length
         cc = column constant
         s = yield strength
         e = modulus of elasticity
         a = area
         p = Euler critical load
         n = design factor
         ppp = Johnson critical load
         aa = initial crookedness
         ccc = distance from the neutral axis
         c1
         c2
         pa = Euler allowable load
         paa = Johnson allowable load
         c11
         c111
         */
			float r,rr,b,h,d,sr,k,l,cc,s,e,a,p,n,ppp,aa,ccc,c1,c2,pa,paa,c11,c111;
			cout<<"Enter the diameter(D): ";
			cin>>d;
			cout<<"Enter the constant end fixity(K): ";
			cin>>k;
			cout<<"Enter the initial crookedness(a): ";
			cin>>aa;
			cout<<"Enter the design factor(N): ";
			cin>>n;
			cout<<"Enter the actual length(L): ";
			cin>>l;
			cout<<"Enter the yield strength of material(s): ";
			cin>>s;
			cout<<"Enter the modulus of elasticity of materials(E): ";
			cin>>e;
         cout<<"\n------RESULT------"<<endl;
			r=d/4;
			cout<<"Radius of gyration: "<<r<<endl;
			a=(M_PI*d*d)/4;
			cout<<"Area: "<<a<<endl;
			sr=(k*l)/r;
			cout<<"Slenderness ration: "<<sr<<endl;
			cc=sqrt((2*M_PI*M_PI*e)/s);
			cout<<"Column constants: "<<cc<<endl;
			ccc=d/2;
			if(sr>cc){
				cout<<"The column is long, so use Euler's formula."<<endl;
				p=(M_PI*M_PI*e*a)/(sr*sr);
				cout<<"Critical Load: "<<p<<endl;
				c11=(aa*ccc)/(r*r);
				c1=(-1/n)*((s*a)+(1+c11)*p);
				cout<<"C1: "<<c1<<endl;
				c2=(s*a*p)/(n*n);
				cout<<"C2: "<<c2<<endl;
				/*pa=(((pa*pa)+c2)/c1);*/

            pa=((-c1)-(sqrt(c1*c1-4*c2)))/(2);

				cout<<"Allowable Load: "<<pa<<endl;
			}
			else{
				cout<<"The column is short, so use Johnson's formula."<<endl;
				ppp=(a*s)*(1-(s*sr*sr)/(4*M_PI*M_PI*e));
				cout<<"Critical Load: "<<ppp<<endl;
				c111=(aa*ccc)/(r*r);
				c1=(-1/n)*((s*a)+(1+c111)*ppp);
				cout<<"C1: "<<c1<<endl;
				c2=(s*a*ppp)/(n*n);
				cout<<"C2: "<<c2<<endl;
				/*paa=((paa*paa)+c2)/c1;*/

            paa=((-c1)-(sqrt(c1*c1-4*c2)))/(2);


				cout<<"Allowable Load: "<<paa<<endl;
			}
			goto back;

		case 2:
			cout<<"Enter the base(B): ";
			cin>>b;
			cout<<"Enter the hieght(H): ";
			cin>>h;
			cout<<"Enter the length(L): ";
			cin>>l;
			cout<<"Enter the design factor: ";
			cin>>n;
			cout<<"Enter the constant end fixity: ";
			cin>>k;
			cout<<"Enter the yield strength of material: ";
			cin>>s;
			cout<<"Enter the modulus of elasticity: ";
			cin>>e;
         cout<<"\n------RESULT------"<<endl;
			r=b/sqrt(12);
			cout<<"Radius of gyration: "<<r<<endl;
			a=b*h;
			cout<<"Area: "<<a<<endl;
			sr=(k*l)/r;
			cout<<"Slenderness ratio: "<<sr<<endl;
			cc=sqrt((19.719*e)/s);
			cout<<"Column constant: "<<cc<<endl;
			ccc=b/2;
			if(sr>cc){
				cout<<"The column is long, so use Euler's formula."<<endl;
				p=(9.869*e*a)/(sr*sr);
				cout<<"Critical Load: "<<p<<endl;
				c11=(aa*ccc)/(r*r);
				c1=(-1/n)*((s*a)+(1+c11)*p);
				cout<<"C1: "<<c1<<endl;
				c2=(s*a*p)/(n*n);
				cout<<"C2: "<<c2<<endl;
				pa=(((pa*pa)+c2)/c1);
				cout<<"Allowable Load: "<<pa<<endl;
			}
			else{
				cout<<"The column is short, so use Johnson's formula."<<endl;
				ppp=(a*s)*(1-(s*sr*sr)/(39.478*e));
				cout<<"Critical Load: "<<ppp<<endl;
				c111=(aa*ccc)/(r*r);
				c1=(-1/n)*((s*a)+(1+c111)*ppp);
				cout<<"C1: "<<c1<<endl;
				c2=(s*a*ppp)/(n*n);
				cout<<"C2: "<<c2<<endl;
				paa=((paa*paa)+c2)/c1;
				cout<<"Allowable load: "<<paa<<endl;
			}
			goto back;
	}

eccentric:
	cout<<"\nPlease type if its 1-circular cross section, 2-rectangular cross section";
	cin>>option;
	switch(option){
		case 1:
			float r,rr,b,h,d,sr,k,l,cc,s,e,a,p,n,ppp,aa,ccc,c1,c2,pa,paa,c11,c111,ee,o,o1,o2,o3;
			cout<<"Enter the diamter(D) :";
			cin>>d;
			cout<<"Enter the constant end fixity(K): ";
			cin>>k;
			cout<<"Enter the inital crookedness(a): ";
			cin>>aa;
			cout<<"Enter the design factor(N): ";
			cin>>n;
			cout<<"Enter the actual length(L): ";
			cin>>l;
			cout<<"Enter the yield strength of material(S): ";
			cin>>s;
			cout<<"Enter the modulus of elasticity of material(E): ";
			cin>>e;
			cout<<"Enter the eccentricity(e): ";
			cin>>ee;
         cout<<"\n------RESULT------"<<endl;
			r=d/4;
			cout<<"Radius of gyration: "<<r<<endl;
			a=(3.14*d*d)/4;
			cout<<"Area: "<<a<<endl;
			sr=(k*l)/r;
			cout<<"Slender ratio: "<<sr<<endl;
			cc=sqrt((19.719*e)/s);
			cout<<"Column constants: "<<cc<<endl;
			ccc=d/2;
			if(sr>cc){
				cout<<"The coulum is long, so use Euler's formula."<<endl;
				p=(9.869*e*a)/(sr*sr);
				cout<<"Critical Load: "<<p<<endl;
				c11=(aa*ccc)/(r*r);
				c1=(-1/n)*((s*a)+(1+c11)*p);
				cout<<"C1: "<<c1<<endl;
				c2=(s*a*p)/(n*n);
				cout<<"C2: "<<c2<<endl;
				pa=(((pa*pa)+c2)/c1);
				cout<<"Allowable Load: "<<pa<<endl;
				o=pa;
				cout<<"Maximum Stresses: "<<o<<endl;
			}
			else{
				cout<<"The column is short, so use Johnson's formula."<<endl;
				ppp=(a*s)*(1-(s*sr*sr)/(39.478*e));
				cout<<"Critical Load: "<<ppp<<endl;
				c111=(aa*ccc)/(r*r);
				c1=(-1/n)*((s*a)+(1+c111)*ppp);
				cout<<"C1: "<<c1<<endl;
				c2=(s*a*ppp)/(n*n);
				paa=((paa*paa)+c2)/c1;
				cout<<"Allowable Load: "<<paa<<endl;
			}
			goto back;

		case 2:
			cout<<"Enter the base(B): ";
			cin>>b;
			cout<<"Enter the hieght(H): ";
			cin>>h;
			cout<<"Enter the length(L): ";
			cin>>l;
			cout<<"Enter the design factor(N): ";
			cin>>n;
			cout<<"Enter the constant end fixity(K): ";
			cin>>k;
			cout<<"Enter the yield strength of material(S): ";
			cin>>s;
         cout<<"Enter the modolus of elasticity(E): ";
			cin>>e;
			cout<<"Enter the eccentricity(e): ";
			cin>>ee;
         cout<<"\n------RESULT------"<<endl;
         r=b/sqrt(12);
			cout<<"Radius of gyration: "<<r<<endl;
			a=b*h;
			cout<<"Area: "<<a<<endl;
			sr=(k*l)/r;
			cout<<"Slenderness ratio: "<<sr<<endl;
			cc=sqrt((19.719*e)/s);
			cout<<"Column constant: "<<cc<<endl;
			ccc=b/2;
			if(sr>cc){
				cout<<"The column is long, so use Euler's formula."<<endl;
				p=(9.869*e*a)/(sr*sr);
				cout<<"Critical Load: "<<p<<endl;
				c11=(aa*ccc)/(r*r);
				c1=(-1/n)*((s*a)+(1+c11)*p);
				cout<<"C1: "<<c1<<endl;
				c2=(s*a*p)/(n*n);
				cout<<"C2: "<<c2<<endl;
				pa=((pa*pa)+c2)/c1;
				cout<<"Allowable Load: "<<pa<<endl;
			}
			else{
				cout<<"The column is short, so use Johnson's formula."<<endl;
				ppp=(a*s)*(1-(s*sr*sr)/(39.478*e));
				cout<<"Critical Load: "<<ppp<<endl;
				c111=(aa*ccc)/(r*r);
				c1=(-1/n)*((s*a)+(1+c111)*ppp);
				cout<<"C1: "<<c1<<endl;
				c2=(s*a*ppp)/(n/n);
				cout<<"C2: "<<c2<<endl;
				paa=((paa=paa)+c2)/c1;
				cout<<"Allowable Load: "<<paa<<endl;
				o1=sqrt(paa/(a*e));
				o2=(k*l)/2*r;
				o3=(1/(cos(o2*o1)));
				o=(paa/a)*(1+(c111)*o3);
				cout<<"Maximum Stress: "<<o<<endl;
			}
			goto back;
	}
	return 0;
exit:
}

