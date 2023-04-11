#include "Schwein.h"

Schwein::Schwein(const std::string &name)  {
    setName(name);
    setGewicht(10);
}

Schwein::Schwein() {
    Schwein("Nobody");
}

void Schwein::setName(const std::string &name) {
    if(name == "Elsa")
        throw std::invalid_argument("Name darf nicht Elsa sein");
    this->name = name;
}

const std::string &Schwein::getName() const {
    return name;
}

int Schwein::getGewicht() const {
    return gewicht;
}

void Schwein::setGewicht(int gewicht) {
    this->gewicht = gewicht;
}

bool Schwein::operator==(const Schwein &rhs) const {
    return name == rhs.name &&
           gewicht == rhs.gewicht;
}

bool Schwein::operator!=(const Schwein &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const Schwein &schwein) {
    os << "name: " << schwein.name << " gewicht: " << schwein.gewicht;
    return os;
}

void Schwein::fuettern() {
    setGewicht(getGewicht() + 1);
}
