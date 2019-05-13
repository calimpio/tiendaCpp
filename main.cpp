
#include<iostream>
using namespace std;

void menu(int,string *);
int selecionarArticulo(int);

float compra(int,string *,float *);

int main()
{

    string grupos_de_articulos[]=
    {"verduras","frutas","utensilios","bebidas"};
    int selector;
    float total = 0.0;
    bool finalizarCompra = false;
    while(!finalizarCompra)
    {
        cout<<"Grupos de articulos: "<<endl;
        menu(4,grupos_de_articulos);

        do{

           selector = selecionarArticulo(4);
        }while(selector == -1);
        switch(selector){
            case 0:{
                int cant_clases_de_verduras = 3;
                string clases_de_verduras[cant_clases_de_verduras]
                ={"cebolla","tomate","pimenton"};
                float precios[cant_clases_de_verduras]=
                {20.0,50.0,1.0};
                cout<<"Clase de "<<grupos_de_articulos[selector]<<endl;
                total += compra(cant_clases_de_verduras,clases_de_verduras,precios);
                break;
                }
            case 1:{
                int cant_clases_de_frutas = 1;
                string clases_de_frutas[cant_clases_de_frutas]
                ={"manzana"};
                float precios[cant_clases_de_frutas]=
                {1.0};
                cout<<"Clase de "<<grupos_de_articulos[selector]<<endl;
                total += compra(cant_clases_de_frutas,clases_de_frutas,precios);
                break;
                }
            case 2:{
                int cant_clases_de_utls = 1;
                string clases_de_utls[cant_clases_de_utls]
                ={"cepillo"};
                float precios[cant_clases_de_utls]=
                {0.20};
                cout<<"Clase de "<<grupos_de_articulos[selector]<<endl;
                total += compra(cant_clases_de_utls,clases_de_utls,precios);
                break;
                }
            case 3:{
                int cant_clases_de_bebidas = 1;
                string clases_de_bebidas[cant_clases_de_bebidas]
                ={"jugo"};
                float precios[cant_clases_de_bebidas]=
                {30.2};
                cout<<"Clase de "<<grupos_de_articulos[selector]<<endl;
                total += compra(cant_clases_de_bebidas,clases_de_bebidas,precios);
                break;
                }
        }
        char op;
        cout<<"Quiere  finalizar la programa?(s/n) ";
        cin>>op;
        if(op=='S'||op=='s'){
            finalizarCompra=true;
        }
    }




    return 0;
}


void menu(int cant_clases_de_articulos,string *clases_de_articulos){
    for(int i=0;i<cant_clases_de_articulos;i++)
    {
      cout<<i+1<<". "<<clases_de_articulos[i]<<endl;
    }
}

int selecionarArticulo(int cant_clases_de_articulos){
    int selector;
    cout<<"Selccione: "<<endl;
    cin>>selector;
    if(selector>0 && selector <= cant_clases_de_articulos){
        return selector-1;
    }
    cout<<"No se puede seleccionar "<<selector<<"por que no existe"<<endl;
    return -1;
}


float compra(int cant_clases_de_articulos,string *clases_de_articulos,float *presios_por_clase_de_articulos){

    int cantindad;
    int selector;
    float total;
    menu(cant_clases_de_articulos,clases_de_articulos);
    do{
        selector = selecionarArticulo(cant_clases_de_articulos);
    }
    while(selector==-1);

    cout<<"Entre la cantidad del articulo"<<clases_de_articulos[selector]<<": ";
    cin>>cantindad;

    total = cantindad * presios_por_clase_de_articulos[selector];
    cout<<"Se suma a la cuenta: "<<total;
    return total;
}



