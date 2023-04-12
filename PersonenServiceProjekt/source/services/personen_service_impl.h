//
// Created by JoachimWagner on 13.12.2022.
//

#pragma once
#include "../persistence/person.h"
#include "../persistence/personen_repository.h"

#include "personen_service_exception.h"
#include "BlacklistService.h"


class personen_service_impl  {

public:
    personen_service_impl(personen_repository &repo, BlacklistService &blacklistService);

    /*
	*	Vorname < 2 -> PSE
	*	Nachname < 2 -> PSE
	*
	*	Attila -> PSE
	*
	*	Alle technische Exceptions -> PSE
	*
	*	Happy Day -> person an Save_or_update Methode uebergeben
	*
	*/
    void speichern(person person_);

    void speichern(std::string vorname, std::string nachname);


private:


    personen_repository &repo;

    BlacklistService &blacklistService;

    void speichernImpl(const person &person_) const;

    void check_person(const person &person_) const;

    void validate(const person &person_) const;

    void business_check(const person &person_) const;
};






