#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int nextIndex;
    int count;

public:
    PhoneBook();

    void addContact(const Contact &c);
    void displayContacts() const;
    void displayContact(int i) const;
};

#endif
