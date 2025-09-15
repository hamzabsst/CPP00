/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset <hbousset@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 02:03:55 by hbousset          #+#    #+#             */
/*   Updated: 2025/09/12 17:01:29 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook() : contactCount(0), oldestIndex(0) {}

void PhoneBook::addContact()
{
	std::string	input;
	Contact		newContact;

	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Error: First name cannot be empty!" << std::endl;
		return;
	}
	newContact.setFirstName(input);

	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Error: Last name cannot be empty!" << std::endl;
		return;
	}
	newContact.setLastName(input);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Error: Nickname cannot be empty!" << std::endl;
		return;
	}
	newContact.setNickname(input);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Error: Phone number cannot be empty!" << std::endl;
		return;
	}
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!std::isdigit(input[i]))
		{
			std::cout << "Error: Phone number must contain only digits!" << std::endl;
			return;
		}
	}
	newContact.setPhoneNumber(input);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Error: Darkest secret cannot be empty!" << std::endl;
		return;
	}
	newContact.setDarkestSecret(input);

	if (contactCount < 8)
	{
		contacts[contactCount] = newContact;
		contactCount++;
	}
	else
	{
		contacts[oldestIndex] = newContact;
		oldestIndex = (oldestIndex + 1) % 8;
	}
	std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::displayContactDetails(int index) const
{
	if (index < 0 || index >= contactCount || contacts[index].isEmpty())
	{
		std::cout << "Error: Invalid index!" << std::endl;
		return;
	}

	std::cout << std::endl;
	contacts[index].displayContact();
	std::cout << std::endl;
}

void PhoneBook::displayContactList() const
{
	std::cout << "|" << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;

	for (int i = 0; i < contactCount; i++)
	{
		if (!contacts[i].isEmpty())
		{
			std::cout << "|" << std::setw(10) << i << "|";
			std::cout << std::setw(10) << truncateString(contacts[i].getFirstName(), 10) << "|";
			std::cout << std::setw(10) << truncateString(contacts[i].getLastName(), 10) << "|";
			std::cout << std::setw(10) << truncateString(contacts[i].getNickname(), 10) << "|" << std::endl;
		}
	}
}
std::string PhoneBook::truncateString(std::string str, size_t width) const
{
	if (str.length() > width)
		return str.substr(0, width - 1) + ".";
	return str;
}

void PhoneBook::searchContacts() const
{
	if (contactCount == 0)
	{
		std::cout << "No contacts available!" << std::endl;
		return;
	}
	displayContactList();

	std::cout << "Enter the index of the contact to display: ";
	std::string input;
	std::getline(std::cin, input);

	if (input.length() == 1 && std::isdigit(input[0]))
	{
		int index = input[0] - '0';
		displayContactDetails(index);
	}
	else
		std::cout << "Error: Invalid index format!" << std::endl;
}
