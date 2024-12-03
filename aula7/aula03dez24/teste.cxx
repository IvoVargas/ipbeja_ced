/*
* Ivo Vargas
* 2024-02-03
*
* Compilação:
* nvcc teste.cxx -o teste
* Procurar em:
* en.cppreference.com/w/cpp/numeric/random
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

int main() {
    std::cout << "teste de números aleatórios" << std::endl;

    srand(time(0));

    // Números aleatórios entre 0 e 100
    int x = rand() % 101;
    std::cout << "x " << x << std::endl;

    // Números aleatórios entre 20 e 30
    int y = (rand() % 11) + 20;
    std::cout << "y " << y << std::endl;

    int z = rand() % 101;
    std::cout << "z " << z << std::endl;

    // Números aleatórios reais (double)
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(20.0, 30.0);

    double r = 0.0;
    std::cout << "r " << r << std::endl;

    r = distribution(generator);
    std::cout << "r " << r << std::endl;

    r = distribution(generator);
    std::cout << "r " << r << std::endl;

    r = distribution(generator);
    std::cout << "r " << r << std::endl;

    return 0;
}