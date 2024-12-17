/*
* CED - Aula 8
* Ivo Vargas
* 17 dezembro de 2024
*
* exemplo de device target
*/

#include <iostream>
#include <omp.h>

int main() {
    std::cout << "17 dezembro de 2024" << std::endl;


int num_devices = 0;
int default_device = 0;
int max_teams = 0;
#pragma omp parallel
{
    max_teams = omp_get_max_teams();
    omp_set_default_device(2);
    num_devices = omp_get_num_devices();
    default_device = omp_get_default_device();
}
    std::cout << "Numero de dispositivos: " << num_devices << std::endl;
    std::cout << "Dispositivo padrão: " << default_device << std::endl;
    std::cout << "Numero maximade equipes: " << max_teams << std::endl;

int num_teams = 0;
#pragma omp target teams device(2) num_teams(108)
{
    num_teams = omp_get_num_teams();
}
    std::cout << "Numero de equipes: " << num_teams << std::endl;

    return 0;
}
