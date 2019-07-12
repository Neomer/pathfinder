//
// Created by vinokurov on 12.07.2019.
//

#include "GameAlreadyStartedPackage.h"

GameAlreadyStartedPackage::GameAlreadyStartedPackage() :
    ErrorPackage(5)
{

}

std::string_view GameAlreadyStartedPackage::getErrorMessage() const {
    return "Игра уже идет!";
}
