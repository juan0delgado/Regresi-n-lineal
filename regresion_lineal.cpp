#include "REGRESION_LINEAL_H.h"
#include <iostream>
#include <fstream>

using namespace std;

Datos* crearDatos(int n) {
    Datos* datos = new Datos;
    datos->x.resize(n);
    datos->y.resize(n);
    datos->n = n;
    return datos;
}

void liberarDatos(Datos* datos) {
    delete datos;
}
void calcularRegresion (Datos* datos, double& m, double& b, double alpha, int epochs)
    m = 0.0;
    b = 0.0;

    ofstream mseFile ("mse.txt");
   
    for (int epoch = 0; epoch < epochs; ++epoch){ 
        double mse = 0.0;
        for (int i = 0; i < datos->; ++i){ 
            double y_pred = m * datos->x[i]+b;
            double error = datos->y[i] - y_pred;
            m += alpha * error * datos->x[i];
            b += alpha * error;
            mse += error * error;
       
    }   
}

        mse /= datos->n;
        mseFile << mse << endl;
        

        // Imprimir la tabla en consola
        cout << "Epoca: " << epoch + 1 << endl;
        cout << "X\tY\tY_pred\tY - Y_pred\tError_Cuad" << endl;
        for (int i = 0; i < datos->n; ++i) {
            double y_pred = m * datos->x[i] + b;
            double error = datos->y[i] - y_pred;
            cout << datos->x[i] << "\t" << datos->y[i] << "\t" << y_pred << "\t" << error << "\t" << error * error << endl;
        }
        cout << "MSE: " << mse << endl << endl;
    }

    mseFile.close();
}
