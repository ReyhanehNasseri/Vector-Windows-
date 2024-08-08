#include <iostream>

namespace std {
template <class T>
class vector{
     public:
	
	vector(int _N, T _Val);
	~vector();
	T operator[] (int i);
	void push_back(T newindex);
	void insert(int insertindex , T newindex );
	void remove (int index);
	int size(){
		return N;
	}
		;
     protected:
        T** data;	
	int N;
	
};


template <class T>
vector<T>::vector(int _N, T _Val ):N(_N){
    data = new T*[N];
    for (int i{0}; i < N; i++){
	    data[i] = new T(_Val);
    }
}

template <class T>
vector<T>::~vector(){
	for (int i{0};i < N; i++){
		delete data[i];
		
	}
	delete [] data;
}

template <class T>
T vector<T>::operator[] (int i){
	try {
		if (i>=0 && i < N){
			return *data[i];
		}
		else
		 throw(i);
	}
		catch(int i){
			std::cout << "out of range, try to access "<< i << " out of " << N <<"\n";
			exit(-1);
		}
	}


template <class T>
void vector<T>::push_back(T newindex){
	T** tmp =  data;
        N++;
        data = new T*[N];
        for (int i = 0 ; i < N - 1 ; i++)
        {
           data[i] = tmp [i];
        }
        data[N-1] = &newindex;

}

template <class T>
void vector<T>::insert(int insertindex , T newindex){
 	T** temp = data;
        N++;
        data = new T* [N];
        for (int i = 0; i < insertindex; i++)
        {
            data[i] = temp[i];
        }
        data[insertindex] = &newindex;
        for (int i = insertindex; i < N - 1; i++)
        {
            data[i + 1] = temp[i];
			
        }


}
template <class T>
void vector<T>::remove(int index){
	 T** temp = data;
        N--;
        data = new T* [N];
        for ( int i = 0; i < index; i++)
        {
            data[i] = temp[i];
        }
        for ( int i = index; i < N - 1; i++)
        {
			
            data[i] = temp[i + 1];
			
        }

}
	
/// end of namespace ///
}
