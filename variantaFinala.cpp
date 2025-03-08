#include <iostream>
#include <cstring>
#include <vector>

class Adresa
{
private:
    char *strada;
    int nr;

public:
    Adresa(const char *strada, int numar)
    {
        this->strada = new char[strlen(strada) + 1];
        strcpy(this->strada, strada);
        this->nr = numar;
    }

    ~Adresa()
    {
        delete[] strada;
    }

    void afisare() const
    {
        std::cout << "Strada " << this->strada << ", numarul " << this->nr << std::endl;
    }
};

class Client
{
private:
    char *nume;
    char *telefon;
    Adresa *adresa;

public:
    Client(const char *nume, const char *telefon, Adresa *adresa)
    {
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
        this->telefon = new char[strlen(telefon) + 1];
        strcpy(this->telefon, telefon);
        this->adresa = adresa;
    }

    ~Client()
    {
        delete[] nume;
        delete[] telefon;
        // Nu mai stergem adresa, va fi stearsa in main()
    }

    void afisare() const
    {
        std::cout << "Client: " << nume << ", cu  numarul de telefon: " << telefon << " si adresa la ";
        adresa->afisare();
    }
};

class Pizza
{
private:
    std::string sortiment; // Folosim std::string pentru a evita alocarea manuală a memoriei
    float pret;
    std::vector<std::string> ingrediente;

public:
    Pizza(const std::string &sortiment, float pret, const std::vector<std::string> &ingrediente)
        : sortiment(sortiment), pret(pret), ingrediente(ingrediente)
    {
    }

    void afisare() const
    {
        std::cout << "Pizza: " << sortiment << ", cu pretul: " << pret << std::endl;
        std::cout << "Ingredientele: ";
        for (const auto &ing : ingrediente)
        {
            std::cout << ing << ", ";
        }
        std::cout << std::endl;
    }
};

class Comanda
{
private:
    static int contorComenzi;
    int idComanda;
    Client *client;
    std::vector<Pizza> pizze;

public:
    Comanda(Client *client, const std::vector<Pizza> &pizze)
    {
        this->idComanda = ++contorComenzi;
        this->client = client;
        this->pizze = pizze;
    }

    void afisare() const
    {
        std::cout << "Comanda #" << idComanda << " pentru ";
        client->afisare();
        std::cout << "Produse comandate: " << std::endl;
        for (const auto &pizza : pizze)
        {
            pizza.afisare();
        }
        std::cout << "-----------------------------" << std::endl;
    }
};

int Comanda::contorComenzi = 0;

int main()
{
    Adresa *adresa1 = new Adresa("Splaiul Independentei", 202);
    Client *client1 = new Client("Vicol Mihnea-Ioan", "0731014466", adresa1);

    Pizza pizza1("Margherita", 54.99, {"Mozzarella", "Sos de rosii", "Busuioc"});
    Pizza pizza2("Quattro Stagioni", 68.99, {"Sunca", "Ciuperci", "Masline", "Ardei"});

    std::vector<Pizza> listaPizze = {pizza1, pizza2};

    Comanda comanda1(client1, listaPizze);
    comanda1.afisare();

    // Eliberare memorie alocata
    delete client1;
    delete adresa1;
    return 0;
    /// daca dau delete la comanda se sterge si counterul? nu cred
}
