#pragma once
#include <ostream>
#include <string>
#include <stdexcept>
#include <stdexcept>
class Schwein
{
	std::string name;
	int gewicht;

    void setGewicht(int gewicht);

public:
    Schwein();

    explicit Schwein(const std::string &name);

    const std::string &getName() const;

    void setName(const std::string &name);

    int getGewicht() const;

    bool operator==(const Schwein &rhs) const;

    bool operator!=(const Schwein &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Schwein &schwein);

    void fuettern() ;
};


