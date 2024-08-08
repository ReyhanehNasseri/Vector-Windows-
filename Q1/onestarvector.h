#include<iostream>
using namespace std;
template<class T>
class CustomVector{
   private:
      T* values = new T[1];
   int index = 0;
   int maxSize = 1;


// by doing this, we create new memory and copy old data only logn times vs. n times which causes a big performance gain
// this func works the same as dynamic array growth logic   

  void reallocate(int newSize) {

   T* temp = new T [index];
  //T* temp = values;

   for(int i = 0 ; i < index; i++){
    temp[i]= values[i];
   }
   values = new T [newSize];
  //T* values = temp;

   for(int i = 0 ; i < index; i++){
    values[i]=temp[i];
   }
      delete[] temp;
  }


   public:

// PUSH BACK
  void pushback (T element){
   if(index < maxSize){
        values[index] = element;
    }
    else {
       maxSize = maxSize * 2;
       reallocate(maxSize);
       values[index]=element;
    }
    index++;
  }
  
//POP BACK 
  void popback (){
    if(index>=maxSize/2){ 
      T *p = &values[index];
      p = NULL;

    }
    else{
      maxSize=maxSize/2;
      reallocate(maxSize);
      T *p = &values[index];
      p = NULL;
    }
    index--;
  }

// SIZE  
   int size (){
    return index;
  }

//SIZEOF
  int size_of(){
    T temp [index];
    for(int i = 0 ; i<index ; i++){
      temp[i]=values[i];
    }

    return sizeof(temp);
  }  

// PRINT 
  void print() {
    cout<<"{";
    for(int i = 0 ; i < index; i++){
        cout<<values[i] <<" ";
    
    }
    cout<<"}";
    cout<<endl;

  }

//RESIZE
 void resize (int newSize , T newindex ){
    if(newSize>=index){
        for(int i = index ; i<newSize; i++){
           pushback(newindex);
        }
    }
    else{
        
        for(int i = index ; i>=newSize; i--){
            popback();
        }

    }
 }

//insert
 void insert (int insertindex , T newindex ){
  reallocate(index+1);//NULL
  for(int i = size()-1 ; i>=insertindex ; i--){
    values[i+1] = values[i];

  }
   index++;
  values[insertindex]=newindex;


 }

 void remove (int removeindex){
  for(int i = removeindex + 1 ; i<size(); i++){
    values[i-1]=values[i];
  }
  popback();
 }
 
    ~CustomVector()
{
    delete[] values;
}
};
