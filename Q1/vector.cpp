#include<iostream>
#include<ctime>
#include"shapes.h"
#include"twostarvector.h"
#include"onestarvector.h"
using namespace std;


int main(){
    
  CustomVector<char> vector1;
  CustomVector<Cube>vector2;
  Cube shape;
  vector2.pushback(shape);

  
//PARTONE:adding insert and remove functions:
  cout<<"\nQ1-PARTONE : "<<endl<<endl;
  cout<<"example of insert : "<<endl;
  vector1.insert(0,'&');
  vector1.insert(0,'p');
  vector1.insert(0,'*');
  vector1.insert(0,'U');
  vector1.print();
  cout<<"example of remove : "<<endl;
  vector1.remove(2);
  vector1.print();
  cout<<endl;

//PARTTWO:Adding shapes to a vector (0.1 megabytes)
  cout<<"Q1-PARTTWO : "<<endl<<endl;
  int oneshape = vector2.size_of();
  for(int i = 0 ; i<100000/oneshape ; i++){
    vector2.pushback(shape);
  }
  cout<<"size of our vector after adding shape objects : "<<vector2.size_of()<<endl<<endl;




//PARTTHREE:vector based on T**:
  cout<<"Q1-PARTTHREE : "<<endl<<endl;
  cout<<"including functionalities yo the T** based vector : "<<endl;
  vector<string>vector3(1,"hi");
  vector3.pushback("test");
  vector3.pushback("yes");
  vector3.insert(1,"no");
  vector3.remove(1);
  vector3.print();
  cout<<endl<<endl;


//PARTFOUR:adding our functions in a new vector by T** method  
  vector<Cube>vector5(4,shape);
  for(int i = 0 ; i<100000/oneshape ; i++){
    vector5.pushback(shape);
  }  

  
//PARTFIVE:Perform several "insert" and "remove" functions on the created objects and compare them
  //compare insert func :

  cout<<"PARTFOUR : "<<endl<<endl;
  clock_t start = clock();

  for(int i = 0 ; i<500 ; i++){
    vector2.insert(5,shape);
  }

  clock_t end = clock();

  cout<<"insert clock (T*) : " << end-start<<endl;

  start = clock();

  for(int i = 0 ; i<500 ; i++){
    vector5.insert(5,shape);
  }

  end = clock();

  cout<<"insert clock (T**) : " << end-start<<endl<<endl;

  //compare remove func :
  start = clock();

  for(int i = 0 ; i<500 ; i++){
    vector5.remove(5);
  }

  end = clock();

  cout<<"remove clock (T*) : " << end-start<<endl;

  start = clock();

  for(int i = 0 ; i<500 ; i++){
    vector2.remove(5);
  }

  end = clock();

  cout<<"remove clock (T**) : " << end-start<<endl<<endl;

  //compare pushback func :
  start = clock();

  for(int i = 0 ; i<500 ; i++){
    vector5.pushback(shape);
  }

  end = clock();

  cout<<"pushback clock (T*) : " << end-start<<endl;
  start = clock();

  for(int i = 0 ; i<500 ; i++){
    vector2.pushback(shape);
  }

  end = clock();

  cout<<"pushback clock (T**) : " << end-start<<endl<<endl;



    return 0;
}
