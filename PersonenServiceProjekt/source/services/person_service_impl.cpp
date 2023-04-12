//
// Created by JoachimWagner on 13.12.2022.
//
#include "personen_service_impl.h"

void personen_service_impl::speichern(person person_) {
    try {
        person_.setId("fed4e4b7-43b9-4914-8e33-03af5912b7ef");
        speichernImpl(person_);
    } catch (const personen_service_exception & ex) {
        throw ex;
    } catch (...) {
        throw personen_service_exception("Fehler beim Speichern");
    }

}

void personen_service_impl::speichernImpl(const person &person_) const {

    check_person(person_);
    repo.save_or_update(person_);

}

void personen_service_impl::check_person(const person &person_) const {
    validate(person_);
    business_check(person_);
}

void personen_service_impl::business_check(const person &person_) const {
    if (blacklistService.is_blacklisted(person_))
        throw personen_service_exception("Antipath");
}

void personen_service_impl::validate(const person &person_) const {
    if (person_.getVorname().length() < 2)
        throw personen_service_exception("Vorname zu kurz");
    if (person_.getNachname().length() < 2)
        throw personen_service_exception("Nachname zu kurz");
}

personen_service_impl::personen_service_impl(personen_repository &repo, BlacklistService &blacklistService) : repo(
        repo), blacklistService(blacklistService) {}

void personen_service_impl::speichern(std::string vorname, std::string nachname) {
    person p{vorname, nachname};
    //p.setId("123");
    speichern(p);
}

