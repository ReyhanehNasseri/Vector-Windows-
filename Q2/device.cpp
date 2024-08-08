#include<iostream>
#include"shapes.h"
using namespace std;

class laptopdevice {
    protected:
   //simple parts:
    string brand;
    string model;
    string color;
    string bodymaterial;
    int usbportcounts;
    int htmiportcounts;

    public:
    laptopdevice(){}
    laptopdevice( string _brand , string _model ){
        brand=_brand;
        model=_model;
    }

    void getbrand(string _brand){
        brand=_brand;
    }

    void getmodel(string _model){
        model=_model;
    }

    
    void getcolor(string _color){
        color=_color;
    }

    void getbodymaterial(string _bodymaterial){
        bodymaterial=_bodymaterial;   
    }

    void getusbportcounts(int _usbportcounts){
        usbportcounts=_usbportcounts;
    }
    
    void gethtmiportcounts(int _htmiportcounts){
        htmiportcounts=_htmiportcounts;
    }

    void print_laptop_details(){
        cout<<"brand : "<<brand<<endl;
        cout<<"model : "<<model<<endl;
        cout<<"color : "<<color<<endl;
        cout<<"usb port count: "<<usbportcounts<<endl;
        cout<<"htmi port count: "<<htmiportcounts<<endl;
    }



};

//Complicated part(child) of laptopdevice (cpu & storage):

class cpu : public laptopdevice{
    //simple parts
    protected:
    float speed;
    int socketcounts;

    public:
    cpu(){}
    cpu( string _brand , string _model ){
        brand=_brand;
        model=_model;
    }

    void getspeed(float _speed){
        speed=_speed;//Gigahertz
    }
    void getsocket(float _socketcounts){
        socketcounts=_socketcounts;
    }

    void print_cpu_details(){
        cout<<"brand : "<<brand<<endl;
        cout<<"model : "<<model<<endl;
        cout<<"speed : "<<speed <<" GHz"<<endl;
        cout<<"socket count: "<<socketcounts<<endl;
    }

};

class storage : public laptopdevice{
    //simple parts
    protected:
    string type;
    int memory;

    public:
    storage(){}
    storage( string _brand , string _model ){
        brand=_brand;
        model=_model;
    }
    
    void gettype(string _type){
        type=_type;
    }

    void getmemory(int _memory){
        memory=_memory;//Gigabytes
    }
    void print_storage_details(){
        cout<<"brand : "<<brand<<endl;
        cout<<"model : "<<model<<endl;
        cout<<"type : "<<type<<endl;
        cout<<"memory "<<memory<<endl;
    }

};

//complicated part(child) of cpu (cpucore)

class cpucore : public cpu {
    //simple parts
    protected:
    int corecount;

    public:
    cpucore(){};
    void getcorecount(int _corecount){
        corecount = _corecount;
    }
    void print_cpucore_details(){
        cout<<"core count: "<<corecount<<endl;
    }
 
 
};

//complicated part(child) of storage (slot)

class slot : public storage{
    //simple parts
    protected:
    int slotcount;

    public:
    slot(){}
    void getslotcount(int _slotcount){
        slotcount = _slotcount;
    }
    void print_slot_details(){
        cout<<"slot count: "<<slotcount<<endl;
        cout<<"type : "<<type<<endl;
    }

};

int main(){

    laptopdevice reyhanehpc("asus" , "UX550VD");
    reyhanehpc.getcolor("navyblue");
    reyhanehpc.getbodymaterial("aluminum");
    reyhanehpc.getusbportcounts(2);
    reyhanehpc.gethtmiportcounts(2);

    cpu mycpu ("intel" , "12thgen_corei7");
    mycpu.getspeed(2.4);//Gigahertz
    mycpu.getsocket(1);

    storage mystorage("ADATA" , "HD680");
    mystorage.gettype("HHD");
    mystorage.getmemory(1000);//Gigabytes

    cpucore mycpucore;
    mycpucore.getcorecount(8);

    slot myslot;
    myslot.gettype("M2");
    myslot.getslotcount(2);


    cout<<endl<<"LAPTOP DETAILS : " << endl;
    reyhanehpc.print_laptop_details();

    cout<<endl<<"CPU DETAILS : " << endl;
    mycpu.print_cpu_details();

    cout<<endl<<"STORAGE DETAILS : " << endl;
    mystorage.print_storage_details();

    cout<<endl<<"CPUCORE DETAILS : " << endl;
    mycpucore.print_cpucore_details();
    
    cout<<endl<<"SLOT DETAILS : " << endl;
    myslot.print_slot_details();
    cout<<endl;

    cout<<"******************"<<endl;


    //LAST PART:
    Cube laptop(45 , 30 , 10);
    laptop.getdensity(27);

    Cube cpu(15,10,3);
    cpu.getdensity(9);

    Cube storage(20 , 15 , 3);
    storage.getdensity(12);

    sphere cpucore(0.5);
    cpucore.getdensity(2);

    cout<<"LAPTOP: "<<endl<<"mass : "<<laptop.evalmass()<<endl;
    cout<<"volume : "<<laptop.EvalVolume()<<endl<<"surface : "<<laptop.evalsurface()<<endl<<endl;

    cout<<"CPU: "<<endl<<"mass : "<<cpu.evalmass()<<endl;
    cout<<"volume : "<<cpu.EvalVolume()<<endl<<"surface : "<<cpu.evalsurface()<<endl<<endl;

    cout<<"STORAGE: "<<endl<<"mass : "<<storage.evalmass()<<endl;
    cout<<"volume : "<<storage.EvalVolume()<<endl<<"surface : "<<storage.evalsurface()<<endl<<endl;

    cout<<"CPUCORE: "<<endl<<"mass : "<<cpucore.evalmass()<<endl;
    cout<<"volume : "<<cpucore.EvalVolume()<<endl<<"surface : "<<cpucore.evalsurface()<<endl<<endl;














    return 0 ;
}

