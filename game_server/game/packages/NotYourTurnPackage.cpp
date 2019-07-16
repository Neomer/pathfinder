//
// Created by kir on 12.07.19.
//

#include "NotYourTurnPackage.h"

std::string_view NotYourTurnPackage::getErrorMessage() const
{
    return "Сейчас не ваш ход!";
}

NotYourTurnPackage::NotYourTurnPackage() :
        ErrorPackage(7)
{

}
