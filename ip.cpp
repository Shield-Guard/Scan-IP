#include <iostream>
#include <string>
#include <cstdlib> // for system()

int main() {
    std::string ipAddress;
    std::cout << "Entrez l'adresse IP de départ du sous-réseau (par exemple, 192.168.1.0): ";
    std::getline(std::cin, ipAddress);

    for (int i = 1; i <= 254; ++i) {
        std::string currentIP = ipAddress + "." + std::to_string(i);
        std::string command = "ping -c 1 -W 1 " + currentIP + " >/dev/null 2>&1";

        // Exécution de la commande ping
        int result = system(command.c_str());

        if (result == 0) {
            std::cout << "\033[40;37m[\033[40;32m+\033[40;37m] Adresse IP \033[42;37m" << currentIP << "\033[40;37m : Disponible\n";
        } else {
            std::cout << "\033[40;37m[\033[40;34m?\033[40;37m] Adresse IP \033[41;37m" << currentIP << "\033[40;37m : Indisponible\n";
        }
    }

    return 0;
}
