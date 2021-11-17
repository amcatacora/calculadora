/*
    Calcular factorial de un numero
*/
int factorial(int n) {
    if(n > 0) {
        return n * factorial(n - 1);
    } else {
        return 1;
    }
}

/*
    Calcular la suma (A+B)
*/
float suma(float a, float b){
    return a + b;
}

/*
    Calcular la resta (A-B)
*/
float resta(float a, float b){
  return a - b;
}

/*
    Calcular la division (A/B)
*/
float division(float a, float b){
    if(b > 0 ) {
        return a / b;
    } else {
        return 0;
    }
}

/*
    Calcular la multiplicacion (A*B)
*/
float multiplicacion(float a, float b){
  return a * b;
}
