#include <iostream>

int main() {

    int va = 10;
    int vb = 20;
    float vc = 30;

    int tambah;
    int kurang;
    int kali;
    int bagi;

    char name = 'fany';
    
    std::cout << "--------" << std::endl;
    std::cout << "code by kuro" << std::endl;
    std::cout << "--------" << std::endl;

    std::cout << "variable pertama adalah" << va << std::endl;
    std::cout << "variable kedua adalah" << vb << std::endl;

    tambah = va + vb;
    kurang = va - vb;
    kali = va * vb;
    bagi = va / vb;

    std::cout << "va + vb = " << tambah << std::endl;
    std::cout << "va - vb = " << kurang << std::endl;
    std::cout << "va x vb = " << kali << std::endl;
    std::cout << "va : vb = " << bagi << std::endl;

    return 0;
}