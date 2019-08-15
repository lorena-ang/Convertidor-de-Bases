//
//  main.cpp
//  Conversiones Sist. Num.
//
//  Created by Lore Ang on 6/10/19.
//  Copyright © 2019 Lore Ang. All rights reserved.
//
//  No encontré la manera de descargar un .exe a partir de este programa porque fue creado con XCode en Mac y no supe como.. una disculpa :(

#include <iostream>
#include <math.h>
#include <string>
using namespace std;

// Función para pedir base en ciclo centinela para seguir pidiendo hasta que se inserte 0
int inicio()
{
    // Declaración de variables
    int iPrim;
    
    // Preguntar base inicial
    cout << "\n¿De qué base deseas convertir? Escribe 1 para decimal, 2 para otro tipo de base o 0 para salir: ";
    cin >> iPrim;
    
    return iPrim;
}

// Función recursiva para convertir de decimal a cualquier otra base
void convertirDeDecimal(int iNum, int iBase)
{
    // Declaración de variables
    char cArrA[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    
    // Se regresa hasta que el número deje de ser mayor a 0
    if (iNum >= 1)
    {
        // Correr función de nuevo pero ahora el número es igual al resultado de la división
        convertirDeDecimal(iNum / iBase, iBase);
        // Imprimir el residuo según posición en arreglo
        cout << cArrA[iNum % iBase];
    }
}

// Función para convertir de cualquier base a decimal
void convertirDeBase(string sNum, int iBase)
{
    // Declaración de variables
    char cArrB[sNum.size()];
    int iAcum, iSize, iNuevo;
    
    // Guardar cada digito del string con el guarismo en un arreglo de chars
    for (int iN = 0; iN < sNum.size(); iN++)
    {
        cArrB[iN] = sNum[iN];
    }
    
    iAcum = 0;
    iSize = sizeof(cArrB);
    
    // Ciclo para comenzar conversión
    for (int iG = 0, iH = iSize - 1; iG < iSize; iG++, iH--)
    {
        // Convertir cada elemento del arreglo de chars en su numero ASCII
        iNuevo = (int)cArrB[iG];
        
        // Si son números
        if (iNuevo >= 48 && iNuevo <= 57)
        {
            // Calcular número normal ej. '9' -> 9
            iNuevo = iNuevo - 48;
            // Si se ingresa un número que no es congruente con la base, notificar error y pedir otro número
            if (iNuevo >= iBase)
            {
                cout << "Número inválido, intenta de nuevo.\n";
                break;
            }
            else
            {
                // Multiplicar número por la base elevada a la cantidad de elementos - 1, porque se está a comenzando a multiplicar desde la izquierda
                iNuevo = iNuevo * pow(iBase, iH);
                // Sumar resultado de multiplicación a acumulador
                iAcum += iNuevo;
            }
        }
        // Si son letras
        else
        {
            // Calcular número equivalente a cada letra ej. 'A' = 10
            iNuevo = iNuevo - 55;
            iNuevo = iNuevo * pow(iBase, iH);
            iAcum += iNuevo;
        }
    }
    
    // Solo desplegar resultado si el número fue válido
    if (iAcum != 0)
    {
        // Desplegar resultado
        cout << iAcum;
    }
}

int main()
{
    // Declaración de variables
    int iPrim, iNum, iBase;
    string sNum;
    
    cout << "¡Bienvenido al convertidor de bases!\n";
    
    // Inicializar vcc
    iPrim = inicio();

    // Ciclo centinela para repetir hasta que se ingrese un 0 para salir
    while (iPrim != 0)
    {
        switch (iPrim)
        {
            // De decimal a otra base
            case 1:
                do
                {
                    // Preguntar número
                    cout << "¿Qué guarismo deseas convertir?: ";
                    cin >> iNum;
                    // Preguntar base a convertir
                    cout << "¿A qué base deseas convertir? Ingresa un valor del 2 al 36: ";
                    cin >> iBase;
                }
                while (iBase <= 1 || iBase > 36);
                // Desplegar resultado
                cout << "El guarismo " << iNum << " en base " << iBase << " es: ";
                convertirDeDecimal(iNum, iBase);
                cout << endl;
                break;
                
            // De otra base a decimal
            case 2:
                do
                {
                    // Preguntar número
                    cout << "¿Qué guarismo deseas convertir? Ingresa números del 0-9 y/o letras mayúsculas A-Z dependiendo del caso: ";
                    cin >> sNum;
                    // Preguntar de qué base desea convertir
                    cout << "¿De qué base deseas convertir? Ingresa un valor del 2 al 36: ";
                    cin >> iBase;
                }
                while (iBase <= 1 || iBase > 36);
                // Desplegar resultado
                cout << "El guarismo " << sNum << " de base " << iBase << " a decimal es: ";
                convertirDeBase(sNum, iBase);
                cout << endl;
                break;
                
            default:
                cout << "Error, dato incorrecto. Intenta de nuevo.\n";
        }
        
        // Actualizar vcc
        iPrim = inicio();
    }
    
    cout << "¡Hasta luego! Gracias por usar el convertidor de bases.\n";
    
    return 0;
}
