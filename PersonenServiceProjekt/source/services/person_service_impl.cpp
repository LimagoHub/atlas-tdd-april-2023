//
// Created by JoachimWagner on 13.12.2022.
//
#include "personen_service_impl.h"

void personen_service_impl::speichern(person person_) {
    if(person_.getVorname().length() < 2)
        throw personen_service_exception("Vorname zu kurz");
    throw personen_service_exception("Nachname zu kurz");
}

personen_service_impl::personen_service_impl(personen_repository &repo):repo(repo) {

}
