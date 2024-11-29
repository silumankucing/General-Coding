// code by kurooo

#include <iostream>

int main() {

    int va;
    int vb;
    int hasil;

    char operasi;
    char name = 'fany';
    
    std::cout << "--------" << std::endl;
    std::cout << "code by kuro" << std::endl;
    std::cout << "--------" << std::endl;

    std::cout << "variable pertama : " << std::endl;
    std::cin >> va;
    std::cout << "variable kedua : " << std::endl;
    std::cin >> vb;

    std::cout << "operasi : " << std::endl;
    std::cin >> operasi;

    if (operasi = 'tambah') {
        hasil = va + vb;
        std::cout << "hasil penambahan adalah " << hasil << std::endl;
    } else if (operasi = 'kurang') {
        hasil = va - vb;
        std::cout << "hasil pengurangan adalah " << hasil << std::endl;
    } else if (operasi = 'bagi') {
        hasil = va / vb;
        std::cout << "hasil pembagian adalah " << hasil << std::endl;
    } else {
        hasil = va * vb;
        std::cout << "hasil perkalian adalah" << hasil << std::endl;
    }

    return 0;
}