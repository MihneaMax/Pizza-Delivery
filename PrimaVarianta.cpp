#include <iostream>
#include <cstring>
#include <vector>
/// clasa de adresa, care va fii continuta si de un clasa client.
class Adresa
{
private:
    char *strada;
    int nr;

public:
    /// constructorul:
    Adresa(const char *strada, int numar)
    {
        this->strada = new char[strlen(strada) + 1];
        strcpy(this->strada, strada);
        this->nr = numar;
    }
    /// destructorul pentru adresa
    ~Adresa()
    {
        delete[] strada;
    }
    /// functie de afisare
    void afisare() const
    {
        std::cout << "Strada " << this->strada << ", numarul " << this->nr << std::endl;
    }
};
/// classa Client
class Client
{
private:
    char *nume;
    char *telefon; /// trebuie char pentru 07.... pentru a retine si primul zero i guess
    Adresa *adresa;

public:
    /// deci trebuie sa avem un costructor, un destructor si o afisare eventual
    Client(const char *nume, const char *telefon, Adresa *adresa)
    {
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
        this->telefon = new char[strlen(telefon) + 1];
        strcpy(this->telefon, telefon);
        this->adresa = adresa;
    }
    /// destructorul pentru client; (ar trebui sa distruga si adresa sa oare? pot fii
    /// mai multi clienti la aceeasi adresa??)
    ~Client()
    {
        delete[] nume;
        delete[] telefon;
        delete[] adresa;
    }
    /// afisarea unui client
    void afisare() const
    {
        std::cout << "Client: " << nume << ", cu  numarul de telefon: " << telefon << " si adresa la ";
        adresa->afisare(); /// care are automat un endl;
    }
};
class Pizza
{
private:
    char *sortiment;
    float pret;
    /// si un vector cu incrediente?
    std::vector<std::string> ingrediente;

public:
    /// in primul rand constructorul
    Pizza(const char *sortiment, float pret, std::vector<std::string> ingrediente)
    {
        this->sortiment = new char[strlen(sortiment) + 1];
        strcpy(this->sortiment, sortiment);
        this->pret = pret;
        this->ingrediente = ingrediente;
    }
    /// destrucgorul
    ~Pizza()
    {
        delete[] sortiment;
    }
    /// si afisarea produsului efectiv
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

/// mai putem face o clasa de comenzi care sa contina , la
/// private: numarul comenzii, clientul care a comandat-o si pizza pe care o doreste.
int main()
{
    Adresa *adresa1 = new Adresa("Splaiul Independentei", 202);
    Client client1("Vicol Mihnea-Ioan", "0731014466", adresa1);
    Pizza pizza1("Margherita", 54.99, {"Mozzarella", "Sos de rosii", "Busuioc"});
    client1.afisare();
    pizza1.afisare();
    return 0;
}
