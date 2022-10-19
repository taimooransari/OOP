// q1
#include<iostream>

using namespace std;

class Complex{
private:
double real;
double imag;
  public:  
  Complex(double r=0,double i=0){
      real= r;
      imag=i;
  }
//   add
 Complex operator +(Complex b){
     
     return Complex(real+b.real,imag+b.imag);
 }
 
 Complex operator +(double b){
     
     return Complex(real+b,imag);
 }
  
//   sub
  
 Complex operator -(Complex b){
     
     return Complex(real-b.real,imag-b.imag);
 }
 
 Complex operator -(double b){
     
     return Complex(real-b,imag);
 }
 
//  mult

 Complex operator *(Complex b){
     
     return Complex(real*b.real - imag*b.imag,real*b.imag + imag*b.real);
 }
 
 Complex operator *(double b){
     
     return Complex(real*b,imag*b);
 }
 
friend ostream & operator << (ostream &out, const Complex &c)
{
    if(c.real!=0){
    out << c.real;
    }
    if(c.imag>0){
    out << "+" << c.imag <<"i";
    }
    else if(c.imag<0){
        
    out << c.imag <<"i";
    }
    return out;
}
 
friend istream & operator >> (istream &in,  Complex &c)
{
    in >> c.real;
    in >> c.imag;
    return in;
}

};



int main(){
   Complex c1, c2;
    
    cin>>c1; //extraction operator is overloaded
    cin>>c2;

    double d1;
    cin>>d1;
    
    Complex result;
    //showing the numbers:
    cout<<"c1: "<< c1 <<endl; // insertion operator is overloaded
    cout<<"c2: "<< c2 <<endl; 
    cout<<"d1: "<< d1 <<endl;

    // Check the opertions where both operands are complex
    result = c1 + c2; 
    cout<<"c1+c2: "<<result<<endl;
    
    
    result = c1 - c2; 
    cout<<"c1-c2: "<< result <<endl;
    
    result = c1 * c2; 
    cout<<"c1*c2: "<< result <<endl;
    
    // Check the opertions where one operator is complex, other is double

    result = c1 + d1; 
    cout<<"c1+d1: "<< result <<endl;
    
    
    result = c1 - d1; 
    cout<<"c1-d1: "<< result <<endl;
    
    result = c1 * d1; 
    cout<<"c1*d1: "<< result <<endl;
}

/*
#include<iostream>

using namespace std;

struct Complex{
    float real, imag;
};

Complex add(Complex c1, Complex c2){
    return {c1.real+c2.real, c1.imag+c2.imag};
}

Complex subtract(Complex c1, Complex c2){
    return {c1.real-c2.real, c1.imag-c2.imag};
}

Complex multiply(Complex c1, Complex c2){
    return {c1.real*c2.real-c1.imag*c2.imag, c1.real*c2.imag+c1.imag*c2.real};
}

void show(Complex c){
    if(c.imag>0)
    cout<<c.real<<"+"<<c.imag<<"i";
    else
    {
    cout<<c.real<<c.imag<<"i";
    }    
    cout<<endl;
}


int main(){
    Complex c1, c2;
    cin>>c1.real>>c1.imag;
    cin>>c2.real>>c2.imag;

    cout<<"Addition: "; show(add(c1,c2));
    cout<<"Subtraction: "; show(subtract(c1,c2));
    cout<<"Multiplication: "; show(multiply(c1,c2));
}
*/



// q2
#include<iostream>

using namespace std;

struct Distance{
    double feet, inches;
};

// Write the Area class here, and overload the double operator in it.

class Area{
    private:
        Distance length;
        Distance width;
    public:
        Area(Distance l={0,0},Distance w ={0,0})
        {
            length=l;
            width =w;
        };
    
    
operator double(){
        return (length.feet +length.inches/12) * (width.feet + width.inches/12);

     };
};
int main(){
    double ft1, ft2, in1, in2;
    cin>>ft1>>in1>>ft2>>in2;
    Area area1 = {{ft1, in1}, {ft2,in2}};
    
    double decimalArea = area1; // overload the double operator to convert area object into decimal value.
    cout<<"Area is: "<< decimalArea <<"sq feet"<<endl;

}