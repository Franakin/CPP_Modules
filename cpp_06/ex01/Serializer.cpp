/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serializer.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/24 16:43:27 by fpurdom       #+#    #+#                 */
/*   Updated: 2023/05/24 16:59:23 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

//defaults--------------------------------------------------------------------------------------------------------------------------------------------
Serializer::Serializer(void){}

Serializer::Serializer(const Serializer &copy){(void)copy;}

Serializer::~Serializer(void){}

//operators--------------------------------------------------------------------------------------------------------------------------------------------
Serializer	&Serializer::operator=(const Serializer &copy)
{
	(void)copy;
	return (*this);
}

//member functions--------------------------------------------------------------------------------------------------------------------------------------------

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data			*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}