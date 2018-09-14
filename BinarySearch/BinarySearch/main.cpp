#include <iostream>
#include <vector>
using namespace std;

bool binarysearch(vector<int> listaordenada,int num, int inicio, int fin){
    cout<<"inicio: "<<inicio<<" fin: "<<fin<<endl;
    if (fin - inicio == 1){
        cout<<"condicion de parado, no se encontro el numero"<<endl;
        return 0;
    }
    int mitad = (inicio+fin)>>1;
    if(listaordenada[mitad]==num){
        cout<<"Se encontro el numero en la posicion : "<<mitad<<endl;
        return 1;
    }
    if(listaordenada[mitad]>num){
        return binarysearch(listaordenada,num,inicio,mitad-1);
    }
    else{
        return binarysearch(listaordenada,num,mitad,fin);
    }
    cout<<"no se encontro el numero"<<endl;
    return 0;
}

int main()
{
   vector<int> listaordenada = {0,1,2,3,4,5,6};
   int num = 2; // numero de la lista ordenada
   int inicio=0;
   int fin=listaordenada.size();
   binarysearch(listaordenada,num,inicio,fin);
}
