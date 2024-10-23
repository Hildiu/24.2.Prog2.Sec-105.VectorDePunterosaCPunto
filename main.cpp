/*----------------------------------------------------------------------------------------------------
 * El programa permite hallar el perimetro de un poligono, ingresando como datos la cantidad de lados
 * del poligono y las coordenadas de cada punto.
 * Dato de Entrada: lados (int)   numero de lados de un poligono
 *                  las coordenadas de cada punto.
 * Dato de Salida:  perimetro  (double)
 * Se usa : Vector de Punteros a CPuntos
 ---------------------------------------------------------------------------------------------------*/

#include "CPunto.h"
#include <vector>

int main()
{ int nlados;
  double x,y;

    cout << "Numero de lados del poligono: ";
    cin >> nlados;
    //--- se crea el vector de puntos.
    //-- esta invocando al constructor por defecto
    vector<CPunto*> vec(nlados);
    //--- leemos las coordenadas

    for(int i=0; i<nlados; i++)
    {
        cout << "\n";
        cout << "Punto " << i <<  "\n";
        cout << "x : "; cin >> x;
        cout << "y : "; cin >> y;
        vec[i] = new CPunto(x,y);
    }
    cout << "Calculamos el perimetro\n";
    double perimetro = 0;
    for(int i=0; i<vec.size()-1; i++)
        perimetro +=   vec[i]->distancia(*(vec[i+1]));
    perimetro += vec[vec.size()-1]->distancia(*(vec[0]));
    cout << "El perimetro del poligono es: " << perimetro<< "\n";
    //--- Se libera memoria ocupada por cada punto.
    for(int i=0; i<vec.size(); i++)
        delete  vec[i];
}
