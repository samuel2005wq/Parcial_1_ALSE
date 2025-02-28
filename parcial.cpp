#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

// Definir la estructura de un punto en 2D
struct Point
{
    double x;
    double y;
};

/*Como puede modificar la declaración de la función para que sea mas eficiente en el manejo de memoria?
Teniendo en cuenta que solo necesita leer los valores, pero no modificarlos*/
double calcularDistancia(const Point &p1, const Point &p2)
{
    double x1, y1, x2, y2;
    // Se obtienen las coordenadas de los puntos
    x1 = p1.x;
    y1 = p1.y;
    x2 = p2.x;
    y2 = p2.y;
    // Se calcula la distancia entre los puntos
    double distancia = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    return distancia;
}

// Función para leer las coordenadas de varios puntos
void leerPuntos(Point puntos[], int n)
{
    char respuesta;
    std::cout << "¿Desea ingresar los puntos manualmente? (s/n): ";
    // Leer la respuesta del usuario
    std::cin >> respuesta;

    // Completar: Verificar si la respuesta es 's' o 'n', tener en cuenta mayúsculas y minúsculas
    if (respuesta == 's' || respuesta == 'S')
    {
        // Completar: Leer las coordenadas de cada punto
        for (int i = 0; i < n; i++)
        {
            std::cout << "Ingrese las coordenadas del punto " << i + 1 << " (x, y): ";
            std::cin >> puntos[i].x >> puntos[i].y;
        }
    }
    else
    {
        // Usar puntos predeterminados
        std::cout << "Usando puntos predeterminados...\n";
        puntos[0] = {0, 0};  // Punto 1 (0, 0)
        puntos[1] = {3, 4};  // Punto 2 (3, 4)
        puntos[2] = {6, 8};  // Punto 3 (6, 8)
        puntos[3] = {9, 12}; // Punto 4 (9, 12)
    }
}

double calcularDistanciaMasCercana(Point puntos[], int n, const Point &pUsuario, int &indiceMasCercano)
{
    int indice = 0;
    double distanciaMinima = calcularDistancia(puntos[0], pUsuario);
    vector<double> distancias;
    // Se calcula la distancia entre todos los puntos y el punto del usuario
    for (int i = 0; i < n; i++)
    {
        // Se almacenan las distancias en un vector
        distancias.push_back(calcularDistancia(puntos[i], pUsuario));
    }
    // Se busca la distancia menor
    for (int j = 0; j < distancias.size(); j++)
    {
        if (distancias[j] < distanciaMinima)
        {
            distanciaMinima = distancias[j];
            indice = j;
        }
        else
        {
            distanciaMinima = distanciaMinima;
            indice = indice;
        }
    }

    // Se almacena el indice del punto más cercano
    indiceMasCercano = indice;
    return distanciaMinima;
}

// Función para mostrar el punto más cercano y la distancia
void mostrarResultado(Point puntos[], int indiceMasCercano, double distancia)
{
    std::cout << "El punto más cercano es: (" << puntos[indiceMasCercano].x << ", " << puntos[indiceMasCercano].y << ")\n";
    std::cout << "El indice más cercano es: " << indiceMasCercano << std::endl;
    std::cout << "La distancia al punto más cercano es: " << distancia << std::endl;
}

int main()
{
    int n;
    int indiceMasCercano;
    std::cout << "Ingrese el número de puntos (mínimo 2): ";
    // Leer el número de puntos
    std::cin >> n;

    if (n < 2)
    {
        std::cout << "Se necesitan al menos 2 puntos para calcular las distancias.\n";
        return 1;
    }

    Point puntos[n]; // Arreglo de estructuras para almacenar las coordenadas (x, y)

    // Leer los puntos (manual o predeterminado)
    leerPuntos(puntos, n);

    // Ingresar el punto del usuario
    Point pUsuario;
    std::cout << "Ingrese las coordenadas del punto desde el que calcular la distancia (x, y): ";
    std::cin >> pUsuario.x >> pUsuario.y;

    // Calcular la distancia más cercana
    double distancia = calcularDistanciaMasCercana(puntos, n, pUsuario, indiceMasCercano);
    indiceMasCercano;

    // Mostrar el resultado
    mostrarResultado(puntos, indiceMasCercano, distancia);

    return 0;
}